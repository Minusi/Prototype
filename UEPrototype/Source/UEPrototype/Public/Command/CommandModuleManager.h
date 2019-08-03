// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module/ModuleManagerBase.h"
#include "CommandModuleManager.generated.h"



class UCommandQueue;
class UCommandConstraintManager;



/**
 *	Command 모듈을 관리하는 모듈 관리자입니다.
 */
UCLASS()
class UEPROTOTYPE_API UCommandModuleManager : public UModuleManagerBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UCommandModuleManager();

private:
	/*	월드 컨텍스트를 가지고 있는 CDO인지 여부를 판단합니다.
	이것을 수행하는 이유는 AEditorWorldManager의 구성 요소들만이 유효한
	프레임워크 플로우를 따를 수 있기 때문입니다. */
	UFUNCTION()
	bool ContainWorldContextCDO();
	


protected:
	/* 하위 컴포넌트들을 초기화합니다 */
	virtual void Initialized() override;

public:
	/* CommandModuleManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Command", meta = (UnsafeDuringActorConstruction = "true"))
	static UCommandModuleManager* GetGlobalCommandModuleManager();

	/* CommandQueue의 Getter함수입니다 */
	UFUNCTION(BlueprintGetter, Category="Command")
		FORCEINLINE UCommandQueue* GetCommandQueue() const
	{
		return CommandQueue;
	}

	/* CommandConstraintManager의 Getter함수입니다. */
	UFUNCTION(BlueprintGetter, Category = "Command")
		FORCEINLINE UCommandConstraintManager* GetCommandConstraintManager() const
	{
		return CommandConstraintManager;
	}



private:
	/* 명령들을 담아 명령 취소/재실행을 수행할 수 있는 명령 큐입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Command", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetCommandQueue)
	UCommandQueue * CommandQueue;

	/* 커맨드의 제약조건들을 생성 및 관리하는 매니저입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Command", meta = (AllowPrivateAccess = true),
				BlueprintGetter = GetCommandConstraintManager)
	UCommandConstraintManager* CommandConstraintManager;
};
