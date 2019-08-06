// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool/ToolBase.h"
#include "SightToolBase.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTriggerFocusEventDispatcher, UCommandBase*, TriggeredCommand);

/**
 *	SIghtToolBase는 도구들 중에서 사용자의 시선에 대한
 *	명령 수행이 가능한 도구들에 대한 Base class입니다.
 *	사용자의 High Level Focus 정보를 해석하여 알맞은 명
 *	령을 실행시켜 줍니다. 모든 시선 관련 도구들은 이 클
 *	래스로부터 상속받아야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API USightToolBase : public UToolBase
{
	GENERATED_BODY()
	
public:
	/* 사용자로부터 포커스를 받아 적절한 커맨드를 실행합니다.
	반드시 파생클래스에서 구현해야 합니다 */
	virtual UCommandBase* HandleFocus(FHighLevelFocusData Focus);



	/* FocusAvailables의 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category = "Tool")
	FORCEINLINE TMap<EFocusMetadata, FSubclassOfCommandBase> GetFocusAvailables() const
	{
		return FocusAvailables;
	}



	/* TriggerFocusEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FTriggerFocusEventDispatcher& OnTriggerFocus()
	{
		return TriggerFocusEventDispatcher;
	}





private:
	/* 도구가 실행할 수 있는 시선 관련 커맨드들을 담은 컨테이너입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "Tool", meta = (AllowPrivateAccess = true),
		BlueprintGetter = GetFocusAvailables)
	TMap<EFocusMetadata, FSubclassOfCommandBase> FocusAvailables;

	/* 도구가 포커스 관련 명령을 실행했을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Tool|Delegate",
		meta = (AllowPrivateAccess = true))
	FTriggerFocusEventDispatcher TriggerFocusEventDispatcher;
};
