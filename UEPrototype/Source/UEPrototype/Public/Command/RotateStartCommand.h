// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "RotateStartCommand.generated.h"

class UActorConstraintMarker;
class ATransformer;
class UGizmoMeshComponent;
class AEditorGizmo;

USTRUCT(BlueprintType)
struct FRotateInfo
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
class UEPROTOTYPE_API URotateStartCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:
	URotateStartCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;
	UFUNCTION(BlueprintCallable)
	void SetTransformer(ATransformer* Transformer) { this->Transformer = Transformer; }
	UFUNCTION(BlueprintCallable, Category = "TranslateStartCommand")
	void SetRotateInfo(FRotateInfo RotateInfo) { this->RotateInfo = RotateInfo; }
	UFUNCTION(BlueprintCallable, Category = "TranslateStartCommand")
	void SetEditorGizmo(AEditorGizmo* EditGizmo) { EditorGizmo = EditGizmo; }
private:
	static UActorConstraintMarker* ActorConstraintMarker;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	ATransformer* Transformer;

	FRotateInfo RotateInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	AEditorGizmo* EditorGizmo;
};
