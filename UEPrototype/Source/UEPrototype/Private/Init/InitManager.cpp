// Fill out your copyright notice in the Description page of Project Settings.

#include "Init/InitManager.h"
#include "Utility/MinusiFrameworkLibrary.h"
#include "UEPrototype.h"



// Sets default values
AInitManager::AInitManager()
{
	

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bUniquesEndInit = false;
}

// Called when the game starts or when spawned
void AInitManager::BeginPlay()
{
	Super::BeginPlay();
	InitializeUniques();
}





void AInitManager::InitializeUniques()
{
	{
		FReferenceDelegate OnEndInitDelegate;
		OnEndInitDelegate.BindDynamic(this, &AInitManager::OnEndInitEvent);
		SafeRefUniqueToActor(OnEndInitDelegate);
	}
}

void AInitManager::SafeRefUniqueToActor(FReferenceDelegate EventToBind)
{
	if (EventToBind.IsBound() == false)
	{
		VP_LOG(Error, TEXT("델리게이트에 바인딩 된 함수가 존재하지 않습니다."));
		return;
	}

	if (bUniquesEndInit == true)
	{
		EventToBind.ExecuteIfBound();
	}
	else
	{
		OnUniquesEndInit.Add(EventToBind);
	}
}

void AInitManager::OnEndInitEvent()
{
	bUniquesEndInit = true;
}
