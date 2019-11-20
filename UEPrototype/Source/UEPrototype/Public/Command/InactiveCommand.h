// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "InactiveCommand.generated.h"

class UActorConstraintMarker;
class UOutliner;
//class AUserBlackBoard;
class UPlayerTaskManager;

/**
 *
 */
UCLASS()
class UEPROTOTYPE_API UInactiveCommand : public UActorCommandBase
{
	GENERATED_BODY()

public:
	/* 생성자 */
	UInactiveCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

private:
	/* 오브젝트를 비활성화 상태로 변경하기 위한 마커입니다. */
	static UActorConstraintMarker* ActorConstraintMarker;

	/* 오브젝트에 윤곽선을 그려주는 도구입니다. */
	static UOutliner* Outliner;

	/* 사용자의 상호작용 상태를 읽어오기 위한 블랙보드입니다. */
	//static AUserBlackBoard* UserBlackBoard;

	static UPlayerTaskManager* PlayerTaskManager;
};
