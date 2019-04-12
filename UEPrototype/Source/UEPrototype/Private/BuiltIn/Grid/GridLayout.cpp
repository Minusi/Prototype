// Fill out your copyright notice in the Description page of Project Settings.

#include "GridLayout.h"

// Sets default values
AGridLayout::AGridLayout()
{
	VP_CTOR;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TestComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("test"));
}

// Called when the game starts or when spawned
void AGridLayout::BeginPlay()
{
	Super::BeginPlay();
	
	if (TargetActor != nullptr)
	{
		TestComp->AttachToComponent
		(
			TargetActor->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale
		);

		TestComp = nullptr;
	}
}

// Called every frame
void AGridLayout::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridLayout::PlaceGrid(EArrangeType ArrangeType)
{
	if (ArrangeType == EArrangeType::AT_NONE)
	{
		VP_LOG(Warning, TEXT("레이아웃 형식(EArrangeType)이 지정되지 않았습니다."));
		return;
	}
	else if (ArrangeType == EArrangeType::AT_LATTICE)
	{
		GridObjectPool->PopObject();
	}
	else
	{
		VP_LOG(Error, TEXT("올바르지 않은 EArrangeType이 지정되었습니다."));
		return;
	}
}

