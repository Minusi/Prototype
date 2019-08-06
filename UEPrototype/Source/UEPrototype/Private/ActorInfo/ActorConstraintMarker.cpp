// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorConstraintMarker.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"



UActorConstraintMarker::UActorConstraintMarker()
{
	// DEBUG
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}





UActorConstraintMarker* UActorConstraintMarker::GetGlobalActorConstraintMarker()
{
	for (const auto& it : TObjectRange<UActorConstraintMarker>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}

	

	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UActorConstraintMarker::StaticClass()->GetName());
	return nullptr;
}





void UActorConstraintMarker::MarkActor(AActor* Target, EActorConstraintState State)
{
	/* 액터에 대한 유효성 검사를 수행합니다 */
	if (IsValid(Target) == false)
	{
		VP_LOG(Warning, TEXT("Actor가 유효하지 않습니다"));
		return;
	}

	FActorConstraintInfo ActorConstraintInfo;
	ActorConstraintInfo.Target = Target;
	ActorConstraintInfo.TargetState = State;

	/* 브로드캐스트합니다 */
	ActorConstraintMarkEventDispatcher.Broadcast(ActorConstraintInfo);
}