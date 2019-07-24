// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Disposer.generated.h"


UCLASS()

// 인벤토리 위젯에서 선택된 오브젝트를 월드에 생성, 혹은 월드에 생성된 오브젝트를 제거 하는 함수를 가지며
// 월드에 배치하기 전 미리 가상의 배치상태를 볼 수 있는 GhostObject 를 보여주는 함수를 가졌습니다.
class UEPROTOTYPE_API ADisposer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADisposer();

	// 커서의 위치에 위젯에서 선택된 오브젝트를 생성하는 함수입니다.
	UFUNCTION(BlueprintCallable, Category = "Disposer")
		void ObjectSpawn(UStaticMesh* ObjectMesh, FVector SpawnPosition);

	// 월드에 생성되어있는 오브젝트를 제거해주는 함수 입니다.
	UFUNCTION(BlueprintCallable, Category = "Disposer")
		void DeleteObject(AActor * HitActor);

	// 선택된 오브젝트의 가상의 배치상태를 보여주는 GhostObject를 바꾸어주는 함수 입니다.
	UFUNCTION(BlueprintCallable, Category = "Disposer")
		void ChangeGhostObject(UStaticMesh* NewGhostObject);


private:

	class UStaticMeshComponent* GhostObject;

};
