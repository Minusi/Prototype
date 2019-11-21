// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/EngineTypes.h"
#include "Core/VPPlayerController.h"
#include "VPDirectorPawn.generated.h"

/*
 *	폰의 이동 기준 축을 지정해주는 열거형 클래스입니다.
 */
UENUM(BlueprintType)
enum class EMoveType : uint8
{
	// 폰의 현재 컨트롤 로테이션을 축으로 이동합니다.
	MT_LOCALAXIS		UMETA(DisplayName = "LocalAxis"),

	// 폰의 특정 시점 컨트롤 로테이션을 축으로 이동합니다.
	MT_FIXEDAXIS		UMETA(DisplayName = "FixedAxis"),

	// 월드 기준 축으로 이동합니다.
	MT_ABSOLUTEAXIS		UMETA(DisplayName = "WorldAxis"),

	// 특정 오브젝트를 중심으로, 월드 축을 기준으로 공전합니다.
	MT_ORBITAXIS		UMETA(DisplayName = "OrbitAxis")
};

/*
 *	커브드 세그먼트를 어떻게 그릴지를 결정하는 열거형 클래스입니다.
 */
UENUM(BlueprintType)
enum class EDrawSegment : uint8
{
	SEG_DebugLine	UMETA(DisplayName = "DebugLine"),
	SEG_Beam		UMETA(DisplayName = "Beam")
};

class AUserBlackBoard;
class USceneComponent;
class UToolManager;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUserFocusEventDispatcher, AActor*, Target, float, DeltaTime);

/*
 *	DirectorPawn은 프로토타입 월드에서 프로토타입을 담당하는 플레이어가
 *	기본적으로 빙의하는 폰입니다. VR 기기와 컨트롤러를 사용하는 유저의
 *	모습을 구현합니다.
 */
UCLASS()
class UEPROTOTYPE_API AVPDirectorPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVPDirectorPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/* 매 프레임마다 실행되는 함수입니다 */
	virtual void Tick(float DeltaTime) override;

public:
	/* 사용자의 시점에서 포커스를 수행합니다 */
	UFUNCTION(BlueprintCallable, Category = "Core|Player")
		void Focus(float DeltaTime, FHitResult & OutHit, TArray<AActor*> IgnoreActors);

	/* 주 모션 컨트롤러의 포인팅을 수행합니다. */
	UFUNCTION(BlueprintCallable, Category = "Core|Player")
		void Point(const USceneComponent* InComponent, const TArray<AActor*> Ignores, FVector& OutPoint1, FVector& OutPoint2, FHitResult& OutHit, bool& bHit);

public:
	/* Called to bind functionality to input */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* 입력한 무브 타입 방식으로 이동을 수행합니다. */
	UFUNCTION(BlueprintCallable, Category = "Core|Player")
		void MoveAround(EMoveType InMoveType, float InX, float InY, float InZ, AActor const * InOrbitTarget = nullptr);

	/* 좌우를 둘러봅니다 */
	UFUNCTION(BlueprintCallable, Category = "Core|Player")
		void LookSide(float Value);

	/* 위아래를 둘러봅니다 */
	UFUNCTION(BlueprintCallable, Category = "Core|Player")
		void LookUpSide(float Value);

	// Blueprint 영역
public:
	/* 커브 포인터 궤적을 그립니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void DrawCurvedTrajectory(const USceneComponent* InComponent);

	/* 선형 포인터 궤적을 그립니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void DrawLinearTrajectory(const USceneComponent* InComponent);

	/* 커브 세그먼트를 그리며 라인트레이스를 수행합니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void GetSegmentAtTime(const FVector& StartLocation, const FVector& InitialVelocity,
			const FVector& Gravity, float Time1, float Time2, FVector& OutPoint1, FVector& OutPoint2);

	/* 커브 세그먼트를 입력된 열거형 타입에 따라 비주얼라이즈합니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void VisualizeSegment(EDrawSegment DrawType, const FVector& Point1, const FVector& Point2);

	/* 커브 빔을 그립니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void AddCurvedBeam(const FVector& Point1, const FVector& Point2);

	/* 선형 빔을 그립니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void AddLinearBeam(const FVector& Point1, const FVector& Point2);

	/* 빔을 삭제합니다. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void RemoveBeam();

	//위젯앵커에 위젯을 추가합니다.
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Core|Player")
		void AddWidgetToAnchor(const AActor* Widget);

public:
	//VRCamera의 Getter
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE UCameraComponent* GetVRCamera() const
	{
		return VRCamera;
	}

	/* RMotionController의 Getter */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE UMotionControllerComponent* GetRMotionController() const
	{
		return RMotionController;
	}

	/* RAttachedSocket의 Getter */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE USceneComponent* GetRAttachedSocket() const
	{
		return RAttachedSocket;
	}

	/* LMotionController의 Getter */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE UMotionControllerComponent* GetLMotionController() const
	{
		return LMotionController;
	}

	//LMotionController의 Getter
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE USceneComponent* GetWidgetAnchor() const
	{
		return WidgetAnchor;
	}

	/* CurrentMoveType의 Setter 함수입니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		void SetMoveType(EMoveType InMoveType);

	/* CurrentMoveType의 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE EMoveType GetMoveType() const
	{
		return CurrentMoveType;
	}

	/* YawRotSpeed의 Setter 함수입니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		void SetYawRotSpeed(float InYawRotSpeed);

	/* YawRotSpeed의 Getter입니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		FORCEINLINE float GetYawRotSpeed() const
	{
		return YawRotSpeed;
	}

	/* PitchRotSpeed의 Setter 함수입니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		void SetPitchRotSpeed(float InPitchRotSpeed);

	/* PitchRotSpeed의 Getter입니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		FORCEINLINE float GetPitchRotSpeed() const
	{
		return PitchRotSpeed;
	}

	/* LineTraceLength의 Setter 함수입니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		void SetLineTraceLength(int32 InLength);

	/* LineTraceLength의 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE int32 GetLineTraceLength() const
	{
		return LineTraceLength;
	}

	/* bIsPickingActor의 Setter 함수입니다. */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
		void SetIsPickingActor(bool IsPicking);

	/* bIsPickingActor의 Getter 함수입니다. */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
		FORCEINLINE bool IsPickingActor() const
	{
		return bIsPickingActor;
	}

	/* UserFocusEventDispatcher의 Getter입니다. */
	FORCEINLINE FUserFocusEventDispatcher& OnUserFocus()
	{
		return UserFocusEventDispatcher;
	}

private:
	/* 절대 좌표 기준으로 폰의 이동을 수행합니다. */
	UFUNCTION()
		void MoveAbsoluteAxis(float InX, float InY, float InZ);

	// 특정 순간 폰의 오브젝트 축을 고정하여 이동을 수행합니다.
	UFUNCTION()
		void MoveFixedAxis(float InX, float InY, float InZ);

	// 폰의 오브젝트 축 기반 이동을 수행합니다.
	UFUNCTION()
		void MoveLocalAxis(float InX, float InY, float InZ);

	// 대상을 중심으로, 월드 축을 기반으로 공전 이동을 수행합니다.
	UFUNCTION()
		void MoveOrbitAxis(float InX, float InY, float InZ, AActor const * OrbitTarget);

private:
	/* 유저 상호작용을 저장하는 블랙보드입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		AUserBlackBoard * UserBlackBoardCache;

	/* 도구들을 관리하는 매니저입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		UToolManager* ToolManager;

	/* 플레이어 콜리전 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent * RootCollision;

	/* 플레이어 VR 루트 트랜스폼 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* VRRootTransform;

	/* 플레이어 VR 카메라 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"),
		BlueprintGetter = GetVRCamera)
		class UCameraComponent* VRCamera;

	/* 위젯 생성되는 위치를 위한 앵커 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"),
		BlueprintGetter = GetWidgetAnchor)
		class USceneComponent* WidgetAnchor;

	/* 기즈모 사용시 나타나는 위젯의 위치를 위한 앵커 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* GizmoWidgetAnchor;

	/* 플레이어 좌측 모션 컨트롤러 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"),
		BlueprintGetter = GetLMotionController)
		class UMotionControllerComponent* LMotionController;

	/* 플레이어 좌측 모션 컨트롤러 위젯 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"))
		class UWidgetComponent* LMotionWidget;

	/* 플레이어 우측 모션 컨트롤러 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"),
		BlueprintGetter = GetRMotionController)
		class UMotionControllerComponent* RMotionController;

	/* 우측 모션 컨트롤러의 라인트레이스에서 충돌 지점을 가리키는 씬 컴포넌트입니다.
		주 목적은 무언가를 집는데 사용됩니다. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"),
		BlueprintGetter = GetRAttachedSocket)
		class USceneComponent* RAttachedSocket;

	// 플레이어 좌측 모션 컨트롤러 위젯
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"))
		class UWidgetComponent* RMotionWidget;

	/* 플레이어 이동 컴포넌트 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = "true"))
		class UFloatingPawnMovement* FloatingPawnMovement;

private:
	/* 플레이어의 현재 이동 타입 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Core|Player", meta = (Bitmask, AllowPrivateAccess = "true"),
		BlueprintSetter = SetMoveType, BlueprintGetter = GetMoveType)
		EMoveType CurrentMoveType;

	/* 고정 이동 시 고정할 축 데이터입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		FRotator FixedAxis;

private:
	/* 좌우 회전 속도 스케일입니다 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true),
		BlueprintSetter = SetYawRotSpeed, BlueprintGetter = GetYawRotSpeed)
		float YawRotSpeed;

	/* 수직 회전 속도 스케일입니다 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true),
		BlueprintSetter = SetPitchRotSpeed, BlueprintGetter = GetPitchRotSpeed)
		float PitchRotSpeed;

private:
	/* 라인트레이싱할 길이입니다 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true),
		BlueprintSetter = SetLineTraceLength, BlueprintGetter = GetLineTraceLength)
		int32 LineTraceLength;

	/* 직선 라인트레이스 오프셋. (모션컨트롤러의 트리거 버튼에서 레이저가 나가도록 설계합니다. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		float LineTraceZOffset;

	/* 직선 라인트레이스 시작점 */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		FVector LineTraceStart;

	/* 직선 라인트레이스 종료점 */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		FVector LineTraceEnd;

	/* 현재 액터를 픽업하고 있는지 여부입니다. */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true),
		BlueprintSetter = SetIsPickingActor, BlueprintGetter = IsPickingActor)
		bool bIsPickingActor;

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		/* 궤적을 그리는 투사체의 시작 속도 */
		FVector InitialLocalVelocity;

	/* 포커스 정보를 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Core|Player", meta = (AllowPrivateAccess = true))
		FUserFocusEventDispatcher UserFocusEventDispatcher;
};
