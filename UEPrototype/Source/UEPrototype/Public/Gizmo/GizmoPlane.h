// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gizmo/GizmoMeshComponent.h"
#include "GizmoPlane.generated.h"

/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UGizmoPlane : public UGizmoMeshComponent
{
	GENERATED_BODY()

public:
	virtual void UpdateGizmoTransType(EGizmoTransType InTransType) override;
};
