// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ActorPlaceInfoMarker.generated.h"





/**
 *	FActorPlaceContent는 배치되는 액터에 대한 간단한 정보를
 *	표시하기 위해 구성된 구조체입니다. 주 목적은 하이라이트
 *	되었을 때, 물체에 대한 간단한 정보를 제공하는 것입니다.
 */
USTRUCT(BlueprintType)
struct FActorPlaceContent
{
	GENERATED_BODY()
	
public:
	/* 디폴트 생성자 */
	FActorPlaceContent()
	{
		Name = FString();
		Type = nullptr;
		UserName = FString();
		bScripted = false;
	}

	bool operator==(const FActorPlaceContent& Rhs) const
	{
		return ((Name == Rhs.Name)
			&& (Type == Rhs.Type)
			&& (UserName == Rhs.UserName)
			&& (bScripted == Rhs.bScripted));
	}

public:
	/* 이 액터의 이름입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FString Name;

	/* 이 액터의 클래스입니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	UClass* Type;

	/* 이 액터를 배치한 유저입니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	FString UserName;

	/* 이 액터가 스크립팅되었는 지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	bool bScripted;
};





/**
 *	ActorPlaceInfo는 특정 액터와 해당 액터에 대한 간단한 정보
 *	를 제공하는 구조체입니다. 월드를 관리하는 클래스에서 사용
 *	됩니다.
 */
USTRUCT(BlueprintType)
struct FActorPlaceInfo
{
	GENERATED_BODY()
	
public:
	/* == 연산자 오버로딩 */
	bool operator==(const FActorPlaceInfo& Rhs)
	{
		return (Target == Rhs.Target) && (TargetContent == Rhs.TargetContent);
	}



public:
	/* 월드에 배치된 액터입니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	AActor* Target;

	/* 월드에 배치된 액터의 간단한 정보입니다 */
	UPROPERTY(BlueprintReadWrite, Category = "ActorInfo")
	FActorPlaceContent TargetContent;
};





DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorPlaceInfoMarkEventDispatcher, FActorPlaceInfo, ActorPlaceInfo);



/**
 *	월드에 배치된 액터에 대해서 액터 배치에 대한 정보를
 *	변경하는 요구가 들어왔을 때 해당 자료를 소유하고 있는
 *	인스턴스에 브로드캐스트하는 중계자 클래스입니다.
 */
UCLASS()
class UEPROTOTYPE_API UActorPlaceInfoMarker : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UActorPlaceInfoMarker();



	/* ActorInfoModuleManager를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static UActorPlaceInfoMarker* GetGlobalActorPlaceInfoMarker();



	/* ActorPlaceInfoMarkEventDispatcher의 Getter 함수입니다 */
	FORCEINLINE FActorPlaceInfoMarkEventDispatcher& OnActorPlaceInfoMark()
	{
		return ActorPlaceInfoMarkEventDispatcher;
	}

	/* 대상 액터의 배치 정보를 브로드캐스트합니다 */
	UFUNCTION(BlueprintCallable, Category="ActorInfo")
	void MarkActor(AActor* Target, FActorPlaceContent Content);





private:
	/* 액터 배치 정보가 변경되면 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="ActorInfo",
				meta=(AllowPrivateAccess=true))
	FActorPlaceInfoMarkEventDispatcher ActorPlaceInfoMarkEventDispatcher;
};
