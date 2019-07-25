// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetRegistry/Public/AssetData.h"
#include "Inventory/AssetInventory.h"
#include "Inventory.generated.h"

UCLASS(BlueprintType)
class UEPROTOTYPE_API AInventory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:	

	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	void GenerateAssetInventory(TSubclassOf<UObject> ObjectType, TArray<FAssetData> AssetDatas);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	AAssetInventory* GetAssetInventory(TSubclassOf<UObject> ObjectType);

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Asset", meta = (AllowPrivateAccess = "true"))
	TArray<AAssetInventory*> AssetInventorys;
};
