// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "ActivateCommand.generated.h"



class UActorConstraintMarker;
class UOutliner;



/*
 *
 */
UCLASS()
class UEPROTOTYPE_API UActivateCommand : public UActorCommandBase
{
	GENERATED_BODY()
public:
	/* 생성자 */
	UActivateCommand();

	/* UCommandBase로부터 상속됨 */
	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;





private:
	/* 오브젝트를 활성화 상태로 변경하기 위한 마커입니다. */
	static UActorConstraintMarker* ActorConstraintMarker;

	/* 물체에 윤곽선을 그려줍니다. */
	static UOutliner* Outliner;
};
