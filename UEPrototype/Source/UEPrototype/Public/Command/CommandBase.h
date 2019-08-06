// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommandBase.generated.h"

/**
 *	CommandBase 클래스는 모든 커맨드의 Base Class입니다. 명령 패턴으로
 *	설계되어 있으며, 모든 명령은 이것을 상속받아야 합니다. 주요 기능은
 *	명령의 실행과 되돌리기입니다.
 */
UCLASS()
class UEPROTOTYPE_API UCommandBase : public UObject
{
	GENERATED_BODY()
	
public:
	/* 조건을 만족하면 명령을 실행합니다 */
	UFUNCTION()
	virtual void ExecuteIf();
	
	/* 실행한 명령을 취소합니다 */
	UFUNCTION()
	virtual void Undo();



protected:
	/* 명령을 취소할 수 있는 지에 대한 플래그입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Command", meta=(AllowPrivateAccess=true))
	bool bCanUndo = false;
};
