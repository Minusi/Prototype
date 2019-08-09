// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/VPPlayerController.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "VPDirectorPawn.h"
#include "Core/EditorInterpreterManager.h"
#include "Core/EditorActionMetaInputInterpreter.h"
#include "Core/EditorActionMultInputInterpreter.h"



AVPPlayerController::AVPPlayerController()
{
	VP_CTOR;
}



void AVPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/* 입력 모듈을 불러와서 프로퍼티 참조에 대한 초기화를 준비합니다 */
	UEditorInterpreterManager* EditorInterpreterManager =
		UEditorInterpreterManager::GetGlobalEditorInterpreterManager();
	if (IsValid(EditorInterpreterManager) == false)
	{
		return;
	}

	

	/* 프로퍼티 참조 초기화를 수행합니다 */
	EditorActionMetaInputInterpreter = EditorInterpreterManager->GetEditorActionMetaInputInterpreter();
	EditorFocusMetaInputInterpreter = EditorInterpreterManager->GetEditorFocusMetaInputInterpreter();
	EditorActionMultInputInterpreter = EditorInterpreterManager->GetEditorActionMultInputInterpreter();

	
	
	/* 참조된 프로퍼티에 대한 유효성을 검사합니다 */
	if (IsValid(EditorActionMetaInputInterpreter) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UEditorActionMetaInputInterpreter::StaticClass()->GetName());
		return;
	}
	if (IsValid(EditorFocusMetaInputInterpreter) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UEditorFocusMetaInputInterpreter::StaticClass()->GetName());
		return;
	}
	if (IsValid(EditorActionMultInputInterpreter) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UEditorActionMultInputInterpreter::StaticClass()->GetName());
		return;
	}

	

	// DEBUG : 현재 원인을 알 수 없는 이유로 간헐적으로 싱글톤 CDO가 복수개가 생성되는
	// 현상이 일어나고 있습니다. 이것은 이 현상을 잡아내기 위한 디버깅 코드입니다. 이
	// 현상이 해결된다면 디버깅 코드를 지워주시길 바랍니다.
	if (EditorActionMetaInputInterpreter != UEditorActionMetaInputInterpreter::GetGlobalEditorActionMetaInputInterpreter())
	{
		VP_LOG(Error, TEXT("%s(%d)와 %s(%d)가 일치하지 않습니다."),
			*EditorActionMetaInputInterpreter->GetName(),
			EditorActionMetaInputInterpreter->GetUniqueID(),
			*UEditorActionMetaInputInterpreter::GetGlobalEditorActionMetaInputInterpreter()->GetName(),
			UEditorActionMetaInputInterpreter::GetGlobalEditorActionMetaInputInterpreter()->GetUniqueID());
		return;
	}
	if (EditorFocusMetaInputInterpreter != UEditorFocusMetaInputInterpreter::GetGlobalEditorFocusMetaInputInterpreter())
	{
		VP_LOG(Error, TEXT("%s와 %s가 일치하지 않습니다."),
			*EditorFocusMetaInputInterpreter->GetName(),
			*UEditorFocusMetaInputInterpreter::GetGlobalEditorFocusMetaInputInterpreter()->GetName());
		return;
	}
	if (EditorActionMultInputInterpreter != UEditorActionMultInputInterpreter::GetGlobalEditorActionMultInputInterpreter())
	{
		VP_LOG(Error, TEXT("%s와 %s가 일치하지 않습니다."),
			*EditorActionMultInputInterpreter->GetName(),
			*UEditorActionMultInputInterpreter::GetGlobalEditorActionMultInputInterpreter()->GetName());
		return;
	}



	/* DirectorPawn을 받아 와서 이벤트를 바인딩합니다. */
	AVPDirectorPawn* DirectorPawn = Cast<AVPDirectorPawn>(GetPawn());
	if (IsValid(DirectorPawn) == false)
	{
		VP_LOG(Warning, TEXT("폰이 유효하지 않습니다."));
		return;
	}

	/* 이벤트를 바인딩합니다 */
	DirectorPawn->OnUserFocus().AddDynamic(this, &AVPPlayerController::ReceiveFocusEvent);
}