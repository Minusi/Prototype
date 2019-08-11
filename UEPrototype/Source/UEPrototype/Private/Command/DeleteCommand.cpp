// Fill out your copyright notice in the Description page of Project Settings.

#include "DeleteCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "ActorInfo/Outliner.h"

UActorConstraintMarker* UDeleteCommand::ActorConstraintMarker = nullptr;

UOutliner* UDeleteCommand::Outliner = nullptr;

UDeleteCommand::UDeleteCommand()
{
	VP_CTOR;
	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager())) return;

	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint()))return;

	/* 이미 초기화되어 있으면 생략합니다 */
	if ((ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel()))
	{
		VP_LOG(Log, TEXT("UDeleteCommand의 멤버가 유효하다네요?"));
		return;
	}
	VP_LOG(Log, TEXT("UdeleteCommand의 멤버가 유효하지 않다네요?"));

	/* 초기화하는 데 필요한 객체를 가지고 있는 모듈의 유효성을 검사합니다 */
	UEditorModulesManager* EditorModulesManager =
	UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}


	UCmdActivatedConstraint* ActivateConstraint = UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint();
	if (IsValid(ActivateConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint()->GetName());
		return;
	}
	IActorCmdConstraint* ConstraintInterface = Cast<IActorCmdConstraint>(ActivateConstraint);
	if (ConstraintInterface == nullptr)
	{
		VP_LOG(Warning, TEXT(";;;"));
		return;
	}
	Constraints.Add(ActivateConstraint);

	if (Outliner != nullptr && Outliner->IsValidLowLevel() && ActorConstraintMarker != nullptr &&
		ActorConstraintMarker->IsValidLowLevel())
	{
		VP_LOG(Log, TEXT("DelectCommand의 멤버가 유효하다네요?"));
		return;
	}

	/* 초기화를 수행합니다 */
	VP_LOG(Warning, TEXT("[DEBUG] 에디터 모듈이 초기화가 되어있습니다."));
	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();
	Outliner = UOutliner::GetGlobalOutliner();



	/* 초기화된 객체들에 대한 유효성 검사를 실행합니다 */

	if (IsValid(ActorConstraintMarker) == false)
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
	VP_LOG(Warning, TEXT("[DEBUG] %s : %d, Pointer Address : %x"), *ActorConstraintMarker->GetName(), ActorConstraintMarker->GetUniqueID(), &ActorConstraintMarker);
}


void UDeleteCommand::ExecuteIf()
{
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
			//TODO:나중에 제대로 Delete 되도록 조정해야함. 일단 SetActive를 이용해 화면상에 보이지않게할것.
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Unfocused);

			if (!Target.Target->bHidden)
			{
				Target.Target->SetActorHiddenInGame(true);
				Target.Target->SetActorEnableCollision(false);
				Target.Target->SetActorTickEnabled(false);

				Outliner->EraseActorOutline();

			}
			

			return;
		}
	}

}

void UDeleteCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}
