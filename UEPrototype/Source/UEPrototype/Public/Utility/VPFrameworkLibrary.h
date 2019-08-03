// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VPFrameworkLibrary.generated.h"



class AEditorWorldManager;

/**
 *	
 */
UCLASS()
class UEPROTOTYPE_API UVPFrameworkLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/* AEditorWorldManager::GetGlobalEditorWorldManager의 래퍼 함수입니다 */
	UFUNCTION(BlueprintGetter, Category = "Utility", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static AEditorWorldManager * GetEditorWorldManager(const UObject* WorldContextObject);



public:
	/* 현재 객체가 아키타입이 아니면서 EditorWorldManager에 Owned되고 있는지 검사합니다.
		이 검사는 싱글톤 프레임워크를 구성하기 위해 반드시 생성자에서 프로퍼티들을 초기화
		하기 이전에 검사되어야 합니다. */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Utility|System")
	static bool IsValidSingletonCDO(UObject* Target);
};
 