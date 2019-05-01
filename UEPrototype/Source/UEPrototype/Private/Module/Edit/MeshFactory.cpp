// Fill out your copyright notice in the Description page of Project Settings.

#include "Module/Edit/MeshFactory.h"
#include "Module/Init/InitManager.h"

// Sets default values
AMeshFactory::AMeshFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMeshFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeshFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}