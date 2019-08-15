// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/VPDirectorPawn.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "MinusiFrameworkLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "PhysicsEngine/PhysicsSettings.h"
#include "DrawDebugHelpers.h"

#include "Core/UserBlackBoard.h"
#include "Tool/ToolManager.h"

#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SceneComponent.h"

#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "MotionTrackedDeviceFunctionLibrary.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
AVPDirectorPawn::AVPDirectorPawn()
{
	// DEBUG : 생성자 로그
	VP_CTOR;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	/* Pawn 프로퍼티 초기화 */
	bUseControllerRotationRoll = true;
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;



	// RootCollision 초기화
	RootCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SphereCollision"));
	RootComponent = RootCollision;

	// VRRootTransform 초기화
	VRRootTransform = CreateDefaultSubobject<USceneComponent>(TEXT("VRRootTransform"));
	VRRootTransform->SetupAttachment(RootCollision);

	// VRCamera 초기화
	VRCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCamera"));
	VRCamera->SetupAttachment(VRRootTransform);

	/* WidgetAnchor 초기화 */
	WidgetAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("WidgetAnchor"));
	WidgetAnchor->SetupAttachment(VRCamera);
	
	/* GizmoWidgetAnchor 초기화 */
	GizmoWidgetAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("GizmoWidgetAnchor"));
	GizmoWidgetAnchor->SetupAttachment(VRCamera);

	/* LMotionController 초기화 */
	LMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LMotionController"));
	LMotionController->SetupAttachment(VRRootTransform);

	/* LWidgetComponent 초기화 */
	LMotionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("LMotionWidget"));
	LMotionWidget->SetupAttachment(LMotionController);

	/* LMotionController 초기화 */
	RMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RMotionController"));
	RMotionController->SetupAttachment(VRRootTransform);

	/* RAttachedSocket 초기화 */
	RAttachedSocket = CreateDefaultSubobject<USceneComponent>(TEXT("RAttachedSocket"));
	RAttachedSocket->SetupAttachment(RMotionController);

	/* RWidgetComponent 초기화 */
	RMotionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("RMotionWidget"));
	RMotionWidget->SetupAttachment(RMotionController);

	/* FloatingPawnMovement 초기화 */
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingPawnMovement->UpdatedComponent = RootComponent;



	bIsPickingActor = false;

	/* EMoveType 초기화 */
	CurrentMoveType = EMoveType::MT_LOCALAXIS;
	FixedAxis = FRotator(0, 0, 0);



	/* 라인트레이스 길이가 에디터에 의해 초기홛되지 않았다면 초기화합니다 */
	if (LineTraceLength == 0)
	{
		LineTraceLength = 100 * 1000;
	}
}



// Called when the game starts or when spawned
void AVPDirectorPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// DEBUG : 월드의 고유성 및 객체의 고유성 확인
	for (const auto& it : TObjectRange<AVPDirectorPawn>())
	{
		UMinusiFrameworkLibrary::GetInfoWithOuterChain(it);
	}

	/* 유저 블랙보드를 업데이트하기 위해 캐시합니다, */
	UserBlackBoardCache = AUserBlackBoard::GetGlobalUserBlackBoard(this);

	/* 도구 매니저를 캐시합니다. */
	ToolManager = UToolManager::GetGlobalToolManager();
	if (IsValid(ToolManager) == false)
	{
		return;
	}
}





void AVPDirectorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/* 포커스하는 대상을 알아냅니다. 
	현재 블루프린트에서 구현되어 있습니다. */
	//Focus(DeltaTime);
	//Point(DeltaTime);
	//DrawCurvedTrajectory();
}



void AVPDirectorPawn::Focus(float DeltaTime)
{
	FHitResult OutHit;

	FVector Start = VRCamera->GetComponentLocation();
	FVector Forward = VRCamera->GetForwardVector();
	FVector End = (Start + (Forward * LineTraceLength));

	FCollisionQueryParams CollisionQueryParams;

	// DEBUG : 라인트레이스 라인을 그립니다.
	// DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Red, false);

	//자기자신은 raycast 충돌을 무시합니다.
	CollisionQueryParams.AddIgnoredActor(this);

	bool HitResult = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility,
		CollisionQueryParams);



	if (HitResult == true)
	{
		if (OutHit.bBlockingHit)
		{
			// DEBUG : 엔진의 디스플레이에 로그를 남깁니다.
			//if (GEngine)
			//{
			//	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, FString::Printf(TEXT("Hit Actor : %s"), *OutHit.GetActor()->GetName()));
			//	GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Red, FString::Printf(TEXT("Hit Point : %s"), *OutHit.ImpactPoint.ToString()));
			//	GEngine->AddOnScreenDebugMessage(3, 1.f, FColor::Red, FString::Printf(TEXT("Hit Normal : %s"), *OutHit.ImpactNormal.ToString()));
			//}
				
			/* 라인트레이스 결과를 브로드캐스트합니다 */
			UserFocusEventDispatcher.Broadcast(OutHit.Actor.Get(), DeltaTime);

			/* 블랙보드에 기록합니다. */
			UserBlackBoardCache->SetFocusedActor(OutHit.Actor.Get());
			return;
		}
	}
	else
	{
		/* 라인트레이스가 어떤 액터도 가리키지 않을 때 nullptr을 넘겨줍니다. */
		UserFocusEventDispatcher.Broadcast(nullptr, 0.0f);

		/* 블랙보드에 기록합니다. */
		UserBlackBoardCache->SetFocusedActor(nullptr);
		return;
	}
}



void AVPDirectorPawn::Point(const USceneComponent* InComponent, const AActor* Ignore, FVector& OutPoint1, FVector& OutPoint2, FHitResult& OutHit, bool& bHit)
{
	if (IsValid(UserBlackBoardCache) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *AUserBlackBoard::StaticClass()->GetName());
		return;
	}



	LineTraceStart = InComponent->GetComponentLocation() + (LineTraceZOffset * (InComponent->GetUpVector()));
	FVector Forward = InComponent->GetForwardVector();
	LineTraceEnd = (LineTraceStart + (Forward * LineTraceLength));

	FCollisionQueryParams CollisionQueryParams;



	/* 결과값을 반환합니다. */
	OutPoint1 = LineTraceStart;
	OutPoint2 = LineTraceEnd;



	// DEBUG : 라인트레이스 라인을 그립니다.
	// DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor::Blue, false);

	/* 자기자신은 raycast 충돌을 무시합니다. */
	CollisionQueryParams.AddIgnoredActor(this);
	CollisionQueryParams.AddIgnoredActor(Ignore);

	/* 결과값을 반환합니다.(OutHit) */
	bool HitResult = GetWorld()->LineTraceSingleByChannel(OutHit, LineTraceStart, LineTraceEnd, ECC_Visibility,
		CollisionQueryParams);

	/* 결과값을 반환합니다. */
	bHit = HitResult;

	if (HitResult == true)
	{
		if (OutHit.bBlockingHit)
		{
			// DEBUG : 엔진의 디스플레이에 로그를 남깁니다.
			if (GEngine)
			//{
			//	GEngine->AddOnScreenDebugMessage(4, 1.f, FColor::Blue, FString::Printf(TEXT("Hit Actor : %s"), *OutHit.GetActor()->GetName()));
			//	GEngine->AddOnScreenDebugMessage(5, 1.f, FColor::Blue, FString::Printf(TEXT("Hit Point : %s"), *OutHit.ImpactPoint.ToString()));
			//	GEngine->AddOnScreenDebugMessage(6, 1.f, FColor::Blue, FString::Printf(TEXT("Hit Normal : %s"), *OutHit.ImpactNormal.ToString()));
			//}

			/* 포인트 결과를 블랙보드에 기록합니다. */			
			UserBlackBoardCache->SetPointedActor(OutHit.GetActor());
			return;
		}
	}
	else
	{
		/* 포인트 결과를 블랙보드에 기록합니다. */			
		UserBlackBoardCache->SetPointedActor(nullptr);
		return;
	}
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



void AVPDirectorPawn::LookSide(float Value)
{
	if (bUseControllerRotationRoll == true)
	{
		AddControllerYawInput(Value);
	}
}



void AVPDirectorPawn::LookUpSide(float Value)
{
	if (bUseControllerRotationPitch == true)
	{
		AddControllerPitchInput(Value);
	}
}





void AVPDirectorPawn::SetMoveType(EMoveType InMoveType)
{
	CurrentMoveType = InMoveType;
}



void AVPDirectorPawn::SetYawRotSpeed(float InYawRotSpeed)
{
	if (InYawRotSpeed > 0.f)
	{
		YawRotSpeed = InYawRotSpeed;
	}
	else
	{
		YawRotSpeed = 1.f;
	}
}



void AVPDirectorPawn::SetPitchRotSpeed(float InPitchRotSpeed)
{
	if (InPitchRotSpeed > 0.f)
	{
		PitchRotSpeed = InPitchRotSpeed;
	}
	else
	{
		PitchRotSpeed = 1.f;
	}
}



void AVPDirectorPawn::SetLineTraceLength(int32 InLength)
{
	if (InLength > 0)
	{
		LineTraceLength = InLength;
	}
	else
	{
		LineTraceLength  = 100 * 10000;
	}
}

void AVPDirectorPawn::SetIsPickingActor(bool IsPicking)
{
	bIsPickingActor = IsPicking;
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
	FRotator InRot = VRCamera->GetComponentRotation();
	//	GetControlRotation();

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





