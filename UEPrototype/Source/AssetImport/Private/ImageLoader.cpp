// Fill out your copyright notice in the Description page of Project Settings.

#include "ImageLoader.h"
#include "AssetImport.h"

#include "Misc/Paths.h"
#include "Engine/Texture2D.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Modules/ModuleManager.h"
#include "RenderUtils.h"
#include "Async/Async.h"



// 모듈 로딩이 메인 스레드의 외부에서 허용되지 않으므로, 미리 ImageWrapper 모듈을 로드합니다.
static IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));



UTexture2D * UImageLoader::LoadImageFromDisk(UObject * Outer, FString const & ImagePath)
{
	// 먼저 파일이 존재하는 지 확인합니다.
	if (FPaths::FileExists(ImagePath))
	{
		AI_LOG(Error, TEXT("파일을 찾을 수 없습니다 : %s"), *ImagePath);
		return nullptr;
	}

	// 파일로부터 압축된 byte data로 로드합니다.
	TArray<uint8> FileData;
	if (!FFileHelper::LoadFileToArray(FileData, *ImagePath))
	{
		AI_LOG(Error, TEXT("파일을 로드하는데 실패하였습니다 : %s"), *ImagePath);
		return nullptr;
	}

	// ImageWrapper 모듈을 사용하여 이미지 타입을 감지합니다.
	EImageFormat ImageFormat = ImageWrapperModule.DetectImageFormat(FileData.GetData(), FileData.Num());
	if (ImageFormat == EImageFormat::Invalid)
	{
		AI_LOG(Error, TEXT("알 수 없는 이미지 파일 형식 : %s"), *ImagePath);
		return nullptr;
	}

	// 발견된 이미지 포맷에 대해 ImageWrapper를 생성합니다.
	IImageWrapperPtr ImageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);
	if (!ImageWrapper.IsValid())
	{
		AI_LOG(Error, TEXT("파일의 이미지 래퍼를 생성하는 것에 실패했습니다 : %s"), *ImagePath);
		return nullptr;
	}

	// 이미지 데이터를 압축 해제합니다.
	const TArray<uint8>* RawData = nullptr;
	ImageWrapper->SetCompressed(FileData.GetData(), FileData.Num());
	ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, RawData);
	if (RawData == nullptr)
	{
		AI_LOG(Error, TEXT("이미지 파일을 압축 해제하는 데 실패했습니다 : %s"), *ImagePath);
		return nullptr;
	}

	// 텍스처를 생성하고 압축 해제된 이미지 데이터를 업로드합니다.
	FString TextureBaseName = TEXT("Tex_") + FPaths::GetBaseFilename(ImagePath);
	return CreateTexture(Outer, *RawData, ImageWrapper->GetWidth(), ImageWrapper->GetHeight(),
		EPixelFormat::PF_B8G8R8A8, FName(*TextureBaseName));
}

UImageLoader* UImageLoader::LoadImageFromDiskAsync(UObject* Outer, FString const & ImagePath)
{
	// 단순히 새로운 ImageLoader를 생성하여, 비동기 로드를 수행합니다.
	UImageLoader* ImageLoader = NewObject<UImageLoader>();
	ImageLoader->LoadImageAsync(Outer, ImagePath);
	return ImageLoader;
}

void UImageLoader::LoadImageAsync(UObject * Outer, FString const & ImagePath)
{
	// 비동기 로딩 연산이 완료되면 결과 값을 가지는 Future로 표현됩니다.
	Future = LoadImageFromDiskAsync(Outer, ImagePath, [this]()
	{
		if (Future.IsValid())
		{
			// 게임 스레드에서 로드된 텍스처에 대한 리스너들에게 노티파이합니다.
			AsyncTask(ENamedThreads::GameThread, [this]()
			{
				LoadCompleted.Broadcast(Future.Get());
			});
		}
	});
}

TFuture<UTexture2D*> UImageLoader::LoadImageFromDiskAsync(UObject * Outer, FString const & ImagePath, TFunction<void()> CompletionCallback)
{
	return Async<UTexture2D*>(EAsyncExecution::ThreadPool, [=]()
	{
		return LoadImageFromDisk(Outer, ImagePath);
	}, CompletionCallback);
}





UTexture2D * UImageLoader::CreateTexture(UObject * Outer, TArray<uint8> const & PixelData, int32 InSizeX, int32 InSizeY, EPixelFormat InFormat, FName BaseName)
{
	// UTexture2D::CreateRransient를 몇 가지 수정하여 베꼈습니다.
	if (InSizeX <= 0 || InSizeY <= 0 ||
		(InSizeX % GPixelFormats[InFormat].BlockSizeX) != 0 ||
		(InSizeY % GPixelFormats[InFormat].BlockSizeY) != 0)
	{
		AI_LOG(Error, TEXT("Invalid parameters specified for UImageLoader::CreateTexture()"));
		return nullptr;
	}
	
	// UTexture2D::CreateTransient와 다른 가장 중요한 부분입니다:
	// 새 텍스처데 이름과 owner를 제공합니다.
	FName TextureName = MakeUniqueObjectName(Outer, UTexture2D::StaticClass(), BaseName);
	UTexture2D* NewTexture = NewObject<UTexture2D>(Outer, TextureName, RF_Transient);
	
	NewTexture->PlatformData = new FTexturePlatformData();
	NewTexture->PlatformData->SizeX = InSizeX;
	NewTexture->PlatformData->SizeY = InSizeY;
	NewTexture->PlatformData->PixelFormat = InFormat;

	// 첫 밉맵을 할당하고 픽셀 데이터를 업로드합니다.
	int32 NumBlocksX = InSizeX / GPixelFormats[InFormat].BlockSizeX;
	int32 NumBlocksY = InSizeY / GPixelFormats[InFormat].BlockSizeY;
	FTexture2DMipMap* Mip = new(NewTexture->PlatformData->Mips) FTexture2DMipMap();
	Mip->SizeX = InSizeX;
	Mip->SizeY = InSizeY;

	Mip->BulkData.Lock(LOCK_READ_WRITE);
	void* TextureData = Mip->BulkData.Realloc(NumBlocksX * NumBlocksY * GPixelFormats[InFormat].BlockBytes);
	Mip->BulkData.Unlock();

	NewTexture->UpdateResource();
	return NewTexture;
}
 