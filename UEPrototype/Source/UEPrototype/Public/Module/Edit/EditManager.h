// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Module/Edit/MeshFactory.h"
#include "EditManager.generated.h"

UCLASS()
class UEPROTOTYPE_API AEditManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEditManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	

private:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Prototype|Edit", meta=(AllowPrivateAccess = "true"))
	class AMeshFactory* MeshFactory;
};
