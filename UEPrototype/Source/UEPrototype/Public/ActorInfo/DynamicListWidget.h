// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "DynamicListWidget.generated.h"

/*
 *	DynamicListText는 동적 리스트 위젯에 텍스트
 *	배열을 전달하기 위해서 구성된 래퍼 구조체입
 *	니다. 주 사용 예는 컨텍스트 메뉴를 띄우는
 *	것입니다.
 */
USTRUCT(BlueprintType)
struct FDynamicListText
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
		TArray<FText> TextList;
};

/*
 *	DynamicListProperty는 동적 리스트 위젯에 프로퍼티
 *	컨테이너를 전달하기 위해서 구성된 래퍼 구조체입니
 *	다. 주 사용 예는 펹집 창에서 편집 컨텍스트 메뉴를
 *	띄우는 것입니다.
 */
USTRUCT(BlueprintType)
struct FDynamicParamList
{
	GENERATED_BODY()

public:
	/* 머티리얼, 이미터 등의 동적 파라미터에 대응됩니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	TMap<FName, FVector> NameVectorMap;

	/* 머티리얼, 이미터 등의 동적 파라미터에 대응됩니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	TMap<FName, float> NameScalarMap;

	/* 머티리얼, 이미터 등의 동적 파라미터에 대응됩니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	TMap<FName, UTexture2D*> NameTextureMap;

	/* 머티리얼, 이미터 등의 동적 파라미터에 대응됩니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	TMap<FName, FLinearColor> NameColorMap;
};

/**
 *	위젯의 ui 컴포넌트들이 액터의 타입에 맞게 동적으로 생성되고
 *	확장될 수 있는 커스텀 위젯입니다. 이 클래스는 단지 BP의 생성
 *	을 위한 Base class로, 구현은 BP에서 수행되어야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API UDynamicListWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/* Text 배열을 입력받아 동적으로 UI를 구성합니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "ActorInfo")
	void ConstructDynamicListText(const FDynamicListText& InTextList);

	/* Property 컨테이너를 입력받아 동적으로 UI를 구성합니다 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "ActorInfo")
	void ConstructDynamicListProperpty(const FDynamicParamList& InPropertyList);
};
