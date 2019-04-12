// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Containers/Array.h"
#include "GridObjectPool.h"
#include "GridLayout.generated.h"

/*
*	ArrangeType은 배치를 하는 방법을 결정하는 데 사용되는
*	열거형 클래스입니다. 새로운 배치 방법을 추가하기 위해서
*	우선 이 열거형에 컴포넌트를 추가해야 합니다.
*/
enum class EArrangeType
{
	// 디폴트, 아무것도 하지 않습니다.
	AT_NONE,
	// 격자형으로 정렬합니다.
	AT_LATTICE
};

UCLASS()
class UEPROTOTYPE_API AGridLayout : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridLayout();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



public:
	// 지정된 레이아웃 방식대로 배치합니다.
	void PlaceGrid(EArrangeType ArrangeType);


private:
	//
	 



private:
	TArray<UStaticMeshComponent*> GridSMComp;

	// 배치할 오브젝트들을 담고 있는 오브젝트 풀입니다.
	UGridObjectPool* GridObjectPool;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* TestComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	AActor* TargetActor;
};
