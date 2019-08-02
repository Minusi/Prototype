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

//카메라를 고정시킬것인지, 액터를 따라다닐 것인지, 카메라 이용을 따로 하지않고 자유롭게 움직이며 관찰할 떄
//에 대한 enum값
UENUM(BlueprintType)
enum class ECameraStyle : uint8
{
	STATIC		UMETA(DisplayName = "Static"),
	RELATIVE	UMETA(DisplayName = "Relative"),
	CONTROL		UMETA(DisplayName = "Control"),
};

//카메라가 Perspective 방식이냐 Orthographic 방식인지에 관한 enum
UENUM(BlueprintType)
enum class EPROJECTION_MODE : uint8
{
	PERSPECTIVE,
	ORTHOGRAPHIC,

};

//OrthoGraphic에 설정 값에 대한 구조체
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

//Perspective에 설정 값에 대한 구조체
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

//SetViewTargetWithBlend()에 들어가는 파라미터 값에대한 구조체
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

	//카메라 엑터의 관점으로 볼 수 있게하는 함수
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
	//줌 인 기능
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void ZoomIn();
	//줌 아웃 기능
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	void ZoomOut();



private:
	// 플레이어 카메라의 레퍼런스를 반환하는 함수
	UFUNCTION(BlueprintCallable, Category = "VPCameraActor")
	APlayerCameraManager* GetPlayerCameraMgr() const;

	// 플레이어 카메라에 대한 레퍼런스
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	APlayerCameraManager* PlayerCameraMgr;

	// 카메라 컴포넌트 캐싱을 위한 레퍼런스
	UPROPERTY(BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CachedCameraComponent;

	//카메라를 고정된위치에 붙일것인지, 액터와 상대적으로 움직이도록 할 것인지에 대한 EnumClass
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	ECameraStyle CameraStyle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPCameraActor", meta = (AllowPrivateAccess = "true"))
	APlayerController* PlayerController;

	// Perspective , Orthographic
	EPROJECTION_MODE ProjectionMode;

	// 초기화와 실행 기능이 분리 되어있기 떄문에 초기화 떄 ViewTarget 파라미터를 담아두기 위한 변수
	FViewTarget ViewTarget;

	const FString CameraLabel = "VPCameraActor";

	
	//액터에 붙을 수 있는 최대 카메라 개수
	const int MaxAttachedCameraNumber = 2;
};
