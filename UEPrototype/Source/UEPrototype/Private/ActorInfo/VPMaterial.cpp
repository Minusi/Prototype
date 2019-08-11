// Fill out your copyright notice in the Description page of Project Settings.

#include "VPMaterial.h"
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




UVPMaterial::UVPMaterial()
{

}

void UVPMaterial::SetMaterialVectorParam(AActor* Target, FVector Vector,FName Name)
{

	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SM_Comp;
	Target->GetComponents(SM_Comp);
	
	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto SMIter = SM_Comp.CreateConstIterator(); SMIter; ++SMIter)
	{
		
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			UMaterialInstanceDynamic* DynamicInst = UMaterialInstanceDynamic::Create(thisComp->GetMaterial(0), NULL);
			DynamicInst->SetVectorParameterValue(Name, Vector);
			thisComp->SetMaterial(0, DynamicInst);

		}
	}

	
	

}

void UVPMaterial::SetMaterialUTexture2DParam(AActor* Target,UTexture2D* Texture, FName Name)
{
	
	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SM_Comp;
	Target->GetComponents(SM_Comp);
	
	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto SMIter = SM_Comp.CreateConstIterator(); SMIter; ++SMIter)
	{
		
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			UMaterialInstanceDynamic* DynamicInst = UMaterialInstanceDynamic::Create(thisComp->GetMaterial(0), NULL);
			DynamicInst->SetTextureParameterValue(Name, Texture);
			thisComp->SetMaterial(0, DynamicInst);

		}
	}
}

void UVPMaterial::SetMaterialLinearColor(AActor* Target,FLinearColor Color, FName Name)
{
	
	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SM_Comp;
	Target->GetComponents(SM_Comp);
	
	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto SMIter = SM_Comp.CreateConstIterator(); SMIter; ++SMIter)
	{
		
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			UMaterialInstanceDynamic* DynamicInst = UMaterialInstanceDynamic::Create(thisComp->GetMaterial(0), NULL);
			DynamicInst->SetVectorParameterValue(Name, Color);
			thisComp->SetMaterial(0, DynamicInst);
			
		}
	}
}

void UVPMaterial::SetMaterialScalarParam(AActor * Target, float Value, FName Name)
{
	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SM_Comp;
	Target->GetComponents(SM_Comp);

	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto SMIter = SM_Comp.CreateConstIterator(); SMIter; ++SMIter)
	{

		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			UMaterialInstanceDynamic* DynamicInst = UMaterialInstanceDynamic::Create(thisComp->GetMaterial(0), NULL);
			DynamicInst->SetScalarParameterValue(Name, Value);
			thisComp->SetMaterial(0, DynamicInst);

		}
	}
}
