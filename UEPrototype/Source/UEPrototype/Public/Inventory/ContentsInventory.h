// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContentsInventory.generated.h"

// 콘텐츠를 담고 사용할 수 있게 인벤토리 생성 및 쿼리를 제공
UCLASS(BlueprintType)
class UEPROTOTYPE_API AContentsInventory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AContentsInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	// 위젯을 생성합니다. (블루프린트상에서 구현)
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|Asset")
	void GenerateWidget();

	// 이 인벤토리가 나타내는 오브젝트 타입을 설정합니다.
	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	void SetObjectType(TSubclassOf<UObject> InObjectType);

	// 데이터 배열을 받아와서 슬롯으로 설정합니다.
	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	void SetSlots(TArray<struct FAssetData> NewSlots);

	// 슬롯에 새로운 에셋(FAssetData)을 추가합니다.
	UFUNCTION(BlueprintCallable, Category = "Inventory|Asset")
	bool InsertAsset(struct FAssetData NewAssetData);

	// 인덱스 위치에 담겨있는 에셋 데이터를 가져옵니다.
	UFUNCTION(BlueprintPure, Category = "Inventory|Asset")
	bool GetAssetInfoAtIndex(int32 Index, struct FAssetData& OutAssetData);

	inline TSubclassOf<UObject> GetObjectType() { return ObjectType; };
		
private:
	// 최대 담을 수 있는 슬롯의 크기 (현재는 스크롤 방식이므로 크게 의미 없음)
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	int32 MaxSlotSize;

	// 이 인벤토리가 나타내는 오브젝트형
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Asset", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UObject> ObjectType;

	// 오브젝트의 데이터 배열
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Inventory|Asset", meta = (AllowPrivateAccess = "true"))
	TArray<struct FAssetData> Slots;
};