// Fill out your copyright notice in the Description page of Project Settings.

#include "Tool/BasicTool.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "Core/VPDirectorPawn.h"
#include "Command/ActorCommandFactory.h"



UBasicTool::UBasicTool()
{
	// DEBUG : 생성자 로그
	VP_CTOR;



	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}



	/* 사용 가능한 기능과 요구 입력을 추가하여 매핑합니다. */
	// TODO : 매핑 작성할 것
}



UBasicTool * UBasicTool::GetGlobalBasicTool()
{
	for (const auto& it : TObjectRange<UBasicTool>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UBasicTool::StaticClass()->GetName());
	return nullptr;
}





UCommandBase * UBasicTool::HandleInput(FHighLevelInputData Input)
{
	/* High Level 입력에 대응되는 커맨드가 있는지 확인합니다. */
	FSubclassOfCommandBase Command;
	if (ActionAvailables.Contains(Input) == true)
	{
		Command = ActionAvailables.FindRef(Input);
	}

	// TODO : 현재는 액터 기반 커맨드만 존재하지만, 추후 다른 종류의
	// 생성되면 리팩토링을 요구로 함.
	/* 대응되는 커맨드가 없으면 종료합니다. */
	if (Command.CommandClass.Get() == nullptr)
	{
		return nullptr;
	}
	
	

	/* 대응되는 커맨드가 있으면 커맨드를 생성하기 위한 정보를 생성합니다. */
	// TODO : 구현할 것

	return nullptr;
}