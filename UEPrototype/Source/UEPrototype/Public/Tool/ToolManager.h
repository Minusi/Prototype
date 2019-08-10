// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Set.h"
#include "Core/EditorActionMetaInputInterpreter.h"
#include "Core/EditorFocusMetaInputInterpreter.h"
#include "ToolManager.generated.h"



class UToolBase;
class UToolKit;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FToolEquippedEventDispatcher, UToolBase*, EquippedTool);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FToolUnequippedEventDispatcher, UToolBase*, UnequippedTool);


/**
 *	ToolManager는 사용자가 사용중인 도구들을 관리하는
 *	관리자 클래스입니다. 주요 목적은 적재적소에 도구들
 *	을 장착 또는 장착해제하거나 도구가 여러개일 떄 도
 *	구들 간 명령 겹침 등을 관리하는 것입니다.
 */
UCLASS()
class UEPROTOTYPE_API UToolManager : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UToolManager();

	/* ToolManager을 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category="Tool")
	static UToolManager* GetGlobalToolManager();



public:
	/* 도구를 장착합니다 */
	UFUNCTION(BlueprintCallable, Category="Tool")
	void EquipTool(UToolBase* Tool);

	/* 도구를 장착 해제합니다. */
	UFUNCTION(BlueprintCallable, Category="Tool")
	void UnequipTool(UToolBase* Tool);

	UFUNCTION(BlueprintCallable, Category="Tool")
	bool IsUsedTool(UToolBase* Tool);



	/* 장착중인 도구들을 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Tool")
	FORCEINLINE TSet<UToolBase*> GetEquippedTools() const
	{
		return EquippedTools;
	}

	/* 커맨드가 이미 트리거됐는지 여부를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Tool")
		FORCEINLINE bool IsCommandTriggered() const
	{
		return bCommandTriggered;
	}

	/* ToolKit의 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category="Tool")
	FORCEINLINE UToolKit* GetToolKit() const
	{
		return ToolKit;
	}


private:
	/* 모듈로부터 필요한 컴포넌트들을 받아 초기화합니다. */
	void BindToEvents();

	

public:
	/* 입력 정보를 처리합니다. */
	UFUNCTION(BlueprintCallable, Category="Tool")
	void ProcessInput(FHighLevelInputData Input);

	/* 포커스 정보를 처리합니다. */
	UFUNCTION(BlueprintCallable, Category="Tool")
	void ProcessFocus(FHighLevelFocusData Input);
	
private:
	/* 입력에 대한 실행가능한 도구의 기능이 여러개가 있는 지 확인합니다. */
	UFUNCTION()
	bool CheckInputOverlap(FHighLevelInputData Input);

	UFUNCTION()
	bool CheckFocusOverlap(FHighLevelFocusData Input);

	/* 적합한 도구에게 입력 정보를 브로드캐스트합니다 */
	UFUNCTION()
	void BroadcastInput(FHighLevelInputData Input);

	/* 적합한 도구에게 포커스 정보를 브로드캐스트합니다 */
	UFUNCTION()
	void BroadcastFocus(FHighLevelFocusData Input);



public:
	/* FToolEquippedEventDispatcher의 Getter입니다. */
	FORCEINLINE FToolEquippedEventDispatcher& OnToolEquipped()
	{
		return ToolEquippedEventDispatcher;
	}

	/* FToolUnequippedEventDispatcher의 Getter입니다. */
	FORCEINLINE FToolUnequippedEventDispatcher& OnToolUnequipped()
	{
		return ToolUnequippedEventDispatcher;
	}





private:
	/* 장착하고 있는 도구들을 담는 컨테이너입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetEquippedTools)
	TSet<UToolBase*> EquippedTools;

	/* 커맨드 충돌 여부를 나타내는 플래그입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=IsCommandTriggered) 
	bool bCommandTriggered;

	/* 모든 사용가능한 도구들을 담고 있는 도구상자입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetToolKit)
	UToolKit* ToolKit;



	/* 도구를 장착할 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Tool", meta=(AllowPrivateAccess=true))
	FToolEquippedEventDispatcher ToolEquippedEventDispatcher;

	/* 도구를 장착 해제할 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Tool", meta=(AllowPrivateAccess=true))
	FToolUnequippedEventDispatcher ToolUnequippedEventDispatcher;
};
