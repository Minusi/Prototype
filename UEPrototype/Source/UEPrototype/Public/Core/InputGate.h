// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputGate.generated.h"

/**
 *	UInputGate는 내부 플래그에 따라서 사용자의 입력을 차단하기 위해
 *	고안된 단순한 bool 래퍼 클래스입니다. 전적으로 UEditorInterpret
 *	erManager 클래스에서 생성 및 관리되어야 하며, 다른 클래스에서 
 *	사용하는 것을 금지합니다. 
 *
 *	용도는 APlayerController에서 파생된 클래스에서 각각의 축 및 액션
 *	이벤트에 대해서 입력을 차단하거나 허용하는 단순한 게이트 역할을
 *	수행합니다.
 */
UCLASS()
class UEPROTOTYPE_API UInputGate : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자입니다. */
	UInputGate();
	
	/* 입력 차단 여부를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category = "Core|Input")
	FORCEINLINE bool IsInputBlocked() const
	{
		return bInputBlocked;
	}

	/* 입력 차단 여부를 토글합니다 */
	UFUNCTION(BlueprintCallable, Category = "Core|Input")
	void ToggleInputBlock();

	/* 입력 차단 여부를 설정합니다 */
	UFUNCTION(BlueprintSetter, Category = "Core|Input")
	void SetInputBlocked(bool bNeedBlock);


private:
	/* 입력을 차단할 지에 대한 플래그입니다 */
	UPROPERTY(BlueprintGetter=IsInputBlocked, BlueprintSetter=SetInputBlocked, Category = "Core|Input", meta = (AllowPrivateAccess = true))
	bool bInputBlocked;
};
