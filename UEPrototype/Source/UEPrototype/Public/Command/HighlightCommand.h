// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "HighlightCommand.generated.h"



class AActor;
class UOutliner;
class UActorConstraintMarker;



/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UHighlightCommand : public UActorCommandBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UHighlightCommand();

	/* UCommandBase로부터 상속됨 */
	
	virtual void ExecuteIf() override;
	
	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;


private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	/* 물체에 윤곽선을 그려줍니다 */
	static UOutliner* Outliner;




};
