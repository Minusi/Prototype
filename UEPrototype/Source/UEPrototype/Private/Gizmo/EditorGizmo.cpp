// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/EditorGizmo.h"
#include "UEPrototype.h"
#include "Utility/MinusiFrameworkLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AEditorGizmo::AEditorGizmo()
{
	VP_CTOR;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Dummy = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Dummy->SetupAttachment(RootComponent);

	Axis_X = CreateDefaultSubobject<UGizmoAxis>(TEXT("UGizmoAxis_X"));
	Axis_Y = CreateDefaultSubobject<UGizmoAxis>(TEXT("UGizmoAxis_Y"));
	Axis_Z = CreateDefaultSubobject<UGizmoAxis>(TEXT("UGizmoAxis_Z"));
	Plane_XY = CreateDefaultSubobject<UGizmoPlane>(TEXT("UGizmoPlane_XY"));
	Plane_YZ = CreateDefaultSubobject<UGizmoPlane>(TEXT("UGizmoPlane_YZ"));
	Plane_XZ = CreateDefaultSubobject<UGizmoPlane>(TEXT("UGizmoPlane_XZ"));
	Origin = CreateDefaultSubobject<UGizmoOrigin>(TEXT("UGizmoOrigin"));

	Axis_X->SetupAttachment(RootComponent);
	Axis_Y->SetupAttachment(RootComponent);
	Axis_Z->SetupAttachment(RootComponent);
	Plane_XY->SetupAttachment(RootComponent);
	Plane_YZ->SetupAttachment(RootComponent);
	Plane_XZ->SetupAttachment(RootComponent);
	Origin->SetupAttachment(RootComponent);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Axis_Move(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Axis_Move"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Axis_Scale(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Axis_Scale"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Plane_Move(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Plane_Move"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Plane_Rotate(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Plane_Rotate"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Origin(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Origin"));


	if (SM_Axis_Move.Object != nullptr) AxisTransTypeMeshs.Add(EGizmoTransType::GM_MOVE, SM_Axis_Move.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Axis_Move을 찾을 수 없습니다."));
	AxisTransTypeMeshs.Add(EGizmoTransType::GM_ROTATE, nullptr);
	if (SM_Axis_Scale.Object != nullptr) AxisTransTypeMeshs.Add(EGizmoTransType::GM_SCALE, SM_Axis_Scale.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Axis_Scale을 찾을 수 없습니다."));



	if (SM_Plane_Move.Object != nullptr) PlaneTransTypeMeshs.Add(EGizmoTransType::GM_MOVE, SM_Plane_Move.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Plane_Move을 찾을 수 없습니다."));
	if (SM_Plane_Rotate.Object != nullptr) PlaneTransTypeMeshs.Add(EGizmoTransType::GM_ROTATE, SM_Plane_Rotate.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Plane_Rotate을 찾을 수 없습니다."));
	PlaneTransTypeMeshs.Add(EGizmoTransType::GM_SCALE, nullptr);


	if (SM_Origin.Object != nullptr) OriginTransTypeMeshs.Add(EGizmoTransType::GM_MOVE, SM_Origin.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Origin을 찾을 수 없습니다."));
	OriginTransTypeMeshs.Add(EGizmoTransType::GM_ROTATE, nullptr);
	if (SM_Origin.Object != nullptr) OriginTransTypeMeshs.Add(EGizmoTransType::GM_SCALE, SM_Origin.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Origin을 찾을 수 없습니다."));

	Axis_X->CreateGizmo({ EGizmoAxisType::GM_AXIS_X }, 200);
	Axis_Y->CreateGizmo({ EGizmoAxisType::GM_AXIS_Y }, 200);
	Axis_Z->CreateGizmo({ EGizmoAxisType::GM_AXIS_Z }, 200);
	Plane_XY->CreateGizmo({ EGizmoAxisType::GM_AXIS_X, EGizmoAxisType::GM_AXIS_Y }, 80);
	Plane_YZ->CreateGizmo({ EGizmoAxisType::GM_AXIS_Y, EGizmoAxisType::GM_AXIS_Z }, 80);
	Plane_XZ->CreateGizmo({ EGizmoAxisType::GM_AXIS_X, EGizmoAxisType::GM_AXIS_Z }, 80);
	Origin->CreateGizmo({ EGizmoAxisType::GM_AXIS_X,EGizmoAxisType::GM_AXIS_Y, EGizmoAxisType::GM_AXIS_Z }, 0);


	CoordType = EGizmoCoordType::GM_LOCALSPACE;
	SetupGizmoTransType(EGizmoTransType::GM_MOVE);
	ActivateGizmo(false);
}

// Called when the game starts or when spawned
void AEditorGizmo::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEditorGizmo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEditorGizmo::OnObjectClicked(AActor* TargetObject)
{
	if (TargetObject != nullptr)
	{
		this->SelectedActor = TargetObject;
		this->SetActorLocation(TargetObject->GetActorLocation());
		if (!bIsGizmoActivated)
			ActivateGizmo(true);
	}
	else VP_LOG(Error, TEXT("GM_ 선택된 오브젝트가 없습니다."));

}

void AEditorGizmo::ActivateGizmo(bool bActive)
{
	bIsGizmoActivated = bActive;

	SetActorEnableCollision(bActive);
	SetActorTickEnabled(bActive);

	Plane_XY->SetVisibility(bActive, true);
	Plane_YZ->SetVisibility(bActive, true);
	Plane_XZ->SetVisibility(bActive, true);
	Axis_X->SetVisibility(bActive, true);
	Axis_Y->SetVisibility(bActive, true);
	Axis_Z->SetVisibility(bActive, true);
	Origin->SetVisibility(bActive, true);
}

void AEditorGizmo::SetupGizmoTransType(EGizmoTransType InTransType)
{
	TransType = InTransType;
	if (AxisTransTypeMeshs.Contains(InTransType))
	{
		Axis_X->SetStaticMesh(AxisTransTypeMeshs[InTransType]);
		Axis_Y->SetStaticMesh(AxisTransTypeMeshs[InTransType]);
		Axis_Z->SetStaticMesh(AxisTransTypeMeshs[InTransType]);
	}
	else VP_LOG(Error, TEXT("GM_ 기즈모 변형 모드에 알맞는 Axis Static Mesh가 없습니다."));

	if (PlaneTransTypeMeshs.Contains(InTransType))
	{
		Plane_XY->SetStaticMesh(PlaneTransTypeMeshs[InTransType]);
		Plane_YZ->SetStaticMesh(PlaneTransTypeMeshs[InTransType]);
		Plane_XZ->SetStaticMesh(PlaneTransTypeMeshs[InTransType]);
	}
	else VP_LOG(Error, TEXT("GM_ 기즈모 변형 모드에 알맞는 Plane Static Mesh가 없습니다."));

	if (OriginTransTypeMeshs.Contains(InTransType))
		Origin->SetStaticMesh(OriginTransTypeMeshs[InTransType]);
	else VP_LOG(Error, TEXT("GM_ 기즈모 변형 모드에 알맞는 Origin Static Mesh가 없습니다."));
}

void AEditorGizmo::SetupGizmoCoordType(EGizmoCoordType InCoordType)
{
	CoordType = InCoordType;
}

EGizmoCoordType AEditorGizmo::GetGizmoCoordType()
{
	return CoordType;
}

EGizmoTransType AEditorGizmo::GetGizmoTransType()
{
	return TransType;
}

void AEditorGizmo::FollowSelectedObject()
{
	if (bIsGizmoActivated && SelectedActor != nullptr)
	{
		if (GetGizmoTransType() == EGizmoTransType::GM_SCALE)
			SetActorLocationAndRotation(SelectedActor->GetActorLocation(), SelectedActor->GetActorRotation());
		else
		{
			if (GetGizmoCoordType() == EGizmoCoordType::GM_WORLDSPACE)
				SetActorLocationAndRotation(SelectedActor->GetActorLocation(), FRotator::ZeroRotator);
			else
				SetActorLocationAndRotation(SelectedActor->GetActorLocation(), SelectedActor->GetActorRotation());
		}
	}
}
FVector AEditorGizmo::GetAxisVector(EGizmoAxisType AxisType)
{
	FVector AxisVector;
	switch (AxisType)
	{
	case EGizmoAxisType::GM_AXIS_X: AxisVector = GetActorForwardVector(); break;
	case EGizmoAxisType::GM_AXIS_Y: AxisVector = GetActorRightVector(); break;
	case EGizmoAxisType::GM_AXIS_Z: AxisVector = GetActorUpVector(); break;
	}
	return AxisVector;
}