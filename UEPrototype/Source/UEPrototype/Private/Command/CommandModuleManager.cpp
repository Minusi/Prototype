// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/CommandModuleManager.h"
#include "Command/CommandQueue.h"
#include "Command/CommandConstraintManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"



UCommandModuleManager::UCommandModuleManager()
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
	VP_LOG(Warning, TEXT("[DEBUG] Command 모듈 초기화완료"));
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}





void UCommandModuleManager::Initialized()
{
	/* 하위 모듈들을 초기화합니다 */
	CommandQueue = CreateDefaultSubobject<UCommandQueue>
		(UCommandQueue::StaticClass()->GetFName());
	CommandConstraintManager = CreateDefaultSubobject<UCommandConstraintManager>
		(UCommandConstraintManager::StaticClass()->GetFName());



	/* 하위 모듈들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(CommandQueue) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandQueue::StaticClass()->GetName());
		return;
	}
	if (IsValid(CommandConstraintManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::StaticClass()->GetName());
		return;
	}

	VP_LOG(Log, TEXT("초기화 bInitialized : %d"), bInitialized);
}





UCommandModuleManager * UCommandModuleManager::GetGlobalCommandModuleManager()
{
	for (const auto& it : TObjectRange<UCommandModuleManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UCommandModuleManager::StaticClass()->GetName());
	return nullptr;
}