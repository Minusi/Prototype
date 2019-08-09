// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "ActivateCommand.generated.h"

class UActorConstraintMarker;

UCLASS()
class UEPROTOTYPE_API UActivateCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:
	UActivateCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

private:

	static UActorConstraintMarker* ActorConstraintMarker;
};
