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
		
	// MotionController 초기화
	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	MotionController->SetupAttachment(VRRootTransform);

	// WidgetComponent 초기화
	MCWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("MCWidget"));
	MCWidget->SetupAttachment(MotionController);

	// FloatingPawnMovement 초기화
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingPawnMovement->UpdatedComponent = RootComponent;

	// EMoveType 초기화
	CurrentMoveType = EMoveType::MT_LOCALAXIS;
	FixedAxis = FRotator(0, 0, 0);
}



// Called when the game starts or when spawned
void AVPDirectorPawn::BeginPlay()
{
	Super::BeginPlay();
	
}





// Called to bind functionality to input
void AVPDirectorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}





void AVPDirectorPawn::MoveAround(EMoveType InMoveType, float InX, float InY, float InZ, AActor const * InOrbitTarget)
{
	
	if (InMoveType == EMoveType::MT_LOCALAXIS)
	{
		MoveLocalAxis(InX, InY, InZ);
	}
	else if (InMoveType == EMoveType::MT_FIXEDAXIS)
	{
		MoveFixedAxis(InX, InY, InZ);
	}
	else if (InMoveType == EMoveType::MT_ABSOLUTEAXIS)
	{
		MoveAbsoluteAxis(InX, InY, InZ);
	}
	else if (InMoveType == EMoveType::MT_ORBITAXIS)
	{
		MoveOrbitAxis(InX, InY, InZ, InOrbitTarget);
	}
	else
	{
		VP_LOG(Warning, TEXT("올바르지 않은 EMoveType 타입입니다."));
	}
}





void AVPDirectorPawn::SetMoveType(EMoveType InMoveType)
{
	CurrentMoveType = InMoveType;
}





void AVPDirectorPawn::MoveAbsoluteAxis(float InX, float InY, float InZ)
{
	AddMovementInput(FVector(1, 0, 0), InX);
	AddMovementInput(FVector(0, 1, 0), InY);
	AddMovementInput(FVector(0, 0, 1), InZ);

	CurrentMoveType = EMoveType::MT_ABSOLUTEAXIS;
}



void AVPDirectorPawn::MoveFixedAxis(float InX, float InY, float InZ)
{
	// 모드가 처음 바뀌었을 때, 이 축을 중심으로 폰이 이동하기 시작합니다.
	// 다른 모드로 전환되기 전까지 유지됩니다.
	if (CurrentMoveType != EMoveType::MT_FIXEDAXIS)
	{
		FixedAxis = GetControlRotation();
	}

	FVector TargetDirectionX = FRotationMatrix(FixedAxis).GetScaledAxis(EAxis::X);
	FVector TargetDirectionY = FRotationMatrix(FixedAxis).GetScaledAxis(EAxis::Y);
	FVector TargetDirectionZ = FRotationMatrix(FixedAxis).GetScaledAxis(EAxis::Z);

	AddMovementInput(TargetDirectionX, InX);
	AddMovementInput(TargetDirectionY, InY);
	AddMovementInput(TargetDirectionZ, InZ);

	CurrentMoveType = EMoveType::MT_FIXEDAXIS;
}



void AVPDirectorPawn::MoveLocalAxis(float InX, float InY, float InZ)
{
	FRotator InRot = GetControlRotation();

	// UKismetMathLibrary::GetForwardVector(FRotator InRot)의 구현
	FVector TargetDirectionX = FRotationMatrix(InRot).GetScaledAxis(EAxis::X);
	FVector TargetDirectionY = FRotationMatrix(InRot).GetScaledAxis(EAxis::Y);
	FVector TargetDirectionZ = FRotationMatrix(InRot).GetScaledAxis(EAxis::Z);

	AddMovementInput(TargetDirectionX, InX);
	AddMovementInput(TargetDirectionY, InY);
	AddMovementInput(TargetDirectionZ, InZ);

	CurrentMoveType = EMoveType::MT_LOCALAXIS;
}



void AVPDirectorPawn::MoveOrbitAxis(float InX, float InY, float InZ, AActor const * InOrbitTarget)
{
	if (InOrbitTarget == nullptr)
	{
		VP_LOG(Error, TEXT("공전할 대상이 유효하지 않습니다."));
		return;
	}

	FVector TargetLocation = InOrbitTarget->GetActorLocation();
}