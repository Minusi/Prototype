// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeCodedActor.h"
#include "UEPrototype.h"

/*********************************/
#include "UObject/Package.h"
#include "Engine/Texture2D.h"
#include "Math/UnrealMathUtility.h"
#include "TextureResource.h"
#include "UObject/ConstructorHelpers.h"
/*********************************/
#include "Misc/Paths.h"
#include "UObjectHash.h"
#include "MetaData.h"
/*********************************/
#include "AssetRegistryModule.h"
#include "IAssetRegistry.h"
/*********************************/
#include "Engine/StaticMesh.h"
#include "StaticMeshResources.h"
#include "StaticMeshVertexData.h"




// Sets default values
APrototypeCodedActor::APrototypeCodedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APrototypeCodedActor::BeginPlay()
{
	Super::BeginPlay();

	/*
	int32 TextureWidth = 512;
	int32 TextureHeight = 512;


	FString TextureName = TEXT("Texture");
	FString PackageName = TEXT("/Game/");
	PackageName += TextureName;

	UPackage* Package = CreatePackage(nullptr, *PackageName);
	Package->FullyLoad();

	UTexture2D* NewTexture = NewObject<UTexture2D>(Package, *TextureName, RF_Public | RF_Standalone | RF_MarkAsRootSet);

	NewTexture->AddToRoot();
	NewTexture->PlatformData = new FTexturePlatformData();
	NewTexture->PlatformData->SizeX = TextureWidth;
	NewTexture->PlatformData->SizeY = TextureHeight;
	NewTexture->PlatformData->NumSlices = 1;
	NewTexture->PlatformData->PixelFormat = EPixelFormat::PF_B8G8R8A8;

	uint8* Pixels = new uint8[TextureWidth * TextureHeight * 4];
	for (int32 y = 0; y < TextureHeight; ++y)
	{
		for (int32 x = 0; x < TextureWidth; ++x)
		{
			int32 curPixelIndex = ((y * TextureWidth) + x);
			Pixels[4 * curPixelIndex] = FMath::RandRange(0,255);		// B
			Pixels[4 * curPixelIndex + 1] = FMath::RandRange(0, 255);	// G
			Pixels[4 * curPixelIndex + 2] = FMath::RandRange(0, 255);	// R
			Pixels[4 * curPixelIndex + 2] = FMath::RandRange(0, 255);	// A
		}
	}

	// Allocate first mipmap
	FTexture2DMipMap* Mip = new(NewTexture->PlatformData->Mips) FTexture2DMipMap();
	Mip->SizeX = TextureWidth;
	Mip->SizeY = TextureHeight;

	// Lock the texture so it can be modified
	Mip->BulkData.Lock(LOCK_READ_WRITE);
	uint8* TextureData = (uint8*)Mip->BulkData.Realloc(TextureWidth * TextureHeight * 4);
	FMemory::Memcpy(TextureData, Pixels, sizeof(uint8) * TextureWidth * TextureHeight * 4);
	Mip->BulkData.Unlock();

	...

	*/


}





void APrototypeCodedActor::SaveImagePackage(UTexture2D* Texture)
{
	FString Dummy = TEXT("/Game/DummyText");
	UPackage* Package = CreatePackage(nullptr, *Dummy);
	if (Texture == nullptr)
	{
		VP_LOG(Error, TEXT("텍스처가 유효하지 않습니다"));
		return;
	}

	FString LongDummy = FPackageName::LongPackageNameToFilename(Dummy, FPackageName::GetAssetPackageExtension());

	if (UPackage::SavePackage(Package, Texture, RF_Standalone, *LongDummy))
	{
		UPackage* SavedPackage = LoadPackage(nullptr, *LongDummy, LOAD_None);
		TArray<UObject*> ObjectsInPackage;

		GetObjectsWithOuter(SavedPackage, ObjectsInPackage, false);

		for (const auto& EachObject : ObjectsInPackage)
		{
			if (IsValid(EachObject) == false)
			{
				VP_LOG(Log, TEXT("FALSE"));
				continue;
			}

			UTexture2D* PackageTexture = Cast<UTexture2D>(EachObject);

			VP_LOG(Log, TEXT("%s"), *EachObject->StaticClass()->GetName());
			VP_LOG(Log, TEXT("%s"), *EachObject->GetClass()->GetName());

			UMetaData* TestMeta = Cast<UMetaData>(EachObject);
			if (TestMeta)
			{
				VP_LOG(Log, TEXT("MetaData Extract..."));
			}

			if (PackageTexture)
			{
				VP_LOG(Log, TEXT("Success!!"));
				TestTexture = PackageTexture;
			}
			else
			{
				VP_LOG(Warning, TEXT("NO"));
			}
		}
	}
	else
	{
		VP_LOG(Warning, TEXT("Falied!!!"));
	}

	//Texture->SetFlags(RF_Public);
	//Texture->Rename(*FPaths::GetCleanFilename(Dummy), Package, RF_Public);
	//VP_LOG(Log, TEXT("PacakageName : %s"), *FPaths::GetCleanFilename(Dummy));

	//FAssetRegistryModule::AssetCreated(Texture);
	//Texture->MarkPackageDirty();
}

void APrototypeCodedActor::PrintAllPathFunction()
{
	VP_LOG(Log, TEXT("FPaths::RootDir() : %s"), *FPaths::RootDir());
	VP_LOG(Log, TEXT("FPaths::EngineDir() : %s"), *FPaths::EngineDir());
	VP_LOG(Warning, TEXT("FPaths::EngineDir()_FULL : %s"), *FPaths::ConvertRelativePathToFull(*FPaths::EngineDir()));
	VP_LOG(Log, TEXT("FPaths::EngineConfigDir() : %s"), *FPaths::EngineConfigDir());
	VP_LOG(Log, TEXT("FPaths::EngineContentDir() : %s"), *FPaths::EngineContentDir());
	VP_LOG(Log, TEXT("FPaths::EngineIntermediateDir() : %s"), *FPaths::EngineIntermediateDir());
	VP_LOG(Log, TEXT("FPaths::EngineSavedDir() : %s"), *FPaths::EngineSavedDir());
	VP_LOG(Log, TEXT("FPaths::EngineSourceDir() : %s"), *FPaths::EngineSourceDir());
	VP_LOG(Log, TEXT("FPaths::EnginePluginsDir() : %s"), *FPaths::EnginePluginsDir());
	VP_LOG(Log, TEXT("FPaths::LaunchDir() : %s"), *FPaths::LaunchDir());
	
	VP_LOG(Log, TEXT("================================"));

	VP_LOG(Log, TEXT("FPaths::FeaturePackDir() : %s"), *FPaths::FeaturePackDir());
	VP_LOG(Log, TEXT("FPaths::EnterpriseDir() : %s"), *FPaths::EnterpriseDir());
	VP_LOG(Log, TEXT("FPaths::EnterpriseFeaturePackDir() : %s"), *FPaths::EnterpriseFeaturePackDir());
	VP_LOG(Log, TEXT("FPaths::EnterprisePluginsDir() : %s"), *FPaths::EnterprisePluginsDir());

	VP_LOG(Log, TEXT("================================"));
	VP_LOG(Log, TEXT("FPaths::EngineUserDir() : %s"), *FPaths::EngineUserDir());
	VP_LOG(Log, TEXT("FPaths::EngineVersionAgnosticUserDir() : %s"), *FPaths::EngineVersionAgnosticUserDir());
	VP_LOG(Log, TEXT("FPaths::GameAgnosticSavedDir() : %s"), *FPaths::GameAgnosticSavedDir());
	VP_LOG(Log, TEXT("FPaths::ShaderWorkingDir() : %s"), *FPaths::ShaderWorkingDir());

	VP_LOG(Log, TEXT("================================"));
	
	VP_LOG(Log, TEXT("FPaths::ProjectDir() : %s"), *FPaths::ProjectDir());
	VP_LOG(Log, TEXT("FPaths::ProjectUserDir() : %s"), *FPaths::ProjectUserDir());

	VP_LOG(Log, TEXT("FPaths::ProjectConfigDir() : %s"), *FPaths::ProjectConfigDir());
	VP_LOG(Log, TEXT("FPaths::SourceConfigDir() : %s"), *FPaths::SourceConfigDir());

	VP_LOG(Log, TEXT("FPaths::ProjectIntermediateDir() : %s"), *FPaths::ProjectIntermediateDir());

	VP_LOG(Log, TEXT("FPaths::GameContentDir() : %s"), *FPaths::GameContentDir());
	VP_LOG(Log, TEXT("FPaths::GameDevelopersDir() : %s"), *FPaths::GameDevelopersDir());
	VP_LOG(Log, TEXT("FPaths::GameUserDeveloperDir() : %s"), *FPaths::GameUserDeveloperDir());

	VP_LOG(Log, TEXT("FPaths::ProjectSavedDir() : %s"), *FPaths::ProjectSavedDir());
	VP_LOG(Log, TEXT("FPaths::AutomationDir() : %s"), *FPaths::AutomationDir());
	VP_LOG(Log, TEXT("FPaths::AutomationLogDir() : %s"), *FPaths::AutomationLogDir());
	VP_LOG(Log, TEXT("FPaths::AutomationTransientDir() : %s"), *FPaths::AutomationTransientDir());
	VP_LOG(Log, TEXT("FPaths::BugItDir() : %s"), *FPaths::BugItDir());
	VP_LOG(Log, TEXT("FPaths::CloudDir() : %s"), *FPaths::CloudDir());
	VP_LOG(Log, TEXT("FPaths::DiffDir() : %s"), *FPaths::DiffDir());
	VP_LOG(Log, TEXT("FPaths::GeneratedConfigDir() : %s"), *FPaths::GeneratedConfigDir());
	VP_LOG(Log, TEXT("FPaths::ProjectLogDir() : %s"), *FPaths::ProjectLogDir());

	VP_LOG(Log, TEXT("FPaths::ProjectModsDir() : %s"), *FPaths::ProjectModsDir());
	VP_LOG(Log, TEXT("FPaths::GameSourceDir() : %s"), *FPaths::GameSourceDir());
	VP_LOG(Log, TEXT("FPaths::ProjectPluginsDir() : %s"), *FPaths::ProjectPluginsDir());

	VP_LOG(Log, TEXT("FPaths::ProjectPersistentDownloadDir() : %s"), *FPaths::ProjectPersistentDownloadDir());
	VP_LOG(Log, TEXT("FPaths::ProfilingDir() : %s"), *FPaths::ProfilingDir());
	VP_LOG(Log, TEXT("FPaths::SandboxesDir() : %s"), *FPaths::SandboxesDir());
	VP_LOG(Log, TEXT("FPaths::ScreenShotDir() : %s"), *FPaths::ScreenShotDir());
	VP_LOG(Log, TEXT("FPaths::VideoCaptureDir() : %s"), *FPaths::VideoCaptureDir());
}

void APrototypeCodedActor::ExecuteAssetResigtryFunction()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	const UClass* Class = UTexture2D::StaticClass();
	AssetRegistryModule.Get().GetAssetsByClass(Class->GetFName(), AssetData);
	for (auto EachTexture : AssetData)
	{
		if (EachTexture.AssetName.ToString().StartsWith("Engine") == false)
		{
			VP_LOG(Warning, TEXT("------------------------"));
			VP_LOG(Log, TEXT("AssetData Name   : %s"), *EachTexture.AssetName.ToString());
			VP_LOG(Log, TEXT("AssetData Class  : %s"), *EachTexture.AssetClass.ToString());
			VP_LOG(Log, TEXT("AssetData Pacakge: %s"), *EachTexture.PackageName.ToString());
		}
	} 

}



void APrototypeCodedActor::AnalyzeAboutStaticMesh(UStaticMesh* InStaticMesh)
{
	if (IsValid(InStaticMesh) == false)
	{
		VP_LOG(Warning, TEXT("StaticMesh Argument is not valid"));
		return;
	}

	for (int32 LODIndex = 0; LODIndex < InStaticMesh->RenderData->LODResources.Num(); ++LODIndex)
	{
		for (uint32 Index = 0; Index < InStaticMesh->RenderData->LODResources[LODIndex].VertexBuffers.PositionVertexBuffer.GetNumVertices(); ++Index)
		{
			FVector EachVector = InStaticMesh->RenderData->LODResources[LODIndex].VertexBuffers.PositionVertexBuffer.VertexPosition(Index);
			VP_LOG(Log, TEXT("Index(%d) : (%f, %f, %f)"), Index, EachVector.X, EachVector.Y, EachVector.Z);
		}
	}
	
	VP_LOG(Warning, TEXT("********** END AnalyzeAboutStaticMesh **********"));
}