// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include <Engine/EngineTypes.h>
#include "VPTexturer.generated.h"

class UMaterialInstanceDynamic;
class UCanvasRenderTarget2D;
class UMaterial;
class UTextureRenderTarget2D;
class UTexture;
class AActor;
class UMaterialInstance;

USTRUCT(BlueprintType)
struct FPaintParameter
{
	//float DrawSize, FColor Color, UTexture* PreviousTexture, float ForceStrength
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	float DrawSize;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	FColor Color;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	float ForceStrength;
};

USTRUCT(BlueprintType)
struct FDrawParameter
{
	//FVector2D LocationToDraw, FName PaintMarkParam, bool isHit
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	FVector2D LocationToDraw;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	FName PaintMarkParam;
};

/* 모든 액터는 각각 다른 페인팅 조건을 가지고있어야할것같아서 추가하고 테스트해봄.*/
USTRUCT(BlueprintType)
struct FTestTextureParameter
{
	//FVector2D LocationToDraw, FName PaintMarkParam, bool isHit
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* DynamicPaintMat;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* DynamicPaintMarkerMat;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	UTextureRenderTarget2D* MyRenderTarget;
};

UCLASS()
class UEPROTOTYPE_API UVPTexturer : public UObject
{
	GENERATED_BODY()
public:

	UVPTexturer();

	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static UVPTexturer* GetGlobalTexturer();
	
	//Texture 생성 및 편집에 필요한 파라미터 초기화
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void InitEditMaterial(AActor* Actor, FName DrawLocationName,
	UTextureRenderTarget2D* CanvasRT);
	// TODO 2019.11.18 위의 함수를 수정하기위해 임의로 작성. 만약 11.22일 이후에도 존재한다면 지우길 바람.
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void TestInitEditMaterial(AActor* Actor, UTextureRenderTarget2D* Target);

	//실시간으로 그리기 작업
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void PaintTexture(FVector2D LocationToDraw, FName PaintMarkParam);

	// TODO 2019.11.18 위의 함수를 수정하기위해 임의로 작성. 만약 11.22일 이후에도 존재한다면 지우길 바람.
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void TestPaintTexture(AActor* Actor, FVector2D LocationToDraw, FName PaintMarkParam);

	//그리기 도구 편집용 함수
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void EditPaintParameter(float DrawSize, FColor Color, float ForceStrength, UTextureRenderTarget2D* CanvasRT = nullptr);
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void EraseTarget();
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void TestEraseTarget(AActor* Actor);
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void SetDrawing(bool isDrawing) { IsDrawing = isDrawing; }
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	bool GetDrawing()const { return IsDrawing; }
private:
	// 직접적으로 텍스쳐와 합쳐질 머테리얼
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* DynamicPaintMat;

	// 그리기도구에 대한 머테리얼
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	UMaterialInstanceDynamic* DynamicPaintMarkerMat;

	//그려질 RenderTarget
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	UTextureRenderTarget2D* MyRenderTarget;

	UPROPERTY()
	bool IsDrawing;

	UPROPERTY()
	TMap<AActor*, FTestTextureParameter> DrawingActors;

	
	/*
		이 밑에 것들은 아직 적용이안됨. 나중에 제작.
	*/
	// DynamicPaintMarkerMat에 그려질 위치에대한 파라미터
	UPROPERTY()
	FName DrawLocation;

	// 현재 그려진 컬러
	UPROPERTY()
	FLinearColor CurrentColor;

	
};
