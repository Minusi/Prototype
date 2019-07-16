// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GizmoAxes.h"
#include "GizmoManager.generated.h"

UCLASS(BlueprintType)
class UEPROTOTYPE_API AGizmoManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGizmoManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Gizmo", meta = (AllowPrivateAccess = "true"))
	//TSubclassOf<AGizmoAxes> GizmoAxes;
};
