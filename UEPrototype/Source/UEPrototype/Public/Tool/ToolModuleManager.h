// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module/ModuleManagerBase.h"
#include "ToolModuleManager.generated.h"



class UToolKit;
class UToolManager;



/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UToolModuleManager : public UModuleManagerBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UToolModuleManager();
	
	/* ToolModuleManager을 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Tool")
	static UToolModuleManager* GetGlobalToolModuleManager();

	/* ToolKit의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category="Tool")
	FORCEINLINE UToolKit* GetToolKit() const
	{
		return ToolKit;
	}

	/* ToolManager의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category = "Tool")
	FORCEINLINE UToolManager* GetToolManager() const
	{
		return ToolManager;
	}



protected:
	/* ModuleManagerBase로부터 상속됨 */
	virtual void Initialized() override;
	




private:
	/* 도구들을 담고 있는 가방입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetToolKit)
	UToolKit * ToolKit;

	/* 도구들을 관리하는 관리자입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Tool", meta = (AllowPrivateAccess = true),
				BlueprintGetter = GetToolManager)
	UToolManager* ToolManager;
};
