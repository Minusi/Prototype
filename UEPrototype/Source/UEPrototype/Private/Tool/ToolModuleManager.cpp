// Fill out your copyright notice in the Description page of Project Settings.

#include "Tool/ToolModuleManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "Tool/ToolKit.h"
#include "Tool/ToolManager.h"



UToolModuleManager::UToolModuleManager()
{
	// DEBUG
	VP_CTOR;

	bInitialized = false;
	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}


	
	/* 초기화합니다. */
	Initialized();



	// DEBUG
	VP_LOG(Warning, TEXT("[DEBUG] Tool 모듈 초기화완료"));
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}



UToolModuleManager * UToolModuleManager::GetGlobalToolModuleManager()
{
	for (const auto& it : TObjectRange<UToolModuleManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UToolModuleManager::StaticClass()->GetName());
	return nullptr;
}





void UToolModuleManager::Initialized()
{
	/* 하위 모듈들을 초기화합니다 */
	ToolKit = CreateDefaultSubobject<UToolKit>(UToolKit::StaticClass()->GetFName());
	ToolManager = CreateDefaultSubobject<UToolManager>(UToolManager::StaticClass()->GetFName());

	

	if (IsValid(ToolKit) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UToolKit::StaticClass()->GetName());
		return;
	}
	if (IsValid(ToolManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UToolManager::StaticClass()->GetName());
		return;
	}
}