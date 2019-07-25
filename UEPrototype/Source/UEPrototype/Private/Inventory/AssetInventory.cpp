// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory/AssetInventory.h"

// Sets default values
AAssetInventory::AAssetInventory()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAssetInventory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAssetInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAssetInventory::SetObjectType(TSubclassOf<UObject> InObjectType)
{
	ObjectType = InObjectType;
}

bool AAssetInventory::GetAssetInfoAtIndex(int32 Index, FAssetData& OutAssetData)
{
	if (Slots.IsValidIndex(Index))
	{
		OutAssetData = Slots[Index];
		return true;
	}
	return false;
}

bool AAssetInventory::InsertAsset(FAssetData NewAssetData)
{
	if (NewAssetData != nullptr)
	{
		Slots.Add(NewAssetData);
		return true;
	}
	return false;
}

void AAssetInventory::SetSlots(TArray<FAssetData> NewSlots)
{
	Slots = NewSlots;
}
