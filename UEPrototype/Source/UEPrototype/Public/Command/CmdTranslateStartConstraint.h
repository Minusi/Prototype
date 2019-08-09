// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Command/ActorCmdConstraint.h"
#include "ActorConstraintMarker.h"
#include "CmdTranslateStartConstraint.generated.h"

/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UCmdTranslateStartConstraint : public UObject, public IActorCmdConstraint
{
	GENERATED_BODY()
	
public:
	/* IActorCmdConstraint로부터 상속됨 */
	virtual bool CheckConstraint(FActorConstraintInfo TargetInfo) override;
};
