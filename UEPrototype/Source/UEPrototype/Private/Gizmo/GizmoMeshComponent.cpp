// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoMeshComponent.h"

UGizmoMeshComponent::UGizmoMeshComponent()
{

}
void  UGizmoMeshComponent::CreateGizmo(FVector InActiveAxis, float InOffsetFromCenter)
{
	this->ActiveAxis = InActiveAxis;
	this->OffsetFromCenter = InOffsetFromCenter;
}
void  UGizmoMeshComponent::UpdateGizmoTransType(EGizmoTransType InTransType)
{
	this->TransType = InTransType;
}
void  UGizmoMeshComponent::UpdateGizmoTransformation(FTransform InTransfrom)
{

}
