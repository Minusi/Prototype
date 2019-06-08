// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrototypeCodedActor.generated.h"



class UTexture2D;

UCLASS()
class UEPROTOTYPE_API APrototypeCodedActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APrototypeCodedActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



private:
	UPROPERTY()
	UTexture2D * TestTexture;

public:	
	// 런타임 동적 이미지 생성을 분석하기 위한 함수 블록입니다.
	UFUNCTION(BlueprintCallable, Category=Prototype)
	void SaveImagePackage(UTexture2D* Texture);

	// 경로에 대해서 분석하기 위한 함수 블록입니다.
	UFUNCTION(BlueprintCallable, Category=Prototype)
	void PrintAllPathFunction();

	// 애셋 레지스트리에 대해서 분석하기 위한 함수 블록입니다.
	UFUNCTION(BlueprintCallable, Category=Prototype)
	void ExecuteAssetResigtryFunction();

	UFUNCTION(BlueprintCallable, Category=Prototype)
	void AnalyzeAboutStaticMesh(class UStaticMesh* InStaticMesh);
};
