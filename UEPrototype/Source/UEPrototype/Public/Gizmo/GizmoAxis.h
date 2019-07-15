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
	
private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Axes|Axis", meta = (AllowPrivateAccess = "true"))
	TMap<EGizmoTransType, UStaticMesh*> TransTypeMeshs;

public:
	virtual void UpdateGizmoTransType(EGizmoTransType InTransType) override;

};
