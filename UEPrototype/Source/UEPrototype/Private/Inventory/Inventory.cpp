// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory/Inventory.h"
#include "Engine/World.h"

AInventory::AInventory()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInventory::GenerateAssetInventory(TSubclassOf<UObject> ObjectType, TArray<FAssetData> AssetDatas)
{
	AAssetInventory* NewAssetInventory = GetWorld()->SpawnActor<AAssetInventory>(FVector::ZeroVector, FRotator::ZeroRotator);
	NewAssetInventory->SetObjectType(ObjectType);
	NewAssetInventory->SetSlots(AssetDatas);
	NewAssetInventory->GenerateWidget();

	AssetInventorys.Add(NewAssetInventory);
}

AAssetInventory* AInventory::GetAssetInventory(TSubclassOf<UObject> ObjectType)
{
	for (auto Inven : AssetInventorys)
	{
		if (Inven->GetObjectType() == ObjectType)
			return Inven;
	}
	return nullptr;
}
