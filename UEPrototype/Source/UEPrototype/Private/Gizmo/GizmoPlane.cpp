// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoPlane.h"


void UGizmoPlane::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter)
{
	Super::CreateGizmo(InAxisTypes, InOffsetFromCenter);

	FVector Pos;
	FRotator Rot = FRotator::ZeroRotator;

	if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_X) && InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Y))
	{
		Pos.Set(InOffsetFromCenter, InOffsetFromCenter, 0);
		RotateAxisTypes = EGizmoAxisType::GM_AXIS_Z;
	}
	else if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_X) && InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Z))
	{
		Rot.Roll = 90;
		Pos.Set(InOffsetFromCenter, 0, InOffsetFromCenter);
		RotateAxisTypes = EGizmoAxisType::GM_AXIS_Y;
	}
	else if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Y) && InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Z))
	{
		Rot.Pitch = -90;
		Pos.Set(0, InOffsetFromCenter, InOffsetFromCenter);
		RotateAxisTypes = EGizmoAxisType::GM_AXIS_X;
	}
	SetWorldLocationAndRotation(Pos, Rot.Quaternion());
}