// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContentsRoom.generated.h"

UCLASS()
class UEPROTOTYPE_API AContentsRoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AContentsRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 새로 배치할 쇼케이스의 위치를 얻어옵니다.
	UFUNCTION(BlueprintPure, Category = "ContentsRoom")
	FVector GetNewShowcaseLocation();
	
	// 새로 배치할 쇼케이스의 방향을 얻어옵니다.
	UFUNCTION(BlueprintPure, Category = "ContentsRoom")
	FRotator GetNewShowcaseRotation();

private:
	// 컨텐츠 간의 좌우 간격
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ContentsRoom", meta = (AllowPrivateAccess = "true"))
	float HorizontalSpace;

	// 컨텐츠 간의 상하 간격
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ContentsRoom", meta = (AllowPrivateAccess = "true"))
	float VerticalSpace;

	// 한 행에 배치할 컨텐츠들의 개수
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ContentsRoom", meta = (AllowPrivateAccess = "true"))
	int32 RowCount;

	// 현재 만들어진 진열장의 개수
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ContentsRoom", meta = (AllowPrivateAccess = "true"))
	int32 ShowcaseCount;

	// 중심으로 부터 진열장의 거리
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ContentsRoom", meta = (AllowPrivateAccess = "true"))
	float ShowcaseDistanceFromCenter;

	// 매쉬의 바운드 크기가 이것을 넘어서면 조절됩니다.
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ContentsRoom", meta = (AllowPrivateAccess = "true"))
	float MaxMeshBounds;
};
