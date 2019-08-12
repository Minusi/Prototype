// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tool/ToolBase.h"
#include "BasicTool.generated.h"



class UCommandBase;
class AUserBlackBoard;



/**
 *	BasicTool은 VR Prototype에서 가장 일반적인 기능을
 *	수행하기 위한 도구입니다. 기초적인 상호 작용을 담
 *	당하고 있으며, 수행가능한 기능이 다음과 같습니다.
 *
 *	- 액터 활성화 / 비활성화
 *	- 컨텍스트 메뉴 호출
 *	- 시스템 메뉴 호출
 *	- 행동 취소 / 취소된 행동 되돌리기
 *	- 취소 (메뉴 닫기. 활성화 취소 등)
 *	- 텔레포트
 *
 *	추후 추가된 기능이 생기면 반드시 다른 사람의 이해
 *	를 위해서 위의 기능 목록에 추가로 등록해 주시길
 *	바랍니다.
 */
UCLASS()
class UEPROTOTYPE_API UBasicTool : public UToolBase
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UBasicTool();

	/* BasicTool을 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Tool", meta = (UnsafeDuringActorConstruction = "true"))
	static UBasicTool* GetGlobalBasicTool();

	/* UserBlackBoard의 Getter입니다. */
	UFUNCTION(BlueprintGetter, Category="Tool")
	FORCEINLINE AUserBlackBoard* GetUserBlackBoard() const
	{
		return UserBlackBoard;
	}

private:
	/* BeginPlay 시점에 실행됩니다. */
	UFUNCTION()
	void ModuleBeginPlay();



public:
	/* ToolBase로부터 상속됨 */
	virtual UCommandBase* HandleInput(FHighLevelInputData Input) override;

	/* ToolBase로부터 상속됨 */
	virtual bool HasTriggerableCommand(FHighLevelInputData Input) override;

protected:
	/* 커맨드들을 바인드합니다. */
	virtual void RegisterCommands() override;





private:
	/* 유저의 상호작용에 대한 정보를 기록하는 블랙보드입니다. */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetUserBlackBoard)
	AUserBlackBoard * UserBlackBoard;
};
