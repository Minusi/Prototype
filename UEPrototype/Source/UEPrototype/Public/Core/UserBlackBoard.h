// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "ActorInfo/ActorPlaceInfoMarker.h"
#include "UserBlackBoard.generated.h"



class AEditorWorldManager;
class UPlayerTaskManager;


/*
 *	UserBlackBoard는 도구가 명령을 실행시키는 데 필요한 정보들을
 *	전역적으로 제공하는 클래스입니다.
 */
UCLASS()
class UEPROTOTYPE_API AUserBlackBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUserBlackBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/* AUserBlackBoard의 Getter입니다. (전역 접근 가능) */
	UFUNCTION(BlueprintCallable, Category = "Core|Player", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "true"))
	static AUserBlackBoard* GetGlobalUserBlackBoard(UObject* WorldContextObject);

	/* TeleportPosition의 Getter입니다. */
	UFUNCTION(BlueprintGetter, Category="Core|Player")
	FORCEINLINE FVector GetTeleportPosition() const
	{
		return TeleportPosition;
	}



	/* PointedActor의 Getter입니다. */
	UFUNCTION(BlueprintGetter, Category="Core|Player")
	FORCEINLINE AActor* GetPointedActor() const
	{
		return PointedActor;
	}

	/* PointedActor의 ActorConstraintState를 반환합니다. */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Core|Player")
	EActorConstraintState GetPointedActorConstraintState() const;

	/* PointedActor의 ActorPlaceContent를 반환합니다. */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Core|Player")
	FActorPlaceContent GetPointedActorPlaceContent() const;



	/* FocusedActor의 Getter입니다. */
	UFUNCTION(BlueprintGetter, Category = "Core|Player")
	FORCEINLINE AActor* GetFocusedActor() const
	{
		return FocusedActor;
	}

	/* FocusedActor의 ActorConstraintState를 반환합니다. */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Core|Player")
	FORCEINLINE EActorConstraintState GetFocusedActorConstraintState() const;

	/* FocusedActor의 ActorPlaceContent를 반환합니다. */
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Core|Player")
	FORCEINLINE FActorPlaceContent GetFocusedActorPlaceContent() const;



	/* TeleportPosition의 Setter입니다. */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
	void SetTeleportPosition(FVector InPosition);
	
	/* PoitnedActor의 Setter입니다. */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
	void SetPointedActor(AActor* InActor);

	/* FocusedActor의 Setter입니다. */
	UFUNCTION(BlueprintSetter, Category = "Core|Player")
	void SetFocusedActor(AActor* InActor);





private:
	/* 텔레포트 포인터가 가리키고 있는 위치입니다. */
	UPROPERTY(BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess=true),
				BlueprintGetter=GetTeleportPosition, BlueprintSetter=SetTeleportPosition)
	FVector TeleportPosition;

	/* 현재 지목되고 있는 액터입니다. */
	UPROPERTY(BlueprintReadWrite, Category="Core|Player", meta=(AllowPrivateAccess=true),
				BlueprintGetter = GetPointedActor, BlueprintSetter = SetPointedActor)
	AActor * PointedActor;

	/* 현재 응시되고 있는 액터입니다. */
	UPROPERTY(BlueprintReadWrite, Category = "Core|Player", meta = (AllowPrivateAccess = true),
				BlueprintGetter = GetFocusedActor, BlueprintSetter = SetFocusedActor)
	AActor* FocusedActor;



private:
	/* 월드에 배치된 액터 정보 컨테이너에 대한 읽기 전용 캐시입니다. */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true))
	AEditorWorldManager* EditorWorldManager;

	/* 상호작용하고 있는 액터 배열에 대한 읽기 전용 캐시입니다. */
	UPROPERTY(BlueprintReadOnly, Category="Core|Player", meta=(AllowPrivateAccess=true))
	UPlayerTaskManager* PlayerTaskManager;



};
