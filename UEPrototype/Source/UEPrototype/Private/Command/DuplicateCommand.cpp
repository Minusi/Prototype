// Fill out your copyright notice in the Description page of Project Settings.

#include "DuplicateCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "ActorInfo/ActorConstraintMarker.h"


UActorConstraintMarker* UDuplicateCommand::ActorConstraintMarker = nullptr;

UDuplicateCommand::UDuplicateCommand() 
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


	


	/* 초기화를 수행합니다 */
	VP_LOG(Warning, TEXT("[DEBUG] 에디터 모듈이 초기화가 되어있습니다."));
	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();




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

void UDuplicateCommand::ExecuteIf()
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

	/* 명령이 제약 조건을 만족하는 지 확인합니다 */

	for (const auto& it : Constraints)
	{
		if (it->CheckConstraint(Target) == true)
		{
			Duplicate();
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_None);
			
			return;
		}
	}

}

void UDuplicateCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}

void UDuplicateCommand::Duplicate()
{
	if (Target.Target == nullptr) return;

	FActorSpawnParameters ASParam;
	{
		ASParam.Template = Target.Target;
		//ASParam.Owner = Target.Target->GetOwner();
		//ASParam.Instigator = Target.Target->GetInstigator();
		//ASParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	}


	

	//Actor를 복제하는 과정. 복제이기 때문에 spawn과정에 필요한 parameter는 모두 해당 Actor에 관한 것들.
	//if (!IsValid(GetWorld()->SpawnActor<AActor>(Target.Target->GetClass(),Target.Target->GetActorTransform(),ASParam))) return;
	AActor* SpawnActor = Target.Target->GetWorld()->SpawnActor<AActor>(Target.Target->GetClass(), Target.Target->GetActorTransform());
	

	


}
