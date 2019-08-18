// Fill out your copyright notice in the Description page of Project Settings.

#include "ActivateCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdUnfocusedConstraint.h"
#include "Command/CmdFocusedConstraint.h"
#include "Command/CmdHighlightedConstraint.h"
#include "ActorInfo/Outliner.h"
#include "ActorInfo/ActorConstraintMarker.h"



UActorConstraintMarker* UActivateCommand::ActorConstraintMarker = nullptr;
UOutliner* UActivateCommand::Outliner = nullptr;

UActivateCommand::UActivateCommand()
{
	// DEBUG : 생성자 로깅
	VP_CTOR;

	UCommandConstraintManager* CommandConstraintManager = UCommandConstraintManager::GetGlobalCommandConstraintManager();
	if (IsValid(CommandConstraintManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetName());
		return;
	}

	/* 포커스 제약조건들의 유효성을 검사합니다. */
	UCmdUnfocusedConstraint* UnfocusedConstraint = CommandConstraintManager->GetCmdUnfocusedConstraint();
	UCmdFocusedConstraint* FocusedConstraint = CommandConstraintManager->GetCmdFocusedConstraint();
	UCmdHighlightedConstraint* HighlightedConstraint = CommandConstraintManager->GetCmdHighlightedConstraint();
	if (IsValid(UnfocusedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdUnfocusedConstraint::StaticClass()->GetName());
		return;
	}
	if (IsValid(FocusedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdFocusedConstraint::StaticClass()->GetName());
		return;
	}
	if (IsValid(HighlightedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdHighlightedConstraint::StaticClass()->GetName());
		return;
	}

	/* OR 제약 조건을 추가합니다. */
	Constraints.Add(UnfocusedConstraint);
	Constraints.Add(FocusedConstraint);
	Constraints.Add(HighlightedConstraint);





	/* 이미 초기화되어 있으면 생략합니다 */
	if (ActorConstraintMarker->IsValidLowLevel()
		&& Outliner->IsValidLowLevel())
	{
		VP_LOG(Log, TEXT("UnFocusedCommand의 멤버가 이미 유효합니다."));
		return;
	}
	VP_LOG(Log, TEXT("%s의 멤버가 유효하지 않으므로 초기화를 수행합니다."), *UActivateCommand::StaticClass()->GetName());

	/* 초기화하는 데 필요한 객체를 가지고 있는 모듈의 유효성을 검사합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}





	/* 초기화를 수행합니다 */
	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();
	Outliner = UOutliner::GetGlobalOutliner();



	/* 초기화된 객체들에 대한 유효성 검사를 실행합니다 */
	if (IsValid(Outliner) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UOutliner::StaticClass()->GetName());
		return;
	}
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UActorConstraintMarker::StaticClass()->GetName());
		return;
	}
	if (Constraints.Num() == 0)
	{
		VP_LOG(Warning, TEXT("제약 조건이 설정되지 않았습니다. 제약 조건의 수 : %d"), Constraints.Num());
		return;
	}
}





void UActivateCommand::ExecuteIf()
{
	/* 멤버 유효성을 검사합니다. */
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_LOG(Warning, TEXT("명령을 실행하는데 %s가 유효하지 않습니다."), *UActorConstraintMarker::StaticClass()->GetName());
		return;
	}

	/* 대상에 대한 유효성을 검사합니다 */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("명령의 대상 액터가 유효하지 않습니다."));
	}

	/* 명령이 제약 조건을 만족하는 지 확인합니다 */
	for (const auto& it : Constraints)
	{
		if (it->CheckConstraint(Target) == true)
		{
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Activated);
			Outliner->DrawActorOutline(Target.Target, true);
		}
	}
}





void UActivateCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}
