// Fill out your copyright notice in the Description page of Project Settings.

#include "Tool/ToolManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "VPFrameworkLibrary.h"
#include "Tool/ToolModuleManager.h"
#include "Tool/ToolKit.h"
#include "Tool/ToolBase.h"



UToolManager::UToolManager()
{
	// DEBUG
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}



	/* 상위 모듈을 불러와서 이벤트에 함수들을 바인딩합니다 */
	UToolModuleManager* ToolModuleManager
		= UToolModuleManager::GetGlobalToolModuleManager();
	if (IsValid(ToolModuleManager) == false)
	{
		return;
	}

	FEventToRegister Event;
	Event.BindUFunction(this, "BindToEvents");
	ToolModuleManager->RegisterIf(Event);
}



UToolManager * UToolManager::GetGlobalToolManager()
{
	for (const auto& it : TObjectRange<UToolManager>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UToolManager::StaticClass()->GetName());
	return nullptr;
}





void UToolManager::EquipTool(UToolBase * Tool)
{
	/* ToolKit의 유효성을 검사합니다 */
	if (IsValid(ToolKit) == false)
	{
		VP_LOG(Warning, TEXT("도구가 유효하지 않습니다."));
		return;
	}

	/* 도구가 이미 장착 중이면 스킵합니다 */
	if (ToolKit->IsAvaliable(Tool) == false)
	{
		VP_LOG(Warning, TEXT("해당 도구가 이미 장착 중에 있습니다."));
		return;
	}

	/* 도구를 장착하고 브로드캐스트합니다. */
	EquippedTools.Add(Tool);
	ToolEquippedEventDispatcher.Broadcast(Tool);
}



void UToolManager::UnequipTool(UToolBase * Tool)
{
	/* ToolKit의 유효성을 검사합니다 */
	if (IsValid(ToolKit) == false)
	{
		VP_LOG(Warning, TEXT("도구가 유효하지 않습니다."));
		return;
	}

	/* 도구가 이미 장착 해제되어 있으면 스킵합니다 */
	if (ToolKit->IsAvaliable(Tool) == true)
	{
		VP_LOG(Warning, TEXT("해당 도구가 이미 장착 해제되어 있습니다."));
	}
	
	/* 도구를 장착해제하고 브로드캐스트합니다. */
	EquippedTools.Remove(Tool);
	ToolUnequippedEventDispatcher.Broadcast(Tool);
}



bool UToolManager::IsUsedTool(UToolBase * Tool)
{
	if (EquippedTools.Contains(Tool) &&
		(ToolKit->IsAvaliable(Tool) == false))
	{
		return true;
	}

	return false;
}





void UToolManager::BindToEvents()
{
	/* ToolKit을 가져옵니다 */
	ToolKit = UToolKit::GetGlobalToolKit();
	if (IsValid(ToolKit) == false)
	{
		return;
	}

	// TODO : 모든 도구들의 이벤트에 함수를 바인딩해야 합니다.
}





void UToolManager::BroadcastInput(FHighLevelInputData Input)
{
	/* 입력을 브로드캐스트합니다 */
	for (auto& it : EquippedTools)
	{
		it->HandleInput(Input);
	}
}