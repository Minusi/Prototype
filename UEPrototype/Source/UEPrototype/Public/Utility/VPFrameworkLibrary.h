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
};
 