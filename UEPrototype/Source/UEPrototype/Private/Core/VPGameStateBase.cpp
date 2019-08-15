// Fill out your copyright notice in the Description page of Project Settings.

#include "VPGameStateBase.h"
#include "UEPrototype.h"

// DEBUG
#include "MinusiFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"



AVPGameStateBase::AVPGameStateBase()
{
	VP_CTOR;
	
	FActorSpawnParameters SpawnParams;

	// TODO : 핫 리로드 시 유효하지 않다고 뜨지만, 플레이 시에는 유효하다고 뜸. 여기에 대한
	// 관련 레퍼런스를 보충하기 전까지는 잠재적 버그의 대상으로 간주합니다.
	if (IsValid(GetWorld()) == false)
	{
		VP_LOG(Warning, TEXT("[Marked] 월드가 유효하지 않습니다."));
		return;
	}

	AEditorWorldManager* Spawned = GetWorld()->SpawnActor<AEditorWorldManager>(SpawnParams);
	if (IsValid(Spawned) == false)
	{
		VP_LOG(Error, TEXT("[Marked] 액터 %s를 스폰하는 데 실패하였습니다."), *AEditorWorldManager::StaticClass()->GetName());
		return;
	}
}



void AVPGameStateBase::BeginPlay()
{
	Super::BeginPlay();
}



void AVPGameStateBase::SetWorldState(EWorldState InWorldState)
{
	WorldState = InWorldState;

	/* 월드 상태가 변했음을 브로드캐스틍합니다 */
	WorldStateChangedEventDispatcher.Broadcast(InWorldState);
}