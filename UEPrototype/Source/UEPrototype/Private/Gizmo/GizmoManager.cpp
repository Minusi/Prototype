// Fill out your copyright notice in the Description page of Project Settings.

#include "Gizmo/GizmoManager.h"

// Sets default values
AGizmoManager::AGizmoManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGizmoManager::BeginPlay()
{
	Super::BeginPlay();
	//GizmoAxes = GetWorld()->SpawnActor<AGizmoAxes>(FVector::ZeroVector, FRotator::ZeroRotator);
}

// Called every frame
void AGizmoManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

