// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include <Engine/EngineTypes.h>
#include "VPTextureEditor.generated.h"

class UMaterialInstanceDynamic;
class UCanvasRenderTarget2D;
class UMaterial;

USTRUCT(BlueprintType)
struct FPaintParameter2 
{
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
class UEPROTOTYPE_API AVPTextureEditor : public AActor
{
	GENERATED_BODY()

public:

	AVPTextureEditor();
	

	//Texture 생성 및 편집에 필요한 파라미터 초기화
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void InitEditMaterial(AActor* Actor, UMaterial* PaintMat, FName DrawLocationName,
	UMaterial* PaintMarkMat, UTextureRenderTarget2D* CanvasRT);

	//실시간으로 그리기 작업
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void PaintTexture(FVector2D LocationToDraw, FName PaintMarkParam,bool isHit);

	//그리기 도구 편집용 함수
	UFUNCTION(BlueprintCallable, Category = "VPEditor")
	void EditPaintParameter(float DrawSize, FColor Color, UTexture* PreviousTexture, float ForceStrength);
protected:


public:
	



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
