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

	/* UOutliner를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static UVPMaterial* GetGlobalMaterial();

	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialVectorParam(UStaticMeshComponent* Target, FVector Vector, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialUTexture2DParam(UStaticMeshComponent* Target, UTexture2D* Texture2D, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialLinearColor(UStaticMeshComponent* Target, FLinearColor Color, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetMaterialScalarParam(UStaticMeshComponent* Target, float Value, FName Name);


};
