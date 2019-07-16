// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gizmo/GizmoMeshComponent.h"
#include "GizmoAxis.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UEPROTOTYPE_API UGizmoAxis : public UGizmoMeshComponent
{
	GENERATED_BODY()

public:
	virtual void CreateGizmo(EGizmoAxisType InAxisType, float InOffsetFromCenter, UStaticMesh* InMesh);
	virtual void UpdateGizmoTransType(EGizmoTransType InTransType);
};
