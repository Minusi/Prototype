// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PrototypeStateBase.generated.h"



class UToolManager;



/**
 *	PrototypeStateBase는 유저가 프로토타이핑 중일 때, 특정
 *	작업 상태로 들어갈 때(예를 들어, 애셋 편집 상태나 트랜
 *	스폼 상태 등) 선행되어야 할 모든 작업들을 일괄처리하는
 *	State 패턴 기반의 Base class입니다. 모든 상태 클래스들
 *	은 이 클래스로부터 파생되어야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API UPrototypeStateBase : public UObject
{
	GENERATED_BODY()
	
public:
	/* 상태로 진입할 때 필요한 것들을 설정합니다. 파생 클래
	스에서 반드시 구현되어야 합니다. */
	virtual void SetupState();





protected:
	/* 도구를 관리하는 관리자 클래스입니다 */
	UPROPERTY(BlueprintReadonly, Category="Core|Player", meta=(AllowPrivateAcces=true))
	UToolManager * ToolManager;
};
