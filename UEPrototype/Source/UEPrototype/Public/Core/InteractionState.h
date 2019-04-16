// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"


#include "InteractionState.generated.h"

/**
 * 
 */
UCLASS(abstract, ClassGroup="Custom")
class UEPROTOTYPE_API UInteractionState : public UObject
{
	GENERATED_BODY()
	
public:
	UInteractionState();

	virtual void Execute();
};
