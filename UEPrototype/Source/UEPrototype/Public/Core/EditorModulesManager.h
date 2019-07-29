// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module/ModuleManagerBase.h"
#include "EditorModulesManager.generated.h"



class UCoreInputModuleManager;



/**
 *	모든 모듈들의 생명 주기를 관리하는 모듈들의 왕입니다.
 *	최상위 모듈들에 대한 전역적 접근 및 생명주기를 관리하며,
 *	모듈들의 초기화를 수행하도록 명령하는 매니저 클래스입니다.
 */
UCLASS()
class UEPROTOTYPE_API UEditorModulesManager : public UModuleManagerBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UEditorModulesManager();



protected:
	/* 초기화합니다 */
	virtual void Initialized() override;



public:
	// TODO : 다른 모든 모듈들에 대한 Getter 함수를 작성하시기 바랍니다.

	/* CoreInput 모듈 매니저를 반환합니다(전역 접근 가능) */
	UFUNCTION(BlueprintCallable, Category = "Core|World", meta = (WorldContext = "WorldContextObject",
				UnsafeDuringActorConstruction = "true"))
	static UCoreInputModuleManager* GetCoreInputModuleManager(UObject* WorldContextObject);



private:
	// TODO : 다른 모든 모듈들을 작성하시기 바랍니다.

	/* CoreInputModuleManager입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAcces=true))
	UCoreInputModuleManager * CoreInputModuleManager;
};
