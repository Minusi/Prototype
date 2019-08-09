// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "EmitterCommand.generated.h"

class UActorConstraintMarker;
class AVPEmitter;

UCLASS()
class UEPROTOTYPE_API UEmitterCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:
	/* 생성자 */
	UEmitterCommand();

	/* UCommandBase로부터 상속됨 */

	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

	UFUNCTION(BlueprintCallable)
	void SetVPAmbientSound(AVPEmitter* Emit) { VPEmitter = Emit; }

private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	AVPEmitter* VPEmitter;


};
