// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory/Item.h"
#include "ItemInventory.generated.h"

USTRUCT(BlueprintType)
struct FSlotState
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	int32 ValidSlotIndex;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	bool bIsAllSlotsFull;

public:
	FSlotState()
	{
		ValidSlotIndex = 0;
		bIsAllSlotsFull = true;
	}

	void SetState(int32 ValidSlotIndex, bool bIsAllSlotsFull)
	{
		this->ValidSlotIndex = ValidSlotIndex;
		this->bIsAllSlotsFull = bIsAllSlotsFull;
	}
};

UCLASS(BlueprintType)
class UEPROTOTYPE_API AItemInventory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	void GenerateInventory();

	UFUNCTION(BlueprintPure, Category = "Inventory|Item")
	bool GetItemInfoAtIndex(int32 Index, FItemInfo& OutItemInfo);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	bool AddItem(AItem* NewItem);

private:

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	FSlotState SearchEmptySlotIndex();

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	bool IsAllSlotFull();

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	bool IsSlotEmpty(int32 Index);

private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	int32 MaxSlotSize;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	int32 UsedSlotCount;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	int32 MaxStackedSize;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	TArray<AItem*> Slots;
};
