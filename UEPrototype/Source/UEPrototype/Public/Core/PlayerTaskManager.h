// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Array.h"
#include "ActorConstraintMarker.h"
#include "PlayerTaskManager.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractedActorAddedEventDispatcher, FActorConstraintInfo, InteractedActorInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractedActorRemovedEventDispatcher, AActor*, UninteractedActor);



/**
 *	PlayerTaskManager는 플레이어의 작업 상태를 관리하는 클래스입니다.
 *	플레이어가 조작하고 있는 액터에 대한 관리를 수행합니다. 이것은 로
 *	컬 전용으로, 네트워크 환경에서는 AEditorWorldManager의 BlockedAct
 *	or와 상호 통신 관계를 유지해야 합니다,
 */
UCLASS()
class UEPROTOTYPE_API UPlayerTaskManager : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UPlayerTaskManager();
	
	/* PlayerTaskManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Player", meta = (UnsafeDuringActorConstruction = "true"))
	static UPlayerTaskManager* GetGlobalPlayerTaskManager();


	/* 현재 액터가 상호작용 중인지 확인합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Player")
	bool IsInteractedActor(AActor* Target) const;



	/* 현재 상호작용 중인 액터들을 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Core|Player")
	TArray<FActorConstraintInfo> GetInteractedActorsInfo() const
	{
		return InteractedActorsInfo;
	}
	
	/* 입력받은 액터의 상태를 반환합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Player")
	EActorConstraintState GetActorConstraintState(AActor* Target) const;
	


private:
	/* 외부 모듈의 이벤트 디스패처에 이벤트를 바인딩합니다 */
	UFUNCTION()
	void BindToEvents();

	/* ActorInfo 모듈의 ActorConstraintMarker의 이벤트를 수신하여 처리합니다 */
	UFUNCTION()
	void UpdateActorInteracted(FActorConstraintInfo Target);

	/* 상호작용할 액터를 추가합니다. */
	UFUNCTION()
	void AddActorInteracted(FActorConstraintInfo Target);

	/* 상호작용하고 있는 액터를 제거합니다 */
	UFUNCTION()
	void RemoveActorInteracted(FActorConstraintInfo Target);

	/* 상호작용하고 있는 액터를 액터만으로 제거합니다 */
	UFUNCTION()
	void RemoveActorInteractedWithoutState(AActor* Target);

	/* 상호작용하고 있는 액터의 상태를 변경합니다 */
	UFUNCTION()
	void ChangeActorInteracted(FActorConstraintInfo Target);



	/* InteractedActorAddedEventDispatcher의 Getter입니다 */
	FInteractedActorAddedEventDispatcher& OnInteractedActorAdded()
	{
		return InteractedActorAddedEventDispatcher;
	}

	/* InteractedActorRemovedEventDispatcher의 Getter입니다 */
	FInteractedActorRemovedEventDispatcher& OnInteractedActorRemoved()
	{
		return InteractedActorRemovedEventDispatcher;
	}





private:
	/* 유저와 상호작용하고 있는 액터들에 대한 컨테이너입니다 */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetInteractedActorsInfo)
	TArray<FActorConstraintInfo> InteractedActorsInfo;

	/* 유저와 상호작용 중인 액터가 추가될 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Core|Player", meta=(AllowPrivateAccess=true))
	FInteractedActorAddedEventDispatcher InteractedActorAddedEventDispatcher;

	/* 유저와 상호작용 중인 액터가 제거될 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Core|Player", meta=(AllowPrivateAccess=true))
	FInteractedActorRemovedEventDispatcher InteractedActorRemovedEventDispatcher;
};
