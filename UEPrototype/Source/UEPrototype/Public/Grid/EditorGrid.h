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

	// �׸��� ������ ����ȭ�� ���� on/off �� �� �ִ� �Լ��Դϴ�
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetSyncWithGridSnapEnabled(bool bSyncWithGridSnap);

	// �׸��� ������ ����ȭ���θ� ��ȯ�ϴ� �Լ��Դϴ�.
	UFUNCTION(BlueprintPure, Category = "Grid")
	bool IsSyncWithGridSnap() const ;

	// �׸��� ������ �����ϴ� �Լ��Դϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
	void SetGridInterval(float GridInterval);

	// �׸��� ������ ��ȯ�ϴ� �Լ��Դϴ�.
	UFUNCTION(BlueprintPure, Category = "Grid")
	float GetGridInterval() const;






	// Ÿ�̸ӷ� ������ �ð����� �÷��̾��� x,y ��ġ���� �޾Ƽ� ���� ��ġ�� �߰����ִ� �Լ��Դϴ�
	UFUNCTION(BluePrintCallable, Category = "Grid")
		void UpdateGridPosition();

	// �׸��� ǥ�� ���θ� ����մϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
		FORCEINLINE bool ToggleGridView()
	{
		return (bGridVisualize = !bGridVisualize);
	};

	// TOGGLE TRACING�� TRUE�� �� UpdateGridPosition�� Ȱ��ȭ�մϴ�. �׸��尡 ����ڸ� �������� ���θ� ����մϴ�.		�ּ� ���� �ʿ��մϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
		FORCEINLINE bool ToggleTracing()
	{
		return (bGridTracing = !bGridTracing);
	}






	// ������ �ε����� �׸��� ������ �����մϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
		void SetGridColor(FLinearColor InColor, int InGridIndex);

	// �׸��� ���� ������ �����մϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
		void SetGridScale(float InGridScale);

	// �׸����� ���̵� ���� �Ÿ��� �����մϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
		void SetGridFadeDistance(float InFadeLength);

	// �׸����� ���Ľ�Ƽ�� �����մϴ�.
	UFUNCTION(BlueprintCallable, Category = "Grid")
		void SetGridOpacity(float InGridOpacity);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* EditorGridMesh;

	// SM Comp�� ���� ��Ƽ����
	UPROPERTY()
	UMaterialInstanceDynamic * MIDTemplate;

	// �׸��� ���ݰ� ������ ����ȭ�� �������ִ� �����Դϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	bool bSyncWithGridSnap;
	
	// �׸����� ������ �����޴� �����Դϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	float GridInterval;

	// ������ �׸��� ���� ���� �������ִ� �����Դϴ�.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid", meta = (AllowPrivateAccess = true))
	float GridIntervalCache;


	// �׸��尡 �ð�ȭ �������� ����
	bool bGridVisualize;

	// �׸��尡 ������ �i�ƴٴ� �� ����
	bool bGridTracing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid",meta = (AllowPrivateAccess = "true", ClampMin = "1.0", UIMin = "1.0"))
	float TraceTimerInterval;


	// ���� �÷��̾� ĳ��
	UPROPERTY()
	APlayerController const * CachedPlayer;


};
