// Fill out your copyright notice in the Description page of Project Settings.

#include "VPCameraActor.h"
#include <Camera/CameraActor.h>
#include <Engine/World.h>
#include <Engine/Engine.h>
#include <Camera/PlayerCameraManager.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Actor.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/PlayerController.h>
#include <Kismet/KismetMathLibrary.h>
#include <GameFramework/Character.h>
#include <EngineUtils.h>



void AVPCameraActor::InitCameraSetting(AActor * Actor, FTransform Transform, FViewTarget ViewTarget, ECameraStyle CameraStyle, EPROJECTION_MODE ProjectionMode)
{
	//DefaultInit
	{
		
		//현재 플레이어 컨트롤러 가져옴
		PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

		PlayerCameraMgr = GetPlayerCameraMgr();
		MyCameraComponent = GetCameraComponent();

		// CameraActor Label 설정
		this->SetActorLabel(CameraLabel);
		this->ViewTarget = ViewTarget;
		this->ProjectionMode = ProjectionMode;
		MyCameraComponent->ProjectionMode = (ECameraProjectionMode::Type)ProjectionMode;
		this->SetActorTransform(Transform);
		this->MyCameraComponent->bConstrainAspectRatio = false;

	}


	if (CameraStyle == ECameraStyle::RELATIVE)
	{
		//CameraActor를 Actor에 붙이는데 상대적인 조건을 따름.
		this->AttachToActor(Actor, FAttachmentTransformRules::KeepRelativeTransform);
		//CameraActor에 대한 CameraComponent의 상대적인 위치를 정해줌.
		MyCameraComponent->SetRelativeLocation(Transform.GetLocation());

		//카메라 컴포넌트가 타겟 액터를 바라보게 하는 회전율을 구함.
		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(MyCameraComponent->GetComponentLocation()
			, Actor->GetActorLocation());//FRotationMatrix::MakeFromX(TargetPos).Rotator();

		//카메라 컴포넌트가 타겟을 바라보는 방향으로 회전함.
		MyCameraComponent->SetRelativeRotation(Rot);

	}
	else if (CameraStyle == ECameraStyle::STATIC)
	{
		FVector ActorVec = Actor->GetActorLocation();
		this->SetActorLocation(ActorVec + Transform.GetLocation());

		//카메라 컴포넌트가 타겟 액터를 바라보게 하는 회전율을 구함.
		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(MyCameraComponent->GetComponentLocation()
			, Actor->GetActorLocation());//FRotationMatrix::MakeFromX(TargetPos).Rotator();

		//카메라 컴포넌트가 타겟을 바라보는 방향으로 회전함.
		MyCameraComponent->SetRelativeRotation(Rot);


	}
	

}

void AVPCameraActor::ConverseViewTarget()
{
	if (CameraStyle == ECameraStyle::CONTROL)
		return;

	//타겟 카메라로 전환됨.
	PlayerController->SetViewTargetWithBlend(this, ViewTarget.BlendTime, ViewTarget.BlendFunc, ViewTarget.BlendExp
		, ViewTarget.LockOutgoing);

}

// Gizmo를 붙여줘야함 나중에 Transform대신에 GizmoTransform이 달려야함
void AVPCameraActor::AdjustCameraSetting_Perspective(FTransform Transform, FPerspective Perspective)
{
	MyCameraComponent->SetRelativeTransform(Transform);
	MyCameraComponent->FieldOfView = Perspective.FieldofView;
	MyCameraComponent->AspectRatio = Perspective.AspectRatio;
}
// Gizmo를 붙여줘야함 나중에 Transform대신에 GizmoTransform이 달려야함
void AVPCameraActor::AdjustCameraSetting_OrthoGraphic(FTransform Transform, FOrthoGraphic OrthoGraphic)
{

	MyCameraComponent->SetRelativeTransform(Transform);
	MyCameraComponent->OrthoWidth = OrthoGraphic.Width;
	MyCameraComponent->AspectRatio = OrthoGraphic.AspectRatio;

}

void AVPCameraActor::ReturnPlayerCamera()
{
	//플레이어 카메라로 즉시 전환
	PlayerController->SetViewTarget(Cast<AActor>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)));
}

void AVPCameraActor::ZoomIn()
{
	if (MyCameraComponent->FieldOfView > 0)
		MyCameraComponent->SetFieldOfView(MyCameraComponent->FieldOfView - 5.f);
}

void AVPCameraActor::ZoomOut()
{
	if (MyCameraComponent->FieldOfView < 90)
		MyCameraComponent->SetFieldOfView(MyCameraComponent->FieldOfView + 5.f);
}



APlayerCameraManager* AVPCameraActor::GetPlayerCameraMgr() const
{
	if (!GEngine)
	{
		UE_LOG(LogTemp, Log, TEXT("GetCameraActor :: GEngine is nullptr"));
		return nullptr;
	}

	return PlayerController->PlayerCameraManager;
}
