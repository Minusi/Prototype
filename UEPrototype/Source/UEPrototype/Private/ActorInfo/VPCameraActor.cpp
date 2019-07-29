// Fill out your copyright notice in the Description page of Project Settings.

#include "VPCameraActor.h"
#include <EngineUtils.h>
#include <Camera/CameraActor.h>
#include <Camera/PlayerCameraManager.h>
#include <Camera/CameraComponent.h>
#include <Engine/World.h>
#include <Engine/Engine.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Actor.h>
#include <GameFramework/PlayerController.h>
#include <GameFramework/Character.h>






void AVPCameraActor::InitCameraSetting(AActor * Actor, FTransform Transform, FViewTarget ViewTarget, ECameraStyle CameraStyle, EPROJECTION_MODE ProjectionMode)
{
	//DefaultInit
	{
		if (PlayerCameraMgr == nullptr)return;
		if (CachedCameraComponent == nullptr) return;

		//현재 플레이어 컨트롤러 가져옴
		PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

		PlayerCameraMgr = GetPlayerCameraMgr();
		CachedCameraComponent = GetCameraComponent();

		// CameraActor Label 설정
		SetActorLabel(CameraLabel);
		ViewTarget = ViewTarget;
		ProjectionMode = ProjectionMode;
		CachedCameraComponent->ProjectionMode = (ECameraProjectionMode::Type)ProjectionMode;
		SetActorTransform(Transform);
		CachedCameraComponent->bConstrainAspectRatio = false;

	}


	if (CameraStyle == ECameraStyle::RELATIVE)
	{
		//CameraActor를 Actor에 붙이는데 상대적인 조건을 따름.
		AttachToActor(Actor, FAttachmentTransformRules::KeepRelativeTransform);
		//CameraActor에 대한 CameraComponent의 상대적인 위치를 정해줌.
		CachedCameraComponent->SetRelativeLocation(Transform.GetLocation());

		//카메라 컴포넌트가 타겟 액터를 바라보게 하는 회전율을 구함.
		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(CachedCameraComponent->GetComponentLocation()
			, Actor->GetActorLocation());//FRotationMatrix::MakeFromX(TargetPos).Rotator();

		//카메라 컴포넌트가 타겟을 바라보는 방향으로 회전함.
		CachedCameraComponent->SetRelativeRotation(Rot);

	}
	else if (CameraStyle == ECameraStyle::STATIC)
	{
		FVector ActorVec = Actor->GetActorLocation();
		SetActorLocation(ActorVec + Transform.GetLocation());

		//카메라 컴포넌트가 타겟 액터를 바라보게 하는 회전율을 구함.
		FRotator Rot = UKismetMathLibrary::FindLookAtRotation(CachedCameraComponent->GetComponentLocation()
			, Actor->GetActorLocation());//FRotationMatrix::MakeFromX(TargetPos).Rotator();

		//카메라 컴포넌트가 타겟을 바라보는 방향으로 회전함.
		CachedCameraComponent->SetRelativeRotation(Rot);


	}
	

}

void AVPCameraActor::ConverseViewTarget()
{
	if (CameraStyle == ECameraStyle::CONTROL)
		return;
	if (PlayerController == nullptr) return;

	//타겟 카메라로 전환됨.
	PlayerController->SetViewTargetWithBlend(this, ViewTarget.BlendTime, ViewTarget.BlendFunc, ViewTarget.BlendExp
		, ViewTarget.LockOutgoing);

}

// Gizmo를 붙여줘야함 나중에 Transform대신에 GizmoTransform이 달려야함
void AVPCameraActor::AdjustCameraSetting_Perspective(FTransform Transform, FPerspective Perspective)
{
	if (CachedCameraComponent == nullptr) return;
	CachedCameraComponent->SetRelativeTransform(Transform);
	CachedCameraComponent->FieldOfView = Perspective.FieldofView;
	CachedCameraComponent->AspectRatio = Perspective.AspectRatio;
}
// Gizmo를 붙여줘야함 나중에 Transform대신에 GizmoTransform이 달려야함
void AVPCameraActor::AdjustCameraSetting_OrthoGraphic(FTransform Transform, FOrthoGraphic OrthoGraphic)
{
	if (CachedCameraComponent == nullptr) return;
	CachedCameraComponent->SetRelativeTransform(Transform);
	CachedCameraComponent->OrthoWidth = OrthoGraphic.Width;
	CachedCameraComponent->AspectRatio = OrthoGraphic.AspectRatio;

}

void AVPCameraActor::ReturnPlayerCamera()
{
	if (PlayerController == nullptr) return;
	//플레이어 카메라로 즉시 전환
	PlayerController->SetViewTarget(Cast<AActor>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)));
}

void AVPCameraActor::ZoomIn()
{
	if (CachedCameraComponent == nullptr) return;
	if (CachedCameraComponent->FieldOfView > 0)
		CachedCameraComponent->SetFieldOfView(CachedCameraComponent->FieldOfView - 5.f);
}

void AVPCameraActor::ZoomOut()
{
	if (CachedCameraComponent == nullptr) return;
	if (CachedCameraComponent->FieldOfView < 90)
		CachedCameraComponent->SetFieldOfView(CachedCameraComponent->FieldOfView + 5.f);
}



APlayerCameraManager* AVPCameraActor::GetPlayerCameraMgr() const
{
	if (PlayerController == nullptr) 
	{
		UE_LOG(LogTemp, Log, TEXT("GetCameraActor :: GetPlayerCameraMgr :: PlayerController is nullptr"));
		return nullptr;
	} 
	if (!GEngine)
	{
		UE_LOG(LogTemp, Log, TEXT("GetCameraActor :: GEngine is nullptr"));
		return nullptr;
	}

	return PlayerController->PlayerCameraManager;
}
