// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorModulesManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "CoreInputModuleManager.h"



UEditorModulesManager::UEditorModulesManager()
{
	initialized();
}



void UEditorModulesManager::Initialized()
{
	/* CoreInputModuleManager를 생성합니다 */
	CoreInputModuleManager = CreateDefaultSubobject<UCoreInputModuleManager>
								(MakeUniqueObjectName(this, UCoreInputModuleManager::StaticClass()));



	/* 하위 모듈들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(CoreInputModuleManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCoreInputModuleManager::StaticClass()->GetName());
	}
}



UCoreInputModuleManager * UEditorModulesManager::GetCoreInputModuleManager(UObject * WorldContextObject)
{
	/* World Context Object의 유효성을 검사합니다 */
	if (IsValid(WorldContextObject) == false)
	{
		VP_LOG(Warning, TEXT("World Context Object가 유효하지 않습니다"));
		return nullptr;
	}
	
	/* UCoreInputModuleManager를 수색하여 1번째 결과물을 반환합니다 */
	for (const auto& it : TObjectRange<UCoreInputModuleManager>())
	{
		return it;
	}

	return nullptr;
}

