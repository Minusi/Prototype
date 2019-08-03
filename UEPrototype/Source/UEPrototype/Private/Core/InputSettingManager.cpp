// Fill out your copyright notice in the Description page of Project Settings.

#include "InputSettingManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "GameFramework/InputSettings.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"



UInputSettings* UInputSettingManager::InputSettings = UInputSettings::GetInputSettings();



UInputSettingManager::UInputSettingManager()
{
	// DEBUG
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}



UInputSettingManager* UInputSettingManager::GetGlobalInputSettingManager()
{
	for (const auto& it : TObjectRange<UInputSettingManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}
	/* 유효하지 않으면 시스템에 큰 결합이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UInputSettingManager::StaticClass()->GetName());
	return nullptr;
}



void UInputSettingManager::AddActionMappings(FName NewActionName, const TArray<FInputActionKeyMapping>& NewActionKeyMappings)
{
	// InputSettings가 유효한지 검사합니다.
	if (IsValid(InputSettings) == false)
	{
		return;
	}

	// 유효하지 않은 키매핑이 섞여있는지 확인합니다.
	// 입력된 키매핑들은 모두 등록되거나, 모두 등록되지 않거나입니다.
	for (const auto& it : NewActionKeyMappings)
	{
		if (NewActionName != it.ActionName)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 액션 이름을 가진 키매핑이 유입되었습니다(%s). 입력된 액션 이름과 일치해야 합니다 : %s."), 
				*it.ActionName.ToString(), *NewActionName.ToString());
			return;
		}
	}

	// 추가합니다.
	for (const auto& it : NewActionKeyMappings)
	{
		InputSettings->AddActionMapping(it,false);
	}

	// DEBUG
	TArray<UObject*> sa = ActionAddedEventDispatcher.GetAllObjects();
	for (const auto& it : sa)
	{
		VP_LOG(Log, TEXT("이벤트 디스패처 목록 : %s"), *it->GetName());
	}

	// 액션 추가 이벤트에 대해 브로드캐스트합니다.
	ActionAddedEventDispatcher.Broadcast(NewActionName, NewActionKeyMappings);

	// 구독자들이 적절한 행동을 취한 후, 키맵을 빌드합니다.
	InputSettings->ForceRebuildKeymaps();
}



void UInputSettingManager::RemoveActionMappings(FName ExistActionName)
{
	/* InputSettings가 유효한지 검사합니다. */
	if (IsValid(InputSettings) == false)
	{
		return;
	}

	TArray<FInputActionKeyMapping> RemovedList;
	InputSettings->GetActionMappingByName(ExistActionName, RemovedList);

	/* 컨테이너의 요소가 존재하지 않으면, 해당 액션 이름이 없다는 의미입니다 */
	if (RemovedList.Num() == 0)
	{
		VP_LOG(Warning, TEXT("제거할 액션 이름이 존재하지 않습니다 : %s."),
			*ExistActionName.ToString());
		return;
	}
	
	/* 제거합니다. */
	for (const auto& it : RemovedList)
	{
		InputSettings->RemoveActionMapping(it,false);
	}

	/* 액션 삭제 이벤트에 대해 브로드캐스트합니다. */
	ActionRemovedEventDispatcher.Broadcast(ExistActionName);
	
	// 구독자들이 적절한 행동을 취한 후, 키맵을 빌드합니다.
	InputSettings->ForceRebuildKeymaps();
}



void UInputSettingManager::ChangeActionKeyMappings(FName TargetActionName, const TArray<FInputActionKeyMapping>& Removes, const TArray<FInputActionKeyMapping>& Adds)
{
	// InputSettings가 유효한지 검사합니다.
	if (IsValid(InputSettings) == false)
	{
		return;
	}

	TArray<FInputActionKeyMapping> TargetMappings;
	InputSettings->GetActionMappingByName(TargetActionName, TargetMappings);




	// 지워야할 키매핑들이 유효한 입력인지 검사합니다.
	for (const auto& it : Removes)
	{
		if (it.ActionName != TargetActionName)
		{
			VP_LOG(Warning, TEXT("유효하지 액션 이름을 가진 키매핑이 유입되었습니다 : %s, 다음 이름을 가져야 합니다 : %s."), *it.ActionName.ToString(), *TargetActionName.ToString());
			return;
		}

		bool bMatched = false;

		for (const auto& jt : TargetMappings)
		{
			// 지워야할 키가 입력 매핑 배열에 존재하면 유효하다는 의미입니다.
			if (it == jt)
			{
				bMatched = true;
				break;
			}
		}

		// 지워야할 키가 입력 매핑 배열에 존재하지 않을 때 예외처리를 수행합니다.
		if (bMatched == false)
		{
			VP_LOG(Warning, TEXT("지우고자 하는 키가 입력 매핑에 존재하지 않습니다 : %s."), *it.Key.GetDisplayName().ToString());
			return;
		}
	}

	// 추가할 키매핑들이 유효한 입력인지 검사합니다.
	for (const auto& it : Adds)
	{
		if (it.ActionName != TargetActionName)
		{
			VP_LOG(Warning, TEXT("유효하지 액션 이름을 가진 키매핑이 유입되었습니다 : %s, 다음 이름을 가져야 합니다 : %s."), *it.ActionName.ToString(), *TargetActionName.ToString());
			return;
		}

		bool bMatched = false;

		for (const auto& jt : TargetMappings)
		{
			// 추가할 키가 입력 매핑 배열에 존재하면 유효하지 않으므로 예외처리를 수행합니다.
			if (it.Key == jt.Key
				&& it.bAlt == jt.bAlt
				&& it.bCmd == jt.bCmd
				&& it.bCtrl == it.bCtrl
				&& it.bShift == it.bShift)
			{
				VP_LOG(Warning, TEXT("추가하고자 하는 키가 이미 입력 매핑에 존재합니다 : %s"), *it.Key.GetDisplayName().ToString());
				return;
			}
		}
	}

	

	// 제거 및 추가 작업을 수행합니다.
	for (const auto& it : Removes)
	{
		InputSettings->RemoveActionMapping(it, false);
	}
	for (const auto& it : Adds)
	{
		InputSettings->AddActionMapping(it, false);
	}

	// 키 변경 이벤트를 브로드캐스트합니다.
	ActionKeyChangedEventDispatcher.Broadcast(TargetActionName, Removes, Adds);
	
	// 매핑 설정을 강제로 리빌드합니다.
	InputSettings->ForceRebuildKeymaps();
}