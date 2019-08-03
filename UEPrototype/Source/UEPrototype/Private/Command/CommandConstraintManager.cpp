// Fill out your copyright notice in the Description page of Project Settings.

#include "Command/CommandConstraintManager.h"
#include "UEPrototype.h"
#include "UObjectIterator.h"
#include "EditorWorldManager.h"
#include "Command/CmdUnfocusedConstraint.h"
#include "Command/CmdFocusedConstraint.h"
#include "Command/CmdHighlightedConstraint.h"
#include "Command/CmdActivatedConstraint.h"



UCommandConstraintManager::UCommandConstraintManager()
{
	// DEBUG
	VP_CTOR;

	/* 월드 컨텍스트를 포함하지 않는 CDO는 프레임워크에서 필요로 하지 않는 CDO이므로,
	더이상의 초기화를 수행하지 않습니다 */
	if (ContainWorldContextCDO() == false)
	{
		return;
	}

	InitializeConstraints();
}



bool UCommandConstraintManager::ContainWorldContextCDO()
{
	/* OuterChain을 거슬러 올라가면서, AEditorWorldManager가 있는지 탐색합니다 */
	UObject* OuterChain = this;
	while ((OuterChain = OuterChain->GetOuter()) != nullptr)
	{
		/* OuterChain에 AEditorWorldManager가 있으면 참을 반환합니다. */
		if (OuterChain->GetClass() == AEditorWorldManager::StaticClass())
		{
			return true;
		}
	}

	return false;
}



void UCommandConstraintManager::InitializeConstraints()
{
	/* 제약조건들을 모두 초기화합니다 */
	CmdUnfocusedConstraint = CreateDefaultSubobject<UCmdUnfocusedConstraint>(UCmdUnfocusedConstraint::StaticClass()->GetFName());
	CmdFocusedConstraint = CreateDefaultSubobject<UCmdFocusedConstraint>(UCmdFocusedConstraint::StaticClass()->GetFName());
	CmdHighlightedConstraint = CreateDefaultSubobject<UCmdHighlightedConstraint>(UCmdHighlightedConstraint::StaticClass()->GetFName());
	CmdActivatedConstraint = CreateDefaultSubobject<UCmdActivatedConstraint>(UCmdActivatedConstraint::StaticClass()->GetFName());



	/* 제약조건들의 유효성을 검사합니다 */
	if (IsValid(CmdUnfocusedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdUnfocusedConstraint::StaticClass()->GetName());
		return;
	}
	if (IsValid(CmdFocusedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdFocusedConstraint::StaticClass()->GetName());
		return;
	}
	if (IsValid(CmdHighlightedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdHighlightedConstraint::StaticClass()->GetName());
		return;
	}
	if (IsValid(CmdActivatedConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCmdActivatedConstraint::StaticClass()->GetName());
		return;
	}
}

UCommandConstraintManager * UCommandConstraintManager::GetGlobalCommandConstraintManager()
{
	for (const auto& it : TObjectRange<UCommandConstraintManager>())
	{
		if (it->ContainWorldContextCDO())
		{
			return it;
		}
	}

	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::StaticClass()->GetName());
	return nullptr;
}
