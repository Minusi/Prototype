// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreInputModuleManager.h"
#include "UEPrototype.h"
#include "InputSettingManager.h"
#include "EditorInterpreterManager.h"



UCoreInputModuleManager::UCoreInputMoudleManager()
{
	// 초기화합니다.
	initialized();
}





void UCoreInputModuleManager::Initialized()
{
	/* 하위 모듈들을 초기화합니다 */
	InputSettingManager = CreateDefaultSubobject<UInputSettingManager>
							(MakeUniqueObjectName(this, UInputSettingManager::StaticClass()));
	EditorInterpreterManager = CreateDefaultSubobject<UEditorInterpreterManager>
							(MakeUniqueObjectName(this, UEditorInterpreterManager::StaticClass()));

	

	/* 하위 모듈들에 대한 유효성 검사를 수행합니다 */
	if (IsValid(InputSettingManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UInputSettingManager::StaticClass()->GetName());
		return;
	}
	if (IsValid(EditorInterpreterManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UEditorInterpreterManager::StaticClass()->GetName());
		return;
	}
}





void UCoreInputModuleManager::ReceiveRegisterEndEvent()
{

}
