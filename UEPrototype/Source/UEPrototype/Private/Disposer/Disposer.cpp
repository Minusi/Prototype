// Fill out your copyright notice in the Description page of Project Settings.

#include "Disposer.h"
#include "UEPrototype.h"
#include "Components/StaticMeshComponent.h"
#include "Components/MeshComponent.h"
#include "SpawnHelper.h"
#include "Engine/World.h"


// Sets default values
ADisposer::ADisposer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GhostObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GhostObject"));

	// 고스트 오브젝트의 머티리얼을 설정해 주어야 합니다.
	// 현재 고스트 오브젝트에 설정해줄 머티리얼이 없어서 주석처리를 해 놓았습니다.
	//GhostObjectMesh->SetMaterial();

	GhostObject->SetupAttachment(RootComponent);
}




void ADisposer::ObjectSpawn(UStaticMesh* ObjectMesh, FVector SpawnPosition)
{
	if (ObjectMesh == nullptr)
	{
		VP_LOG(Warning, TEXT("오브젝트가 선택되지 않았습니다.."));
	}

	//SpawnHelper 에서 SMComp 를 받아와 액터를 생성한 후 생성할 오브젝트의 매쉬를 입힙니다.
	ASpawnHelper* ObjectToSpawn = GetWorld()->SpawnActor<ASpawnHelper>(SpawnPosition, FRotator::ZeroRotator);
	ObjectToSpawn->GetSMComp()->SetStaticMesh(ObjectMesh);

}

void ADisposer::DeleteObject(AActor * HitActor)
{
	if (!IsValid(HitActor))
	{
		VP_LOG(Warning, TEXT("선택된 오브젝트가 명확하지 않습니다."));
	}
	HitActor->Destroy();

}

void ADisposer::ChangeGhostObject(UStaticMesh* NewGhostObject)
{
	// 초기에는 어떠한 오브젝트도 선택되어 있지 않아 null 값을 가지기 때문에 유효성 검사를 하지 않습니다.
	GhostObject->SetStaticMesh(NewGhostObject);
}