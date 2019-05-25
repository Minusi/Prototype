// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Async/Future.h"
#include "UObject/NoExportTypes.h"
#include "PixelFormat.h"
#include "ImageLoader.generated.h"



class UTexture2D;



/**
 *	UImageLoader 클래스는 이미지를 텍스처에 비동기적으로 로드하는 유틸리티 클래스입니다.
 *	Blueprint 스크립트가 이미지의 비동기 로딩을 요청하고 로딩이 완료되면 알림을 받을 수 있습니다.
 */
UCLASS(BlueprintType, ClassGroup=Assimp)
class ASSETIMPORT_API UImageLoader : public UObject
{
	GENERATED_BODY()
	
public:
	/** 이미지 로딩이 끝났을 때 브로드캐스트하는 멀티캐스트입니다. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnImageLoadCompleted, UTexture2D*, Texture);



public:
	/** 
		이미지 파일을 디스크에서 텍스처로 로드합니다. 완료될 때까지 호출 스레드를 블록합니다.
		@return 로드된 이미지 파일로부터 생성된 텍스처
	*/
	UFUNCTION(BlueprintCallable, Category = Assimp, meta = (HidePin = "Outer", DefaultToSelf = "Outer"))
	static UTexture2D* LoadImageFromDisk(UObject* Outer, FString const & ImagePath);

	/**
		이미지 파일을 디스크에서 작업자 스레드의 텍스처로 로드합니다. 이것을 호출 스레드를 블록하지 않습니다.
		내부적으로 LoadImageAsync 함수를 호출합니다.
		@return 사용자가 바인드할 수 있는 OnLoadCompleted 이벤트가 있는 이미지 로더 객체입니다. 로딩이 완료되면 알림을 받습니다.
	*/
	UFUNCTION(BlueprintCallable, Category=Assimp, meta=(HidePin="Outer", DefaultToSelf="Outer"))
	static UImageLoader* LoadImageFromDiskAsync(UObject* Outer, FString const & ImagePath);

private:
	/**
		로드 작업을 수행하고 완료됐을 때 이벤트를 호출하는 헬퍼 함수입니다.
		내부적으로 LoadImageFromDiskAsync(args[3])을 호출합니다.
	*/
	void LoadImageAsync(UObject* Outer, FString const & ImagePath);

public:
	/**
		이미지 파일을 디스크에서 워커 스레드의 텍스처로 로드합니다. 이것은 호출 스레드를 블록하지 않습니다.
		@return 로드가 완료되면, 이미지 텍스처를 보관 및 유지하는 Future 객체입니다.
	*/
	static TFuture<UTexture2D*> LoadImageFromDiskAsync(UObject* Outer, FString const & ImagePath, TFunction<void()> CompletionCallback);

	/** 이 액세서 함수는 C++ 코드를 이벤트에 바인드할 수 있도록 합니다. */
	FOnImageLoadCompleted & OnLoadCompleted()
	{
		return LoadCompleted;
	}

private:
	/**	Raw 픽셀 데이터로부터 새로운 텍스처를 동적으로 생성하는 헬퍼 함수입니다. */
	static UTexture2D* CreateTexture(UObject* Outer, TArray<uint8> const & PixelData,
		int32 InSizeX, int32 InSizeY, EPixelFormat PixelFromat = EPixelFormat::PF_B8G8R8A8, FName BaseName = NAME_None);





private:
	/**
		이미지 로드 완료시 브로드캐스트트 하는 이벤트 델리게이트입니다.
		블루프린트 스크립트에서 이벤트 바인딩을 허용합니다.
	*/
	UPROPERTY(BlueprintAssignable, Category=Assimp, meta=(AllowPrivateAccess=true))
	FOnImageLoadCompleted LoadCompleted;

	/** 비동기 로딩 연산 이후 값이 저장되는 Future 객체입니다. */
	TFuture<UTexture2D*> Future;
};
