// Fill out your copyright notice in the Description page of Project Settings.

#include "VPGameStateBase.h"
#include "UEPrototype.h"

// DEBUG
#include "UObjectIterator.h"
#include "CoreInputModuleManager.h"
#include "EditorInterpreterManager.h"
#include "MinusiFrameworkLibrary.h"



void AVPGameStateBase::BeginPlay()
{
	FActorSpawnParameters ActorSpawnParams;
	EditorWorldManagerCache = GetWorld()->SpawnActor<AEditorWorldManager>(ActorSpawnParams);

	/* 스폰 후 유효성 검사를 수행합니다 */
	if (IsValid(EditorWorldManagerCache) == false)
	{
		VP_LOG(Error, TEXT("유효하지 않습니다. 월드에 스폰되지 않았을 수 있습니다 : %s."), *AEditorWorldManager::StaticClass()->GetName());
		return;
	}

	

	for (const auto& it : TObjectRange<UCoreInputModuleManager>())
	{
		// DEBUG
		UMinusiFrameworkLibrary::GetInfoWithOuterChain(it);
	}
}



void AVPGameStateBase::SetWorldState(EWorldState InWorldState)
{
	WorldState = InWorldState;

	/* 월드 상태가 변했음을 브로드캐스틍합니다 */
	WorldStateChangedEventDispatcher.Broadcast(InWorldState);
}