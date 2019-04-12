// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "UtilityLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UEPROTOTYPE_API UUtilityLibrary : public UObject
{
	GENERATED_BODY()
	

public:
	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Util|Component", meta = (AllowPrivateAccess = "true"))
	static void TransferComponentToOtherActor(UActorComponent* SourceComp, AActor* DestActor)
	{
	}
};
