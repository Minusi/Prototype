// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "UObject/NoExportTypes.h"
#include "EditorInterpreterManager.generated.h"



class UEditorActionMetaInputInterpreter;
class UEditorActionMultInputInterpreter;

class UInputGate;





/**
 *	UEditorInterpreterManager는 입력 인터프리터 시스템을 관리하는 
 *	관리자 클래스입니다. 메타입력 및 멀티키 입력 인터프리터 및 기
 *	타 인터프리터들에 대해 인터프리터들이 의존하는 외부 기능들에 
 *	대해서 이벤트 바인딩을 수행하고 해제하는 역할을 맡습니다.
 */
UCLASS()
class UEPROTOTYPE_API UEditorInterpreterManager : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자입니다 */
	UEditorInterpreterManager();
	



private:
	/* 인터프리터들을 초기화합니다 */
	UFUNCTION()
	void InitializeInterpreters();
	
	/* InputGate를 초기화합니다 */
	UFUNCTION()
	void InitializeInputGates();





	/* EditorActionMetaInputInterpreter의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category="Core|Input")
	FORCEINLINE UEditorActionMetaInputInterpreter* GetEditorActionMetaInputInterpreter() const
	{
		return EditorActionMetaInputInterpreter;
	}

	/* EditorActionMultInputInterpreter의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category="Core|Input")
	FORCEINLINE UEditorActionMultInputInterpreter* GetEditorActionMultInputInterpreter() const
	{
		return EditorActionMultInputInterpreter;
	}

	/* 주어진 입력 이름에 맞는 UInputGate를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category = "Core|Input")
	FORCEINLINE UInputGate* GetActionInputGate(FName InputName)
	{
		if (ActionInputGates.Contains(InputName) == false)
		{
			return nullptr;
		}
		
		return ActionInputGates.FindRef(InputName);
	}





private:
	/* 액션에 대한 메타입력 해석기입니다 */
	UPROPERTY()
	UEditorActionMetaInputInterpreter * EditorActionMetaInputInterpreter;

	/* 액션에 대한 멀티키 입력 해석기입니다 */
	UPROPERTY()
	UEditorActionMultInputInterpreter* EditorActionMultInputInterpreter;

	/* 액션 이름에 대한 인풋 게이트를 저장하는 컨테이너입니다 */
	UPROPERTY()
	TMap<FName,UInputGate*> ActionInputGates;
};
