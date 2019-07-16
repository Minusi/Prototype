// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoAxis.h"

void UGizmoAxis::CreateGizmo(EGizmoAxisType InAxisType, float InOffsetFromCenter, UStaticMesh* InMesh)
{
	Super::CreateGizmo(InAxisType, InOffsetFromCenter, InMesh);
	FVector Pos, Dir;
	FRotator Rot = FRotator::ZeroRotator;

	switch (AxisType)
	{
	case EGizmoAxisType::GM_AXIS_X: 

		Rot.Pitch = -90;
		//Dir.Set(0, -90, 0);
		Pos = Rot.Vector().ForwardVector * OffsetFromCenter;
		break;

	case EGizmoAxisType::GM_AXIS_Y: 
		Rot.Roll = 90;
		//Dir.Set(90, 0, 0);
		Pos = Rot.Vector().RightVector * OffsetFromCenter;
		break;

	case EGizmoAxisType::GM_AXIS_Z: 
		Pos = FVector::UpVector * OffsetFromCenter;
		break;

	}
	SetWorldLocationAndRotation(Pos, Rot.Quaternion());
}

void UGizmoAxis::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	Super::UpdateGizmoTransType(InTransType);
}

