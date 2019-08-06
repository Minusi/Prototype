// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorConstraintMarker.h"
#include "UEPrototype.h"
#include "ActorCommandBase.h"
#include "ActorCommandFactory.generated.h"



/**
 *	ActorCommandBase 파생 클래스들을 생성하는 팩토리 클래스
 *	입니다. 액터 커맨드를 생성하면서 동시에 초기화까지 담당
 *	합니다.
 */
UCLASS()
class UEPROTOTYPE_API UActorCommandFactory : public UObject
{
	GENERATED_BODY()
	
public:
	/* 액터 커맨드를 생성하여 후처리한 후 반환합니다 */
	template<typename CmdType>
	static FORCEINLINE CmdType* CreateActorCommand(const FActorConstraintInfo Target)
	{
		UActorCommandBase* ActorCommand = Cast<UActorCommandBase>(NewObject<CmdType>());
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}
};
