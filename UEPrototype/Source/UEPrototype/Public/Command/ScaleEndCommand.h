// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "ScaleEndCommand.generated.h"

class AActor;
class UActorConstraintMarker;
class ATransformer;

UCLASS()
class UEPROTOTYPE_API UScaleEndCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:

	UScaleEndCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;
	UFUNCTION(BlueprintCallable)
	void SetTransformer(ATransformer* Transformer) { this->Transformer = Transformer; }
private:
	static UActorConstraintMarker* ActorConstraintMarker;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
		ATransformer* Transformer;
};
