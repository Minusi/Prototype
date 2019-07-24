// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnHelper.generated.h"

UCLASS()

// Disposer 모듈에서 월드에 생성, 배치를 하기위한 오브젝트와, 생성 하기 전 배치 상태를 볼 수 있는
//GhostObject 에 사용될 메시 컴포넌트를 생성해놓은 함수입니다.

class UEPROTOTYPE_API ASpawnHelper : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnHelper();


	// Disposer에서 사용할 스태틱 매쉬 컴포넌트를 반환합니다.
	UFUNCTION(BlueprintCallable, Category = "SpawnHelper")
		UStaticMeshComponent* ProvideSMComp();


private:
	class UStaticMeshComponent* ObjectSMComp;

};
