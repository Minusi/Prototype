// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module/ModuleManagerBase.h"
#include "ActorInfoModuleManager.generated.h"



class UOutliner;
class UActorConstraintMarker;
class UActorPlaceInfoMarker;



/**
 *	ActorInfo 모듈을 관리하는 관리자 클래스입니다.
 *  ActorInfo 모듈의 단 하나만 생성되어야 하는 컴포넌트들의 생성 및
 *	안전한 참조를 보장합니다.
 */
UCLASS()
class UEPROTOTYPE_API UActorInfoModuleManager : public UModuleManagerBase
{
	GENERATED_BODY()
	
	
public:
	/* 생성자 */
	UActorInfoModuleManager();

	/* ActorInfoModuleManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (WorldContext = "WorldContextObject",
		UnsafeDuringActorConstruction = "true"))
	static UActorInfoModuleManager* GetGlobalActorInfoModuleManager();
	
protected:
	/* 모듈 컴포넌트들을 초기화합니다 */
	virtual void Initialized() override;





private:
	/* 윤곽선을 그려주는 Outliner입니다 */
	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true))
	UOutliner * Outliner;

	/* 액터의 Constraint 상태의 변경을 알립니다 */
	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true))
	UActorConstraintMarker* ActorConstraintMarker;

	/* 액터의 PlaceInfo 상태의 변경을 알립니다 */
	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true))
	UActorPlaceInfoMarker* ActorPlaceInfoMarker;
};
