// Fill out your copyright notice in the Description page of Project Settings.

#include "FocusCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Core/PlayerTaskManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdUnfocusedConstraint.h"
#include "Command/CmdFocusedConstraint.h"
#include "ActorInfo/Outliner.h"
#include "ActorInfo/ActorConstraintMarker.h"

UOutliner* UFocusCommand::Outliner = nullptr;
UActorConstraintMarker* UFocusCommand::ActorConstraintMarker = nullptr;
UPlayerTaskManager* UFocusCommand::PlayerTaskManager = nullptr;

UFocusCommand::UFocusCommand()
{
	// TODO : 나중에 주석을 풀어주세요
	// VP_CTOR;

	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager()))
	{
		return;
	}

	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdUnfocusedConstraint()))return;

	UCmdUnfocusedConstraint * UnFocusedConstraint = UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdUnfocusedConstraint();

	if (IsValid(UnFocusedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdUnfocusedConstraint()->GetName());
		return;
	}
	IActorCmdConstraint* ConstraintInterface = Cast<IActorCmdConstraint>(UnFocusedConstraint);
	if (ConstraintInterface == nullptr)
	{
		VP_LOG(Warning, TEXT(";;;"));
		return;
	}
	Constraints.Add(UnFocusedConstraint);

	if (Outliner != nullptr && PlayerTaskManager != nullptr && Outliner->IsValidLowLevel() && ActorConstraintMarker != nullptr &&
		ActorConstraintMarker->IsValidLowLevel())
	{
		// TODO : 나중에 주석을 풀어주세요.
		//VP_LOG(Log, TEXT("FocusCommand의 멤버가 유효하다네요?"));
		return;
	}

	/* 초기화하는 데 필요한 객체를 가지고 있는 모듈의 유효성을 검사합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}

	UCommandConstraintManager* CommandConstraintManager = UCommandConstraintManager::GetGlobalCommandConstraintManager();
	if (IsValid(CommandConstraintManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetName());
		return;
	}

	/* 초기화를 수행합니다 */
	VP_LOG(Warning, TEXT("[DEBUG] 에디터 모듈이 초기화가 되어있습니다."));
	Outliner = UOutliner::GetGlobalOutliner();
	PlayerTaskManager = UPlayerTaskManager::GetGlobalPlayerTaskManager();
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
	if (IsValid(PlayerTaskManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UActorConstraintMarker::StaticClass()->GetName());
		return;
	}

	if (Constraints.Num() == 0)
	{
		VP_LOG(Warning, TEXT("제약 조건이 올바르게 설정되지 않았습니다."));
		return;
	}

	// DEBUG
	VP_LOG(Warning, TEXT("[DEBUG] %s : %d, Pointer Address : %x"), *Outliner->GetName(), Outliner->GetUniqueID(), &Outliner);
	VP_LOG(Warning, TEXT("[DEBUG] %s : %d, Pointer Address : %x"), *ActorConstraintMarker->GetName(), ActorConstraintMarker->GetUniqueID(), &ActorConstraintMarker);
}

void UFocusCommand::ExecuteIf()
{
	/* 실행 전 유효성을 검사합니다 */
	if (IsValid(Outliner) == false)
	{
		VP_LOG(Warning, TEXT("명령을 실행하는데 %s가 유효하지 않습니다."), *UOutliner::StaticClass()->GetName());
		return;
	}
	if (IsValid(PlayerTaskManager) == false)
	{
		VP_LOG(Warning, TEXT("명령을 실행하는데 %s가 유효하지 않습니다."), *UPlayerTaskManager::StaticClass()->GetName());
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
		// TODO : 나중에 주석을 풀어주세요.
		//VP_LOG(Warning, TEXT("명령의 대상 액터가 유효하지 않습니다."));
		return;
	}

	/* 명령이 제약 조건을 만족하는 지 확인합니다 */
	// 포커스커맨드 호크포크 플레이어테스크이용
	for (const auto& it : Constraints)
	{
		// TODO : 모든 액터는 생성시 CSTR_None상태. 나중에 PlayerTaskManager 부분을 손 봐야할듯
		if (it->CheckConstraint(Target) == true || Target.TargetState == EActorConstraintState::CSTR_None)
		{
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Focused);
			Outliner->AddFocusedOutline(Target.Target);
			break;
		}
	}
}

void UFocusCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}