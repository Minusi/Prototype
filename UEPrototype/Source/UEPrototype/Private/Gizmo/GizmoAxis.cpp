// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoAxis.h"

void UGizmoAxis::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter)
{
	Super::CreateGizmo(InAxisTypes, InOffsetFromCenter);
	FVector Pos;
	FRotator Rot = FRotator::ZeroRotator;

	if (InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_X))
	{
		Rot.Pitch = -90;
		Pos = Rot.Vector().ForwardVector * InOffsetFromCenter;
	}
	else if(InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Y))
	{
		Rot.Roll = 90;
		Pos = Rot.Vector().RightVector * InOffsetFromCenter;
	}
	else if(InAxisTypes.Contains(EGizmoAxisType::GM_AXIS_Z))
	{
		Pos = FVector::UpVector * InOffsetFromCenter;
	}
	SetWorldLocationAndRotation(Pos, Rot.Quaternion());
}
