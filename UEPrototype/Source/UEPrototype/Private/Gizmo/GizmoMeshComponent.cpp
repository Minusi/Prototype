// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
//#include "UEPrototype.h"

//UGizmoMeshComponent::UGizmoMeshComponent()
//{
//	//Super::UStaticMeshComponent();
//	VP_CTOR;
//}
void UGizmoMeshComponent::CreateGizmo(TArray<EGizmoAxisType> InAxisTypes, float InOffsetFromCenter)
{
	this->AxisTypes = InAxisTypes;
	//else
	//	VP_LOG(Error, TEXT("GM_ 기즈모에 알맞은 매쉬를 찾을 수 없습니다."));
	//GetClass()->GetDisplayNameText().ToString()
}

FVector UGizmoMeshComponent::GetAxisUnitDirectionVector()
{
	return RelativeLocation;
}
