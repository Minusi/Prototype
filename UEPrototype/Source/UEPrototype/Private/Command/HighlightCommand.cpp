// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/HighlightCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdFocusedConstraint.h"
#include "Command/CmdHighlightedConstraint.h"
#include "ActorInfo/Outliner.h"
#include "ActorInfo/ActorConstraintMarker.h"



UActorConstraintMarker* UHighlightCommand::ActorConstraintMarker = nullptr;
UOutliner* UHighlightCommand::Outliner = nullptr;



UHighlightCommand::UHighlightCommand()
{
	// DEBUG : 생성자 로깅
	VP_CTOR;

	/* 컨스트레인트르를 가져오기 위해 제약 조건 매니저를 가져옵니다.
	엔진이 처음 로드될 때 에러를 유발하지만, 모듈 초기화 시에 같이 초기화될 필요
	없으므로 무시해도 됩니다. */
	UCommandConstraintManager* CommandConstraintManager = UCommandConstraintManager::GetGlobalCommandConstraintManager();
	if (IsValid(CommandConstraintManager))
	{
		return;
	}

	/* 포커스 제약조건의 유효성을 검사합니다. */
	UCmdFocusedConstraint* FocusedConstraint = CommandConstraintManager->GetCmdFocusedConstraint();
	if (IsValid(FocusedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdFocusedConstraint()->GetName());
		return;
	}

	/* 포커스 제약 조건을 추가합니다. */
	Constraints.Add(FocusedConstraint);






	/* 이미 초기화되어 있으면 생략합니다 */
	if ((ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel())
		&& Outliner != nullptr && Outliner->IsValidLowLevel())
	{
		VP_LOG(Log, TEXT("HighlightCommand의 멤버가 유효하다네요?"));
		return;
	}
	VP_LOG(Log, TEXT("%s의 멤버가 유효하지 않으므로 초기화를 수행합니다."), *UHighlightCommand::StaticClass()->GetName());

	/* 초기화하는 데 필요한 객체를 가지고 있는 모듈의 유효성을 검사합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}


	


	/* 초기화를 수행합니다 */
	Outliner = UOutliner::GetGlobalOutliner();
	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();
	
	


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
		VP_LOG(Warning, TEXT("제약 조건이 설정되지 않았습니다. 등록된 제약 조건 갯수 : %d"), Constraints.Num());
		return;
	}
}





void UHighlightCommand::ExecuteIf()
{
	/* 실행 전 유효성을 검사합니다 */
	if (IsValid(Outliner) == false)
	{
		VP_LOG(Warning, TEXT("명령을 실행하는데 %s가 유효하지 않습니다."), *UOutliner::StaticClass()->GetName());
		return;
	}
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
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Highlighted);
			Outliner->DrawActorOutline(Target.Target,true);
			return;
		}
	}
}





void UHighlightCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}