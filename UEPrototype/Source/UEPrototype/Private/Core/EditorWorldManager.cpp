// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorWorldManager.h"
#include "UEPrototype.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "EditorModulesManager.h"

// DEBUG
#include "Command/HighlightCommand.h"



// Sets default values
AEditorWorldManager::AEditorWorldManager()
{
	// DEBUG
	VP_CTOR;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/* 모듈 최상위 관리자를 생성합니다 */
	EditorModulesManager = CreateDefaultSubobject<UEditorModulesManager>(MakeUniqueObjectName(this, UEditorModulesManager::StaticClass()));
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Error, TEXT("%s가 유효하지 않습니다. 생성에 실패했을 수 있습니다."), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}

	FEventToRegister Event;
	Event.BindUFunction(this, "BindToEvents");
	EditorModulesManager->RegisterIf(Event);
}





bool AEditorWorldManager::IsActorBlocked(const AActor * InTarget) const
{
	/* 액터 인자의 유효성을 검사합니다 */
	if (IsValid(InTarget) == false)
	{
		VP_LOG(Warning, TEXT("입력받은 InTarget 인자가 유효하지 않습니다"));
		return false;
	}

	/* 배열에서 해당 액터를 수색합니다 */
	EActorConstraintState TargetState = EActorConstraintState::CSTR_None;
	for (const auto& it : BlockedActors)
	{
		if (it.Target == InTarget)
		{
			TargetState = it.TargetState;
			break;
		}
	}

	/* Blocked 상태이면 참을 반환합니다 */
	if (TargetState == EActorConstraintState::CSTR_Blocked)
	{
		return true;
	}

	return false;
}





void AEditorWorldManager::GetActorPlaceContent(const AActor * InTarget, FActorPlaceContent& OutContent) const
{
	/* 액터 인자의 유효성을 검사합니다 */
	if (IsValid(InTarget) == false)
	{
		VP_LOG(Warning, TEXT("입력받은 InTarget 인자가 유효하지 않습니다"));
		return;
	}

	/* 컨테이너에서 해당 액터를 수색합니다 */
	for (const auto& it : ActorsPlaceInfo)
	{
		if (InTarget == it.Target)
		{
			OutContent = it.TargetContent;
			break;
		}
	}
}





void AEditorWorldManager::BindToEvents()
{
	/* ActorConstraintMarker를 얻어옵니다 */
	UActorConstraintMarker* ActorConstraintMarker =
		UActorConstraintMarker::GetGlobalActorConstraintMarker();
	if (IsValid(ActorConstraintMarker) == false)
	{
		return;
	}
	
	/* 이벤트에 함수를 바인딩합니다 */
	ActorConstraintMarker->OnActorConstraintChanged().AddDynamic(this, &AEditorWorldManager::UpdateBlockedActors);



	/* ActorPlaceInfoMarker를 얻어옵니다 */
	UActorPlaceInfoMarker* ActorPlaceInfoMarker =
		UActorPlaceInfoMarker::GetGlobalActorPlaceInfoMarker();
	if (IsValid(ActorPlaceInfoMarker) == false)
	{
		return;
	}

	/* 이벤트에 함수를 바인딩합니다. */
	ActorPlaceInfoMarker->OnActorPlaceInfoMark().AddDynamic(this, &AEditorWorldManager::UpdateActorsPlaceInfo);
}



void AEditorWorldManager::UpdateBlockedActors(FActorConstraintInfo ChangedInfo)
{
	if (IsValid(ChangedInfo.Target) == false)
	{
		VP_LOG(Warning, TEXT("브로드캐스트된 액터가 유효하지 않습니다."));
		return;
	}
	
	/* BlockedActor 컨테이너에 쿼리를 던지기 위해 새로 구성합니다 */
	FActorConstraintInfo QueryBlocked;
	QueryBlocked.Target = ChangedInfo.Target;
	QueryBlocked.TargetState = EActorConstraintState::CSTR_Blocked;
	


	/* 해당 액터가 컨테이너에 존재하고 Blocked가 아니게 된다는 이벤트를 수신
		받았다면, 삭제합니다 */
	if (BlockedActors.Contains(QueryBlocked)
		&& ChangedInfo.TargetState != EActorConstraintState::CSTR_Blocked)
	{
		BlockedActors.Remove(QueryBlocked);

		/* 삭제되었음을 알리는 이벤트를 브로드캐스트합니다 */
		BlockedActorRemovedEventDispatcher.Broadcast(ChangedInfo.Target);
		return;
	}



	
	/* 해당 액터가 컨테이너에 존재하지 않고 Blocked이게 된다는 이벤트를 수신
		받았다면, 추가합니다 */
	if (BlockedActors.Contains(QueryBlocked) == false
		&& ChangedInfo.TargetState == EActorConstraintState::CSTR_Blocked)
	{
		BlockedActors.Add(QueryBlocked);

		/* 추가되었음을 알리는 이벤트를 브로드캐스트합니다 */
		BlockedActorAddedEventDispatcher.Broadcast(ChangedInfo.Target);
		return;
	}


	/* 이번 이벤트는 EditorWorldManager에서 무시해도 되는 이벤트입니다 */
	VP_LOG(Log, TEXT("해당 액터는 처리 대상이 아닙니다 : Actor(%s), State(%d)"),
		*ChangedInfo.Target->GetName(), (uint8)(ChangedInfo.TargetState));
	return;
}



void AEditorWorldManager::UpdateActorsPlaceInfo(FActorPlaceInfo ChangedPlaceInfo)
{
	/* 액터가 유효한지 검사합니다. */
	if (IsValid(ChangedPlaceInfo.Target) == false)
	{
		VP_LOG(Warning, TEXT("브로드캐스트된 액터가 유효하지 않습니다."));
		return;
	}


	
	/* 해당 액터가 월드에 배치되어 있는지 확인합니다. */
	for (auto& it : ActorsPlaceInfo)
	{
		/* 액터가 월드에 존재한다면, 해당 액터의 배치 정보를 갱신합니다. */
		if (it.Target == ChangedPlaceInfo.Target)
		{
			/* 만약 액터가 삭제됨으로써 발생한 정보라면 삭제합니다.*/
			if (IsValid(it.TargetContent.Type) == false)
			{
				ActorsPlaceInfo.Remove(it);
				return;
			}
			/* 그 외의 경우, 변경된 내용을 업데이트합니다. */
			else
			{
				it.TargetContent = ChangedPlaceInfo.TargetContent;
				return;
			}
		}
	}

	/* 액터과 월드에 존재하지 않는다면, 해당 액터의 정보를 추가합니다. */
	ActorsPlaceInfo.Add(ChangedPlaceInfo);
}





AEditorWorldManager * AEditorWorldManager::GetGlobalEditorWorldManager(const UObject* WorldContextObject)
{
	/* 월드 컨텍스트 객체를 얻어 AEditorWorldManager를 찾습니다. */
	for (const auto& it : TActorRange<AEditorWorldManager>(WorldContextObject->GetWorld()))
	{
		return it;
	}

	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *AEditorWorldManager::StaticClass()->GetName());
	return nullptr;
}
