// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ActorConstraintMarker.h"
#include "ActorCmdConstraint.generated.h"



/**
 *	ActorCmdConstraint 클래스는 명령이 실행될 때 만족해야 할
 *	Actor의 제약조건을 기술하는 것에 대한 통합적인 인터페이스
 *	를 제공하는 인터페이스 클래스입니다.
 *
 *	모든 ActorCommandBase 파생 클래스들은 이 인터페이스의 구현
 *	체가 지닌 제약 조건들 모두를 만족해야 명령을 실행할 수 있
 *	습니다. 자세한 것은 drawio 다이어그램 또는 UActorCommandB
 *	ase를 참조하시기 바랍니다.
 */
UINTERFACE(BlueprintType)
class UEPROTOTYPE_API UActorCmdConstraint : public UInterface
{
	GENERATED_BODY()
};



class UEPROTOTYPE_API IActorCmdConstraint
{
	GENERATED_BODY()
	
public:
	/* 제약조건을 만족하는 지 검사합니다. 
		만족하면 참, 만족하지 못하면 거짓을 반환합니다 */
	UFUNCTION(Category="Command")
	virtual bool CheckConstraint(FActorConstraintInfo TargetInfo) = 0;
};