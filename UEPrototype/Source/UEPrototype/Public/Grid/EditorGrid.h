// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Math/Color.h"

#include "EditorGrid.generated.h"

class UMaterialInstanceDynamic;
class UStaticMeshComponent;
class APlayerController;

UCLASS()
class UEPROTOTYPE_API AEditorGrid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEditorGrid();

	// 그리드 스냅의 동기화를 설정 on/off 할 수 있는 함수입니다
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetSyncWithGridSnapEnabled(bool bSyncWithGridSnap);

	// 그리드 스냅의 동기화여부를 반환하는 함수입니다.
	UFUNCTION(BlueprintPure, Category = "Grid")
	bool IsSyncWithGridSnap() const;

	// 그리드 간격을 설정하는 함수입니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetGridInterval(float GridInterval);

	// 그리드 간격을 반환하는 함수입니다.
	UFUNCTION(BlueprintPure, Category = "Grid")
	float GetGridInterval() const;






	// 타이머로 지정한 시간마다 플레이어의 x,y 위치값을 받아서 현재 위치에 추가해주는 함수입니다
	UFUNCTION(BluePrintCallable, Category = "Grid")
	void UpdateGridPosition();

	// 그리드 표시 여부를 토글합니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE bool ToggleGridView()
	{
		return (bGridVisualize = !bGridVisualize);
	};

	// TOGGLE TRACING이 TRUE일 때 UpdateGridPosition를 활성화합니다. 그리드가 사용자를 추적할지 여부를 토글합니다.		주석 수정 필요합니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	FORCEINLINE bool ToggleTracing()
	{
		return (bGridTracing = !bGridTracing);
	}






	// 지정된 인덱스의 그리드 색상을 변경합니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetGridColor(FLinearColor InColor, int InGridIndex);

	// 그리드 격자 간격을 조정합니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetGridScale(float InGridScale);

	// 그리드의 페이드 시작 거리를 조정합니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetGridFadeDistance(float InFadeLength);

	// 그리드의 오파시티를 조정합니다.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetGridOpacity(float InGridOpacity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* EditorGridMesh;

	// SM Comp에 입힐 머티리얼
	UPROPERTY()
	UMaterialInstanceDynamic * MIDTemplate;

	// 그리드 간격과 스냅의 동기화를 설정해주는 변수입니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	bool bSyncWithGridSnap;

	// 그리드의 간격을 설정받는 변수입니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	float GridInterval;

	// 이전의 그리드 간격 값을 저장해주는 변수입니다.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	float GridIntervalCache;


	// 그리드가 시각화 상태인지 여부
	bool bGridVisualize;

	// 그리드가 유저를 쫒아다닐 지 여부
	bool bGridTracing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid", meta = (AllowPrivateAccess = "true", ClampMin = "1.0", UIMin = "1.0"))
	float TraceTimerInterval;


	// 로컬 플레이어 캐시
	UPROPERTY()
	APlayerController const * CachedPlayer;


};