// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "ScaleStartCommand.generated.h"

class UActorConstraintMarker;
class ATransformer;
class AEditorGizmo;
class UGizmoMeshComponent;

USTRUCT(BlueprintType)
struct FScaleInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TranslateStartCommand")
	UGizmoMeshComponent* SelectedGizmoComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TranslateStartCommand")
	float SnapInterval;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TranslateStartCommand")
	float Delta;
};


UCLASS()
class UEPROTOTYPE_API UScaleStartCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:

	UScaleStartCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

	UFUNCTION(BlueprintCallable)
	void SetTransformer(ATransformer* Transformer) { this->Transformer = Transformer; }

	UFUNCTION(BlueprintCallable, Category = "TranslateStartCommand")
	void SetScaleInfo(FScaleInfo ScaleInfo) { this->ScaleInfo = ScaleInfo; }

	UFUNCTION(BlueprintCallable, Category = "TranslateStartCommand")
	void SetEditorGizmo(AEditorGizmo* EditGizmo) { EditorGizmo = EditGizmo; }

private:
	static UActorConstraintMarker* ActorConstraintMarker;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	ATransformer* Transformer;

	FScaleInfo ScaleInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	AEditorGizmo* EditorGizmo;
};
