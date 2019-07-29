// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorInterpreterManager.h"
#include "UEPrototype.h"
#include "Containers/Array.h"
#include "GameFramework/InputSettings.h"
#include "EditorActionMetaInputInterpreter.h"
#include "EditorActionMultInputInterpreter.h"
#include "InputGate.h"



UEditorInterpreterManager::UEditorInterpreterManager()
{
	InitializeInterpreters();
	InitializeInputGates();
}



void UEditorInterpreterManager::InitializeInterpreters()
{
	/* 하위 구성요소들을 초기화합니다 */
	EditorActionMetaInputInterpreter = CreateDefaultSubobject<UEditorActionMetaInputInterpreter>
										(MakeUniqueObjectName(this, UEditorActionMetaInputInterpreter::StaticClass()));
	EditorActionMultInputInterpreter = CreateDefaultSubobject<UEditorActionMultInputInterpreter>
										(MakeUniqueObjectName(this, UEditorActionMultInputInterpreter::StaticClass()));
	


	/* 유효성 검사를 각각 수행합니다. */
	if (IsValid(EditorActionMetaInputInterpreter) == false)
	{
		VP_LOG(Error, TEXT("생성하는 데 실패하였습니다 : %s"), *UEditorActionMetaInputInterpreter::StaticClass()->GetName());
		return;
	}
	if (IsValid(EditorActionMultInputInterpreter) == false)
	{
		VP_LOG(Error, TEXT("생성하는 데 실패하였습니다 : %s"), *UEditorActionMultInputInterpreter::StaticClass()->GetName());
		return;
	}
}

void UEditorInterpreterManager::InitializeInputGates()
{
	/* InputSetting를 받아옵니다 */
	const UInputSettings* InputSettings = GetDefault<UInputSettings>();


	
	TArray<FName> ActionKeyMappings;
	InputSettings->GetActionNames(ActionKeyMappings);
	uint32 NumActions = ActionKeyMappings.Num();
	for (const auto& it : ActionKeyMappings)
	{
		/* 추가합니다 */
		ActionInputGates.Add(it, CreateDefaultSubobject<UInputGate>
						(MakeUniqueObjectName(this, UInputGate::StaticClass())));
	}
}
