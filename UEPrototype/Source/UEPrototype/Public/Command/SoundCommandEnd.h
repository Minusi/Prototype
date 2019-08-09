// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "SoundCommandEnd.generated.h"


class UActorConstraintMarker;
class AVPAmbientSound;

UCLASS()
class UEPROTOTYPE_API USoundCommandEnd : public UActorCommandBase
{
	GENERATED_BODY()
public:
	/* 생성자 */
	USoundCommandEnd();

	/* UCommandBase로부터 상속됨 */

	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

	UFUNCTION(BlueprintCallable)
	void SetVPAmbientSound(AVPAmbientSound* Sound) { VPAmbientSound = Sound; }

private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	AVPAmbientSound* VPAmbientSound;

};
