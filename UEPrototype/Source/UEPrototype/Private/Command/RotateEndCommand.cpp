// Fill out your copyright notice in the Description page of Project Settings.

#include "RotateEndCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdBlockedConstraint.h"
#include "Transformer/Transformer.h"
#include "ActorInfo/ActorConstraintMarker.h"

UActorConstraintMarker* URotateEndCommand::ActorConstraintMarker = nullptr;

URotateEndCommand::URotateEndCommand() 
{
	VP_CTOR;
	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager())) return;

	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdBlockedConstraint()))return;

	UCmdBlockedConstraint* BlockedConstraint = UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdBlockedConstraint();

	if (IsValid(BlockedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdBlockedConstraint()->GetName());
		return;
	}



	IActorCmdConstraint* ConstraintInterface = Cast<IActorCmdConstraint>(BlockedConstraint);
	if (ConstraintInterface == nullptr)
	{
		VP_LOG(Warning, TEXT(";;;"));
		return;
	}
	Constraints.Add(BlockedConstraint);


	if (ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel())
	{
		VP_LOG(Log, TEXT("TranslateEndCommand의 멤버가 유효하다네요?"));
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

	

	/* 초기화를 수행합니다 */
	VP_LOG(Warning, TEXT("[DEBUG] 에디터 모듈이 초기화가 되어있습니다."));

	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();

	/* 초기화된 객체들에 대한 유효성 검사를 실행합니다 */
	if (IsValid(Transformer) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *ATransformer::StaticClass()->GetName());
		return;
	}

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

void URotateEndCommand::ExecuteIf()
{

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

	if (IsValid(Transformer) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *ATransformer::StaticClass()->GetName());
		return;
	}

	/* 명령이 제약 조건을 만족하는 지 확인합니다 */



	for (const auto& it : Constraints)
	{
		if (it->CheckConstraint(Target) == true)
		{
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Activated);
			return;
		}
	}
}

void URotateEndCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
	
}
