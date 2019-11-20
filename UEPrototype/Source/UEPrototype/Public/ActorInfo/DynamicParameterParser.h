// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorInfo/DynamicListWidget.h"
#include "DynamicParameterParser.generated.h"



struct FEmitterParam;
class AVPEmitter;
class AEmitter;
class UMaterialInstance;

UCLASS()
class UEPROTOTYPE_API UDynamicParameterParser : public UObject
{
	GENERATED_BODY()

public:

	UDynamicParameterParser();
public:
	UFUNCTION(BlueprintCallable, Category = "DynamicParameter")
	static void ParseMaterial(const UMaterialInstance* MaterialInstance, FDynamicParamList & DynamicParamList);
	UFUNCTION(BlueprintCallable, Category = "DynamicParameter")
	static void ParseParticleSystem(const UParticleSystemComponent* ParticleSystemComp, FDynamicParamList & DynamicParamList);

	
};
