// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory/ContentsInventory.h"

// Sets default values
AContentsInventory::AContentsInventory()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AContentsInventory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AContentsInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AContentsInventory::SetObjectType(TSubclassOf<UObject> InObjectType)
{
	ObjectType = InObjectType;
}

bool AContentsInventory::GetAssetInfoAtIndex(int32 Index, struct FAssetData& OutAssetData)
{
	if (Slots.IsValidIndex(Index))
	{
		OutAssetData = Slots[Index];
		return true;
	}
	return false;
}

bool AContentsInventory::InsertAsset(struct FAssetData NewAssetData)
{
	if (NewAssetData != nullptr)
	{
		Slots.Add(NewAssetData);
		return true;
	}
	return false;
}

void AContentsInventory::SetSlots(TArray<struct FAssetData> NewSlots)
{
	Slots = NewSlots;
}
