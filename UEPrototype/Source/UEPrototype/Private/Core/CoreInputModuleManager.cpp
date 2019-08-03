// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreInputModuleManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "EditorWorldManager.h"
#include "EditorInterpreterManager.h"
#include "InputSettingManager.h"
#include "UObjectIterator.h"



UCoreInputModuleManager::UCoreInputModuleManager()
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
	VP_LOG(Warning, TEXT("[DEBUG] Core|Input 모듈 초기화완료"));
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}


 


void UCoreInputModuleManager::Initialized()
{
	/* 하위 모듈들을 초기화합니다 */
	InputSettingManager = CreateDefaultSubobject<UInputSettingManager>
							(UInputSettingManager::StaticClass()->GetFName());
	EditorInterpreterManager = CreateDefaultSubobject<UEditorInterpreterManager>
							(UEditorInterpreterManager::StaticClass()->GetFName());
	 
	  

	/* 하위 모듈들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(InputSettingManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UInputSettingManager::StaticClass()->GetName());
		return;
	}
	if (IsValid(EditorInterpreterManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UEditorInterpreterManager::StaticClass()->GetName());
		return;
	}
}





UCoreInputModuleManager * UCoreInputModuleManager::GetGlobalCoreInputModuleManager()
{
	for (const auto& it : TObjectRange<UCoreInputModuleManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UCoreInputModuleManager::StaticClass()->GetName());
	return nullptr;
}