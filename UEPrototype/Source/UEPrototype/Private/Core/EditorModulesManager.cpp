// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorModulesManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"
#include "CoreInputModuleManager.h"
#include "CorePlayerModuleManager.h"
#include "ActorInfoModuleManager.h"



UEditorModulesManager::UEditorModulesManager()
{
	// DEBUG
	VP_CTOR;

	bInitialized = false;
	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}



	/* 초기화합니다 */
	Initialized();

	/* 모든 하위 모듈의 초기화가 완료되었음을 브로드캐스트합니다. */
	// DEBUG
	VP_LOG(Warning, TEXT("[DEBUG] 모든 모듈 초기화완료"));
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}





void UEditorModulesManager::Initialized()
{
	/* CoreInputModuleManager를 생성합니다 */
	CoreInputModuleManager = CreateDefaultSubobject<UCoreInputModuleManager>
								(UCoreInputModuleManager::StaticClass()->GetFName());
	/* CorePlayerModuleManager를 생성합니다 */
	CorePlayerModuleManager = CreateDefaultSubobject<UCorePlayerModuleManager>
								(UCorePlayerModuleManager::StaticClass()->GetFName());
	/* ActorInfoModuleManager를 생성합니다 */
	ActorInfoModuleManager = CreateDefaultSubobject<UActorInfoModuleManager>
								(UActorInfoModuleManager::StaticClass()->GetFName());



	/* 하위 모듈들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(CoreInputModuleManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCoreInputModuleManager::StaticClass()->GetName());
	}
	if (IsValid(CorePlayerModuleManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCorePlayerModuleManager::StaticClass()->GetName());
	}
	if (IsValid(ActorInfoModuleManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UActorInfoModuleManager::StaticClass()->GetName());
	}
}





UEditorModulesManager * UEditorModulesManager::GetGlobalEditorModulesManager()
{
	for (const auto& it : TObjectRange<UEditorModulesManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}

	/* 유효하지 않다면, 시스템에 결함이 있습니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *AEditorWorldManager::StaticClass()->GetName());
	return nullptr;
}