// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "GameFramework/InputSettings.h"
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
	

	
public:
	/* EditorInterpreterManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Input", meta = (WorldContext = "WorldContextObject",
	UnsafeDuringActorConstruction = "true"))
	static UEditorInterpreterManager* GetGlobalEditorInterpreterManager();


private:
	/* 인터프리터들을 초기화합니다 */
	UFUNCTION()
	void InitializeInterpreters();
	
	/* InputGate를 초기화합니다 */
	UFUNCTION()
	void InitializeInputGates();
	


private:
	/* 필요한 이벤트들을 구독합니다 */
	UFUNCTION()
	void BoundToEvents();

	/* 해당 액션이름에 대한 입력 게이트를 추가합니다 */
	UFUNCTION()
	void AddInputGate(FName AddedActionName, const TArray<FInputActionKeyMapping>& AddedActionKeyMappings);

	/* 해당 액션이름에 대한 입력 게이트를 제거합니다 */
	UFUNCTION()
	void RemoveInputGate(FName RemovedActionName);



public:
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
	UPROPERTY(BlueprintReadOnly, Category="Core}Input", meta=(AllowPrivateAccess=true))
	UEditorActionMetaInputInterpreter * EditorActionMetaInputInterpreter;

	/* 액션에 대한 멀티키 입력 해석기입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core}Input", meta=(AllowPrivateAccess=true))
	UEditorActionMultInputInterpreter* EditorActionMultInputInterpreter;

	/* 액션 이름에 대한 인풋 게이트를 저장하는 컨테이너입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core}Input", meta=(AllowPrivateAccess=true))
	TMap<FName,UInputGate*> ActionInputGates;
};
