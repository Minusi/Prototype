// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoPlane.h"


void UGizmoPlane::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter, UStaticMesh* InMesh)
{
	Super::CreateGizmo(InAxisTypes, InOffsetFromCenter, InMesh);

	FVector Pos;
	FRotator Rot = FRotator::ZeroRotator;

	if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_X) && InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Y))
	{
		Pos.Set(OffsetFromCenter, OffsetFromCenter, 0);
	}
	else if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_X) && InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Z))
	{
		Rot.Roll = 90;
		Pos.Set(OffsetFromCenter, 0, OffsetFromCenter);
	}
	else if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Y) && InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Z))
	{
		Rot.Pitch = -90;
		Pos.Set(0, OffsetFromCenter, OffsetFromCenter);
	}
	SetWorldLocationAndRotation(Pos, Rot.Quaternion());
}

void UGizmoPlane::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	Super::UpdateGizmoTransType(InTransType);
}
