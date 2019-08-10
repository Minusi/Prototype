// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorInfoModuleManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "Outliner.h"
#include "VPTexturer.h"
#include "EditorWorldManager.h"
#include "EditorModulesManager.h"
#include "ActorConstraintMarker.h"
#include "ActorPlaceInfoMarker.h"



UActorInfoModuleManager::UActorInfoModuleManager()
{
	VP_CTOR;

	bInitialized = false;
	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}



	/* 초기화를 수행합니다 */
	Initialized();

	/* ActorInfo 모듈의 초기화가 완료되었음을 브로드캐스트합니다. */
	// DEBUG
	VP_LOG(Warning, TEXT("[DEBUG] ActorInfo 모듈 초기화완료"));
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}



UActorInfoModuleManager * UActorInfoModuleManager::GetGlobalActorInfoModuleManager()
{
	for (const auto& it : TObjectRange<UActorInfoModuleManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UActorInfoModuleManager::StaticClass()->GetName());
	return nullptr;
}





void UActorInfoModuleManager::Initialized()
{
	/* 하위 컴포넌트들을 초기화합니다 */
	Outliner = CreateDefaultSubobject<UOutliner>(UOutliner::StaticClass()->GetFName());
	VPTexturer = CreateDefaultSubobject<UVPTexturer>(UVPTexturer::StaticClass()->GetFName());
	ActorConstraintMarker = CreateDefaultSubobject<UActorConstraintMarker>(UActorConstraintMarker::StaticClass()->GetFName());
	ActorPlaceInfoMarker = CreateDefaultSubobject<UActorPlaceInfoMarker>(UActorPlaceInfoMarker::StaticClass()->GetFName());



	/* 컴포넌트들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(Outliner) == false)
	{
		VP_LOG(Error, TEXT("%s가 유효하지 않습니다. 생성되지 않았을 수 있습니다."), *UOutliner::StaticClass()->GetName());
		return;
	}
	if (IsValid(VPTexturer) == false)
	{
		VP_LOG(Error, TEXT("%s가 유효하지 않습니다. 생성되지 않았을 수 있습니다."), *UVPTexturer::StaticClass()->GetName());
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
}