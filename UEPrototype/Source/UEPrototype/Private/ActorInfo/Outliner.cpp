// Fill out your copyright notice in the Description page of Project Settings.

#include "Outliner.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectGlobals.h"
#include "UObjectIterator.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "EditorWorldManager.h"

UOutliner::UOutliner()
{
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}

UOutliner* UOutliner::GetGlobalOutliner()
{
	for (const auto& it : TObjectRange<UOutliner>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}

	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UOutliner::StaticClass()->GetName());
	return nullptr;
}

/* 현재 포커싱된 아웃라인을 지웁니다 */
void UOutliner::ClearFocusedOutline()
{
	if (OutlineFocusedActor != nullptr)
		OutlineFocusedActor->Destroy();
}

void UOutliner::AddFocusedOutline(AActor * Actor, TCHAR* OutlinePath)
{
	ClearFocusedOutline();

	UMaterialInstance* OutlineMaterial;
	// TODO : 나중에 텍스트부분을 사용자가 고칠 수 있도록 경로의 변수화를 해 줘야함.
	OutlineMaterial = LoadObject<UMaterialInstance>(nullptr, OutlinePath);
	
	// Template을 통해 아웃라이너를 생성합니다.
	FActorSpawnParameters SpawnParam;
	SpawnParam.Template = Actor;
	SpawnParam.Owner = Actor;
	OutlineFocusedActor = Actor->GetWorld()->SpawnActor<AActor>(Actor->GetClass(), SpawnParam);

	/* 생성된 액터는 라인트레이스의 영향을 받지 않도록, 콜리전을 제거합니다. */
	OutlineFocusedActor->SetActorEnableCollision(false);

	// 아웃라인을 스폰후 액터의 자식으로 넣어준다(기즈모나 트랜스폼에 의한 이동에 대해서 같이 따라가야하니깐)
	OutlineFocusedActor->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);

	//자식 이름을 변경해준다. 이것을 통해 outline의 생성여부를 key로서 확인할 것이다.
	OutlineFocusedActor->Tags.Add(OutlinerLabelName);

	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SMComps;
	OutlineFocusedActor->GetComponents(SMComps);

	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto& it : SMComps)
	{
		UStaticMesh* Mesh = it->GetStaticMesh();
		if (IsValid(Mesh))
		{
			it->SetMaterial(0, UMaterialInstanceDynamic::Create(OutlineMaterial, this));
		}
	}
}


/* Draw는 이전의 하이라이트들을 모두 지우고 해당 타겟에 대한 하이라이트를 생성합니다. */
void UOutliner::DrawHighlightedOutline(AActor * Actor, TCHAR * OutlinePath)
{
	ClearHighlightedOutline();
	AddHighlightedOutline(Actor, OutlinePath);
}

/* OutlineHighlightActors에 담긴 모든 액터에 대한 Highlight를 지웁니다 */
void UOutliner::ClearHighlightedOutline()
{
	ClearFocusedOutline();
	for (int i = 0; i < OutlineHighlightActors.Num(); i++)
	{
		OutlineHighlightActors.Array()[i]->Destroy();
	}
	OutlineHighlightActors.Reset();
}

/* 해당 액터에 대해 Highlight를 추가 시킵니다 */
void UOutliner::AddHighlightedOutline(AActor * Actor, TCHAR * OutlinePath)
{
	//Highlight가 켜질 때 focus부분은 제거된다.
	ClearFocusedOutline();
	RemoveHighlightedOutline(Actor);

	UMaterialInstance* OutlineMaterial;
	// TODO : 나중에 텍스트부분을 사용자가 고칠 수 있도록 경로의 변수화를 해 줘야함.
	OutlineMaterial = LoadObject<UMaterialInstance>(nullptr, OutlinePath);

	FActorSpawnParameters SpawnParam;
	SpawnParam.Template = Actor;
	SpawnParam.Owner = Actor;
	AActor* SpawnHighlightActor = Actor->GetWorld()->SpawnActor<AActor>(Actor->GetClass(), SpawnParam);

	/* 생성된 액터는 라인트레이스의 영향을 받지 않도록, 콜리전을 제거합니다. */
	SpawnHighlightActor->SetActorEnableCollision(false);

	// 아웃라인을 스폰후 액터의 자식으로 넣어준다(기즈모나 트랜스폼에 의한 이동에 대해서 같이 따라가야하니깐)
	SpawnHighlightActor->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);

	//자식 이름을 변경해준다. 이것을 통해 outline의 생성여부를 key로서 확인할 것이다.
	OutlineFocusedActor->Tags.Add(OutlinerLabelName);

	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SMComps;
	SpawnHighlightActor->GetComponents(SMComps);

	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto& it : SMComps)
	{
		UStaticMesh* Mesh = it->GetStaticMesh();
		if (IsValid(Mesh))
		{
			it->SetMaterial(0, UMaterialInstanceDynamic::Create(OutlineMaterial, this));
			OutlineHighlightActors.Add(SpawnHighlightActor);
		}
	}
}

void UOutliner::AddHighlightedOutline(TSet<AActor*>& Actors)
{
	RemoveHighlightedOutline(Actors);
	for (int i = 0; i < Actors.Num(); ++i)
	{
		AddHighlightedOutline(Actors.Array()[i]);
	}
}

void UOutliner::RemoveHighlightedOutline(TSet<AActor*>& Actors)
{
	for (int ActorsNum = 0; ActorsNum < Actors.Num(); ActorsNum++)
	{
		TArray<AActor*> ParentActor;
		Actors.Array()[ActorsNum]->GetAttachedActors(ParentActor);

		for (int i = 0; i < OutlineHighlightActors.Num(); i++)
		{
			for (int j = 0; j < ParentActor.Num(); j++)
			{
				if (OutlineHighlightActors.Array()[i] == ParentActor[j])
				{
					OutlineHighlightActors.Array()[i]->Destroy();
					return;
				}
			}
		}
	}
}

void UOutliner::RemoveHighlightedOutline(AActor * Actor)
{
	if (IsValid(Actor) == false)
	{
		VP_LOG(Error, TEXT("Actor가 존재하지 않습니다."));
		return;
	}

	/*
		삭제되는 액터를 OutlineHighlightActors에서 찾아야 하는데 매개변수로 받아오는 Actor와
		배열에 담고있는 HighlightActor는 서로 다른 actor이기 때문에
		매개변수로 받아오는 Actor에 부착된 자식 액터중에 HighlightActor와 같은것을
		찾는방식으로 destroy함.
	*/
	TArray<AActor*> ParentActor;
	Actor->GetAttachedActors(ParentActor);

	for (int i = 0; i < OutlineHighlightActors.Num(); i++)
	{
		for (int j = 0; j < ParentActor.Num(); j++)
		{
			if (OutlineHighlightActors.Array()[i] == ParentActor[j])
			{
				// TODO : 추후에 성능을위해 Destroy 시키지 않는 방법을 사용할 것
				OutlineHighlightActors.Array()[i]->Destroy();
				OutlineHighlightActors.Remove(OutlineHighlightActors.Array()[i]);
				return;
			}
		}
	}
}