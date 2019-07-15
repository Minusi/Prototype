// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GizmoMeshComponent.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGizmoTransType : uint8
{
	GM_MOVE UMETA(DisplayName = "Move"),
	GM_ROTATE UMETA(DisplayName = "Rotate"),
	GM_SCALE UMETA(DisplayName = "Scale"),
};

UENUM(BlueprintType)
enum class EGizmoCoordType : uint8
{
	GM_WORLDSPACE UMETA(DisplayName = "WorldSapce"),
	GM_LOCALSPACE UMETA(DisplayName = "LocalSpace"),
};

UCLASS(BlueprintType)
class UEPROTOTYPE_API UGizmoMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	UGizmoMeshComponent();

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	FVector ActiveAxis;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	EGizmoTransType TransType;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	float OffsetFromCenter;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	FTransform Transformation;

public:
	UFUNCTION(BlueprintCallable, Category = "Gizmo")
	void CreateGizmo(FVector InActiveAxis, float InOffsetFromCenter);

	UFUNCTION(BlueprintCallable, Category = "Gizmo")
	virtual void UpdateGizmoTransformation(FTransform InTransfrom);
	UFUNCTION(BlueprintCallable, Category = "Gizmo")
	virtual void UpdateGizmoTransType(EGizmoTransType InTransType);

};
