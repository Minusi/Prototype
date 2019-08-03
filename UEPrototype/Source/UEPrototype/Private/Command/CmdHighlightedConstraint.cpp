// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/CmdHighlightedConstraint.h"
#include "UEPrototype.h"



bool UCmdHighlightedConstraint::CheckConstraint(FActorConstraintInfo TargetInfo)
{
	/* 제약 조건을 검사하기 위한 액터의 유효성을 검사합니다 */
	if (IsValid(TargetInfo.Target) == false)
	{
		VP_LOG(Warning, TEXT("제약 조건을 확인하기 위한 액터가 유효하지 않습니다."));
		return false;
	}

	/* 액터의 상태가 Highlighted 상태이면 참을 반환합니다 */
	if (TargetInfo.TargetState == EActorConstraintState::CSTR_Highlighted)
	{
		return true;
	}

	return false;
}