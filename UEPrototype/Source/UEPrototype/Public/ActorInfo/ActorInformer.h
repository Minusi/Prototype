// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorInformer.generated.h"



class UHUDWorldPositioner;
class UWidgetComponent;



UCLASS()
class UEPROTOTYPE_API AActorInformer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorInformer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	/* HUDWorldPositioner을 반환합니다 */
	UFUNCTION(BlueprintGetter, Category = "ActorInfo")
	FORCEINLINE UHUDWorldPositioner* GETHUDWorldPositioner() const
	{
		return HUDWorldPositioner;
	}





private:
	/* 위젯을 배치할 컴포넌트입니다. 위젯은 DynamicListWidget을 상속받은
	위젯이어야 합니다. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ActorInfo", meta = (AllowPrivateAccess = true))
	UWidgetComponent * WidgetComponent;

	/* 적절한 위치에 HUD 배치를 계산해주는 컴포넌트입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "ActorInfo", meta = (AllowPrivateAccess = true),
				BlueprintGetter = GetHUDWorldPositioner)
	UHUDWorldPositioner * HUDWorldPositioner;
};
