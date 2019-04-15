// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/VPDirectorPawn.h"
#include "UEPrototype.h"

// Sets default values
AVPDirectorPawn::AVPDirectorPawn()
{
	VP_CTOR;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// RootCollision 초기화
	RootCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SphereCollision"));
	RootComponent = RootCollision;

	// VRRootTransform 초기화
	VRRootTransform = CreateDefaultSubobject<USceneComponent>(TEXT("VRRootTransform"));
	VRRootTransform->SetupAttachment(RootCollision);

	// VRCamera 초기화
	VRCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCamera"));
	VRCamera->SetupAttachment(VRRootTransform);
		
	// MController 초기화
	LeftMController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftMController"));
	LeftMController->SetupAttachment(VRRootTransform);
	RightMController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightMController"));
	RightMController->SetupAttachment(VRRootTransform);

}

// Called when the game starts or when spawned
void AVPDirectorPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVPDirectorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

// Called to bind functionality to input
void AVPDirectorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}





void AVPDirectorPawn::ModifyVisualizeMControllers()
{
	if (UMotionTrackedDeviceFunctionLibrary::
		IsMotionTrackingEnabledForComponent(RightMController) 
		== false)
	{
		VP_LOG(Log, TEXT("좌측 모션 컨트롤러 없음"));
		LeftMController->SetCustomDisplayMesh(nullptr);
	}


	if (UMotionTrackedDeviceFunctionLibrary::
		IsMotionTrackingEnabledForComponent(RightMController)
		== false)
	{
		VP_LOG(Log, TEXT("우측 모션 컨트롤러 없음"));
		RightMController->SetCustomDisplayMesh(nullptr);
	}
}
