// Fill out your copyright notice in the Description page of Project Settings.

#include "PrototypeCodedActor.h"

/*********************************/
#include "UObject/Package.h"
#include "Engine/Texture2D.h"
#include "Math/UnrealMathUtility.h"
#include "TextureResource.h"
#include "UObject/ConstructorHelpers.h"
/*********************************/



// Sets default values
APrototypeCodedActor::APrototypeCodedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
