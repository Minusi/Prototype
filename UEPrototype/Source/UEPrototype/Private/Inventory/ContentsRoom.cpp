// Fill out your copyright notice in the Description page of Project Settings.

#include "ContentsRoom.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AContentsRoom::AContentsRoom()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AContentsRoom::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AContentsRoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
FVector AContentsRoom::GetNewShowcaseLocation()
{
	float Offset = (RowCount / 2) * HorizontalSpace;
	FVector RightVector = UKismetMathLibrary::NegateVector(GetActorRightVector());
	FVector ForwardVector = GetActorForwardVector() * ShowcaseDistanceFromCenter;

	return ForwardVector + (RightVector * Offset / 2);
}

FRotator AContentsRoom::GetNewShowcaseRotation()
{
	return UKismetMathLibrary::MakeRotator(0, 0, ShowcaseCount * 90);
}