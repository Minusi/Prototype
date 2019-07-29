// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorActionMultInputInterpreter.h"
#include "GameFramework/InputSettings.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "CoreInputModuleManager.h"
#include "InputSettingManager.h"



const UInputSettings* UEditorActionMultInputInterpreter::InputSettings = GetDefault<UInputSettings>();

UEditorActionMultInputInterpreter::UEditorActionMultInputInterpreter()
{
	/* 상위 모듈을 불러와서 이벤트에 함수들을 바인딩합니다 */
	UCoreInputModuleManager* CoreInputModuleManager
		= UCoreInputModuleManager::GetGlobalCoreInputModuleManager();
	if (IsValid(CoreInputModuleManager) == false)
	{
		return;
	}

	FEventToRegister Event;
	Event.BindUFunction(this, "BoundToEvents");
	CoreInputModuleManager->RegisterIf(Event);



	/* InputSettings에 대한 유효성 검사를 수행합니다 */
	if (InputSettings == nullptr)
	{
		VP_LOG(Warning, TEXT("InputSetting이 유효하지 않습니다"));
		return;
	}



	/* 멀티키 입력 컨테이너를 초기화합니다 */
	TArray<FName> ActionNames;
	TArray<FInputActionKeyMapping> MultiKeyActionNames;
	FKeyArray KeyArray;

	InputSettings->GetActionNames(ActionNames);
	for (const auto& it : ActionNames)
	{
		FString ActionString = it.ToString();

		// 멀티 구분자가 붙은 액션에 대해서만 정보를 수집합니다.
		if (ActionString.Contains(MultiKeyActionDelimeter, ESearchCase::CaseSensitive) == true)
		{
			InputSettings->GetActionMappingByName(it, MultiKeyActionNames);
			
			// 멀티 액션의 구성 요소는 현재로써는 다른 일반키와 구분짓기 위해
			// 모든 모디파이어 키 플래그를 세워야 인식합니다.
			for (const auto& it : MultiKeyActionNames)
			{
				if (ValidateMultiKey(it) == true)
				{
					KeyArray.Keys.Add(it.Key);
				}
			}
		}

		// 기존에 같은 이름으로 액션이 존재하지 않을 때만 추가합니다.
		// 이는 같은 이름이 존재할 때, TMap이 override해버리는 특성이
		// 있기 때문입니다.
		if (MultiKeyActionMappings.Contains(it) == false)
		{
			MultiKeyActionMappings.Add(it, KeyArray);
		}
	}
}



UEditorActionMultInputInterpreter * UEditorActionMultInputInterpreter::GetGlobalEditorActionMultInputInterpreter()
{
	for (const auto& it : TObjectRange<UEditorActionMultInputInterpreter>())
	{
		return it;
	}

	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UCoreInputModuleManager::StaticClass()->GetName());
	return nullptr;
}





void UEditorActionMultInputInterpreter::BoundToEvents()
{
	/* 바인드할 객체를 불러옵니다 */
	UInputSettingManager* InputSettingManager =
		UInputSettingManager::GetGlobalInputSettingManager();
	if (IsValid(InputSettingManager) == false)
	{
		return;
	}



	/* InputSettingManager에 액션 키가 추가/제거되면 호출될 수 있도록 등록합니다 */
	InputSettingManager->OnActionAdded().AddDynamic(this, &UEditorActionMultInputInterpreter::RegisterMultikeyAction);
	InputSettingManager->OnActionRemoved().AddDynamic(this, &UEditorActionMultInputInterpreter::UnregisterMultikeyAction);
	InputSettingManager->OnActionKeyChanged().AddDynamic(this, &UEditorActionMultInputInterpreter::ChangeMultikey);
}





void UEditorActionMultInputInterpreter::RegisterMultikeyAction(FName NewMultiKeyActionName, const TArray<FInputActionKeyMapping>& InMultiKeyMappings)
{
	// 입력 세팅에서 멀티키 액션이 유효한지 검사합니다.
	bool bIsValid = ValidateMultiKeyActionFast(NewMultiKeyActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 멀티키 액션 이름입니다 : %s"), *NewMultiKeyActionName.ToString());
		return;
	}

	// 이미 존재하면 등록하지 않습니다.
	if (MultiKeyActionMappings.Contains(NewMultiKeyActionName) == true)
	{
		VP_LOG(Log, TEXT("이미 존재하고 있는 액션이름입니다 : %s"), *NewMultiKeyActionName.ToString());
		return;
	}

	// 입력받은 키매핑들이 멀티키 인식 규칙을 유지하고 있다면 등록합니다.
	FKeyArray KeyArray;
	for (const auto& it : InMultiKeyMappings)
	{
		if( ValidateMultiKey(it)==true)
		{
			KeyArray.Keys.Add(it.Key);
		}
	}

	// 등록합니다.
	MultiKeyActionMappings.Add(NewMultiKeyActionName, KeyArray);
}



void UEditorActionMultInputInterpreter::UnregisterMultikeyAction(FName ExistedMultiKeyActionName)
{
	// 현재 멀티키 액션이 유효한지 검사합니다.
	bool bIsValid = ValidateMultiKeyAction(ExistedMultiKeyActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 멀티키 액션 이름입니다 : %s."), *ExistedMultiKeyActionName.ToString());
		return;
	}

	// 제거합니다.
	MultiKeyActionMappings.Remove(ExistedMultiKeyActionName);
}



void UEditorActionMultInputInterpreter::ChangeMultikey(FName TargetMultiKeyActionName, const TArray<FInputActionKeyMapping>& Removes, const TArray<FInputActionKeyMapping>& Adds)
{
	/* 현재 멀티키 액션이 유효한지 검사합니다 */
	bool bIsValid = ValidateMultiKeyAction(TargetMultiKeyActionName);
	if (bIsValid == false)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 멀티키 액션 이름입니다 : %s."), *TargetMultiKeyActionName.ToString());
		return;
	}
	/* 추가하고 삭제하기 위한 키 배열을 컨테이너로부터 구합니다 */
	FKeyArray& ActionKeysRef = MultiKeyActionMappings[TargetMultiKeyActionName];


	
	/* 추가할 키에 대한 유효성 검사를 수행합니다 */
	for (const auto& it : Adds)
	{
		if (ValidateMultiKey(it) == false)
		{
			VP_LOG(Warning, TEXT("추가할 키가 유효하지 않은 멀티키 조건을 따릅니다 : %s."), *it.Key.GetDisplayName().ToString());
			return;
		}



		bool bKeyExist = false;
		for (const auto& jt : ActionKeysRef.Keys)
		{
			if (it.Key == jt)
			{
				bKeyExist = true;
			}
		}

		if (bKeyExist == true)
		{
			VP_LOG(Warning, TEXT("추가할 키가 대상 멀티키 액션에 이미 존재합니다 : %s."), *it.Key.GetDisplayName().ToString());
			return;
		}
	}

	/* 키들을 추가합니다 */
	for (const auto& it : Adds)
	{
		ActionKeysRef.Keys.Add(it.Key);
	}





	/* 삭제할 키에 대한 유효성 검사를 수행합니다 */
	for (const auto& it : Removes)
	{
		if (ValidateMultiKey(it) == false)
		{
			VP_LOG(Warning, TEXT("삭제할 키가 유효하지 않은 멀티키 조건을 따릅니다 : %s."), *it.Key.GetDisplayName().ToString());
			return;
		}



		bool bKeyExist = false;
		for (const auto& jt : ActionKeysRef.Keys)
		{
			if (it.Key == jt)
			{
				bKeyExist = true;
			}
		}

		if (bKeyExist == false)
		{
			VP_LOG(Warning, TEXT("삭제할 키가 대상 멀티키 액션에 존재하지 않습니다 : %s."), *it.Key.GetDisplayName().ToString());
			return;
		}
	}

	/* 키들을 삭제합니다 */
	for (const auto& it : Removes)
	{
		ActionKeysRef.Keys.Remove(it.Key);
	}
}





void UEditorActionMultInputInterpreter::ReceivePressed(FKey PressedKey)
{
	// 멀티키 입력 조건에 대한 후보자를 담는 배열입니다.
	TArray<FName> MultiKeyCandidates;

	// for-range 검사 도중 후보에서 탈락한 후보자들을 담는 배열입니다.
	// 이 배열에 근거하여 후보자들이 제거됩니다.
	TArray<FName> FailedCandidates;

	// 전체 멀티키 액션에 대해서 PressedKey와 일치하는 것이 있으면
	// 후보자 배열에 추가합니다.
	for (const auto& it : MultiKeyActionMappings)
	{
		if (it.Value.Keys.Contains(PressedKey))
		{
			MultiKeyCandidates.Add(it.Key);
		}
	}

	PressedKeys.Add(PressedKey);

	TArray<FKey> KeyArray;
	// 멀티키 입력 후보자들이 요구를 하는 키들에 대해서
	// 이미 입력된 키들이 요구를 충족시키는 지 소거법으로 검사합니다.
	for (const auto& it : MultiKeyCandidates)
	{
		// 키 배열을 초기화합니다.
		KeyArray.Empty(2);

		// 멀티키 입력 후보자가 요구로 하는 키 배열을 담습니다.
		KeyArray = MultiKeyActionMappings.Find(it)->Keys;
		
		for (const auto& jt : KeyArray)
		{
			// 후보자가 요구하는 키 요소가 현재 눌러진 키 배열에 존재하지 않으면,
			if (PressedKeys.Contains(jt) == false)
			{
				// 탈락할 후보자 명단에 추가하고 다음 후보자 검사를 시작합니다.
				FailedCandidates.Add(it);
				break;
			}
		}
	}

	// 후보자 명단에서 탈락한 후보들을 제거합니다.
	for (const auto& it : FailedCandidates)
	{
		if (MultiKeyCandidates.Contains(it))
		{
			MultiKeyCandidates.Remove(it);
		}
		else
		{
			VP_LOG(Warning, TEXT("예기치 못한 흐름이 발생하였습니다. \
					이 함수에 대한 로직에 문제가 발생했습니다."));
			return;
		}
	}



	// 후보자가 1명도 존재하지 않는다면 멀티키 입력이 일어나지 않음을 의미합니다.
	if (MultiKeyCandidates.Num() == 0)
	{
		return;
	}

	// 후보자가 2개 이상 존재한다면 키 겹침(key overlapping) 현상이 일어난 것이므로,
	// 멀티키 이벤트를 트리거하지 않고 경고를 띄웁니다.
	if (MultiKeyCandidates.Num() >= 2)
	{
		VP_LOG(Warning, TEXT("2개 이상의 멀티키 입력이 감지되었습니다 : "));
		for (const auto& it : MultiKeyCandidates)
		{
			VP_LOG(Warning, TEXT("\t- %s"), *it.ToString());
			return;
		}
	}



	FKeyArray MultiKeyArray = *MultiKeyActionMappings.Find(MultiKeyCandidates[0]);
	// 눌려지고 있는 키에서 제외합니다.
	for (const auto& it : MultiKeyArray.Keys)
	{
		PressedKeys.Remove(it);
	}

	// 이후, 트리거 중인 키로 추가합니다.
	TriggerKeys.Add(MultiKeyArray);

	// 마지막으로 멀티키 이벤트를 브로트캐스트합니다.
	MultiKeyTriggerStartEventDispatcher.Broadcast(MultiKeyArray.Keys);
}



void UEditorActionMultInputInterpreter::ReceiveReleased(FKey ReleasedKey)
{
	// 이 키가 멀티키가 트리거 되지 않았는지 체크합니다.
	bool bKeyIsPressed = false;
	if (PressedKeys.Contains(ReleasedKey))
	{
		bKeyIsPressed = true;
	}

	// 이 키가 멀티키가 트리거 되었는지 체크합니다.
	// 위 결과와 합쳤을 때 두 플래그 중 하나만 참이어야 합니다.
	bool bKeyIsTriggered = false;
	for (const auto& it : TriggerKeys)
	{
		if (it.Keys.Contains(ReleasedKey))
		{
			bKeyIsTriggered = true;
			break;
		}
	}

	// 두 플래그 모두 거짓이나 참일 수 없습니다.
	if ((bKeyIsPressed == false && bKeyIsTriggered == false)
		|| (bKeyIsPressed == true && bKeyIsTriggered == true))
	{
		VP_LOG(Warning, TEXT("Released 되려는 키가 눌려진 상태와 트리거된 상태 \
			모두에 포함되거나 모두에 포함되지 않습니다. 이 로그를 런타임 중에 \
			확인하게 된다면 즉시 디버깅을 시작하시기 바랍니다."));
		return;
	}



	// 단지 멀티키 입력 발동이 되지 않은 키라면 키 배열에서 제거합니다.
	if (bKeyIsPressed == true)
	{
		PressedKeys.Remove(ReleasedKey);
	}
	// 멀티키 입력이 발동 중인 키라면 트리거 키 배열에서 제거하면서 
	// 이벤트를 브로드캐스트합니다.
	if (bKeyIsTriggered == true)
	{
		FKeyArray ShouldBeRemoved;
		for (const auto& it : TriggerKeys)
		{
			if (it.Keys.Contains(ReleasedKey))
			{
				ShouldBeRemoved = it;
				break;
			}
		}

		TriggerKeys.Remove(ShouldBeRemoved);


		// 트리거된 멀티키에 대한 멀티키 배열을 구해 브로드캐스팅합니다.
		TArray<FKey> BroadCastedKeys = ShouldBeRemoved.Keys;
		MultiKeyTriggerEndEventDispatcher.Broadcast(BroadCastedKeys);
	}
}





bool UEditorActionMultInputInterpreter::ValidateMultiKeyAction(FName MultiKeyActionName)
{
	// InputSettings의 유효성을 검사합니다.
	if (IsValid(InputSettings) == false)
	{
		VP_LOG(Error, TEXT("InputSetting이 유효하지 않습니다"));
		return false;
	}

	// 멀티키 액션을 위한 구분자를 준수하고 있는지 검사합니다.
	FString MultiKeyActionString = MultiKeyActionName.ToString();
	if (MultiKeyActionString.Contains(MultiKeyActionDelimeter) == false)
	{
		VP_LOG(Log, TEXT("액션 이름에 다음 구분자가 포함되어야 합니다 : %s."), *MultiKeyActionDelimeter);
		return false;
	}



	TArray<FName> ActionNames;
	InputSettings->GetActionNames(ActionNames);

	// 액션 이름들 중에서 로컬 세팅과 매치되는 것이 있으면 true를 반환합니다.
	for (const auto& it : ActionNames)
	{
		if (it == MultiKeyActionName)
		{
			if (MultiKeyActionMappings.Contains(it) == true)
			{
				return true;
			}
			else
			{
				VP_LOG(Log, TEXT("멀티키 액션(%s)이 InputSettings애눈 등록되어 있지만, \
						로컬 컨테이너에 등록되어 있지 않습니다"));
				return false;
			}
		}
	}
	
	// 존재하지 않으면 false를 반환합니다.
	return false;
}





bool UEditorActionMultInputInterpreter::ValidateMultiKeyActionFast(FName MultiKeyActionName)
{
	// InputSettings의 유효성을 검사합니다.
	if (IsValid(InputSettings) == false)
	{
		VP_LOG(Error, TEXT("InputSetting이 유효하지 않습니다"));
		return false;
	}

	// 멀티키 액션을 위한 구분자를 준수하고 있는지 검사합니다.
	FString MultiKeyActionString = MultiKeyActionName.ToString();
	if (MultiKeyActionString.Contains(MultiKeyActionDelimeter) == false)
	{
		VP_LOG(Log, TEXT("액션 이름에 다음 구분자가 포함되어야 합니다 : %s."), *MultiKeyActionDelimeter);
		return false;
	}



	TArray<FName> ActionNames;
	InputSettings->GetActionNames(ActionNames);

	// 액션 이름들 중에서 로컬 세팅과 매치되는 것이 있으면 참을 반환합니다.
	for (const auto& it : ActionNames)
	{
		if (it == MultiKeyActionName)
		{
			return true;
		}
	}

	// 존재하지 않으면 거짓을 반환합니다.
	return false;
}



bool UEditorActionMultInputInterpreter::ValidateMultiKey(FInputActionKeyMapping MultiKeyMapping)
{
	// 액션 이름의 유효성을 간소화하여 검사합니다.
	bool bActionIsValid = ValidateMultiKeyActionFast(MultiKeyMapping.ActionName);
	if (bActionIsValid == false)
	{
		return false;
	}

	// 멀티키임을 알리려면 Alt, Cmd, Ctrl, Shift 모디파이어 키가 모두
	// 체크되어 있어야 합니다.
	if (MultiKeyMapping.bAlt &&
		MultiKeyMapping.bCmd &&
		MultiKeyMapping.bCtrl &&
		MultiKeyMapping.bShift)
	{
		return true;
	}

	// 그렇지 않으면 거짓을 반환합니다.
	return false;
}
