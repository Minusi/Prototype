// Fill out your copyright notice in the Description page of Project Settings.

#include "VPGeneratorPawn.h"

// Sets default values
AVPGeneratorPawn::AVPGeneratorPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVPGeneratorPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVPGeneratorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVPGeneratorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

