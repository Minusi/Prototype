// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorModulesManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"
#include "CoreInputModuleManager.h"
#include "ActorInfoModuleManager.h"



UEditorModulesManager::UEditorModulesManager()
{
	// DEBUG
	VP_CTOR;

	bInitialized = false;
	/* 월드 컨텍스트를 포함하지 않는 CDO는 프레임워크에서 필요로 하지 않는 CDO이므로,
	더이상의 초기화를 수행하지 않습니다 */
	if (ContainWorldContextCDO() == false)
	{
		return;
	}



	/* 초기화합니다 */
	Initialized();

	/* 모든 하위 모듈의 초기화가 완료되었음을 브로드캐스트합니다. */
	bInitialized = true;
	ModuleEndInitEventDispatcher.Broadcast();
}





void UEditorModulesManager::Initialized()
{
	/* CoreInputModuleManager를 생성합니다 */
	CoreInputModuleManager = CreateDefaultSubobject<UCoreInputModuleManager>
								(UCoreInputModuleManager::StaticClass()->GetFName());
	/* ActorInfoModuleManager를 생성합니다 */
	ActorInfoModuleManager = CreateDefaultSubobject<UActorInfoModuleManager>
								(UActorInfoModuleManager::StaticClass()->GetFName());



	/* 하위 모듈들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(CoreInputModuleManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCoreInputModuleManager::StaticClass()->GetName());
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
		if (it->ContainWorldContextCDO())
		{
			return it;
		}
	}

	/* 유효하지 않다면, 시스템에 결함이 있습니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *AEditorWorldManager::StaticClass()->GetName());
	return nullptr;
}





bool UEditorModulesManager::ContainWorldContextCDO()
{
	/* OuterChain을 거슬러 올라가면서, AEditorWorldManager가 있는지 탐색합니다 */
	UObject* OuterChain = this;
	while ((OuterChain = OuterChain->GetOuter()) != nullptr)
	{
		/* OuterChain에 AEditorWorldManager가 있으면 참을 반환합니다. */
		if (OuterChain->GetClass() == AEditorWorldManager::StaticClass())
		{
			return true;
		}
	}

	return false;
}
