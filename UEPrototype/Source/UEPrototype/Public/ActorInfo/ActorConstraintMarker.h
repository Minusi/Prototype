// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ActorConstraintMarker.generated.h"



/*
 *	액터가 현재 플레이어와 상호작용하고 있는 상태에 대한 
 *	열거형 클래스입니다 
 */
UENUM(BlueprintType)
enum class EActorConstraintState : uint8
{
	/* 초기화되지 않은 상태입니다 */
	CSTR_None,
	/* 사용자와 아무런 상호작용을 하고 있지 않은 상태입니다 */
	CSTR_Unfocused,
	/* 사용자가 물체를 주목하고 있는 상태입니다. */
	CSTR_Focused,
	/* 일정 시간동안 주목받고 있는 상태입니다. */
	CSTR_Highlighted,
	/* 상호작용을 하고 있는 상태입니다. */
	CSTR_Activated,
	/* 특정 상호작용이 행해지고 있는 상태입니다. 
	   이 때 다른 특정 상호작용이 불가능할 수 있습니다 */
	CSTR_Blocked
};





/*
 *	액터와 해당 액터의 상호작용 제약 상태를 함께 나타내기
 *	위한 구조체입니다
 */
USTRUCT(BlueprintType)
struct FActorConstraintInfo
{
	GENERATED_BODY()
	
public:
	/* Constraint 상태를 나타낼 액터입니다 */
	UPROPERTY()
	AActor* Target;

	/* 액터의 상태를 나타냅니다 */
	UPROPERTY()
	EActorConstraintState TargetState;
};





DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorConstraintMarkEventDispatcher, FActorConstraintInfo, ActorConstraintInfo);



/**
 *	ActorConstraintMarker는 월드에 배치된 액터에 대해서 액터 상호작용 제약 조건을
 *	표시하는 클래스입니다. 예를 들어, 텍스처 페인팅 명령을 실행하게 되면 해당
 *	액터를 CSTR_Blocked로 설정합니다.
 */
UCLASS()
class UEPROTOTYPE_API UActorConstraintMarker : public UObject
{
	GENERATED_BODY()
	
public:	
	/* 액터를 입력받은 상태로 설정합니다 */
	UFUNCTION()
	void MarkActor(AActor* Target, EActorConstraintState State);
	
	

	/* ActorConstraintMarkEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FActorConstraintMarkEventDispatcher OnActorConstraintChanged() const
	{
		return ActorConstraintMarkEventDispatcher;
	}





private:
	/* Actor의 제약 상태가 변경되면 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY()
	FActorConstraintMarkEventDispatcher ActorConstraintMarkEventDispatcher;
};
