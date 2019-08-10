// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool/SightToolBase.h"
#include "BasicSightTool.generated.h"

/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UBasicSightTool : public USightToolBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UBasicSightTool();

	/* BasicSightTool을 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Input", meta = (UnsafeDuringActorConstruction = "true"))
	static UBasicSightTool* GetGlobalBasicSightTool();
};
