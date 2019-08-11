// Fill out your copyright notice in the Description page of Project Settings.

#include "TranslateStartCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "Transformer/Transformer.h"
#include "Gizmo/EditorGizmo.h"
#include "Gizmo/GizmoMeshComponent.h"
#include "ActorInfo/ActorConstraintMarker.h"


UActorConstraintMarker* UTranslateStartCommand::ActorConstraintMarker = nullptr;



UTranslateStartCommand::UTranslateStartCommand()
{
	VP_CTOR;
	
	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager())) return;
	

	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint()))return;

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


	if (ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel())
	{
		VP_LOG(Log, TEXT("TranslateStart의 멤버가 유효하다네요?"));
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

void UTranslateStartCommand::ExecuteIf()
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

	if (IsValid(EditorGizmo) == false)
	{
		VP_LOG(Warning, TEXT("EditorGizmo가 존재하지않습니다."));
		return;
	}
	if (IsValid(TranslateInfo.SelectedGizmoComponent))
	{
		VP_LOG(Warning, TEXT("SelectedGizmoComponent가 존재하지않습니다."));
	
	}

	/* 명령이 제약 조건을 만족하는 지 확인합니다 */

	
	for (const auto& it : Constraints)
	{
		if (it->CheckConstraint(Target) == true)
		{
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Blocked);
			
			if (Transformer->GetisStart())
			{
				//Transformer는 액터에 하나만 존재하니깐, 모든 트랜스폼 동작을 Stack을 이용해 담음(Undo를 위해)
				Transformer->PushTrasnform(Target.Target->GetTransform());
				//스택에 마우스 드래그시 단 한번을 담기위해 Start가 true일 떄 한번 담고 false로 바꿔줌.
				Transformer->SetisStart(false);
				
			}
			
			

			for (int i = 0; i < TranslateInfo.SelectedGizmoComponent->GetAxisTypes().Num(); ++i)
			{
				Transformer->MoveObject(Target.Target, EditorGizmo->
				GetAxisDirection(TranslateInfo.SelectedGizmoComponent->GetAxisTypes()[i]), 1, 1);
				
			}


			return;
		}
	}
}

void UTranslateStartCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}
