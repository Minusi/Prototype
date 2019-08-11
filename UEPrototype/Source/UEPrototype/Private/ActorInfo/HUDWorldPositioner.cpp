// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWorldPositioner.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"

#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "Public/Math/Box.h"
#include "Public/Math/Vector.h"
#include "Core/VPDirectorPawn.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

UHUDWorldPositioner::UHUDWorldPositioner()
{
	// DEBUG : 생성자 로그
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}

 void UHUDWorldPositioner::ApplyWidgetPosition(const AActor* Target, AActor* InOutWidget, UIDirectionType direction)
{
	FBox TotalTargetBound;
	AVPDirectorPawn* CharacterPawn = Cast<AVPDirectorPawn>(Target->GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if (!IsValid(CharacterPawn))
	{
		VP_LOG(Warning, TEXT("카메라 폰이 유효하지 않습니다."));
		return;
	}
	
	//타겟 바운드 수집
	TArray<UStaticMeshComponent*> StaticMeshComponents;
	Target->GetComponents<UStaticMeshComponent>(StaticMeshComponents);
	for (UStaticMeshComponent*& it : StaticMeshComponents)
	{
		VP_LOG(Log, TEXT("before overlap %s %s"), *TotalTargetBound.GetCenter().ToString(), *TotalTargetBound.GetSize().ToString());
		TotalTargetBound = TotalTargetBound.Overlap(it->GetStaticMesh()->ExtendedBounds.GetBox());
		VP_LOG(Log, TEXT("after overlap %s %s"), *TotalTargetBound.GetCenter().ToString(), *TotalTargetBound.GetSize().ToString());
	}
	FVector2D WidgetSize;
	TArray<UWidgetComponent*> WidgetComponents;
	//위젯 바운드 수집
	InOutWidget->GetComponents<UWidgetComponent>(WidgetComponents);
	for (UWidgetComponent*& it : WidgetComponents)
	{
		VP_LOG(Log, TEXT("before calced widget : %s"), *WidgetSize.ToString());

		WidgetSize = it->GetDrawSize();
		VP_LOG(Log, TEXT("after calced widget : %s"), *WidgetSize.ToString());

	}
	

	//정렬
	InOutWidget->SetActorTransform(Target->GetTransform());

	VP_LOG(Log, TEXT("L/R : %s"), direction==UIDirectionType::Left?"L":"R");
	VP_LOG(Log, TEXT("size : %f"), (TotalTargetBound.GetExtent().X + WidgetSize.X/2));
	VP_LOG(Log, TEXT("direction : %s"), *(CharacterPawn->GetVRCamera()->GetRightVector()).ToString());

	//위치조정
	InOutWidget->AddActorLocalOffset(
		(direction == UIDirectionType::Left ?-1:1)//왼쪽 오른족에따라 + or - (오른쪽이 +)
		*(WidgetSize.X/2)//크기 : 위젯박스 x 반경+타겟박스 x 반경
		*(CharacterPawn->GetVRCamera()->GetRightVector())//방향 : 정렬된 위젯의 오른쪽 기준
	);
	InOutWidget->AddActorLocalOffset(
		TotalTargetBound.GetExtent()
	);
	InOutWidget->SetActorRotation(
		UKismetMathLibrary::FindLookAtRotation(InOutWidget->GetActorLocation(), CharacterPawn->GetActorLocation()),
		ETeleportType::ResetPhysics
	);


}


UHUDWorldPositioner* UHUDWorldPositioner::GetGlobalHUDWorldPositioner()
{
	for (const auto& it : TObjectRange<UHUDWorldPositioner>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UHUDWorldPositioner::StaticClass()->GetName());
	return nullptr;
}
