// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "UnfocusedCommand.generated.h"

class AActor;
class UOutliner;
class UActorConstraintMarker;

UCLASS()
class UEPROTOTYPE_API UUnfocusedCommand : public UActorCommandBase
{
	GENERATED_BODY()

public:

	UUnfocusedCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;
	
private:

	/* 물체에 윤곽선을 그려줍니다 */
	static UOutliner* Outliner;

	static UActorConstraintMarker* ActorConstraintMarker;
};
