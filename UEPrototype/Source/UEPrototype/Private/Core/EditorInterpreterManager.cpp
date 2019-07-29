// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorInterpreterManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "CoreInputModuleManager.h"
#include "EditorActionMetaInputInterpreter.h"
#include "EditorActionMultInputInterpreter.h"
#include "InputSettingManager.h"
#include "InputGate.h"



UEditorInterpreterManager::UEditorInterpreterManager()
{
	/* 상위 모듈을 받아. 이벤트 바인딩을 수행합니다 */
	UCoreInputModuleManager* CoreInputModuleManager =
		UCoreInputModuleManager::GetGlobalCoreInputModuleManager();
	if (IsValid(CoreInputModuleManager) == false)
	{
		return;
	}
	FEventToRegister Event;
	Event.BindUFunction(this, "BoundToEvents");
	CoreInputModuleManager->RegisterIf(Event);
	
	/* 초기화를 수행합니다 */
	InitializeInterpreters();
	InitializeInputGates();
}



UEditorInterpreterManager * UEditorInterpreterManager::GetGlobalEditorInterpreterManager()
{
	for (const auto& it : TObjectRange<UEditorInterpreterManager>())
	{
		return it;
	}

	/* 존재하지 않는다면 시스템에 큰 결함이 있다는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UEditorInterpreterManager::StaticClass()->GetName());
	return nullptr;
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

void UEditorInterpreterManager::BoundToEvents()
{	
	VP_LOG(Log, TEXT("호출되었습니다"));
	UInputSettingManager* InputSettingManager = 
		UInputSettingManager::GetGlobalInputSettingManager();
	if (IsValid(InputSettingManager) == false)
	{
		return;
	}

	InputSettingManager->OnActionAdded().AddDynamic(this, &UEditorInterpreterManager::AddInputGate);
	InputSettingManager->OnActionRemoved().AddDynamic(this, &UEditorInterpreterManager::RemoveInputGate);
	
}

void UEditorInterpreterManager::AddInputGate(FName AddedActionName, const TArray<FInputActionKeyMapping>& AddedActionKeyMappings)
{
	/* 이미 컨테이너에 키가 존재하는 것은 시스템상 허용되지 않은 행동입니다 */
	if (ActionInputGates.Contains(AddedActionName) == true)
	{
		VP_LOG(Warning, TEXT("컨테이너에 해당 키가 이미 존재합니다"), *AddedActionName.ToString());
		return;
	}
	ActionInputGates.Add(AddedActionName, NewObject<UInputGate>(this));
}

void UEditorInterpreterManager::RemoveInputGate(FName RemovedActionName)
{
	/* 컨테이너에 키가 존재하지 않는 것은 시스템상 허용되지 않은 행동입니다 */
	if (ActionInputGates.Contains(RemovedActionName) == false)
	{
		VP_LOG(Warning, TEXT("컨테이너에 해당 키가 존재하지 않습니다."), *RemovedActionName.ToString());
		return;
	}

	ActionInputGates.Remove(RemovedActionName);
}
