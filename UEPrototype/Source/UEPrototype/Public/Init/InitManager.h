// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "InitManager.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInitEventDispatcher);
DECLARE_DYNAMIC_DELEGATE(FReferenceDelegate);


/*
 *	AInitManager는 단 하나만 생성되어야 하는, 또는 게임 시작시
 *	초기화되어야 하는 것들을 초기화하는 클래스입니다.
 */
UCLASS(abstract)
class UEPROTOTYPE_API AInitManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInitManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// 단 한 개만 생성되어야 할 것들을 모두 초기화(스폰)합니다.
	UFUNCTION(BlueprintCallable, Category = "Prototpe|Init")
		void InitializeUniques();

	// 유니크 객체를 필요로 하는 객체가 안전하게 레퍼런싱하도록 합니다.
	UFUNCTION(BlueprintCallable, Category = "Prototpe|Init")
		void SafeRefUniqueToActor(FReferenceDelegate EventToBind);

private:
	// InitManager가 유키드 초기화를 전부 수행했을 때 발생시킬 이벤트입니다.
	// bUniquesEndInit을 true로 전환합니다.
	UFUNCTION(BlueprintCallable, Category = "Prototype|Init", meta = (AllowPrivateAccess = "true"))
		void OnEndInitEvent();


public:
	// 초기화 매니저가 유니크 초기화를 수행한 이후에 이것들을 필요로 하는
	// 대상에게 브로드캐스트하기 위한 이벤트 디스패처입니다.
	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Prototype|Init")
		FInitEventDispatcher OnUniquesEndInit;

private:
	// 유니크들이 모두 초기화를 마쳤는지 여부입니다.
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Prototype|Init", meta = (AllowPrivateAccess = "true"))
		bool bUniquesEndInit;

};
