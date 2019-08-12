// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Map.h"
#include "Misc/FrameNumber.h"
#include "ToolKit.generated.h"



class UToolBase;



/**
 *	ToolKit은 모든 도구들을 담고 있는 가방과 같은 클래스
 *	입니다. 모든 도구들은 하나씩만 담겨야 합니다.
 */
UCLASS()
class UEPROTOTYPE_API UToolKit : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UToolKit();

	/* ToolKit을 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Tool", meta = (UnsafeDuringActorConstruction = "true"))
	static UToolKit* GetGlobalToolKit();



private:
	/* 모듈로부터 필요한 컴포넌트들을 구해 도구 리스트들을 초기화합니다 */
	UFUNCTION()
	void BindToEvents();
	


public:
	/* 해당 도구를 사용할 수 있는지 여부입니다 */
	UFUNCTION(BlueprintCallable, Category="Tool")
	bool IsAvaliable(const UToolBase* Tool);

private:
	/* 도구의 사용여부를 설정합니다 */
	UFUNCTION()
	void SetToolAvailable(UToolBase* Tool, bool bAvailable);
	
	UFUNCTION()
	void SetToolEnabled(UToolBase* Tool);

	UFUNCTION()
	void SetToolUnenabled(UToolBase* Tool);



public:
	/* 도구 리스트를 사용 가능 여부와 함께 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Tool")
	FORCEINLINE TMap<UToolBase*, bool> GetToolList() const
	{
		return ToolList;
	}





private:
	/* 도구 리스트입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Tool", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetToolList)
	TMap<UToolBase*, bool> ToolList;
};
