// Fill out your copyright notice in the Description page of Project Settings.

#include "Module/Edit/EditManager.h"
#include "UEPrototype.h"

// Sets default values
AEditManager::AEditManager()
{
	VP_CTOR;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEditManager::BeginPlay()
{
	Super::BeginPlay();


}
