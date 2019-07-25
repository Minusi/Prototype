// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorInterpreterManager.h"
#include "UEPrototype.h"
#include "EditorActionMetaInputInterpreter.h"
#include "EditorActionMultInputInterpreter.h"



void UEditorInterpreterManager::InitializeInterpreters()
{
	EditorActionMetaInputInterpreter = NewObject<UEditorActionMetaInputInterpreter>(this);
	EditorActionMultInputInterpreter = NewObject<UEditorActionMultInputInterpreter>(this);
	
	// 유효성 검사를 각각 수행합니다.
	if (IsValid(EditorActionMetaInputInterpreter) == false)
	{
		VP_LOG(Error, TEXT("생성하는 데 실패하였습니다 : %s"), *EditorActionMetaInputInterpreter->GetName());
		return;
	}
	if (IsValid(EditorActionMultInputInterpreter) == false)
	{
		VP_LOG(Error, TEXT("생성하는 데 실패하였습니다 : %s"), *EditorActionMultInputInterpreter->GetName());
		return;
	}
}

void UEditorInterpreterManager::ReceiveRegisterEndEvent()
{
	//TODO : inputsetting를 받아와서 InputGate 설정할 것
}

