// Fill out your copyright notice in the Description page of Project Settings.

#include "Tool/BasicTool.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"
#include "Core/UserBlackBoard.h"
#include "Core/EditorModulesManager.h"
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



	/* 상위 모듈을 받아, 이벤트 바인딩을 수행합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		return;
	}
	FEventToRegister Event;
	Event.BindUFunction(this, "ModuleBeginPlay");
	EditorModulesManager->OnModuleBeginPlay().AddDynamic(this, &UBasicTool::ModuleBeginPlay);



	/* 커맨드들을 등록합니다. */
	RegisterCommands();
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





void UBasicTool::ModuleBeginPlay()
{
	/* 필요한 AActor 파생 클래스들을 참조합니다. */
	UserBlackBoard = AUserBlackBoard::GetGlobalUserBlackBoard(this);
	if (IsValid(UserBlackBoard) == false)
	{
		return;
	}
}





UCommandBase * UBasicTool::HandleInput(FHighLevelInputData Input)
{
	/* High Level 입력에 대응되는 커맨드가 있는지 확인합니다. */
	FSubclassOfCommandBase Command;
	if (ActionAvailables.Contains(Input) == true)
	{
		Command = ActionAvailables.FindRef(Input);
	}

	/* 대응되는 커맨드가 없으면 종료합니다. */
	if (Command.CommandClass.Get() == nullptr)
	{
		return nullptr;
	}
	
	

	/* 대응되는 커맨드가 있으면 커맨드를 생성하기 위한 정보를 생성합니다. */
	// TODO : 구현할 것

	return nullptr;
}



bool UBasicTool::HasTriggerableCommand(FHighLevelInputData Input)
{
	return false;
}



void UBasicTool::RegisterCommands()
{
	FHighLevelInputData InputData;
	FSubclassOfCommandBase Command;

	/* 활성화 커맨드 등록 */
	{
		InputData.MappingName = TEXT("MainFunction");
		InputData.InputMetadata = EInputMetadata::META_Click;
	
		Command.CommandClass = UActivateCommand::StaticClass();
		ActionAvailables.Add(InputData, Command);
	}

	/* 비활성화 커맨드 등록 */
	{
		//InputData.MappingName = TEXT("MainFunction");
		//InputData.InputMetadata = EInputMetadata::META_Click;

		// TODO : 비활성화 커맨드
	}

	{
		/*InputData.MappingName = TEXT("Cancel");
		InputData.InputMetadata = EInputMetadata::META_Click;*/
		
		// TODO : 취소 커맨드		
	}

	/* 텔레포트 커맨드 등록 */
	{
		InputData.MappingName = TEXT("Teleport");
		InputData.InputMetadata = EInputMetadata::META_Click;

	}
}
