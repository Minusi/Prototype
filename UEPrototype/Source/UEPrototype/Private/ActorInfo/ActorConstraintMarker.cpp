// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorConstraintMarker.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"



UActorConstraintMarker::UActorConstraintMarker()
{
	// DEBUG
	VP_CTOR;

	/* 월드 컨텍스트를 포함하지 않는 CDO는 프레임워크에서 필요로 하지 않는 CDO이므로,
	더이상의 초기화를 수행하지 않습니다 */
	if (ContainWorldContextCDO() == false)
	{
		return;
	}
}





UActorConstraintMarker* UActorConstraintMarker::GetGlobalActorConstraintMarker()
{
	for (const auto& it : TObjectRange<UActorConstraintMarker>())
	{
		if (it->ContainWorldContextCDO())
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





bool UActorConstraintMarker::ContainWorldContextCDO()
{
	/* OuterChain을 거슬러 올라가면서, AEditorWorldManager가 있는지 탐색합니다 */
	UObject* OuterChain = this;
	while ((OuterChain = OuterChain->GetOuter()) != nullptr)
	{
		VP_LOG(Log, TEXT("Outer : %s"), *OuterChain->GetName());
		/* OuterChain에 AEditorWorldManager가 있으면 참을 반환합니다. */
		if (OuterChain->GetClass() == AEditorWorldManager::StaticClass())
		{
			return true;
		}
	}

	return false;
}
