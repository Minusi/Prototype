// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "ActorInfo/VPEmitter.h"
#include "EmitterCommandStart.generated.h"

class UActorConstraintMarker;

UCLASS()
class UEPROTOTYPE_API UEmitterCommandStart : public UActorCommandBase
{
	GENERATED_BODY()
public:
	/* 생성자 */
	UEmitterCommandStart();

	/* UCommandBase로부터 상속됨 */

	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

	UFUNCTION(BlueprintCallable)
	void SetVPAmbientSound(AVPEmitter* Emit) { VPEmitter = Emit; }

	void SetEmitter(UParticleSystem* ParticleSystem, FTransform Transform, AActor* Parent = nullptr);
	void SetEmitterParam(const FEmitterParam EmitterParam, const FTransform RelativeTrasnform);



private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	AVPEmitter* VPEmitter;
};
