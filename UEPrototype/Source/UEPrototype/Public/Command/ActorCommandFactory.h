// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorConstraintMarker.h"
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
	//template<typename CmdType>
	//static CmdType* CreateCommand<CmdType>(const FActorConstraintInfo)
	//{
	//	
	//}
};
