// Fill out your copyright notice in the Description page of Project Settings.

#include "Tool/ToolKit.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "VPFrameworkLibrary.h"
#include "Tool/ToolModuleManager.h"
#include "Tool/ToolManager.h"
#include "Tool/ToolBase.h"



UToolKit::UToolKit()
{
	// DEBUG : 생성자 로그
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}

	/* 상위 모듈을 불러와서 이벤트에 함수들을 바인드합니다 */
	UToolModuleManager* ToolModuleManager = UToolModuleManager::GetGlobalToolModuleManager();
	if (IsValid(ToolModuleManager) == false)
	{
		return;
	}
	FEventToRegister Event;
	Event.BindUFunction(this, "BindToEvents");
	ToolModuleManager->RegisterIf(Event);
}



UToolKit * UToolKit::GetGlobalToolKit()
{
	for (const auto& it : TObjectRange<UToolKit>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UToolKit::StaticClass()->GetName());
	return nullptr;
}



void UToolKit::BindToEvents()
{
	UToolManager* ToolManager = UToolManager::GetGlobalToolManager();
	if (IsValid(ToolManager) == false)
	{
		return;
	}

	/* 이벤트 디스패처에 바인딩합니다 */
	ToolManager->OnToolEquipped().AddDynamic(this, &UToolKit::SetToolEnabled);
	ToolManager->OnToolUnequipped().AddDynamic(this, &UToolKit::SetToolUnenabled);
}





bool UToolKit::IsAvaliable(const UToolBase * Tool)
{
	/* 도구의 유효성을 검사합니다 */
	if (IsValid(Tool) == false)
	{
		VP_LOG(Warning, TEXT("확인하려는 도구가 유효하지 않습니다."));
		return false;
	}

	/* 도구가 컨테이너에 있는지 확인합니다 */
	if (ToolList.Contains(Tool) == false)
	{
		VP_LOG(Warning, TEXT("확인하려는 도구가 컨테이너에 존재하지 않습니다 : %s."), *Tool->GetName());
		return false;
	}

	/* 도구의 사용가능 여부를 반환합니다 */
	return *ToolList.Find(Tool);
}

void UToolKit::SetToolAvailable(UToolBase * Tool, bool bAvailable)
{
	/* 도구의 유효성을 검사합니다. */
	if (IsValid(Tool) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UToolBase::StaticClass()->GetName());
		return;
	}

	/* 도구가 컨테이너에 있는지 확인합니다 */
	if (ToolList.Contains(Tool) == false)
	{
		VP_LOG(Warning, TEXT("확인하려는 도구가 컨테이너에 존재하지 않습니다 : %s."), *Tool->GetName());
		return;
	}
	else
	{
		ToolList.Add(Tool, bAvailable);
	}
}

void UToolKit::SetToolEnabled(UToolBase * Tool)
{
	SetToolAvailable(Tool, true);
}

void UToolKit::SetToolUnenabled(UToolBase * Tool)
{
	SetToolAvailable(Tool, false);
}
