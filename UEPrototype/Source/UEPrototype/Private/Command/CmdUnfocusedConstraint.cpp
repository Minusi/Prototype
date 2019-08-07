// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/CmdUnfocusedConstraint.h"
#include "UEPrototype.h"



bool UCmdUnfocusedConstraint::CheckConstraint(FActorConstraintInfo TargetInfo)
{
	/* 제약 조건을 검사하기 위한 액터의 유효성을 검사합니다 */
	if (IsValid(TargetInfo.Target) == false)
	{
		VP_LOG(Warning, TEXT("제약 조건을 확인하기 위한 액터가 유효하지 않습니다."));
		return false;
	}

	/* 액터의 상태가 Unfocused 상태이면 참을 반환합니다 */
	if (TargetInfo.TargetState == EActorConstraintState::CSTR_Unfocused)
	{
		return true;
	}

	return false;
}