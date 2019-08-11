// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "CloseContextCommand.generated.h"

class AContextor;

UCLASS()
class UEPROTOTYPE_API UCloseContextCommand : public UActorCommandBase
{
	GENERATED_BODY()

public:
	/* 생성자 */
	UCloseContextCommand();

	/* UCommandBase로부터 상속됨 */

	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;



private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	static AContextor* Contextor;
};
