// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoOrigin.h"

void UGizmoOrigin::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter, UStaticMesh* InMesh)
{
	Super::CreateGizmo(InAxisTypes, InOffsetFromCenter, InMesh);
	SetWorldLocation(FVector::UpVector * -InOffsetFromCenter);
}

void UGizmoOrigin::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	Super::UpdateGizmoTransType(InTransType);
}

