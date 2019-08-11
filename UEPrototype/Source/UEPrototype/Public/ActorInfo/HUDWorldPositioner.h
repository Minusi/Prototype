// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HUDWorldPositioner.generated.h"



class AActor;
class UUserWidget;

UENUM(BlueprintType)
enum class UIDirectionType: uint8
{
	Right UMETA(DisplayName = "Right"),
	Left 	UMETA(DisplayName = "Left")
	
};


/**
 *	HUDWorldPositioner는 사용자와 상호작용하는 UI가 3D
 *	스페이스에서 어디에 위치하면 좋을지를 판단하고 위치
 *	를 반환하는 클래스입니다.
 */
UCLASS()
class UEPROTOTYPE_API UHUDWorldPositioner : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UHUDWorldPositioner();

	/* HUDWorldPositioner를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static UHUDWorldPositioner* GetGlobalHUDWorldPositioner();


public:
	/* 이전에 HUD를 띄우기 위해 사용되었던 Actor를 반환합니다. */
	UFUNCTION(BlueprintGetter, Category="ActorInfo")
	FORCEINLINE AActor* GetPrevActor() const
	{
		return PrevActor;
	}

	/* 이전에 액터의 정보를 표시하기 위해 띄웠던 위젯을 반환합니다. */
	UFUNCTION(BlueprintGetter, Category="ActorInfo")
		FORCEINLINE UUserWidget* GetPrevWidget() const
	{
		return PrevWidget;
	}
	
public:
	/* 액터와 위젯을 받아 위젯이 생성되기에 적절한 위치를 찾아 위젯의
	   위치를 옮깁니다. */
	UFUNCTION(BlueprintCallable, Category="ActorInfo")
	void ApplyWidgetPosition(const AActor* Target, AActor* InOutWidget,UIDirectionType Direction);





private:
	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true),
		BlueprintGetter=GetPrevActor)
	AActor * PrevActor;

	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true),
		BlueprintGetter=GetPrevWidget)
	UUserWidget* PrevWidget;
};
