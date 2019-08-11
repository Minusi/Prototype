// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Texture2D.h"
#include "Math/Color.h"
#include "VPMaterial.generated.h"


class UMaterialInstanceDynamic;

UCLASS(Blueprintable, BlueprintType)
class UEPROTOTYPE_API UVPMaterial : public UObject
{
	GENERATED_BODY()

public:
	
	UVPMaterial();
	
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialVectorParam(AActor* Target,FVector Vector, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialUTexture2DParam(AActor* Target,UTexture2D* Texture2D, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialLinearColor(AActor* Target,FLinearColor Color, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialScalarParam(AActor* Target, float Value, FName Name);

	
};
