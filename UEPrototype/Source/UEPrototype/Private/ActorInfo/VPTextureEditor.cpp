// Fill out your copyright notice in the Description page of Project Settings.

#include "VPTextureEditor.h"
#include <UObjectGlobals.h>
#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>
#include <Materials/Material.h>
#include <Materials/MaterialInstanceDynamic.h>
#include <Kismet/KismetRenderingLibrary.h>
#include <Engine.h>
#include <Engine/World.h>
#include <Engine/Canvas.h>
#include <Engine/TextureRenderTarget.h>
#include <Engine/CanvasRenderTarget2D.h>





void AVPTextureEditor::InitEditMaterial(AActor * Actor, UMaterial * PaintMat, FName DrawLocationName, UMaterial * PaintMarkMat, UTextureRenderTarget2D * CanvasRT)
{
	if (PaintMarkMat == nullptr || PaintMat == nullptr
		|| PaintMarkMat == nullptr || CanvasRT == nullptr)
	{
		return;
	}

	//사용자가 미리 만들어놓은 머테리얼 생성
	DynamicPaintMat = UMaterialInstanceDynamic::Create(PaintMat, Actor);

	//사용자가 미리 만들어놓은 머테리얼 생성
	DynamicPaintMarkerMat = UMaterialInstanceDynamic::Create(PaintMarkMat, Actor);

	//StaticMesh 내의 Material을 가져오기 위한 것.
	TArray<UStaticMeshComponent*> SM_Comp;
	Actor->GetComponents(SM_Comp);

	//사용자가 미리 만들어 놓은 RenderTarget을 내부 변수에 저장.
	MyRenderTarget = CanvasRT;

	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto SMIter = SM_Comp.CreateConstIterator(); SMIter; ++SMIter)
	{
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			thisComp->SetMaterial(0, DynamicPaintMat);
		}
	}
	//생성 전에 그려진 부분이 있다면 모두 지워주는 작업
	UKismetRenderingLibrary::ClearRenderTarget2D(GetWorld(), MyRenderTarget);

}

void AVPTextureEditor::PaintTexture(FVector2D LocationToDraw, FName PaintMarkParam, bool isHit)
{
	if (!isHit) return;

	// 페인팅 될 위치에 대한 벡터 변수
	FVector LocationVector = FVector(LocationToDraw, 0);

	//런타임에 현재 마우스 커서를 계속 넘겨주면서 페인팅 될 위치에 대한 변수를 수정함.
	DynamicPaintMarkerMat->SetVectorParameterValue(PaintMarkParam, LocationVector);

	//실질적으로 그려주는 작업을 하는 함수
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), MyRenderTarget, DynamicPaintMarkerMat);
}

void AVPTextureEditor::EditPaintParameter(float DrawSize, FColor Color, UTexture* PreviousTexture, float ForceStrength)
{
	// 그려질 머테리얼의 색을 받아옴.
	FLinearColor C = FLinearColor(Color.R, Color.G, Color.B, Color.A);

	// 현재 컬러를 담는 변수(나중에 쓰일 변수, 지금은 아무 의미없음)
	//CurrentColor = DynamicPaintMat->K2_GetVectorParameterValue("MatColor");

	//붓의 크기를 결정
	DynamicPaintMarkerMat->SetScalarParameterValue("DrawSize", DrawSize);

	//붓의 흐리기(blur)효과를 넣음.
	DynamicPaintMarkerMat->SetScalarParameterValue("ForceStrength", ForceStrength);

	//붓의 색을 바꿔줌.
	DynamicPaintMat->SetVectorParameterValue("MatColor", C);

	/*
		나중에 쓰일 함수들. 지금은 아무 의미없음.
	*/
	// 이전 텍스처에 대한 정보를 바꿔줌.
	/*DynamicPaintMat->SetTextureParameterValue("PreviousTexture", PreviousTexture);*/

	// 이전 컬러에 대한 정보를 바꿔줌.
	/*DynamicPaintMat->SetVectorParameterValue("PreviousColor", CurrentColor);*/


}
