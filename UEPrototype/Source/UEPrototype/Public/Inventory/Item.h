// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Texture2D.h"
#include "Item.generated.h"

USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	FText Name;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	FText Description;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	UTexture2D* Icon;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	bool CanBeUsed;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	FText UseText;
};


UCLASS()
class UEPROTOTYPE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	void OnUsedItem();

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	FItemInfo GetItemInfo();

private:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Item", meta = (AllowPrivateAccess = "true"))
	FItemInfo ItemInfo;
};
