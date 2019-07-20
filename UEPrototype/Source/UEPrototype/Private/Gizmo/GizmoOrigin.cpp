// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoOrigin.h"

void UGizmoOrigin::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter)
{
	Super::CreateGizmo(InAxisTypes, InOffsetFromCenter);
	SetWorldLocation(FVector::UpVector * -InOffsetFromCenter);
}