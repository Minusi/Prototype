// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoAxes.h"

// Sets default values
AGizmoAxes::AGizmoAxes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGizmoAxes::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGizmoAxes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGizmoAxes::ActivateGizmo(bool bActive)
{
	Axis_X->Activate(bActive);
	Axis_Y->Activate(bActive);
	Axis_Z->Activate(bActive);
	Plane_XY->Activate(bActive);
	Plane_YZ->Activate(bActive);
	Plane_XZ->Activate(bActive);
	Origin->Activate(bActive);
}

void AGizmoAxes::SetupGizmoTransType(EGizmoTransType InTransType)
{
	Axis_X->UpdateGizmoTransType(InTransType);
	Axis_Y->UpdateGizmoTransType(InTransType);
	Axis_Z->UpdateGizmoTransType(InTransType);
	Plane_XY->UpdateGizmoTransType(InTransType);
	Plane_YZ->UpdateGizmoTransType(InTransType);
	Plane_XZ->UpdateGizmoTransType(InTransType);
	Origin->UpdateGizmoTransType(InTransType);
}
void AGizmoAxes::UpdateGizmoTransform(FTransform InTransform)
{
	Axis_X->SetWorldTransform(InTransform);
	Axis_Y->SetWorldTransform(InTransform);
	Axis_Z->SetWorldTransform(InTransform);
	Plane_XY->SetWorldTransform(InTransform);
	Plane_YZ->SetWorldTransform(InTransform);
	Plane_XZ->SetWorldTransform(InTransform);
	Origin->SetWorldTransform(InTransform);
}


EGizmoCoordType AGizmoAxes::GetGizmoCoordType()
{
	return CoordType;
}

EGizmoTransType AGizmoAxes::GetGizmoTransType()
{
	return TransType;
}

