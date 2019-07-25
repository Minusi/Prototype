// Fill out your copyright notice in the Description page of Project Settings.

#include "Outliner.h"
#include "ActorInfo/Outliner.h"
#include <GameFramework/Actor.h>
#include <Components/StaticMeshComponent.h>
#include <Materials/Material.h>
#include <Engine/World.h>
#include <UObjectGlobals.h>
#include <Materials/MaterialInstanceDynamic.h>


// actor�� const�ε� const�� ���� ����� �� �ִ� �͵��� ����(���߿� �����غ�����)
void UOutliner::DrawActorOutline(AActor * Actor)
{



	//�׸��� �ߺ� �˻�, LableName�� �˻��� �ش� �ڽ� Actor�� LabelName�� �ִٸ� �����Ѵ�.
	TArray<AActor*> ChildOutliner;
	Actor->GetAttachedActors(ChildOutliner);
	for (auto OutlineIter = ChildOutliner.CreateConstIterator(); OutlineIter;++OutlineIter)
	{
		if ((*OutlineIter)->GetActorLabel() == OutlinerLabelName) return;
	}

	//�ߺ��˻縦 ����ϰ�(�������̱׷��������ʴٸ�)���� �׷��� ������ �ش� Actor�� ���� �ֱٿ� �׷��� Actor�� �����Ѵ�.
	LastOutlinedActor = const_cast<AActor*>(Actor);

	//�����ص� material�� �������� �۾�
	UMaterialInstance* OutlineMaterial = LoadObject<UMaterialInstance>(nullptr, TEXT("/Game/Material/MI_Outliner"));
	if (OutlineMaterial == nullptr)
	{
		return;
	}

	//Actor�� �����ϴ� ����. �����̱� ������ spawn������ �ʿ��� parameter�� ��� �ش� Actor�� ���� �͵�.
	AActor* SpawnedOutlineActor = GetWorld()->SpawnActor<AActor>(Actor->GetClass(), Actor->GetActorLocation(), Actor->GetActorRotation());

	// �ƿ������� ������ ������ �ڽ����� �־��ش�(����� Ʈ�������� ���� �̵��� ���ؼ� ���� ���󰡾��ϴϱ�)
	SpawnedOutlineActor->AttachToActor(Actor, FAttachmentTransformRules::KeepWorldTransform);

	//�ڽ� �̸��� �������ش�. �̰��� ���� outline�� �������θ� key�μ� Ȯ���� ���̴�.
	SpawnedOutlineActor->SetActorLabel(OutlinerLabelName);

	//actor(Ȥ�� �ڽ�)�� material�� �����ϱ����� staticmeshcomponent ���
	TArray<UStaticMeshComponent*> SM_Comp;
	SpawnedOutlineActor->GetComponents(SM_Comp);

	//Material�� �����ϴ� ����. �ش� ������ ��� Component���� ��ȸ�Ͽ� StaticMeshComponent�� �ִٸ� �� Component�� material��
	//�̸� �������� material�� ��ü��.
	for (auto SMIter = SM_Comp.CreateConstIterator();SMIter;++SMIter)
	{
		UStaticMeshComponent* thisComp = Cast<UStaticMeshComponent>((*SMIter));
		if (thisComp)
		{
			thisComp->SetMaterial(0, UMaterialInstanceDynamic::Create(OutlineMaterial, this));
		}
	}

}


//�� �Լ������ؼ� �� �� �����غ����Ѵ�. �� �Լ��� erase�� ���� LastOutlineActor�� ���ؼ��� �����Ѱ�.
//������ actor�� �����Ǿ��� �� �پ��� ������� ������ ���� �����ϸ� ������ ���� LastOutlineActor�� nullptr�� ������̾ƴ϶�
//�ϳ��� �迭�� ����(�翬�� stack�����ΰ� �����ϴ�) ���������� üũ�Ǿ��� actor���� ��Ƴ��Ƽ� �������� �����ϴ��������� �����Ѵ�.
void UOutliner::EraseActorOutline()
{
	//�ش� Actor�� �ڽ� Actor���� ���� �迭
	TArray<AActor*> ChildOutliner;

	//Actor�� ���������� ���ٸ� ó���� ���� �ʴ´�.
	if (LastOutlinedActor == nullptr) return;

	//�����ֱ� actor�� �ڽ� actor���� �� �޾ƿ´�.
	LastOutlinedActor->GetAttachedActors(ChildOutliner);

	//�ڽ� actor�� ���ٸ� ó���� ���� �ʴ´�.
	if (ChildOutliner.Num() == 0) return;

	//�ڽ� actor���� ��ȸ�Ͽ� �ش� LableName�� �ִٸ� ������ �������ش�.
	for (auto OutlineIter = ChildOutliner.CreateConstIterator();OutlineIter;++OutlineIter)
	{
		if ((*OutlineIter)->GetActorLabel() == OutlinerLabelName)
		{
			(*OutlineIter)->Destroy();
		}
	}
	//���������� �ֱ� ������ actor�� nullptr�� ������ش�.
	LastOutlinedActor = nullptr;
}





