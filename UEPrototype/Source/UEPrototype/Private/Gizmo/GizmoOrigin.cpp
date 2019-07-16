// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoOrigin.h"

void UGizmoOrigin::CreateGizmo(EGizmoAxisType InAxisType, float InOffsetFromCenter, UStaticMesh* InMesh)
{
	Super::CreateGizmo(InAxisType, InOffsetFromCenter, InMesh);
	SetWorldLocation(FVector::UpVector * -InOffsetFromCenter);
}

void UGizmoOrigin::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	Super::UpdateGizmoTransType(InTransType);
}

