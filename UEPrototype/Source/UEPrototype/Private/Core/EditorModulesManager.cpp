// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorModulesManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "CoreInputModuleManager.h"



UEditorModulesManager::UEditorModulesManager()
{
	Initialized();
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



UEditorModulesManager * UEditorModulesManager::GetGlobalEditorModulesManager()
{
	for (const auto& it : TObjectRange<UEditorModulesManager>())
	{
		return it;
	}

	return nullptr;
}
