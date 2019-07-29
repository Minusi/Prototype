// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorInfoModuleManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "Outliner.h"
#include "ActorConstraintMarker.h"
#include "ActorPlaceInfoMarker.h"



UActorInfoModuleManager::UActorInfoModuleManager()
{
	/* 초기화를 수행합니다 */
	Initialized();
}



UActorInfoModuleManager * UActorInfoModuleManager::GetGlobalActorInfoModuleManager()
{
	for (const auto& it : TObjectRange<UActorInfoModuleManager>())
	{
		return it;
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UActorInfoModuleManager::StaticClass()->GetName());
	return nullptr;
}





void UActorInfoModuleManager::Initialized()
{
	/* 하위 컴포넌트들을 초기화합니다 */
	Outliner = CreateDefaultSubobject<UOutliner>(MakeUniqueObjectName(this, UOutliner::StaticClass()));
	ActorConstraintMarker = CreateDefaultSubobject<UActorConstraintMarker>(MakeUniqueObjectName(this, UActorConstraintMarker::StaticClass()));
	ActorPlaceInfoMarker = CreateDefaultSubobject<UActorPlaceInfoMarker>(MakeUniqueObjectName(this, UActorPlaceInfoMarker::StaticClass()));



	/* 컴포넌트들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(Outliner) == false)
	{
		VP_LOG(Error, TEXT("%s가 유효하지 않습니다. 생성되지 않았을 수 있습니다."), *UOutliner::StaticClass()->GetName());
		return;
	}
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_LOG(Error, TEXT("%s가 유효하지 않습니다. 생성되지 않았을 수 있습니다."), *UActorConstraintMarker::StaticClass()->GetName());
		return;
	}
	if (IsValid(ActorPlaceInfoMarker) == false)
	{
		VP_LOG(Error, TEXT("%s가 유효하지 않습니다. 생성되지 않았을 수 있습니다."), *UActorPlaceInfoMarker::StaticClass()->GetName());
		return;
	}

	/* TODO : 모듈이 끝났을 때 이벤트를 브로드캐스트해야 합니다. 현재 커밋 버전은 모듈이 수정되지 않았습니다 */
}
