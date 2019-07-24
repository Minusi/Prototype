// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorActionMetaInputInterpreter.h"
#include "Containers/Array.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "UEPrototype.h"





const UInputSettings* UEditorActionMetaInputInterpreter::InputSettings = GetDefault<UInputSettings>();

UEditorActionMetaInputInterpreter::UEditorActionMetaInputInterpreter()
{
	if (IsValid(InputSettings) == false)
	{
		VP_LOG(Error, TEXT("InputSetting이 유효하지 않습니다"));
		return;
	}

	TArray<FName> ActionNames;

	InputSettings->GetActionNames(ActionNames);
	for (auto it : ActionNames)
	{
		ActionMetaInputs.Add(it, -1.f);
	}
}



void UEditorActionMetaInputInterpreter::RegisterInputAction(FName NewActionName)
{
	bool bIsValid = ValidateActionFast(NewActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 액션이름입니다 : %s."), *NewActionName.ToString());
		return;
	}

	// 이미 존재하면 등록하지 않습니다.
	if (ActionMetaInputs.Contains(NewActionName) == true)
	{
		VP_LOG(Log, TEXT("이미 존재하고 있는 액션이름입니다 : %s."), *NewActionName.ToString());
		return;
	}

	// 추가합니다.
	ActionMetaInputs.Add(NewActionName, -1.f);
}



void UEditorActionMetaInputInterpreter::UnregisterInputAction(FName ExistActionName)
{
	// 현재 액션이 유효한지 검사합니다.
	bool bIsValid = ValidateAction(ExistActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 액션이름입니다 : %s."), *ExistActionName.ToString());
		return;
	}

	// 제거합니다.
	ActionMetaInputs.Remove(ExistActionName);
}



void UEditorActionMetaInputInterpreter::ReceivePressed(FName ActionName, FHighLevelInputData& MetadataResult)
{
	bool bIsValid = ValidateAction(ActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 액션이름입니다 : %s."), *ActionName.ToString());
		return;
	}

	if (ActionMetaInputs.Contains(ActionName) == false)
	{
		VP_LOG(Warning, TEXT("등록되지 않은 액션이름입니다 : %s."), *ActionName.ToString());
		return;
	}

	const UWorld* ContextWorld = GetWorld();
	if (IsValid(ContextWorld) == false)
	{
		VP_LOG(Log, TEXT("유효하지 않은 월드 객체입니다."));
		return;
	}

	ActionMetaInputs.Add(ActionName, UGameplayStatics::GetTimeSeconds(ContextWorld));

	MetadataResult.MappingName = ActionName;
	MetadataResult.InputMetadata = EInputMetadata::META_Trigger;
}



void UEditorActionMetaInputInterpreter::ReceiveReleased(FName ActionName, FHighLevelInputData& MetadataResult)
{
	TArray<FName> ActionNames;

	// 액션 이름이 유효한지 검사합니다.
	bool bIsValid = ValidateAction(ActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 액션이름입니다 : %s."), *ActionName.ToString());
		return;
	}

	// 유효하지 않은 입력 상태를 검사합니다.
	if (ActionMetaInputs[ActionName] < 0.f)
	{
		VP_LOG(Warning, TEXT("트리거되지 않은 액션(%s)에 대한 메타데이터를 생성하려고 합니다."), *ActionName.ToString());
		return;
	}

	// 게임 시간을 알아내기 위한 월드 객체에 대한 유효성 검사를 수행합니다.
	const UWorld* ContextWorld = GetWorld();
	if (IsValid(ContextWorld) == false)
	{
		VP_LOG(Log, TEXT("유효하지 않은 월드 객체입니다."));
		return;
	}


	// 액션이 눌러진 총 시간을 계산합니다.
	float PressedTime = ActionMetaInputs[ActionName];
	float ElapsedTime = UGameplayStatics::GetTimeSeconds(ContextWorld) - PressedTime;

	// 메타데이터 결과를 생성합니다.
	MetadataResult.MappingName = ActionName;
	MetadataResult.InputMetadata = Interpret(ElapsedTime);
	ResetTime(ActionName);
}



EInputMetadata UEditorActionMetaInputInterpreter::Interpret(float TotalActionTime)
{
	if (TotalActionTime < 0)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 값(%f)을 해석하려고 합니다"), TotalActionTime);
		return EInputMetadata::META_None;
	}

	if (TotalActionTime <= TriggerThreshold)
	{
		return EInputMetadata::META_Idle;
	}
	else if(TotalActionTime <= ClickThreshold)
	{
		return EInputMetadata::META_Click;
	}
	else
	{
		return EInputMetadata::META_Charging;
	}
}



void UEditorActionMetaInputInterpreter::ResetTime(FName ActionName)
{
	if (ActionMetaInputs.Contains(ActionName) == false)
	{
		VP_LOG(Warning, TEXT("등록되지 않은 액션이름입니다 : %s."), *ActionName.ToString());
		return;
	}

	ActionMetaInputs.Add(ActionName, -1.f);
}



bool UEditorActionMetaInputInterpreter::ValidateAction(FName ActionName)
{
	// InputSettings의 유효성을 검사합니다.
	if (IsValid(InputSettings) == false)
	{
		return false;
	}

	TArray<FName> ActionNames;
	InputSettings->GetActionNames(ActionNames);

	// 액션 이름들 중에서 매치되는 것이 있을 때, 그것이 MetaInputs에도 등록되어 있으면
	// 참을 반환합니다.
	for (const auto it : ActionNames)
	{
		if (it == ActionName)
		{
			if (ActionMetaInputs.Contains(it) == true)
			{
				return true;
			}
			else
			{
				VP_LOG(Log, TEXT("액션(%s)이 InputSettings에는 등록되어 있지만, \
						로컬 컨테이너에 등록되어 있지 않습니다."));
				return false;
			}
		}
	}

	// 존재하지 않으면 거짓을 반환합니다.
	return false;
}

bool UEditorActionMetaInputInterpreter::ValidateActionFast(FName ActionName)
{
	// InputSettings의 유효성을 검사합니다.
	if (IsValid(InputSettings) == false)
	{
		return false;
	}

	TArray<FName> ActionNames;
	InputSettings->GetActionNames(ActionNames);

	// 액션 이름들 중에서 매치되는 것이 있으면 참을 반환합니다.
	for (const auto it : ActionNames)
	{
		if (it == ActionName)
		{
			return true;
		}
	}

	// 존재하지 않으면 거짓을 반환합니다.
	return false;
}
