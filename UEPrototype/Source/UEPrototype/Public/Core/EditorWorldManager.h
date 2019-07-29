// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "GameFramework/Actor.h"
#include "ActorConstraintMarker.h"
#include "ActorPlaceInfoMarker.h"
#include "EditorWorldManager.generated.h"



class UEditorModulesManager;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlockedActorAddedEventDispatcher, AActor*, BlockedActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlockedActorRemovedEventDispatcher, AActor*, UnblockedActor);



/*	
 *	EditorWorldManager는 월드 전체를 관리하는 관리자 클래스입니다.
 *	최종적으로 멀티 플레이어 기능까지 고려하고 있는 입장에서, 사용
 *	자들이 편집 중인 물체를 다른 사용자가 무단으로 변경하지 못하거
 *	나 하는 기능들을 포함하여, 월드에 놓인 물체에 대한 종합적인 정
 *	보를 제공합니다.
 *	
 *	VPGameStateBase와 마찬가지로 기능 확장 가능성이 높습니다.
 */
UCLASS(notplaceable)
class UEPROTOTYPE_API AEditorWorldManager : public AActor
{
	GENERATED_BODY()

public:	
	/* 생성자 */
	AEditorWorldManager();



public:
	/* BlockedActor를 사본으로 반환하는 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category="Core|World")
	FORCEINLINE TArray<FActorConstraintInfo> GetBlockedActors() const
	{
		return BlockedActors;
	}

	/* ActorsPlaceInfo를 사본으로 반환하는 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category="Core|World")
	FORCEINLINE TArray<FActorPlaceInfo> GetActorsPlaceInfo() const
	{
		return ActorsPlaceInfo;
	}

	/* 액터가 Blocked 상태인지 여부를 반환합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|World")
	bool IsActorBlocked(const AActor* InTarget) const;

	/* 배치된 액터의 정보를 반환합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|World")
	void GetActorPlaceContent(const AActor* InTarget, FActorPlaceContent& OutContent) const;



	/* 월드 에디터 매니저를 반환합니다(전역 접근 가능) */
	UFUNCTION(BlueprintCallable, Category = "Core|World", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static AEditorWorldManager* GetGlobalEditorWorldManager(const UObject* WorldContextObject);

	/* 에디터 모듈 매니저를 반환합니다(전역 접근 가능) */
	UFUNCTION(BlueprintCallable, Category = "Core|World", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static UEditorModulesManager* GetGlobalEditorModulesManager(const UObject* WorldContextObject);

	/* AEditorWorldManager를 이용하여 에디터 모듈 매니저를 바로 반환받습니다.(전역 접근 가능) */
	UFUNCTION(BlueprintCallable, Category = "Core|World")
	static UEditorModulesManager* GetGlobalEditorModulesManagerFast(const AEditorWorldManager* InEditorWorldManager);



private:
	/* EditorModulesManager의 Getter 함수입니다 */
	UFUNCTION()
	FORCEINLINE UEditorModulesManager* GetEditorModulesManager() const
	{
		return EditorModulesManager;
	}



public:	/* 이벤트와 관련된 함수입니다. 브로드캐스트하거나 받는 함수들을 모아놓습니다 */
	


	/* BlockedActorAddedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FBlockedActorAddedEventDispatcher OnBlockedActorAdded() const
	{
		return BlockedActorAddedEventDispatcher;
	}

	/* BlockedActorRemovedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FBlockedActorRemovedEventDispatcher OnBlockedActorRemoved() const
	{
		return BlockedActorRemovedEventDispatcher;
	}




private:
	/* 모듈들을 관리하는 최상위 매니저입니다 */
	UEditorModulesManager * EditorModulesManager;

	/* 현재 블록된 액터들을 관리하는 컨테이너입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAccess=true))
	TArray<FActorConstraintInfo> BlockedActors;

	/* 현재 배치된 액터들을 관리하는 컨테이너입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAccess=true))
	TArray<FActorPlaceInfo> ActorsPlaceInfo;



	/* 블록된 액터가 추가될 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Core|World|Delegate",
				meta=(AllowPrivateAccess=true))
	FBlockedActorAddedEventDispatcher BlockedActorAddedEventDispatcher;

	/* 블록된 액터가 제거될 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Core|World|Delegate",
				meta = (AllowPrivateAccess = true))
	FBlockedActorRemovedEventDispatcher BlockedActorRemovedEventDispatcher;
};
 