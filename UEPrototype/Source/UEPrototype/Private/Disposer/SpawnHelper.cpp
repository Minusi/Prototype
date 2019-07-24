// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnHelper.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ASpawnHelper::ASpawnHelper()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ObjectSMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectSMComp"));
	ObjectSMComp->SetupAttachment(RootComponent);
}



UStaticMeshComponent* ASpawnHelper::ProvideSMComp()
{
	return ObjectSMComp;
}

