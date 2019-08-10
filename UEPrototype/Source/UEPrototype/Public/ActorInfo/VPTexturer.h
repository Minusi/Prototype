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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VPEditor", meta = (AllowPrivateAccess = "true"))
	bool isHit;

};

UCLASS()
class UEPROTOTYPE_API UVPTexturer : public UObject
{
	GENERATED_BODY()
public:

	UVPTexturer();

	/* UOutliner를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "ActorInfo", meta = (UnsafeDuringActorConstruction = "true"))
	static UVPTexturer* GetGlobalTexturer();
	//Texture 생성 및 편집에 필요한 파라미터 초기화
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void InitEditMaterial(AActor* Actor, UMaterial* PaintMat, FName DrawLocationName,
	UMaterial* PaintMarkMat, UTextureRenderTarget2D* CanvasRT);

	//실시간으로 그리기 작업
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void PaintTexture(FVector2D LocationToDraw, FName PaintMarkParam, bool isHit);

	//그리기 도구 편집용 함수
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void EditPaintParameter(float DrawSize, FColor Color, float ForceStrength);
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void EraseTarget();

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
