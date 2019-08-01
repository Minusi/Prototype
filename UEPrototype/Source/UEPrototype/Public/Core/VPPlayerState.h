// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "VPPlayerState.generated.h"



UENUM(BlueprintType)
enum class EPlayerWorkState : uint8
{
	/* 유효하지 않은 상태 */
	PST_None,
	/* 플레이어가 월드에서 편집 중인 상태*/
	PST_Prototype,
	/* 플레이어가 특정 모드에서 편집 중인 상태 */
	PST_Edit,
	/* 플레이어가 Play 중인 상태 */
	PST_Play
};





class UPlayerTaskManager;



/**
 *	VPPlayerState 클래스는 플레이어의 현재 조작 상태를 나타내는
 *	클래스입니다. 이 클래스는 추후 확장될 가능성이 높습니다.
 */
UCLASS()
class UEPROTOTYPE_API AVPPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	AVPPlayerState();



	/* PlayerWorkState의 Getter입니다. */
	UFUNCTION(BlueprintGetter, Category="Core|Player")
	FORCEINLINE EPlayerWorkState GetPlayerWorkState() const
	{
		return PlayerWorkState;
	}

	/* PlayerTaskManager의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category="Core|Player")
	FORCEINLINE UPlayerTaskManager* GetPlayerTaskManager() const
	{
		return PlayerTaskManager;
	}



protected:
	/* AActor로부터 상속됨 */
	UFUNCTION()
	virtual void BeginPlay() override;





private:
	/* 플레이어의 현재 상태를 나타냅니다 */
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category="Core|Player",
				meta=(AllowPrivateAccess=true), BlueprintGetter=GetPlayerWorkState)
	EPlayerWorkState PlayerWorkState;

	/* 플레이어의 작업을 관리하는 매니저입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetPlayerTaskManager)
	UPlayerTaskManager* PlayerTaskManager;
};
