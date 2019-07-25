// Fill out your copyright notice in the Description page of Project Settings.

#include "Outliner.h"
#include "ActorInfo/Outliner.h"
#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>
#include <Materials/Material.h>
#include <Engine/World.h>
#include <UObjectGlobals.h>
#include <Materials/MaterialInstanceDynamic.h>


// actor가 const인데 const를 떼야 사용할 수 있는 것들이 많음(나중에 생각해봐야함)
void UOutliner::DrawActorOutline(AActor * Actor)
{



	//그리기 중복 검사, LableName을 검사해 해당 자식 Actor에 LabelName이 있다면 제거한다.
	TArray<AActor*> ChildOutliner;
	Actor->GetAttachedActors(ChildOutliner);
	for (auto OutlineIter = ChildOutliner.CreateConstIterator(); OutlineIter;++OutlineIter)
	{
		if ((*OutlineIter)->GetActorLabel() == OutlinerLabelName) return;
	}

	//중복검사를 통과하고(윤곽선이그려져있지않다면)나서 그려질 때마다 해당 Actor를 가장 최근에 그려진 Actor로 지정한다.
	LastOutlinedActor = const_cast<AActor*>(Actor);

	//설정해둔 material을 가져오는 작업
	UMaterialInstance* OutlineMaterial = LoadObject<UMaterialInstance>(nullptr, TEXT("/Game/Material/MI_Outliner"));
	if (OutlineMaterial == nullptr)
	{
		return;
	}

	//Actor를 복제하는 과정. 복제이기 때문에 spawn과정에 필요한 parameter는 모두 해당 Actor에 관한 것들.
	AActor* SpawnedOutlineActor = GetWorld()->SpawnActor<AActor>(Actor->GetClass(), Actor->GetActorLocation(), Actor->GetActorRotation());

	// 아웃라인을 스폰후 액터의 자식으로 넣어준다(기즈모나 트랜스폼에 의한 이동에 대해서 같이 따라가야하니깐)
	SpawnedOutlineActor->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);

	//자식 이름을 변경해준다. 이것을 통해 outline의 생성여부를 key로서 확인할 것이다.
	SpawnedOutlineActor->SetActorLabel(OutlinerLabelName);

	//actor(혹은 자식)의 material에 접근하기위해 staticmeshcomponent 사용
	TArray<UStaticMeshComponent*> SM_Comp;
	SpawnedOutlineActor->GetComponents(SM_Comp);

	//Material을 설정하는 과정. 해당 액터의 모든 Component들을 순회하여 StaticMeshComponent가 있다면 그 Component의 material을
	//미리 만들어놓은 material로 대체함.
	for (auto SMIter = SM_Comp.CreateConstIterator();SMIter;++SMIter)
	{
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			thisComp->SetMaterial(0, UMaterialInstanceDynamic::Create(OutlineMaterial, this));
		}
	}

}


//이 함수에대해서 한 번 생각해봐야한다. 이 함수는 erase를 오직 LastOutlineActor에 대해서만 생각한것.
//복수의 actor가 지정되었을 때 다양한 방식으로 지워질 것을 생각하면 마지막 행의 LastOutlineActor를 nullptr로 지울것이아니라
//하나의 배열을 만들어서(당연이 stack형식인게 유리하다) 마지막으로 체크되었던 actor들을 담아놓아서 차례차례 제거하는형식으로 가야한다.
void UOutliner::EraseActorOutline()
{
	//해당 Actor의 자식 Actor들을 담을 배열
	TArray<AActor*> ChildOutliner;

	//Actor가 지정된적이 없다면 처리를 하지 않는다.
	if (LastOutlinedActor == nullptr) return;

	//가장최근 actor의 자식 actor들을 다 받아온다.
	LastOutlinedActor->GetAttachedActors(ChildOutliner);

	//자식 actor가 없다면 처리를 하지 않는다.
	if (ChildOutliner.Num() == 0) return;

	//자식 actor들을 순회하여 해당 LableName이 있다면 모조리 제거해준다.
	for (auto OutlineIter = ChildOutliner.CreateConstIterator();OutlineIter;++OutlineIter)
	{
		if ((*OutlineIter)->GetActorLabel() == OutlinerLabelName)
		{
			(*OutlineIter)->Destroy();
		}
	}
	//마지막으로 최근 지정된 actor를 nullptr로 만들어준다.
	LastOutlinedActor = nullptr;
}





