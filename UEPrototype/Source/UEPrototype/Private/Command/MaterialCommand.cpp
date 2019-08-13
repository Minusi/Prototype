// Fill out your copyright notice in the Description page of Project Settings.

#include "MaterialCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "ActorInfo/VPMaterial.h"

UActorConstraintMarker* UMaterialCommand::ActorConstraintMarker = nullptr;

UVPMaterial* UMaterialCommand::VPMaterial = nullptr;

UMaterialCommand::UMaterialCommand()
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
	if ((ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel())
		&& (VPMaterial != nullptr && VPMaterial->IsValidLowLevel()))
	{
		VP_LOG(Log, TEXT("UMaterialCommand의 멤버가 유효하다네요?"));
		return;
	}
	VP_LOG(Log, TEXT("UMaterialCommand의 멤버가 유효하지 않다네요?"));

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
	VPMaterial = UVPMaterial::GetGlobalMaterial();



	/* 초기화된 객체들에 대한 유효성 검사를 실행합니다 */
	
	if (IsValid(VPMaterial) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UVPMaterial::StaticClass()->GetName());
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

void UMaterialCommand::ExecuteIf()
{

	if (IsValid(VPMaterial) == false)
	{
		VP_LOG(Warning, TEXT("명령을 실행하는데 VPMaterial가 유효하지 않습니다."));
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
			ActorConstraintMarker->MarkActor(Target.Target, Target.TargetState);
			
			return;
		}
	}
}

void UMaterialCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}

void UMaterialCommand::SetParamsVector(UStaticMeshComponent * Actor, FVector Vector, FName Name)
{
	VPMaterial->SetMaterialVectorParam(Actor, Vector, Name);
}

void UMaterialCommand::SetParamsTexture(UStaticMeshComponent * Actor, UTexture2D * Texture, FName Name)
{
	VPMaterial->SetMaterialUTexture2DParam(Actor, Texture, Name);
}

void UMaterialCommand::SetParamsColor(UStaticMeshComponent * Actor, FLinearColor Color, FName Name)
{
	VPMaterial->SetMaterialLinearColor(Actor, Color, Name);
	
}

void UMaterialCommand::SetParamsScalar(UStaticMeshComponent * Actor, float Value, FName Name)
{
	VPMaterial->SetMaterialScalarParam(Actor, Value, Name);
}
