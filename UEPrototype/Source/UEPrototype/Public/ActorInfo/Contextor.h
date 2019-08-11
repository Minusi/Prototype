// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Map.h"
#include "ActorInfo/DynamicListWidget.h"
#include "Contextor.generated.h"



/*	SubContextLayout은 컨텍스트의 서브 요소가
 *	컨텍스트 메뉴에서 어디에 표현될 지를 결정
 *	하기 위한 열거형 클래스입니다.
 *
 *	- Extrude :메인 컨텍스트와 별개의 다른 컨텍스트 창이
 *				옆으로 돌출됩니다.
 *	- Extend : 메인 컨텍스트의 컨텐츠로 포함되어 메인 컨
 *				텍스트의 아래에 기술됩니다.
 */
UENUM(BlueprintType)
enum class ESubContextLayout : uint8
{
	// 
	LYT_Extrude		UMETA(DisplayName = "Extrude"),
	LYT_Extend		UMETA(DisplayName = "Extend")
};





/*	SubContext는 메인 컨텍스트에 부착되어질 수 있는 서브 컨텍
 *	스트를 정의합니다. 메인 컨텍스트로부터 어떻게 확장될 지를
 *	나타내는 열거형 클래스를 변수로 가집니다
 */
USTRUCT(BlueprintType)
struct FSubContext
{
	GENERATED_BODY()

public:
	/* 메인 컨텍스트로부터 확장 방법을 정의합니다 */
	ESubContextLayout SubContextLayout;
};





/* 
 *	이름과 사용 가능 여부를 표시하는 구조체입니다.
 *	Context 계열 클래스에서 사용됩니다.
 */
USTRUCT(BlueprintType)
struct FTextPair
{
	GENERATED_BODY()
	
public:
	/* 로컬라이징이 가능한 이름입니다. */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FText TextName;

	/* 사용 가능 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	bool bAvailable;
};





/*	월드 액터에 대한 유틸 컨텍스트 기능을 제공하는 모델(Model)
 *	클래스입니다. 액터의 형식에 따라 가능한 명령과 가능하지 않
 *	은 명령이 있으므로 SubContext로 분류합니다.
 */
USTRUCT(BlueprintType)
struct FUtilSubContextInfo : public FSubContext
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	FUtilSubContextInfo()
	{
		SubContextLayout = ESubContextLayout::LYT_Extend;
	}



public:
	/* 플레이어가 가리키는 위치에 활성화된 액터를 배치합니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair PlaceToPoint;
};



/*	
 *	월드 액터에 대한 편집 컨텍스트 기능을 제공하는 모델(Model)
 *	클래스입니다. 액터의 형식에 따라 가능한 명령과 가능하지 않
 *	은 명령이 있으므로 SubContext로 분류합니다.
 */
USTRUCT()
struct FEditContextLayout : public FSubContext
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	FEditContextLayout()
	{
		SubContextLayout = ESubContextLayout::LYT_Extrude;
	}



public:
	/* 지오메트리를 편집할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Geometry;

	/* 머티리얼을 편집할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Material;

	/* 텍스쳐를 편집할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Texture;

	/* 카메라를 편집할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Camera;

	/* 사운드를 편집할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Sound;

	/* 파티클을 편집할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Particle;
};




/*	
 *	월드 액터에 대한 컨텍스트 기능들을 제공하는 모델 클래스입
 *	니다. 액터 모두에게 공통적으로 포함되는 명령 기능들을 정
 *	의합니다.
 */
USTRUCT(BlueprintType)
struct FWorldActorContextInfo
{
	GENERATED_BODY()
	
public:
	/* 액터의 트랜스폼을 조정할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Transform;

	/* 액터를 복제할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Duplicate;

	/* 액터를 제거할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Remove;
	
	/* 액터의 이름을 재지정할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Rename;
	
	/* 액터를 저장할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Save;
	
	/* 컨텍스트 메뉴를 취소할 수 있는지 여부입니다 */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo")
	FTextPair Cancel;
};




class UWidgetComponent;


/*
 *	컨텍스트에 대한 MVC 기능을 제공하는 클래스입니다.
 *	액터를 입력으로 받아, 액터의 형식에 따라 가능한 명령 집합,
 *	및 실행 등을 도와줍니다.
 */
UCLASS()
class UEPROTOTYPE_API AContextor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContextor();
	/* HUDWorldPositioner를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static AContextor* GetGlobalContextor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:
	/* 컨텍스트 창을 띄웁니다. */
	UFUNCTION(BlueprintCallable, Category="ActorInfo")
	void ShowContext(AActor* InActor);
	UFUNCTION(BlueprintCallable, Category = "ActorInfo")
	void CloseContext(AActor* InActor);
private:
	UFUNCTION()
	void ProcessContext(AActor* InActor);



public:
	/* WorldActorContextInfo를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="ActorInfo")
	FORCEINLINE FWorldActorContextInfo GetWorldActorContextInfo() const
	{
		return WorldActorContextInfo;
	}


	/* 이전에 컨텍스트를 띄우는 데 사용했던 액터를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="ActorInfo")
	FORCEINLINE AActor* GetPrevContextedActor() const
	{
		return PrevContextedActor;
	}

	/* HUDWorldPositioner을 반환합니다 */
	UFUNCTION(BlueprintGetter, Category = "ActorInfo")
	FORCEINLINE UHUDWorldPositioner* GETHUDWorldPositioner() const
	{
		return HUDWorldPositioner;
	}


	


private:
	/* 위젯을 배치할 컴포넌트입니다. 위젯은 DynamicListWidget을 상속받은
	위젯이어야 합니다. */
	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true))
	UWidgetComponent* WidgetComponent;


	
	/* 컨텍스트 메뉴에 띄우기 위한 정보들을 담고 있는 구조체입니다. */
	UPROPERTY(BlueprintReadWrite, Category="ActorInfo", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetWorldActorContextInfo)
	FWorldActorContextInfo WorldActorContextInfo;

	/* 이전에 컨텍스트를 띄우는 데 사용했던 액터입니다 */
	UPROPERTY(BlueprintReadOnly, Category="ActorInfo", meta=(AllowPrivateAccess=true),
				BlueprintGetter=GetPrevContextedActor)
	AActor * PrevContextedActor;

	/* 적절한 위치에 HUD 배치를 계산해주는 컴포넌트입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "ActorInfo", meta = (AllowPrivateAccess = true),
				BlueprintGetter = GetHUDWorldPositioner)
	UHUDWorldPositioner* HUDWorldPositioner;
};
