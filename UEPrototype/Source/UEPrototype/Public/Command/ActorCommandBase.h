// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/CommandBase.h"
#include "Command/ActorCmdConstraint.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "Containers/Array.h"
#include "GameFramework/Actor.h"
#include "ActorConstraintMarker.h"
#include "ActorCommandBase.generated.h"



class AActor;
/**
 *	ActorCommandBase 클래스는 명령 중 액터의 프로퍼티에 직접적
 *	으로 관련이 있는 명령들에 대한 Base class입니다. 모든 액터
 *	를 다루는 명령들은 이 클래스를 상속받아야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API UActorCommandBase : public UCommandBase
{
	GENERATED_BODY()
	
public:
	/* 액터 커맨드를 주어진 인자로부터 초기화합니다 */
	UFUNCTION(BlueprintCallable, Category="Command")
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo);
	




protected:
	/* 명령의 대상이 되는 액터입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Command", meta=(AllowPrivateAccess=true))
	FActorConstraintInfo Target;

	/* 해당 명령을 실행하는 데 가해지는 제약 조건입니다. 이 제약 조건 중 하나라도
	만족하면 됩니다. */
	UPROPERTY()
	TArray<TScriptInterface<IActorCmdConstraint>> Constraints;
};
