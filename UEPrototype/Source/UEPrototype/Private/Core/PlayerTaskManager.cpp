// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerTaskManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"
#include "EditorModulesManager.h"

UPlayerTaskManager::UPlayerTaskManager()
{
	// DEBUG
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}

	/* 상위 모듈을 받아, 이벤트 바인딩을 수행합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		return;
	}
	FEventToRegister Event;
	Event.BindUFunction(this, "BindToEvents");
	EditorModulesManager->RegisterIf(Event);
}

UPlayerTaskManager * UPlayerTaskManager::GetGlobalPlayerTaskManager()
{
	for (const auto& it : TObjectRange<UPlayerTaskManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}

	/* 존재하지 않는다면 시스템에 큰 결함이 있다는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UPlayerTaskManager::StaticClass()->GetName());
	return nullptr;
}

bool UPlayerTaskManager::IsInteractedActor(AActor * Target) const
{
	if (IsValid(Target) == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 액터입니다"));
		return false;
	}

	/* 컨테이너에 Actor가 있으면 반환합니다 */
	for (const auto& it : InteractedActorsInfo)
	{
		if (it.Target == Target)
		{
			return true;
		}
	}

	return false;
}

void UPlayerTaskManager::BindToEvents()
{
	/* ActorConstraintMarker를 얻어옵니다 */
	UActorConstraintMarker* ActorConstraintMarker =
		UActorConstraintMarker::GetGlobalActorConstraintMarker();
	if (IsValid(ActorConstraintMarker) == false)
	{
		return;
	}

	/* 이벤트에 함수를 바인딩합니다 */
	ActorConstraintMarker->OnActorConstraintChanged().AddDynamic(this, &UPlayerTaskManager::UpdateActorInteracted);
}
// TODO : 고쳐야 할게 많은 함수입니다. Unfocus 부분과 highlight된 상태의 actor에대해 focus상태도 적용됩니다.
void UPlayerTaskManager::UpdateActorInteracted(FActorConstraintInfo Target)
{
	/* 액터의 유효성을 검사합니다 */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("대상 액터가 유효하지 않습니다"));
		return;
	}

	// TODO : 두 개 일떄는 나중에처리하는걸로

	for (auto& it : InteractedActorsInfo)
	{
		if ((it.TargetState == EActorConstraintState::CSTR_Focused) && (it.Target != Target.Target))
		{
			VP_LOG(Warning, TEXT("t.target(PlayerTask) : %s , t.targetState(PlayerTask) : %d"),
				*it.Target->GetName(), (int)it.TargetState);
			it.TargetState = EActorConstraintState::CSTR_Unfocused;
			RemoveActorInteracted(it);
		}

		if (it.TargetState == EActorConstraintState::CSTR_Activated)
		{
			if (Target.TargetState == EActorConstraintState::CSTR_Unfocused)
			{
				it.TargetState = EActorConstraintState::CSTR_Unfocused;
				RemoveActorInteracted(it);
			}
			else if (Target.TargetState == EActorConstraintState::CSTR_Focused)
			{
				it.TargetState = EActorConstraintState::CSTR_Focused;
				ChangeActorInteracted(it);
			}
		}
	}

	bool bInteracted = InteractedActorsInfo.Contains(Target);

	/* 액터의 제약조건의 유효성을 검사합니다 */
	if (Target.TargetState == EActorConstraintState::CSTR_None)
	{
		VP_LOG(Warning, TEXT("상호작용 중이지 않은 액터에 유효하지 않은 제약 조건입니다 : %s"), *Target.Target->GetName());
		return;
	}

	/* 컨테이너에 없지만 상태는 유효할 경우 추가합니다 */
	if (bInteracted == false)
	{
		AddActorInteracted(Target);
	}

	/* 컨테이너에 존재하면서, Unfocused가 아닌 경우 변경합니다 */
	if (bInteracted == true && Target.TargetState != EActorConstraintState::CSTR_Unfocused)
	{
		ChangeActorInteracted(Target);
	}

	/* 컨테이너에 존재하면서, Unfocused인 경우 제거합니다 */
	if (bInteracted == true && Target.TargetState == EActorConstraintState::CSTR_Unfocused)
	{
		RemoveActorInteracted(Target);
	}
}

void UPlayerTaskManager::AddActorInteracted(FActorConstraintInfo Target)
{
	/* 액터가 유효한지 검사합니다 */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("액터가 유효하지 않습니다."));
		return;
	}

	/* 액터의 상태가 유효한지 검사합니다 */
	if (Target.TargetState == EActorConstraintState::CSTR_None)
	{
		VP_LOG(Warning, TEXT("액터의 상태가 유효하지 않습니다 : %s."), *Target.Target->GetName());
		return;
	}

	/* 액터의 상태가 Unfocued인지 검사합니다 */
	if (Target.TargetState == EActorConstraintState::CSTR_Unfocused)
	{
		// TODO : 나중에 주석을 풀어주세요
		//VP_LOG(Warning, TEXT("상호작용 중이지 않은 Unfocused 액터를 추가할 수 없습니다 : %s."), *Target.Target->GetName());
		return;
	}

	/* 이미 액터가 컨테이너에 존재하면 안됩니다 */
	if (InteractedActorsInfo.Contains(Target) == true)
	{
		VP_LOG(Warning, TEXT("이미 상호작용 중인 액터입니다. 상태의 변경을 원한다면, \
			ChangeActorInteracted 함수를 사용하시길 바랍니다."));
		return;
	}

	/* 추가합니다 */
	InteractedActorsInfo.Add(Target);
	InteractedActorAddedEventDispatcher.Broadcast(Target);
}

void UPlayerTaskManager::RemoveActorInteracted(FActorConstraintInfo Target)
{
	/* 액터가 유효한지 검사합니다 */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("액터가 유효하지 않습니다."));
		return;
	}

	/* 액터의 상태가 유효한지 검사합니다 */
	if (Target.TargetState == EActorConstraintState::CSTR_None)
	{
		VP_LOG(Warning, TEXT("액터의 상태가 유효하지 않습니다 : %s."), *Target.Target->GetName());
		return;
	}

	/* 액터의 상태가 Unfocued인지 검사합니다 */
	if (Target.TargetState != EActorConstraintState::CSTR_Unfocused)
	{
		VP_LOG(Warning, TEXT("상호작용 중인 Non-Unfocused 액터를 제거할 수 없습니다 : %s."), *Target.Target->GetName());
		return;
	}

	/* 현재 컨테이너에 Target이 있는지 확인합니다 */
	if (InteractedActorsInfo.Contains(Target) == false)
	{
		VP_LOG(Warning, TEXT("삭제하려는 대상이 컨테이너에 없습니다 : %s."), *Target.Target->GetName());
		return;
	}

	/* 삭제합니다. */

	InteractedActorsInfo.Remove(Target);
	InteractedActorRemovedEventDispatcher.Broadcast(Target.Target);
}

void UPlayerTaskManager::RemoveActorInteractedWithoutState(AActor * Target)
{
	/* 액터가 유효한지 검사합니다 */
	if (IsValid(Target) == false)
	{
		VP_LOG(Warning, TEXT("액터가 유효하지 않습니다."));
		return;
	}

	/* 컨테이너에 해당 액터가 있는지 확인합니다 */
	for (const auto& it : InteractedActorsInfo)
	{
		/* 있으면 삭제하고 브로드캐스트합니다 */
		if (it.Target == Target)
		{
			InteractedActorsInfo.Remove(it);
			InteractedActorRemovedEventDispatcher.Broadcast(Target);
			return;
		}
	}

	/* 없으면 경고를 출력합니다 */
	VP_LOG(Warning, TEXT("삭제하려는 액터가 컨테이너에 존재하지 않습니다 : %s."), *Target->GetName());
	return;
}

void UPlayerTaskManager::ChangeActorInteracted(FActorConstraintInfo Target)
{
	/* 액터가 유효한지 검사합니다 */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("액터가 유효하지 않습니다."));
		return;
	}

	/* 액터의 상태가 유효한지 검사합니다 */
	if (Target.TargetState == EActorConstraintState::CSTR_None)
	{
		VP_LOG(Warning, TEXT("액터의 상태가 유효하지 않습니다 : %s"), *Target.Target->GetName());
		return;
	}

	/* 액터의 상태가 Unfocued인지 검사합니다 */
	if (Target.TargetState == EActorConstraintState::CSTR_Unfocused)
	{
		VP_LOG(Warning, TEXT("상호작용 중인 액터가 Unfocused일 때 이 함수를  \
				경유해서는 안됩니다 : %s."), *Target.Target->GetName());
		return;
	}

	/* 액터의 상태를 변경합니다 */
	for (auto& it : InteractedActorsInfo)
	{
		if (it == Target)
		{
			it.TargetState = Target.TargetState;

			return;
		}
	}

	/* 없으면 경고를 출력합니다 */
	VP_LOG(Warning, TEXT("변경하려는 액터가 컨테이너에 존재하지 않습니다 : %s."), *Target.Target->GetName());
	return;
}

EActorConstraintState UPlayerTaskManager::GetActorConstraintState(AActor * Target) const
{
	if (IsValid(Target) == false)
	{
		// TODO : 나중에 주석을 풀어주세요. 너무 방해되서 지어놓음.
		//VP_LOG(Warning, TEXT("유효하지 않은 액터입니다"));
		return EActorConstraintState::CSTR_None;
	}

	/* 컨테이너에 Actor가 있으면 상태를 반환합니다 */
	for (const auto& it : InteractedActorsInfo)
	{
		if (it.Target == Target)
		{
			return it.TargetState;
			InteractedActorsInfo;
		}
	}

	return EActorConstraintState::CSTR_None;
}