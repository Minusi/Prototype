// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Command/ActorCmdConstraint.h"
#include "ActorConstraintMarker.h"
#include "CmdHighlightedConstraint.generated.h"



/**
*	대상 액터가 Highlighted 상태임을 만족해야 하는 제약조건을 명시하는
*	클래스입니다.
 */
UCLASS()
class UEPROTOTYPE_API UCmdHighlightedConstraint : public UObject, public IActorCmdConstraint
{
	GENERATED_BODY()
	
public:
	/* IActorCmdConstraint로부터 상속됨 */
	virtual bool CheckConstraint(FActorConstraintInfo TargetInfo) override;
};
