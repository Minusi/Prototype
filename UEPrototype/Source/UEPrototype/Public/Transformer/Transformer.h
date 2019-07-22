// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Transformer.generated.h"


// 그리드 스냅이 활성화 되었을 경우 변경된 값의 비율을 생성할 때의 값을 저장할 구조체
USTRUCT(BlueprintType)
struct FSnapStruct
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformer", meta = (AllowPrivateAccess = true))
		bool bCanSnap;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformer", meta = (AllowPrivateAccess = true))
		float SnappedDelta;

};


// 선택된 물체의 기즈모를 변경 할 수 있는 함수들이 구현되어 있다. 
//기즈모는 위치이동, 스케일 변경, 회전, 그리드스냅 동기화를 켜고 끌 수 있는 함수가 구현되어있음

UCLASS()
class UEPROTOTYPE_API ATransformer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATransformer();



	// 오브젝트를 기즈모의 x,y,z 축으로 이동시키는 함수
	UFUNCTION(BlueprintCallable, Category = "Transformer")
		void MoveObject(AActor* Target, FVector Direction, float SnapInterval, float Delta);

	// 오브젝트를 마우스 커서의 위치로 이동시키는 함수
	UFUNCTION(BlueprintCallable, Category = "Transformer")
		void MoveObjectToCurser(AActor* Target, FVector MousePosition);

	// 오브젝트를 회전시키는 함수
	UFUNCTION(BlueprintCallable, Category = "Transformer")
		void RotateObject(AActor* Target, FVector Axis, float SnapInterval, float Delta);

	// 오브젝트의 스케일을 변경하는 함수
	UFUNCTION(BlueprintCallable, Category = "Transformer")
		void ScaleObject(AActor* Target, FVector Direction, float SnapInterval, float Delta);





	// 그리드 스냅의 동기화 여부를 EditorGrid 의 그리드스냅과 같게 해 주는 함수
	UFUNCTION(BlueprintCallable, Category = "Transformer")
		void SyncWithGridSnap(bool bIsSynced);

	// 그리드 스냅이 활성화 되었을 경우 변경된 값의 비율을 생성하는 함수
	UFUNCTION(BlueprintPure, Category = "Transformer")
		void Snap(float Delta, float SnapInterval, FSnapStruct& SnapElement);



private:

	// Grid 모듈의 그리드 스냅 on/off 여부를 가져올 변수
	bool bIsSynced;


	// 그리드 스냅을 적용하지 않을 경우 사용되는 스냅 간격
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformer", meta = (AllowPrivateAccess = true))
		float DefaultMoveSnapInterval;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformer", meta = (AllowPrivateAccess = true))
		float DefaultRotateSnapInterval;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Transformer", meta = (AllowPrivateAccess = true))
		float DefaultScaleSnapInterval;

};
