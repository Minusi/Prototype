// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoAxes.h"
#include "UEPrototype.h"
#include "Utility/MinusiFrameworkLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AGizmoAxes::AGizmoAxes()
{
	VP_CTOR;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GizmoViewOffsetFromCamera = 200;

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

	SetupGizmoTransType(EGizmoTransType::GM_MOVE);
	CoordType = EGizmoCoordType::GM_LOCALSPACE;



	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Axis_Move(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Axis_Move"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Axis_Rotate(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Axis_Rotate"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Axis_Scale(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Axis_Scale"));

	if (SM_Axis_Move.Object != nullptr) TransTypeMeshs.Add(EGizmoTransType::GM_MOVE, SM_Axis_Move.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Axis_Move을 찾을 수 없습니다."));

	if (SM_Axis_Rotate.Object != nullptr) TransTypeMeshs.Add(EGizmoTransType::GM_ROTATE, SM_Axis_Rotate.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Axis_Rotate을 찾을 수 없습니다."));

	if (SM_Axis_Scale.Object != nullptr) TransTypeMeshs.Add(EGizmoTransType::GM_SCALE, SM_Axis_Scale.Object);
	else VP_LOG(Error, TEXT("SM_Gizmo_Axis_Scale을 찾을 수 없습니다."));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Plane(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Plane"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Origin(TEXT("/Game/Blueprint/Gizmo/GizmoStaticMesh/SM_Gizmo_Origin"));

	Axis_X->CreateGizmo({ EGizmoAxisType::GM_AXIS_X }, 200, SM_Axis_Move.Object);
	Axis_Y->CreateGizmo({ EGizmoAxisType::GM_AXIS_Y }, 200, SM_Axis_Move.Object);
	Axis_Z->CreateGizmo({ EGizmoAxisType::GM_AXIS_Z }, 200, SM_Axis_Move.Object);
	Plane_XY->CreateGizmo({ EGizmoAxisType::GM_AXIS_X, EGizmoAxisType::GM_AXIS_Y }, 80, SM_Plane.Object);
	Plane_YZ->CreateGizmo({ EGizmoAxisType::GM_AXIS_Y, EGizmoAxisType::GM_AXIS_Z }, 80, SM_Plane.Object);
	Plane_XZ->CreateGizmo({ EGizmoAxisType::GM_AXIS_X, EGizmoAxisType::GM_AXIS_Z }, 80, SM_Plane.Object);
	Origin->CreateGizmo({ EGizmoAxisType::GM_AXIS_X,EGizmoAxisType::GM_AXIS_Y, EGizmoAxisType::GM_AXIS_Z }, 0, SM_Origin.Object);

	ActivateGizmo(false);
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

void AGizmoAxes::OnObjectClicked(AActor* TargetObject)
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

void AGizmoAxes::ActivateGizmo(bool bActive)
{
	bIsGizmoActivated = bActive;

	SetActorEnableCollision(bActive);
	SetActorTickEnabled(bActive);

	Axis_X->SetVisibility(bActive, true);
	Axis_Y->SetVisibility(bActive, true);
	Axis_Z->SetVisibility(bActive, true);
	Origin->SetVisibility(bActive, true);

	if (!bActive || GetGizmoTransType() != EGizmoTransType::GM_ROTATE)
	{
		Plane_XY->SetVisibility(bActive, true);
		Plane_YZ->SetVisibility(bActive, true);
		Plane_XZ->SetVisibility(bActive, true);
	}
}

void AGizmoAxes::SetupGizmoTransType(EGizmoTransType InTransType)
{
	if (TransTypeMeshs.Contains(InTransType))
	{
		Axis_X->SetStaticMesh(TransTypeMeshs[InTransType]);
		Axis_Y->SetStaticMesh(TransTypeMeshs[InTransType]);
		Axis_Z->SetStaticMesh(TransTypeMeshs[InTransType]);
	}
	else VP_LOG(Error, TEXT("GM_ 기즈모 변형 모드에 알맞는 Static Mesh가 없습니다."));

	// Rotate의 경우 Plane은 비활성화 상태가 됩니다.
	Axis_X->UpdateGizmoTransType(InTransType);
	Axis_Y->UpdateGizmoTransType(InTransType);
	Axis_Z->UpdateGizmoTransType(InTransType);
	Plane_XY->UpdateGizmoTransType(InTransType);
	Plane_YZ->UpdateGizmoTransType(InTransType);
	Plane_XZ->UpdateGizmoTransType(InTransType);
	Origin->UpdateGizmoTransType(InTransType);

	if (InTransType == EGizmoTransType::GM_ROTATE)
	{
		Plane_XY->SetVisibility(false);
		Plane_YZ->SetVisibility(false);
		Plane_XZ->SetVisibility(false);
	}
	else
	{
		if (bIsGizmoActivated)
		{
			Plane_XY->SetVisibility(true);
			Plane_YZ->SetVisibility(true);
			Plane_XZ->SetVisibility(true);
		}
	}
}

void AGizmoAxes::SetupGizmoCoordType(EGizmoCoordType InCoordType)
{
	FRotator Rot = FRotator::ZeroRotator;

	if (InCoordType == EGizmoCoordType::GM_LOCALSPACE)
	{
		if (SelectedActor != nullptr)
			Rot = SelectedActor->GetActorRotation();
		else VP_LOG(Error, TEXT("GM_ WorldSpace -> LocalSpace 로 변경 중 Actor를 찾을 수 없습니다."));
	}
	SetActorRotation(Rot);
}

EGizmoCoordType AGizmoAxes::GetGizmoCoordType()
{
	return CoordType;
}

EGizmoTransType AGizmoAxes::GetGizmoTransType()
{
	return TransType;
}

void AGizmoAxes::GetGizmoDirectionVector(APlayerController* PC, EGizmoAxisType AxisType, const FVector AxisLocation, FGizmoDriectionData& OutData)
{
	FVector2D OriginVector;
	if (PC != nullptr)
	{
		OutData.AxisDireciton = UKismetMathLibrary::GetDirectionUnitVector(GetActorLocation(), AxisLocation);
		UGameplayStatics::ProjectWorldToScreen(PC, OutData.AxisDireciton, OutData.ProjectedScreenAxisDirection);
		UGameplayStatics::ProjectWorldToScreen(PC, FVector::ZeroVector, OriginVector);
		OutData.ProjectedScreenAxisDirection -= OriginVector;
		OutData.ProjectedScreenAxisDirection.Normalize();
	}
}

void AGizmoAxes::GetGizmoAxisDirectionVector(APlayerController* PC, EGizmoAxisType AxisType, FGizmoDriectionData& OutData)
{
	FVector AxisLocation;
	if (PC != nullptr)
	{
		switch (AxisType)
		{
		case EGizmoAxisType::GM_AXIS_X: AxisLocation = Axis_X->GetComponentLocation(); break;
		case EGizmoAxisType::GM_AXIS_Y: AxisLocation = Axis_Y->GetComponentLocation(); break;
		case EGizmoAxisType::GM_AXIS_Z: AxisLocation = Axis_Z->GetComponentLocation(); break;
		}
		GetGizmoDirectionVector(PC, AxisType, AxisLocation, OutData);
	}
}