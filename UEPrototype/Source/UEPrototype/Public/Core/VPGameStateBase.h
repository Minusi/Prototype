// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EditorWorldManager.h"
#include "VPGameStateBase.generated.h"



/* 
 * 플레이 중인 월드의 상태를 나타내는 열거형 클래스입니다.
 * 플래그가 의미하는 다음과 같습니다 :
 *	 - Edit : 현재 월드가 편집 상태로 진행중에 있습니다.
 *	 - Play : 현재 월드가 생성된 컨텐츠들을 실행중에 있습니다.
 */
UENUM(BlueprintType)
enum class EWorldState : uint8
{
	WORLD_Edit		UMETA(DisplayName = "Edit"),
	WORLD_Play		UMETA(DisplayName = "Play")
};





DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWorldStateChangedEventDispatcher, EWorldState, WorldState);



/**
 *	VPGameStateBase는 게임의 전반적인 상태를 나타내는 클래스입니다.
 *	현재로써는 월드의 상태를 관리하는 용도로 사용되며, 추후 기능이
 *	확장될 여지가 높습니다.
 */
UCLASS()
class UEPROTOTYPE_API AVPGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	/* 월드의 현재 상태를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Core|World")
	FORCEINLINE EWorldState GetWorldState() const
	{
		return WorldState;
	}

	/* 월드의 상태를 설정합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|World")
	void SetWorldState(EWorldState InWorldState);

	/* WorldStateChangedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FWorldStateChangedEventDispatcher OnWorldStateChanged() const
	{
		return WorldStateChangedEventDispatcher;
	}



protected:
	/* AActor로부터 오버라이드됨 */
	virtual void BeginPlay() override;





private:
	/* 현재 월드의 상태를 나타냅니다 */
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Core|World", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetWorldState, BlueprintSetter=SetWorldState)
	EWorldState WorldState;

	/* 월드 전체를 관리하는 매니저 캐시입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAccess=true))
	AEditorWorldManager* EditorWorldManagerCache;

	/* 월드의 상태가 변화될 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Core|World|Delegate", meta=(AllowPrivateAccess=true))
	FWorldStateChangedEventDispatcher WorldStateChangedEventDispatcher;
	
};
