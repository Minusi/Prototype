// Fill out your copyright notice in the Description page of Project Settings.

#include "EmitterCommandStart.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "ActorInfo/VPEmitter.h"

UActorConstraintMarker* UEmitterCommandStart::ActorConstraintMarker = nullptr;

UEmitterCommandStart::UEmitterCommandStart()
{
	VP_CTOR;

	/* 이미 초기화되어 있으면 생략합니다 */
	if ((ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel())
		&& (VPEmitter != nullptr && VPEmitter->IsValidLowLevel()))
	{
		VP_LOG(Log, TEXT("SoundCommand의 멤버가 유효하다네요?"));
		return;
	}
	VP_LOG(Log, TEXT("SoundCommand의 멤버가 유효하지 않다네요?"));

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

void UEmitterCommandStart::ExecuteIf()
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
			ActorConstraintMarker->MarkActor(Target.Target, EActorConstraintState::CSTR_Blocked);
			VPEmitter->ActivateEmitter();
			return;
		}
	}
}

void UEmitterCommandStart::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}

void UEmitterCommandStart::SetEmitter(UParticleSystem * ParticleSystem, FTransform Transform, AActor * Parent)
{
	VPEmitter->InitEmitter(ParticleSystem, Transform, Parent);
}

void UEmitterCommandStart::SetEmitterParam(const FEmitterParam EmitterParam, const FTransform RelativeTrasnform)
{
	VPEmitter->SettingEmitter(EmitterParam, RelativeTrasnform);
}
