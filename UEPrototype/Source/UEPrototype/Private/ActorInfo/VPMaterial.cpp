// Fill out your copyright notice in the Description page of Project Settings.

#include "VPMaterial.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectGlobals.h"
#include "UObjectIterator.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "EditorWorldManager.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectGlobals.h"
#include "UObjectIterator.h"
#include "VPMaterial.h"

UVPMaterial::UVPMaterial()
{
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}

UVPMaterial * UVPMaterial::GetGlobalMaterial()
{
	for (const auto& it : TObjectRange<UVPMaterial>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}
	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UVPMaterial::StaticClass()->GetName());
	return nullptr;
}

void UVPMaterial::SetMaterialVectorParam(UStaticMeshComponent* Target, FVector Vector, FName Name)
{
	// TODO : 여러 개의 머티리얼을 수정할 수 있도록 해야함.
	UMaterialInterface* TargetMaterial = Target->GetMaterial(0);
	UMaterialInstanceDynamic* DynamicInstance;

	if ((DynamicInstance = Cast<UMaterialInstanceDynamic>(TargetMaterial)) == nullptr)
	{
		DynamicInstance = UMaterialInstanceDynamic::Create(TargetMaterial, NULL);
		Target->SetMaterial(0, DynamicInstance);
	}
	DynamicInstance->SetVectorParameterValue(Name, Vector);
}

void UVPMaterial::SetMaterialUTexture2DParam(UStaticMeshComponent* Target, UTexture2D* Texture, FName Name)
{
	// TODO : 여러 개의 머티리얼을 수정할 수 있도록 해야함.
	UMaterialInterface* TargetMaterial = Target->GetMaterial(0);
	UMaterialInstanceDynamic* DynamicInstance;

	if ((DynamicInstance = Cast<UMaterialInstanceDynamic>(TargetMaterial)) == nullptr)
	{
		DynamicInstance = UMaterialInstanceDynamic::Create(TargetMaterial, NULL);
		Target->SetMaterial(0, DynamicInstance);
	}
	DynamicInstance->SetTextureParameterValue(Name, Texture);
}

void UVPMaterial::SetMaterialLinearColor(UStaticMeshComponent* Target, FLinearColor Color, FName Name)
{
	// TODO : 여러 개의 머티리얼을 수정할 수 있도록 해야함.
	UMaterialInterface* TargetMaterial = Target->GetMaterial(0);
	UMaterialInstanceDynamic* DynamicInstance;

	if ((DynamicInstance = Cast<UMaterialInstanceDynamic>(TargetMaterial)) == nullptr)
	{
		DynamicInstance = UMaterialInstanceDynamic::Create(TargetMaterial, NULL);
		Target->SetMaterial(0, DynamicInstance);
	}

	DynamicInstance->SetVectorParameterValue(Name, Color);
}

void UVPMaterial::SetMaterialScalarParam(UStaticMeshComponent * Target, float Value, FName Name)
{
	// TODO : 여러 개의 머티리얼을 수정할 수 있도록 해야함.
	UMaterialInterface* TargetMaterial = Target->GetMaterial(0);
	UMaterialInstanceDynamic* DynamicInstance;

	if ((DynamicInstance = Cast<UMaterialInstanceDynamic>(TargetMaterial)) == nullptr)
	{
		DynamicInstance = UMaterialInstanceDynamic::Create(TargetMaterial, NULL);
		Target->SetMaterial(0, DynamicInstance);
	}

	DynamicInstance->SetScalarParameterValue(Name, Value);
}