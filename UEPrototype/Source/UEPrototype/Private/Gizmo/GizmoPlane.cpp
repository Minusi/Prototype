// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoPlane.h"


void UGizmoPlane::CreateGizmo(EGizmoAxisType InAxisType, float InOffsetFromCenter, UStaticMesh* InMesh)
{
	Super::CreateGizmo(InAxisType, InOffsetFromCenter, InMesh);

	FVector Pos;
	FRotator Rot = FRotator::ZeroRotator;
	switch (AxisType)
	{
	case EGizmoAxisType::GM_AXIS_XY: 
		Pos.Set(OffsetFromCenter, OffsetFromCenter, 0); 
		break;

	case EGizmoAxisType::GM_AXIS_YZ: 
		Rot.Pitch = -90; 
		Pos.Set(0, OffsetFromCenter, OffsetFromCenter); 
		break;

	case EGizmoAxisType::GM_AXIS_XZ:
		Rot.Roll = 90;
		Pos.Set(OffsetFromCenter, 0, OffsetFromCenter);
		break;
	}
	SetWorldLocationAndRotation(Pos, Rot.Quaternion());
}

void UGizmoPlane::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	Super::UpdateGizmoTransType(InTransType);
}
