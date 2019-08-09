// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "BlockedCommand.generated.h"

class UActorConstraintMarker;
UCLASS()
class UEPROTOTYPE_API UBlockedCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:

	UBlockedCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

private:
	static UActorConstraintMarker* ActorConstraintMarker;
};
