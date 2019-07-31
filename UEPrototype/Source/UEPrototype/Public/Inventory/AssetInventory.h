// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory/Item.h"
#include "AssetInventory.generated.h"

UCLASS(BlueprintType)
class UEPROTOTYPE_API AAssetInventory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAssetInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|Asset")
	void GenerateWidget();

	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	void SetObjectType(TSubclassOf<UObject> InObjectType);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	void SetSlots(TArray<FAssetData> NewSlots);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	bool InsertAsset(FAssetData NewAssetData);

	UFUNCTION(BlueprintPure, Category = "Inventory|Asset")
	bool GetAssetInfoAtIndex(int32 Index, FAssetData& OutAssetData);

	inline TSubclassOf<UObject> GetObjectType() { return ObjectType; };

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	int32 MaxSlotSize;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Asset", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UObject> ObjectType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Asset", meta = (AllowPrivateAccess = "true"))
	TArray<FAssetData> Slots;
};