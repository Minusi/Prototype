// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "MotionTrackedDeviceFunctionLibrary.h"

#include "Core/VPPlayerController.h"
#include "VPDirectorPawn.generated.h"

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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 모든 모션 컨트롤러의 유효성을 확인하여 시각화합니다.
	// 이 작업은 단순히 모션 트래킹 되지 않는 컴포넌트의 메시를 날려버립니다.
	UFUNCTION(BlueprintCallable, Category= "Custom|Director")
	void ModifyVisualizeMControllers();



private:
	// 플레이어 콜리전
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category= "Director", meta=(AllowPrivateAccess="true"))
	class UCapsuleComponent * RootCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Director", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* VRRootTransform;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Director", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* VRCamera;

	// 플레이어 좌측 모션 컨트롤러
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Director", meta=(AllowPrivateAccess="true"))
	class UMotionControllerComponent* LeftMController;

	// 플레이어 우측 모션 컨트롤러
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Director", meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* RightMController;
};
