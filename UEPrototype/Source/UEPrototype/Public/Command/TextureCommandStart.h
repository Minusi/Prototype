// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command/ActorCommandBase.h"
#include "VPTexturer.h"
#include "TextureCommandStart.generated.h"

class UActorConstraintMarker;
class UTextureRenderTarget2D;
class UMaterial;

UCLASS()
class UEPROTOTYPE_API UTextureCommandStart : public UActorCommandBase
{
	GENERATED_BODY()
public:
	/* 생성자 */
	UTextureCommandStart();

	/* UCommandBase로부터 상속됨 */

	virtual void ExecuteIf() override;

	/* UActorCommandBase로부터 상속됨 */
	virtual void InitActorCommand(FActorConstraintInfo TargetInfo) override;

	UFUNCTION(BlueprintCallable, Category = "Command")

		void InitVPTexture(AActor * Actor, FName DrawLocationName, UTextureRenderTarget2D * CanvasRT);




	UFUNCTION(BlueprintCallable, Category = "Command")
		void EditPaintParam(float DrawSize, FColor Color, float ForceStrength, UTextureRenderTarget2D *CanvasRT)
	{
		PaintParam.DrawSize = DrawSize;
		PaintParam.Color = Color;
		PaintParam.ForceStrength = ForceStrength;
		VPTextureEditor->EditPaintParameter(DrawSize, Color, ForceStrength, CanvasRT);
	}

	UFUNCTION(BlueprintCallable, Category = "Command")
		void SetDrawParam(FVector2D LocationToDraw, FName PaintMarkParam)
	{
		DrawParam.LocationToDraw = LocationToDraw;
		DrawParam.PaintMarkParam = PaintMarkParam;
	
	}

	/*2019-8-14 수요일 급하게 추가.*/
	UFUNCTION(BlueprintCallable,Category = "Command")
	void ClearPaint();


private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;

	static UVPTexturer* VPTextureEditor;
	UPROPERTY()
		FPaintParameter PaintParam;
	UPROPERTY()
		FDrawParameter DrawParam;
};
