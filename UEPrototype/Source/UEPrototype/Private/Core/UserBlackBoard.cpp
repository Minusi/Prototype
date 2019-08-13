// Fill out your copyright notice in the Description page of Project Settings.

#include "UserBlackBoard.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "EngineUtils.h"
#include "Core/EditorWorldManager.h"
#include "Core/PlayerTaskManager.h"



// Sets default values
AUserBlackBoard::AUserBlackBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}



// Called when the game starts or when spawned
void AUserBlackBoard::BeginPlay()
{
	Super::BeginPlay();

	
	/* 캐시하기 위해 참조하고 유효성을 검사합니다. */
	EditorWorldManager = AEditorWorldManager::GetGlobalEditorWorldManager(this);
	if (IsValid(EditorWorldManager) == false)
	{
		return;
	}
	PlayerTaskManager = UPlayerTaskManager::GetGlobalPlayerTaskManager();
	if (IsValid(PlayerTaskManager) == false)
	{
		return;
	}
}





AUserBlackBoard* AUserBlackBoard::GetGlobalUserBlackBoard(UObject * WorldContextObject)
{
	/* 월드 컨텍스트 객체를 얻어 AUserBlackBoard를 찾습니다. */
	for (const auto& it : TActorRange<AUserBlackBoard>(WorldContextObject->GetWorld()))
	{
		return it;
	}

	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *AUserBlackBoard::StaticClass()->GetName());
	return nullptr;
}





EActorConstraintState AUserBlackBoard::GetPointedActorConstraintState() const
{
	return PlayerTaskManager->GetActorConstraintState(PointedActor);
}



FActorPlaceContent AUserBlackBoard::GetPointedActorPlaceContent() const
{
	FActorPlaceContent ActorPlaceContent;
	EditorWorldManager->GetActorPlaceContent(PointedActor, ActorPlaceContent);
	return ActorPlaceContent;
}



EActorConstraintState AUserBlackBoard::GetFocusedActorConstraintState() const
{
	return PlayerTaskManager->GetActorConstraintState(FocusedActor);
}



FActorPlaceContent AUserBlackBoard::GetFocusedActorPlaceContent() const
{
	FActorPlaceContent ActorPlaceContent;
	EditorWorldManager->GetActorPlaceContent(FocusedActor, ActorPlaceContent);
	return ActorPlaceContent;
}







void AUserBlackBoard::SetTeleportPosition(FVector InPosition)
{
	TeleportPosition = InPosition;
}



void AUserBlackBoard::SetPointedActor(AActor * InActor)
{
	PointedActor = InActor;
}



void AUserBlackBoard::SetFocusedActor(AActor * InActor)
{
	FocusedActor = InActor;
}
