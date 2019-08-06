// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Core/EditorFocusMetaInputInterpreter.h"
#include "VPPlayerController.generated.h"



class UEditorActionMetaInputInterpreter;
class UEditorFocusMetaInputInterpreter;
class UEditorActionMultInputInterpreter;




/**
 *	AVPPlayerController는 플레이어를 반영하는 클래스입니다.
 *	Virtual Prototype에 접속한 플레이어를 대표합니다.
 */
UCLASS()
class UEPROTOTYPE_API AVPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	AVPPlayerController();

protected:
	/* AActor로부터 상속됨 */
	virtual void BeginPlay() override;

public:
	/* DirectorPawn의 포커스 브로드캐스트를 수신하여 처리하는 이벤트입니다. 
		EditorFocusMetaInputInterpreter의 래퍼 함수입니다. */
	UFUNCTION(BlueprintImplementableEvent, Category="Core|Player")
	void ReceiveFocusEvent(AActor* Target, float DeltaTime);





private:
	/* 키 입력에 대한 메타데이터 처리기입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true))
	UEditorActionMetaInputInterpreter * EditorActionMetaInputInterpreter;

	/* 포커스 입력에 대한 메타데이터 처리기입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true))
	UEditorFocusMetaInputInterpreter* EditorFocusMetaInputInterpreter;

	/* 멀티키 입력에 대한 메타데이터 처리기입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true))
	UEditorActionMultInputInterpreter* EditorActionMultInputInterpreter;



};
