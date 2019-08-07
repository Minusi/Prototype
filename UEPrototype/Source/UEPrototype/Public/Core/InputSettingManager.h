// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerInput.h"
#include "UObjectGlobals.h"
#include "InputSettingManager.generated.h"



class UInputSettings;



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionAddedEventDispatcher, FName, AddedActionName, const TArray<FInputActionKeyMapping>&, AddedActionKeyMappings);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionRemovedEventDispatcher, FName, RemovedActionName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FActionKeyChangedEventDispatcher, FName, ChangedActionName, const TArray<FInputActionKeyMapping>&, OldActionKeyMappings, const TArray<FInputActionKeyMapping>&, NewActionKeyMappings);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAxisAddedEventDispatcher, FName, AddedAxisName, const TArray<FInputAxisKeyMapping>&, AddedAxisKeyMappings);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAxisRemovedEventDispatcher, FName, RemovedAxisName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAxisKeyChangedEventDispatcher, FName, ChangedAxisName, const TArray<FInputAxisKeyMapping>&, OldAxisMappings, const TArray<FInputAxisKeyMapping>&, NewAxisKeyMappings);





/**
 *	InputSettingManager는 사용자 요청에 따라 동적으로 키 바인딩을
 *	변경할 수 있도록 지원하는 클래스입니다. 
 *
 *	또한, 인풋 인터프리터 시스템에 변경사항을 전파할 수 있도록
 *	다수의 이벤트 디스패처를 보유하고 있습니다. 특정 입력의 변경
 *	이벤트가 발생하였을 때, 특정 인터프리터의 로컬 세팅이 변경될
 *	필요가 있다면, 이벤트 디스패처를 통해서 이벤트를 등록(regist
 *	er)하셔야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API UInputSettingManager : public UObject
{
	GENERATED_BODY()
	
public:
	// DEBUG
	UInputSettingManager();

	/* InputSettingManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Input", meta = (UnsafeDuringActorConstruction = "true"))
	static UInputSettingManager* GetGlobalInputSettingManager();


public:
	/* InputSettings에서 액션을 추가합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void AddActionMappings(FName NewActionName, const TArray<FInputActionKeyMapping>& NewActionKeyMappings);
	
	/* InputSettings에서 액션을 제거합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void RemoveActionMappings(FName ExistActionName);

	/* InputSettings에서 액션의 특정 키를 변경합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void ChangeActionKeyMappings(FName TargetActionName, const TArray<FInputActionKeyMapping>& Removes, const TArray<FInputActionKeyMapping	>&Adds);



public:
	/* ActionAddedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FActionAddedEventDispatcher& OnActionAdded()
	{
		return ActionAddedEventDispatcher;
	}

	/* ActionRemovedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FActionRemovedEventDispatcher& OnActionRemoved()
	{
		return ActionRemovedEventDispatcher;
	}

	/* ActionChangedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FActionKeyChangedEventDispatcher& OnActionKeyChanged()
	{
		return ActionKeyChangedEventDispatcher;
	}

	/* AxisAddedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FAxisAddedEventDispatcher& OnAxisAdded()
	{
		return AxisAddedEventDispatcher;
	}

	/* AxisRemovedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FAxisRemovedEventDispatcher& OnAxisRemoved()
	{
		return AxisRemovedEventDispatcher;
	}

	/* AxisKeyChangedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FAxisKeyChangedEventDispatcher& OnAxisKeyChanged()
	{
		return AxisKeyChangedEventDispatcher;
	}





private:
	/* 새로운 액션이 추가되었을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable,
	Category = "Core|Input|Delegate", meta = (AllowPrivateAccess = true))
	FActionAddedEventDispatcher ActionAddedEventDispatcher;
	
	/* 기존 액션이 삭제되었을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable,
	Category = "Core|Input|Delegate", meta = (AllowPrivateAccess = true))
	FActionRemovedEventDispatcher ActionRemovedEventDispatcher;

	/* 기존 액션 입력에 키 변경이 일어났을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable,
	Category = "Core|Input|Delegate", meta = (AllowPrivateAccess = true))
		FActionKeyChangedEventDispatcher ActionKeyChangedEventDispatcher;

	/* 새로운 축이 추가되었을 때 브로드캐스트 하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable,
	Category = "Core|Input|Delegate", meta = (AllowPrivateAccess = true))
		FAxisAddedEventDispatcher AxisAddedEventDispatcher;

	/* 기존 축 이 삭제되었을 때 브로드캐스트 하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable,
	Category = "Core|Input|Delegate", meta = (AllowPrivateAccess = true))
		FAxisRemovedEventDispatcher AxisRemovedEventDispatcher;

	/* 기존 축 입력에 키 변경이 일어났을 때 브로드캐스트 하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable,
	Category = "Core|Input|Delegate", meta = (AllowPrivateAccess = true))
		FAxisKeyChangedEventDispatcher AxisKeyChangedEventDispatcher;
	
	/* UInputSettings에 대한 클래스 스코프 캐시입니다 */
	static UInputSettings* InputSettings;
};
