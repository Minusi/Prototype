// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"

#include "GameFramework/Actor.h"

#include "ProceduralMeshComponent.h"
#include "TestProceduralActor.generated.h"

UCLASS()
class UEPROTOTYPE_API ATestProceduralActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestProceduralActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostActorCreated() override;

	virtual void PostLoad() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void CreateTriangle();



private:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* Mesh;
};
