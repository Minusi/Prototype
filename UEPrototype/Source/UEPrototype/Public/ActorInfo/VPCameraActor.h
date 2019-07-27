// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "VPCameraActor.generated.h"

class ACameraActor;
class APlayerCameraManager;
class APlayerController;
class USpringArmComponent;
class USceneComponent;

UENUM(BlueprintType)
enum class ECameraStyle : uint8
{
	STATIC		UMETA(DisplayName = "Static"),
	RELATIVE	UMETA(DisplayName = "Relative"),
	CONTROL		UMETA(DisplayName = "Control"),
};

UENUM(BlueprintType)
enum class EPROJECTION_MODE : uint8
{
	PERSPECTIVE,
	ORTHOGRAPHIC,

};

USTRUCT(BlueprintType)
struct FOrthoGraphic
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		float Width;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		float AspectRatio;
};

USTRUCT(BlueprintType)
struct FPerspective
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		float FieldofView;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		float AspectRatio;
};

USTRUCT(BlueprintType)
struct FViewTarget
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		float BlendTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		TEnumAsByte<EViewTargetBlendFunction> BlendFunc;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		float BlendExp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "VPCameraActor")
		bool LockOutgoing;

};


UCLASS()
class UEPROTOTYPE_API AVPCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	//액터에 붙을 카메라에 대한 정보를 쥐어줌.
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void InitCameraSetting(AActor* Actor, FTransform Transform, FViewTarget ViewTarget, ECameraStyle CameraStyle = ECameraStyle::STATIC,
			EPROJECTION_MODE ProjectionMode = EPROJECTION_MODE::PERSPECTIVE);

	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void ConverseViewTarget();

	//카메라가 생성되고 기즈모나 UI를 통해 Transform이나 기본적인 카메라 옵션 조정
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void AdjustCameraSetting_Perspective(FTransform Transform, FPerspective Perspective);

	//카메라가 생성되고 기즈모나 UI를 통해 Transform이나 기본적인 카메라 옵션 조정
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void AdjustCameraSetting_OrthoGraphic(FTransform Transform, FOrthoGraphic OrthoGraphic);

	//카메라 액터의 기능을 끝냈을 때 다시 Player의 카메라로 돌아오는 함수
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void ReturnPlayerCamera();
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void ZoomIn();
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void ZoomOut();



private:
	// 플레이어 카메라의 레퍼런스를 반환하는 함수
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	APlayerCameraManager* GetPlayerCameraMgr() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	APlayerCameraManager* PlayerCameraMgr;

	// 카메라 컴포넌트 캐싱을 위한 레퍼런스
	UPROPERTY(BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* MyCameraComponent;

	//카메라를 고정된위치에 붙일것인지, 액터와 상대적으로 움직이도록 할 것인지에 대한 EnumClass
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	ECameraStyle CameraStyle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	APlayerController* PlayerController;

	// Perspective , Orthographic
	EPROJECTION_MODE ProjectionMode;

	FViewTarget ViewTarget;

	const FString CameraLabel = "VPCameraActor";

	
	//액터에 붙을 수 있는 최대 카메라 개수
	const int MaxAttachedCameraNumber = 2;
};
