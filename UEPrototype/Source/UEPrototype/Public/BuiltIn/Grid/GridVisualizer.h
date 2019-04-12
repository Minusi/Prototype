// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatform.h"
#include "UObject/ConstructorHelpers.h"

#include "Math/Color.h"

#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"

#include "UEPrototype.h"
#include "GridVisualizer.generated.h"

UCLASS()
class UEPROTOTYPE_API AGridVisualizer : public AActor
{
	GENERATED_BODY()
	
private:
	static TCHAR const * DefaultMesh;
	static TCHAR const * DefaultMaterialInstance;

public:	
	// Sets default values for this actor's properties
	AGridVisualizer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	// 그리드 표시 여부를 토글합니다.
	UFUNCTION(BlueprintCallable, Category="Grid|Visual")
	FORCEINLINE bool ToggleGridView()
	{
		return (bVisualize = !bVisualize);
	};

	// 지정된 인덱스의 그리드 색상을 변경합니다.
	UFUNCTION(BlueprintCallable, Category="Grid|Visual")
	void ChangeGridColor(FLinearColor const InColor, int const InGridIndex);

	// 그리드 격자 간격을 조정합니다.
	UFUNCTION(BluerpintCallable, Category = "Grid|Visual")
	void ConfigureGridScale(float const InGridScale);

	// 그리드의 페이드 시작 거리를 조정합니다.
	UFUNCTION(BlueprintCallable, Category="Grid|Visual")
	void ConfigureGridFadeLength(float const InFadeLength);
	





private:
	// 에디터 상에서 설정되지 않은 컴포넌트들을 디폴트로 설정합니다.
	UFUNCTION()
	void InitializeTemplate();

	// 템플릿 초기화 이후에 설정되어야 하는 프로퍼티들을 설정합니다.
	UFUNCTION()
	void PostInitializeTemplate();




private:
	// 그리드를 나타낼 SMComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Grid|Visual", meta=(AllowPrivateAccess="true"))
	class UStaticMeshComponent * GridComp;

	// SM Comp에 입히기 위한 머티리얼의 템플릿
	UPROPERTY()
	class UMaterialInstance * MITemplate;

	// SM Comp에 입힐 머티리얼
	UPROPERTY()
	class UMaterialInstanceDynamic * CacheMID;

	// 현재 그리드가 시각화 상태인지 여부
	UPROPERTY()
	bool bVisualize;
};
