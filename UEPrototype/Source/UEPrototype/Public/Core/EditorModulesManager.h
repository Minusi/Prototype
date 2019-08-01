// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module/ModuleManagerBase.h"
#include "EditorModulesManager.generated.h"



class UCoreInputModuleManager;
class UActorInfoModuleManager;



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
	/* EditorModulesManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|World", meta = (UnsafeDuringActorConstruction = "true"))
	static UEditorModulesManager* GetGlobalEditorModulesManager();
	


	/* CoreInputModuleManager를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Core|World")
	FORCEINLINE UCoreInputModuleManager* GetCoreInputModuleManager() const
	{
		return CoreInputModuleManager;
	}

	/* ActorInfoModuleManager를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Core|World")
	FORCEINLINE UActorInfoModuleManager* GetActorInfoModuleManager() const
	{
		return ActorInfoModuleManager;
	}

private:
	/*	월드 컨텍스트를 가지고 있는 CDO인지 여부를 판단합니다.
	이것을 수행하는 이유는 AEditorWorldManager의 구성 요소들만이 유효한
	프레임워크 플로우를 따를 수 있기 때문입니다. */
	UFUNCTION()
	bool ContainWorldContextCDO();



private:
	// TODO : 다른 모든 모듈들을 작성하시기 바랍니다.

	/* CoreInputModuleManager입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetCoreInputModuleManager)
	UCoreInputModuleManager * CoreInputModuleManager;

	/* ActorInfoModuleManager입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetActorInfoModuleManager)
	UActorInfoModuleManager* ActorInfoModuleManager;
};

