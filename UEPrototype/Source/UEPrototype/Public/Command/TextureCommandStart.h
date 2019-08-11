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

	UFUNCTION(BlueprintCallable,Category ="Command")
	void InitVPTexture(AActor * Actor, UMaterial * PaintMat, FName DrawLocationName, UMaterial * PaintMarkMat, UTextureRenderTarget2D * CanvasRT);
	
	UFUNCTION(BlueprintCallable, Category = "Command")
	void EditPaintParam(float DrawSize, FColor Color, float ForceStrength)
	{
		PaintParam.DrawSize = DrawSize;
		PaintParam.Color = Color;
		PaintParam.ForceStrength = ForceStrength;
		VPTextureEditor->EditPaintParameter(DrawSize, Color, ForceStrength);
	}

	UFUNCTION(BlueprintCallable, Category = "Command")
	void SetDrawParam(FVector2D LocationToDraw, FName PaintMarkParam, bool isHit)
	{
		DrawParam.LocationToDraw = LocationToDraw;
		DrawParam.PaintMarkParam = PaintMarkParam;
		DrawParam.isHit = isHit;
		
	}
	
private:
	/* 하이라이트로 표시할 마커입니다 */
	static UActorConstraintMarker* ActorConstraintMarker;
	
	static UVPTexturer* VPTextureEditor;
	UPROPERTY()
	FPaintParameter PaintParam;
	UPROPERTY()
	FDrawParameter DrawParam;
};
