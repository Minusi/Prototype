// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridMeshPool.h"
#include "GridManager.generated.h"

UCLASS()
class UEPROTOTYPE_API AGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 테스트. 나중에 삭제하시오.
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Test", meta=(AllowPrivateAccess="true"))
	UGridMeshPool* TestPool;
};
