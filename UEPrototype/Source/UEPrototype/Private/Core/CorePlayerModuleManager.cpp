// Fill out your copyright notice in the Description page of Project Settings.

#include "CorePlayerModuleManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"
#include "PlayerTaskManager.h"



UCorePlayerModuleManager::UCorePlayerModuleManager()
{
	// DEBUG
	VP_CTOR;

	bInitialized = false;
	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}

	VP_LOG(Log, TEXT("생성자 bInitialized : %d"), bInitialized);

	/* 초기화합니다. */
	Initialized();


	// DEBUG
	VP_LOG(Warning, TEXT("[DEBUG] Core|Player 모듈 초기화완료"));
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}



void UCorePlayerModuleManager::Initialized()
{
	/* 컴포넌트들을 초기화합니다 */
	UPlayerTaskManager* PlayerTaskManager = CreateDefaultSubobject<UPlayerTaskManager>
		(UPlayerTaskManager::StaticClass()->GetFName());


	/* 유효성 검사를 수행합니다 */
	if (IsValid(PlayerTaskManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UPlayerTaskManager::StaticClass()->GetName());
		return;
	}
}





UCorePlayerModuleManager * UCorePlayerModuleManager::GetGlobalCorePlayerModuleManager()
{
	for (const auto& it : TObjectRange<UCorePlayerModuleManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UCorePlayerModuleManager::StaticClass()->GetName());
	return nullptr;
}