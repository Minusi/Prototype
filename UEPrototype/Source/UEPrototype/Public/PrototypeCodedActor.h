// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrototypeCodedActor.generated.h"

UCLASS()
class UEPROTOTYPE_API APrototypeCodedActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APrototypeCodedActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
};
