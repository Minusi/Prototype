// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommandConstraintManager.generated.h"



class UCmdUnfocusedConstraint;
class UCmdFocusedConstraint;
class UCmdHighlightedConstraint;
class UCmdActivatedConstraint;



/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UCommandConstraintManager : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UCommandConstraintManager();
	
private:
	/*	월드 컨텍스트를 가지고 있는 CDO인지 여부를 판단합니다.
	이것을 수행하는 이유는 AEditorWorldManager의 구성 요소들만이 유효한
	프레임워크 플로우를 따를 수 있기 때문입니다. */
	UFUNCTION()
	bool ContainWorldContextCDO();

	/* 모든 제약조건들을 초기화합니다 */
	UFUNCTION()
	void InitializeConstraints();



public:
	/* CommandModuleManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Command", meta = (UnsafeDuringActorConstruction = "true"))
	static UCommandConstraintManager* GetGlobalCommandConstraintManager();
	
	/* CmdUnfocusedConstraint의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category="Command")
	FORCEINLINE UCmdUnfocusedConstraint* GetCmdUnfocusedConstraint() const
	{
		return CmdUnfocusedConstraint;
	}

	/* CmdFocusedConstraint의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category="Command")
		FORCEINLINE UCmdFocusedConstraint* GetCmdFocusedConstraint() const
	{
		return CmdFocusedConstraint;
	}

	/* CmdFocusedConstraint의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category = "Command")
	FORCEINLINE UCmdHighlightedConstraint* GetCmdHighlightedConstraint() const
	{
		return CmdHighlightedConstraint;
	}

	/* CmdFocusedConstraint의 Getter입니다 */
	UFUNCTION(BlueprintGetter, Category = "Command")
	FORCEINLINE UCmdActivatedConstraint* GetCmdActivatedConstraint() const
	{
		return CmdActivatedConstraint;
	}
	
	
	
	
private:
	/* 액터의 Unfocused에 대한 제약조건입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Command", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetCmdUnfocusedConstraint)
	UCmdUnfocusedConstraint * CmdUnfocusedConstraint;

	/* 액터의 Focused에 대한 제약조건입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Command", meta = (AllowPrivateAccess = true),
		BlueprintGetter = GetCmdFocusedConstraint)
	UCmdFocusedConstraint* CmdFocusedConstraint;

	/* 액터의 Highlighted에 대한 제약조건입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Command", meta = (AllowPrivateAccess = true),
	BlueprintGetter = GetCmdHighlightedConstraint)
	UCmdHighlightedConstraint* CmdHighlightedConstraint;

	/* 액터의 Activated에 대한 제약조건입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Command", meta = (AllowPrivateAccess = true),
	BlueprintGetter = GetCmdActivatedConstraint)
	UCmdActivatedConstraint* CmdActivatedConstraint;
};
