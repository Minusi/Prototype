// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Map.h"
#include "Core/EditorActionMetaInputInterpreter.h"
#include "Core/EditorFocusMetaInputInterpreter.h"
#include "Command/CommandBase.h"
#include "ToolBase.generated.h"



class UCommandBase;



/*	UE4에서 TMap<__SomeType__, TSubclassOf<__OtherType__>을
 *	UPROPERTY로 지원하지 않기 떄문에 우회하기 위해 만들어진
 *	우회 구조체입니다. ActionAvailables 및 FocusAvailables
 *	에서 사용됩니다.
 */
USTRUCT(BlueprintType)
struct FSubclassOfCommandBase
{
	GENERATED_BODY()

public:

	/* == 연산자 오버로딩 */
	bool operator==(const FSubclassOfCommandBase& Rhs)
	{
		return CommandClass == Rhs.CommandClass;
	}



public:
	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<UCommandBase> CommandClass;
};





DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTriggerCommandEventDispatcher, UCommandBase*, TriggeredCommand);



/**
 *	ToolBase는 도구를 나타내는 Base class입니다. 도구는 사용자의
 *	입력과 소통하는 High Level 인터페이스로, Low-Level 커맨드를
 *	입력에 맞게 실행시켜주는 역할을 수행합니다. 모든 도구들은 이
 *	클래스로부터 상속받아야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API UToolBase : public UObject
{
	GENERATED_BODY()
	
	
public:
	/* 사용자로부터 입력을 받아 맞는 적절한 커맨드를 실행합니다.
		반드시 파생클래스에서 구현해야 합니다 */
	virtual UCommandBase* HandleInput(FHighLevelInputData Input);

	/* 주어진 입력이 도구의 기능을 활성화시킬 수 있는지 여부를 반환합니다. */
	virtual bool HasTriggerableCommand(FHighLevelInputData Input);
	

	
	/* ActionAvailables의 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category="Tool")
	FORCEINLINE TMap<FHighLevelInputData, FSubclassOfCommandBase> GetActionAvailables() const
	{
		return ActionAvailables;
	}



	/* TriggerCommandEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FTriggerCommandEventDispatcher& OnTriggerCommand()
	{
		return TriggerCommandEventDispatcher;
	}




	
protected:
	/* 도구가 실행할 수 있는 커맨드들을 담은 컨테이너입니다. */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetActionAvailables)
	TMap<FHighLevelInputData, FSubclassOfCommandBase> ActionAvailables;



	/* 도구가 명령을 실행했을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Tool|Delegate",
				meta = (AllowPrivateAccess = true))
	FTriggerCommandEventDispatcher TriggerCommandEventDispatcher;
};
