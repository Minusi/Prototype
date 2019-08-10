// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Array.h"
#include "CommandBase.h"
#include "CommandQueue.generated.h"



class UCommandBase;



/**
 *	CommandQueue는 명령 취소/재실행 등의 기능을 지원하기 위한
 *	클래스입니다. 커맨드 큐에 삽입되는 것은 반드시 UCommandBa
 *	se 클래스를 상속받은 것이어야 합니다.
 *
 *	사실 CommandQueue 이름은 기능상 CommandStack이 옳습니다.
 *	이는 초창기 설계 때 미흡했던 것이 드러나는 부분입니다 :/
 */
UCLASS()
class UEPROTOTYPE_API UCommandQueue : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UCommandQueue();
	
private:
	/* 도구의 이벤트 디스패처에 함수를 바인드합니다 */
	UFUNCTION()
	void BindToEvents();


private:
	/* 실행된 명령을 담습니다 */
	UFUNCTION()
	void AddUndoQueue(UCommandBase* CommandExecuted);

	/* 명령을 취소합니다. */
	UFUNCTION(BlueprintCallable, Category="Command")
	void Undo();

	/* 취소한 명령을 재실행합니다 */
	UFUNCTION(BlueprintCallable, Category="Command")
	void Redo();



	/* (편집 전용) 실행된 명령을 담습니다. */
	void AddUndoEditQueue(UCommandBase* CommandExecuted);

	/* (편집 전용) 명령을 취소합니다. */
	UFUNCTION(BlueprintCallable, Category="Command")
	
	void UndoEdit();

	/* (편집 전용) 취소한 명령을 재실행합니다 */
	UFUNCTION(BlueprintCallable, Category="Command")
	void RedoEdit();





private:
	/* 실행 취소 기능에 수행될 명령 큐입니다*/
	UPROPERTY()
	TArray<UCommandBase*> UndoQueue;

	/* 실행 취소 기능에 수행될 편집 전용 명령 큐입니다.
		편집 기능을 종료하면 비워집니다 */
	UPROPERTY()
	TArray<UCommandBase*> UndoEditQueue;

	/* 다시 실행 기능에 수행될 명령 큐입니다. */
	UPROPERTY()
	TArray<UCommandBase*> RedoQueue;

	/* 다시 실행 기능에 수행될 편집 전용 명령 큐입니다 
		편집 기능을 종료하면 비워집니다. */
	UPROPERTY()
	TArray<UCommandBase*> RedoEditQueue;

};
