// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module/ModuleManagerBase.h"
#include "CoreInputModuleManager.generated.h"



class UInputSettingManager;
class UEditorInterpreterManager;



/**
 *	Core 모듈의 서브 모듈인 Input 모듈을 관리하는 서브모듈
 *	관리자입니다.
 */
UCLASS()
class UEPROTOTYPE_API UCoreInputModuleManager : public UModuleManagerBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UCoreInputModuleManager();



protected:
	/* 하위 모듈들을 초기화합니다 */
	virtual void Initialized() override;

public:
	/* CoreInputModuleManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Input", meta = (UnsafeDuringActorConstruction = "true"))
	static UCoreInputModuleManager* GetGlobalCoreInputModuleManager();



	UFUNCTION(BlueprintGetter, Category="Core|Input")
	FORCEINLINE UInputSettingManager* GetInputSettingManager() const
	{
		return InputSettingManager;
	}

	UFUNCTION(BlueprintGetter, Category="Core|Input")
		FORCEINLINE UEditorInterpreterManager* GetEditorInterpreterManager() const
	{
		return EditorInterpreterManager;
	}





private:
	/* InputSettingManager 입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Input", meta = (AllowPrivateAccess = true),
				BlueprintGetter=GetInputSettingManager)
	UInputSettingManager* InputSettingManager;

	/* EditorInterpreterManager 입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Input", meta = (AllowPrivateAccess = true)
,				BlueprintGetter=GetEditorInterpreterManager)
	UEditorInterpreterManager* EditorInterpreterManager;
};
