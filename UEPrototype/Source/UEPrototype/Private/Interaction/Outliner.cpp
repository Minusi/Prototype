// Fill out your copyright notice in the Description page of Project Settings.

#include "Outliner.h"
#include "../Public/Interaction/Outliner.h"
#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>
#include <Materials/Material.h>
#include <Engine/World.h>
#include <UObjectGlobals.h>
#include <Materials/MaterialInstanceDynamic.h>

 UOutliner::UOutliner()
{
	
}
 // actor가 const인데 const를 떼야 사용할 수 있는 것들이 많음(나중에 생각해봐야함)
void UOutliner::DrawActorOutline(const AActor * actor)
{
	LastOutlinedActor = const_cast<AActor*>(actor);
	
	//그리기 중복 검사
	TArray<AActor*> ChildOutliner;
	actor->GetAttachedActors(ChildOutliner);
	for (int i = 0; i < ChildOutliner.Num(); ++i)
	{
		if (ChildOutliner[i]->GetActorLabel() == OutlinerLabelName) return;
	}

	//설정해둔 material을 가져오는 작업
	UMaterialInstance* OutlineMaterial = LoadObject<UMaterialInstance>(nullptr, TEXT("/Game/Material/MI_Outliner"));
	if (OutlineMaterial == nullptr)
	{
		return;
	}

	
	AActor* SpawnedOutlineActor = GetWorld()->SpawnActor<AActor>(actor->GetClass(), actor->GetActorLocation(), actor->GetActorRotation());

	// 아웃라인을 스폰후 액터의 자식으로 넣어준다(기즈모나 트랜스폼에 의한 이동에 대해서 같이 따라가야하니깐)
	SpawnedOutlineActor->AttachToActor(const_cast<AActor*>(actor),FAttachmentTransformRules::KeepWorldTransform);
	
	//자식 이름을 변경해준다. 이것을 통해 outline의 생성여부를 key로서 확인할 것이다.
	SpawnedOutlineActor->SetActorLabel(OutlinerLabelName);

	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SM_Comp;
	SpawnedOutlineActor->GetComponents(SM_Comp);

	for (int i = 0; i < SM_Comp.Num(); i++)
	{
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>(SM_Comp[i]);
		if (thisComp)
		{
			thisComp->SetMaterial(0, UMaterialInstanceDynamic::Create(OutlineMaterial, this));
		}
	}

}

void UOutliner::EraseActorOutline()
{
	TArray<AActor*> ChildOutliner;

	if (LastOutlinedActor == nullptr) return;

	LastOutlinedActor->GetAttachedActors(ChildOutliner);
	
	if (ChildOutliner.Num() == 0) return;

	for (int i = 0; i < ChildOutliner.Num(); ++i)
	{
		if (ChildOutliner[i]->GetActorLabel() == OutlinerLabelName)
		{
			ChildOutliner[i]->Destroy();			
		}
	}
	LastOutlinedActor = nullptr;
}





