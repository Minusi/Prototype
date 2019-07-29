// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "GameFramework/PlayerInput.h"
#include "EditorActionMultInputInterpreter.generated.h"



class UInputSettings;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiKeyTriggerStartEventDispatcher, TArray<FKey>, PressedKeys);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiKeyTriggerEndEventDispatcher, TArray<FKey>, ReleasedKeys);



/*
 * KeyArray는 단순히 UE4가 nested container를 지원하지 않기 때문에
 * 만들어진 래퍼(wrapper) 구조체입니다. 가급적이면 이 구조체를 다른
 * 곳의 멤버 변수나 인자로 사용하는 것을 자제하시길 바랍니다. 그러한
 * 사용은 이 구조체의 생성 원인을 오염시킬 수 있습니다.
 */
USTRUCT()
struct FKeyArray
{
	GENERATED_BODY()
	
public:
	/* 키 배열 */
	UPROPERTY()
	TArray<FKey> Keys;

	/* 키 배열을 반환합니다. */
	FORCEINLINE TArray<FKey> GetKeys() const
	{
		return Keys;
	}

	FKeyArray& operator=(const FKeyArray& rhs)
	{
		Keys = rhs.Keys;

		return *this;
	}

	bool operator==(const FKeyArray& rhs)
	{
		return Keys == rhs.Keys;
	}
};





/**
 *	EditorActionMultiInputInterpreter는 특정 커맨드를 실행시킬 때 모디파이어
 *	키를 포함한 다수의 키로 발동시킬 수 있도록 도와주는 인터프리터입니다. 예
 *	를 들어, R 및 E키를 눌러야 명령을 발동시킬 수 있도록 하는 것입니다.

 *	언리얼 엔진에서 이를 직접적으로 지원하지 않기 때문에, 이것을 구현하기 위
 *	해 모든 멀티키 액션은 "Mult_"라는 구분자를 축 내에 삽입하여야 합니다.
 *	또한, 그 액션을 구성하는 키는 ctrl, cmd, shift, alt키 플래그를 모두 true
 *	로 전환하여야 인터프리터가 해석할 수 있습니다.
 *
 *	또한 다른 하드웨어에서 오는 input들을 하나의 액션에서 지원하는 것은 장기
 *	적 및 단기적 관점 모두에서 유지보수에 있어 긍정적이지 않기 때문에, 같은 
 *	기능이더라도 다른 플랫폼 입력 하드웨어 간에는 같은 액션이름을 공유하지 
 *	않습니다. 예시는 다음과 같습니다:
 *
 *	예시) 발동하고자 하는 멀티키 액션의 이름을 Shooting로 짓고자 할 때,
 *		- 실제로 작명되어야 하는 액션 이름의 Base : Mult_Shooting
 *		- KeyBoard에서 R,E 키로 구현하고자 할 때 액션 이름 : Mult_Shooting_1
 *		- Oculus Rift에서 L 및 R 컨트롤러 트리거로 구현할 때 : Mult_Shooting_2
 *		- Gamepad에서 X 및 Y 키로 구현하고자 할 때 액션 이름 : Mult_Shooting_3
 *		- ...
 */
UCLASS()
class UEPROTOTYPE_API UEditorActionMultInputInterpreter : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UEditorActionMultInputInterpreter();



	/* 새로운 멀티키 액션에 멀티키 기능을 제공하기 위해 등록합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void RegisterMultikeyAction(FName NewMultiKeyActionName, const TArray<FInputActionKeyMapping>& InMultiKeyMappings);
	
	/* 기존의 멀티키 액션을 등록 해제합니다. */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void UnregisterMultikeyAction(FName ExistedMultiKeyActionName);

	/* Action Input으로부터 Pressed 이벤트를 수신하였을 때, 이를 처리합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void ReceivePressed(FKey PressedKey);

	/* Action Input으로부터 Released 이벤트를 수신하였을 때, 이를 처리합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void ReceiveReleased(FKey ReleasedKey);



private:
	/* 멀티키 액션이 입력 세팅과 로컬 세팅 모두에 유효한지,
		또한 액션 이름이 멀티키 액션 명명 규칙을 따르는지 검사합니다 */
	UFUNCTION()
	bool ValidateMultiKeyAction(FName MultiKeyActionName);

	/* 멀티키 액션이 입력 세팅에 유효한지,
		또한 액션 이름이 멀티키 액션 명명 규칙을 따르는지 검사합니다 */
	UFUNCTION()
	bool ValidateMultiKeyActionFast(FName MultiKeyActionName);

	/* 멀티키 매핑이 멀티키 작동을 위한 규칙을 따르는지 검사합니다 */
	UFUNCTION()
	bool ValidateMultiKey(FInputActionKeyMapping MultiKeyMapping);



public:
	/* 멀티키 입력이 발동되었을 때 발생하는 이벤트 디스패처를 반환합니다 */
	UFUNCTION()
	FORCEINLINE FMultiKeyTriggerStartEventDispatcher 
		OnMultiKeyTriggerStart() const
	{
		return MultiKeyTriggerStartEventDispatcher;
	}

	/* 멀티키 입력 발동이 끝났을 때 발생하는 이벤트 디스패처를 반환합니다 */
	UFUNCTION()
	FORCEINLINE FMultiKeyTriggerEndEventDispatcher
		OnMultiKeyTriggerEnd() const
	{
		return MultiKeyTriggerEndEventDispatcher;
	}





private:
	/* 이번 프레임에서 눌려지고 있는 키들의 배열입니다 */
	UPROPERTY()
	TArray<FKey> PressedKeys;

	/* 현재 멀티키 입력이 발동된 키들의 배열을 담는 배열입니다 */
	UPROPERTY()
	TArray<FKeyArray> TriggerKeys;

	/* 멀티키 액션 이름과 해당 액션이 요구로 하는 키 조합을 담고 있는 컨테이너입니다 */
	UPROPERTY()
	TMap<FName, FKeyArray> MultiKeyActionMappings;

	/* 멀티키 액션임을 구분짓기 위한 구분자입니다 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Core|Input", meta=(AllowPrivateAccess=true))
	FString MultiKeyActionDelimeter = TEXT("Mult_");



	/* 멀티키 입력이 발동되었을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, 
			Category="Core|Input|Delegate", meta=(AllowPrivateAccess=true))
	FMultiKeyTriggerStartEventDispatcher MultiKeyTriggerStartEventDispatcher;
	
	/* 멀티키 입력이 발동이 끝났을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, 
			Category="Core|Input|Delegate", meta=(AllowPrivateAccess=true))
	FMultiKeyTriggerEndEventDispatcher MultiKeyTriggerEndEventDispatcher;

	/* UInputSettings에 대한 클래스 스코프 캐시입니다 */
	static const UInputSettings* InputSettings;
};
