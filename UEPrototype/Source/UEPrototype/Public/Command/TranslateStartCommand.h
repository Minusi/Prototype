// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "TranslateStartCommand.generated.h"

class AActor;
class UActorConstraintMarker;
class ATransformer;
class AEditorGizmo;
class UGizmoMeshComponent;

USTRUCT(BlueprintType)
struct FTranslateInfo 
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
class UEPROTOTYPE_API UTranslateStartCommand : public UActorCommandBase
{
	GENERATED_BODY()
	
public:

	UTranslateStartCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

	UFUNCTION(BlueprintCallable)
	void SetTransformer(ATransformer* Transformer) 
	{ 
		this->Transformer = Transformer; 
	}

	UFUNCTION(BlueprintCallable, Category = "TranslateStartCommand")
	void SetTranslateInfo(FTranslateInfo TransInfo) { TranslateInfo = TransInfo; }
	UFUNCTION(BlueprintCallable, Category = "TranslateStartCommand")
	void SetEditorGizmo(AEditorGizmo* EditGizmo) { EditorGizmo = EditGizmo; }
private:
	static UActorConstraintMarker* ActorConstraintMarker;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	ATransformer* Transformer;

	FTranslateInfo TranslateInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	AEditorGizmo* EditorGizmo;
};
