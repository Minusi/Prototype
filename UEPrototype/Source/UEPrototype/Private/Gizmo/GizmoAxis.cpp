// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoAxis.h"

void UGizmoAxis::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter, UStaticMesh* InMesh)
{
	Super::CreateGizmo(InAxisTypes, InOffsetFromCenter, InMesh);
	FVector Pos;
	FRotator Rot = FRotator::ZeroRotator;

	if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_X))
	{
		Rot.Pitch = -90;
		Pos = Rot.Vector().ForwardVector * OffsetFromCenter;
	}
	else if(InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Y))
	{
		Rot.Roll = 90;
		Pos = Rot.Vector().RightVector * OffsetFromCenter;
	}
	else if(InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Z))
	{
		Pos = FVector::UpVector * OffsetFromCenter;
	}
	SetWorldLocationAndRotation(Pos, Rot.Quaternion());
}

void UGizmoAxis::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	Super::UpdateGizmoTransType(InTransType);
}

