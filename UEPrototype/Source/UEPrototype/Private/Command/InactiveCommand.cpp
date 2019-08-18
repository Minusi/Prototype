// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/InactiveCommand.h"
#include "Command/FocusCommand.h"
#include "UEPrototype.h"
#include "Core/EditorModulesManager.h"
#include "Command/ActorCommandFactory.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "ActorInfo/Outliner.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "Core/UserBlackBoard.h"



UActorConstraintMarker* UInactiveCommand::ActorConstraintMarker = nullptr;
UOutliner* UInactiveCommand::Outliner = nullptr;
AUserBlackBoard* UInactiveCommand::UserBlackBoard = nullptr;


UInactiveCommand::UInactiveCommand()
{
	// DEBUG : 생성자 로깅
	VP_CTOR;

	/* 컨스트레인트르를 가져오기 위해 제약 조건 매니저를 가져옵니다.
	엔진이 처음 로드될 때 에러를 유발하지만, 모듈 초기화 시에 같이 초기화될 필요
	없으므로 무시해도 됩니다. */
	UCommandConstraintManager* CommandConstraintManager = UCommandConstraintManager::GetGlobalCommandConstraintManager();
	if (IsValid(CommandConstraintManager) == false)
	{
		return;
	}

	/* 활성화 제약조건의 유효성을 검사합니다. */
	UCmdActivatedConstraint* ActivatedConstraint = CommandConstraintManager->GetCmdActivatedConstraint();
	if (IsValid(ActivatedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdActivatedConstraint::StaticClass()->GetName());
		return;
	}

	/* 포커스 제약 조건을 추가합니다. */
	Constraints.Add(ActivatedConstraint);






	/* 이미 초기화되어 있으면 생략합니다 */
	if ((ActorConstraintMarker->IsValidLowLevel())
		&& Outliner->IsValidLowLevel())
	{
		VP_LOG(Log, TEXT("HighlightCommand의 이미 유효합니다."));
		return;
	}
	VP_LOG(Log, TEXT("%s의 멤버가 유효하지 않으므로 초기화를 수행합니다."), *UInactiveCommand::StaticClass()->GetName());

	/* 초기화하는 데 필요한 객체를 가지고 있는 모듈의 유효성을 검사합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}





	/* 초기화를 수행합니다. */
	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();
	Outliner = UOutliner::GetGlobalOutliner();
	UserBlackBoard = AUserBlackBoard::GetGlobalUserBlackBoard(this);



	/* 초기화된 객체들에 대한 유효성 검사를 실행합니다. */
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_INVALID_WARNING(UActorConstraintMarker);
		return;
	}
	if (IsValid(Outliner) == false)
	{
		VP_INVALID_WARNING(UOutliner);
		return;
	}
	if (IsValid(UserBlackBoard) == false)
	{
		VP_INVALID_WARNING(AUserBlackBoard);
		return;
	}
	if (Constraints.Num() == 0)
	{
		VP_LOG(Warning, TEXT("제약 조건이 설정되지 않았습니다. 제약 조건의 수 : %d"), Constraints.Num());
		return;
	}
}





void UInactiveCommand::ExecuteIf()
{
	/* 멤버 유효성을 검사합니다. */
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_INVALID_WARNING(UActorConstraintMarker);
		return;
	}
	if (IsValid(Outliner) == false)
	{
		VP_INVALID_WARNING(UOutliner);
		return;
	}

	/* 대상에 대한 유효성을 검사합니다. */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("명령의 대상 액터가 유효하지 않습니다."));
		return;
	}

	/* 명령이 제약조건을 만족하면 싪행합니다. */
	for (const auto& it : Constraints)
	{
		if (it->CheckConstraint(Target) == true)
		{
			/* 사용자가 이 액터를 보고 있으면, Focused 명령을 호출합니다. */
			if (UserBlackBoard->GetFocusedActor() == Target.Target)
			{
				Outliner->EraseActorOutline();
				UActorCommandFactory::CreateActorCommand<UFocusCommand>(Target)->ExecuteIf();
			}
			else
			{
				ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Unfocused);
				Outliner->EraseActorOutline();
			}
		}
	}
}





void UInactiveCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}
