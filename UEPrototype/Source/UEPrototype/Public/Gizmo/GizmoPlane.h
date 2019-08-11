// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gizmo/GizmoMeshComponent.h"
#include "GizmoPlane.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UEPROTOTYPE_API UGizmoPlane : public UGizmoMeshComponent
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	EGizmoAxisType RotateAxisTypes;

public:
	virtual void CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter);
};
