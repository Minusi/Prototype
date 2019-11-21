// Fill out your copyright notice in the Description page of Project Settings.

#include "DuplicateCommand.h"
#include "UEPrototype.h"
#include "EditorModulesManager.h"
#include "Command/CommandConstraintManager.h"
#include "Command/CmdActivatedConstraint.h"
#include "Command/ActorCommandFactory.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "ActorInfo/ActorConstraintMarker.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/MeshComponent.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Core/PlayerTaskManager.h"

UActorConstraintMarker* UDuplicateCommand::ActorConstraintMarker = nullptr;

UPlayerTaskManager* UDuplicateCommand::PlayerTaskManager = nullptr;

UDuplicateCommand::UDuplicateCommand()
{
	VP_CTOR;
	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager())) return;

	if (!IsValid(UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint()))return;

	UCmdActivatedConstraint* ActivateConstraint = UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint();
	if (IsValid(ActivateConstraint) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UCommandConstraintManager::GetGlobalCommandConstraintManager()->GetCmdActivatedConstraint()->GetName());
		return;
	}
	IActorCmdConstraint* ConstraintInterface = Cast<IActorCmdConstraint>(ActivateConstraint);
	if (ConstraintInterface == nullptr)
	{
		VP_LOG(Warning, TEXT(";;;"));
		return;
	}
	Constraints.Add(ActivateConstraint);

	/* 이미 초기화되어 있으면 생략합니다 */
	if (PlayerTaskManager != nullptr && (ActorConstraintMarker != nullptr && ActorConstraintMarker->IsValidLowLevel()))
	{
		VP_LOG(Log, TEXT("UDuplicateCommand의 멤버가 유효하다네요?"));
		return;
	}
	VP_LOG(Log, TEXT("UDuplicateCommand의 멤버가 유효하지 않다네요?"));

	/* 초기화하는 데 필요한 객체를 가지고 있는 모듈의 유효성을 검사합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}

	/* 초기화를 수행합니다 */
	VP_LOG(Warning, TEXT("[DEBUG] 에디터 모듈이 초기화가 되어있습니다."));
	ActorConstraintMarker = UActorConstraintMarker::GetGlobalActorConstraintMarker();
	PlayerTaskManager = UPlayerTaskManager::GetGlobalPlayerTaskManager();

	/* 초기화된 객체들에 대한 유효성 검사를 실행합니다 */
	if (IsValid(PlayerTaskManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UPlayerTaskManager::StaticClass()->GetName());
		return;
	}
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다"), *UActorConstraintMarker::StaticClass()->GetName());
		return;
	}
	if (Constraints.Num() == 0)
	{
		VP_LOG(Warning, TEXT("제약 조건이 올바르게 설정되지 않았습니다."));
		return;
	}

	// DEBUG
	VP_LOG(Warning, TEXT("[DEBUG] %s : %d, Pointer Address : %x"), *ActorConstraintMarker->GetName(), ActorConstraintMarker->GetUniqueID(), &ActorConstraintMarker);
}

void UDuplicateCommand::ExecuteIf()
{
	if (IsValid(ActorConstraintMarker) == false)
	{
		VP_LOG(Warning, TEXT("명령을 실행하는데 %s가 유효하지 않습니다."), *UActorConstraintMarker::StaticClass()->GetName());
		return;
	}

	/* 대상에 대한 유효성을 검사합니다 */
	if (IsValid(Target.Target) == false)
	{
		VP_LOG(Warning, TEXT("명령의 대상 액터가 유효하지 않습니다."));
	}

	/* 명령이 제약 조건을 만족하는 지 확인합니다 */

	for (const auto& it : Constraints)
	{
		Duplicate(Target.Target);
		/* TODO : 해당 코드는 마우스로 테스트할 때 사용되었습니다. VR환경에서는 버튼에 의해
			ACTOR가 정해지기 때문에 이런 방식으로 접근하지 않습니다.
			복수 액터에 대한 처리를 할 수 없으므로 Duplicate와 마찬가지로 따로 로직을 생성해야합니다.
		*/
		/*for (const auto & t : PlayerTaskManager->GetInteractedActorsInfo())
		{
			if (it->CheckConstraint(t) == true)
			{
				Duplicate(t.Target);
			}
		}*/
	}
}

void UDuplicateCommand::InitActorCommand(FActorConstraintInfo TargetInfo)
{
	Target = TargetInfo;
}

void UDuplicateCommand::Duplicate(AActor* Target)
{
	if (Target == nullptr)
	{
		VP_LOG(Warning, TEXT("Duplicate 될 타겟이 유효하지 않습니다"));
		return;
	}

	FTransform Transform = Target->GetActorTransform();
	FVector Location = Target->GetTargetLocation();
	FVector BoxExtend;
	FActorSpawnParameters SpawnParam;


	Target->GetActorBounds(false, Location, BoxExtend);
	float MaxExtend = FMath::Max3(BoxExtend.X, BoxExtend.Y, BoxExtend.Z);

	// TODO : 아웃라인 객체만 손보고 거리는 손보지말자 나중에.

	/* Duplicate는 템플릿 이용하여 작성
		카메라와 액터사이의 거리를 구해서 거리에 비례하게 복제된 액터가 생성되도록 설정 */
	Transform.SetLocation(FVector(0, MaxExtend, 0));
	SpawnParam.Template = Target;
	SpawnParam.Owner = Target;

	Target->GetWorld()->SpawnActor<AActor>(Target->GetClass(), Transform, SpawnParam);
}