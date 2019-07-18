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

UENUM(BlueprintType)
enum class EGizmoAxisType : uint8
{
	GM_AXIS_X UMETA(DisplayName = "Axis_X"),
	GM_AXIS_Y UMETA(DisplayName = "Axis_Y"),
	GM_AXIS_Z UMETA(DisplayName = "Axis_Z"),
};


UCLASS(BlueprintType)
class UEPROTOTYPE_API UGizmoMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
//public:
//	UGizmoMeshComponent();
//
protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	TArray<EGizmoAxisType> AxisTypes;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	EGizmoTransType TransType;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo|Data", meta = (AllowPrivateAccess = "true"))
	float OffsetFromCenter;
	
public:
	UFUNCTION(BlueprintCallable, Category = "Gizmo")
	virtual void CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter, UStaticMesh* InMesh);

	UFUNCTION(BlueprintCallable, Category = "Gizmo")
	virtual void UpdateGizmoTransType(EGizmoTransType InTransType);

};
