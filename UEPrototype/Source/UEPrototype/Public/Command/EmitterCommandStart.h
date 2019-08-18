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
	void SetVPEmitter(AVPEmitter* Emit) { VPEmitter = Emit; }
	UFUNCTION(BlueprintCallable)
	void SetEmitter(UParticleSystem* ParticleSystem, FTransform Transform, AActor* Parent = nullptr);
	UFUNCTION(BlueprintCallable)
	void SetEmitterParam(const FEmitterParam EmitterParam, const FTransform RelativeTrasnform);

	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetEmitterVectorParam(UParticleSystemComponent* ParticleSystemComp, FVector Vector, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetEmitterLinearColor(UParticleSystemComponent* ParticleSystemComp, FLinearColor Color, FName Name);
	UFUNCTION(BlueprintCallable, Category = "VPMaterial")
	void SetEmitterScalarParam(UParticleSystemComponent* ParticleSystemComp, float Value, FName Name);


private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	static AVPEmitter* VPEmitter;
};
