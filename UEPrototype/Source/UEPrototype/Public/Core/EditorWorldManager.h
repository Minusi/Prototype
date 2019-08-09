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
UCLASS()
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



private:
	/* 함수들을 이벤트에 바인드합니다 */
	UFUNCTION()
	void BindToEvents();

	/* 액터의 상태가 변경되었을 때 Blocked상태인지 확인하고 맞을 때, 컨테이너에 추가합니다 */
	UFUNCTION()
	void UpdateBlockedActors(FActorConstraintInfo ChangedInfo);

	/* 액터의 배치 정보가 변경되었을 때, 이를 업데이트합니다. */
	void UpdateActorsPlaceInfo(FActorPlaceInfo ChangedPlaceInfo);
	


public:
	UFUNCTION(BlueprintCallable, Category = "Core|World", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static AEditorWorldManager* GetGlobalEditorWorldManager(const UObject* WorldContextObject);



	/* EditorModulesManager의 Getter 함수입니다 */
	UFUNCTION(BlueprintGetter, Category="Core|World")
	FORCEINLINE UEditorModulesManager* GetEditorModulesManager() const
	{
		return EditorModulesManager;
	}
	


	/* BlockedActorAddedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FBlockedActorAddedEventDispatcher& OnBlockedActorAdded()
	{
		return BlockedActorAddedEventDispatcher;
	}

	/* BlockedActorRemovedEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FBlockedActorRemovedEventDispatcher& OnBlockedActorRemoved()
	{
		return BlockedActorRemovedEventDispatcher;
	}





private:
	/* 모듈들을 관리하는 최상위 매니저입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|World", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetEditorModulesManager)
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
 


/*	TODO : 언젠가는 해야할 일이 올지도 모르니 미리 적어둡니다 
 *	현재 BlockedActor의 설계는 전적으로 잘못되어 있습니다. 권장되는 형식은
 *	TMap<AActor*, EActorConstarintState>입니다. 이 문제를 지금 처리하려면,
 *	ActorInfo 모듈의 FActorConstraintInfo와 함께 조정되어야 하는 문제가 있
 *	습니다. 
	
 *	물론 앞으로 문제가 없을 수도 있습니다. 그 경우, 이 주석을 언젠가 도움이
 *	되도록 남겨만 두도록 하시길 바랍니다.
 */