// Fill out your copyright notice in the Description page of Project Settings.

#include "VPTexturer.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectGlobals.h"
#include "UObjectIterator.h"
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



UVPTexturer::UVPTexturer()
{
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}

UVPTexturer* UVPTexturer::GetGlobalTexturer()
{
	for (const auto& it : TObjectRange<UVPTexturer>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UVPTexturer::StaticClass()->GetName());
	return nullptr;
}

void UVPTexturer::InitEditMaterial(AActor * Actor, FName DrawLocationName,UTextureRenderTarget2D * CanvasRT)
{
	
	if (CanvasRT == nullptr)
	{
		VP_LOG(Error, TEXT("CanvasRT가 유효하지 않습니다."));
		return;
	}
	if (Actor == nullptr)
	{
		VP_LOG(Error, TEXT("InitEditMaterial에 Actor가 유효하지않습니다"));
		return;
	}

	UMaterial* PaintMarkMat = LoadObject<UMaterial>(nullptr, TEXT("/Game/Material/M_PaintMarker"));


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
			DynamicPaintMat = UMaterialInstanceDynamic::Create(thisComp->GetMaterial(0), Actor);
			thisComp->SetMaterial(0, thisComp->GetMaterial(0));
		}
		
	}
	//생성 전에 그려진 부분이 있다면 모두 지워주는 작업
	//UKismetRenderingLibrary::ClearRenderTarget2D(GetWorld(), MyRenderTarget);

}

void UVPTexturer::PaintTexture(FVector2D LocationToDraw, FName PaintMarkParam)
{
	
	// 페인팅 될 위치에 대한 벡터 변수
	FVector LocationVector = FVector(LocationToDraw, 0);

	//런타임에 현재 마우스 커서를 계속 넘겨주면서 페인팅 될 위치에 대한 변수를 수정함.
	DynamicPaintMarkerMat->SetVectorParameterValue(PaintMarkParam, LocationVector);

	//실질적으로 그려주는 작업을 하는 함수
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(GetWorld(), MyRenderTarget, DynamicPaintMarkerMat);
}

void UVPTexturer::EditPaintParameter(float DrawSize, FColor Color, float ForceStrength, UTextureRenderTarget2D* CanvasRT)
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

void UVPTexturer::EraseTarget()
{
	if (MyRenderTarget == nullptr)
	{
		VP_LOG(Error, TEXT("MyRenderTarget이 유효하지 않습니다."));
		return;
	}
	UKismetRenderingLibrary::ClearRenderTarget2D(GetWorld(), MyRenderTarget);
}
