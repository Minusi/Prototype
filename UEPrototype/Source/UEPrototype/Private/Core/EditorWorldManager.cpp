// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorWorldManager.h"
#include "UEPrototype.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "EditorModulesManager.h"



// Sets default values
AEditorWorldManager::AEditorWorldManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/* 모듈 최상위 관리자를 생성합니다 */
	EditorModulesManager = CreateDefaultSubobject<UEditorModulesManager>(MakeUniqueObjectName(this, UEditorModulesManager::StaticClass()));
	if (IsValid(EditorModulesManager) == false)
	{
		//VP_LOG(Error, TEXT("서브오브젝트 생성에 실패하였습니다 : %s".), *UEditorModulesManager::StaticClass()->GetName());
		return;
	}
}





bool AEditorWorldManager::IsActorBlocked(const AActor * InTarget) const
{
	/* 액터 인자의 유효성을 검사합니다 */
	if (IsValid(InTarget) == false)
	{
		VP_LOG(Warning, TEXT("입력받은 InTarget 인자가 유효하지 않습니다"));
		return false;
	}

	/* 배열에서 해당 액터를 수색합니다 */
	EActorConstraintState TargetState = EActorConstraintState::CSTR_None;
	for (const auto& it : BlockedActors)
	{
		if (it.Target == InTarget)
		{
			TargetState = it.TargetState;
			break;
		}
	}

	/* Blocked 상태이면 참을 반환합니다 */
	if (TargetState == EActorConstraintState::CSTR_Blocked)
	{
		return true;
	}

	return false;
}





void AEditorWorldManager::GetActorPlaceContent(const AActor * InTarget, FActorPlaceContent& OutContent) const
{
	/* 액터 인자의 유효성을 검사합니다 */
	if (IsValid(InTarget) == false)
	{
		VP_LOG(Warning, TEXT("입력받은 InTarget 인자가 유효하지 않습니다"));
		return;
	}

	/* 컨테이너에서 해당 액터를 수색합니다 */
	for (const auto& it : ActorsPlaceInfo)
	{
		if (InTarget == it.Target)
		{
			OutContent = it.TargetContent;
			break;
		}
	}
}





AEditorWorldManager * AEditorWorldManager::GetGlobalEditorWorldManager(const UObject* WorldContextObject)
{
	/* 월드 컨텍스트 객체를 얻어 AEditorWorldManager를 찾습니다. */
	for (const auto& it : TActorRange<AEditorWorldManager>(WorldContextObject->GetWorld()))
	{
		return it;
	}

	return nullptr;
}



UEditorModulesManager* AEditorWorldManager::GetGlobalEditorModulesManager(const UObject* WorldContextObject)
{
	AEditorWorldManager* LocalEditorWorldManager = GetGlobalEditorWorldManager(WorldContextObject);
	if (IsValid(LocalEditorWorldManager) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *AEditorWorldManager::StaticClass()->GetName());
		return nullptr;
	}

	/* 반환합니다 */
	return LocalEditorWorldManager->EditorModulesManager;
}



UEditorModulesManager * AEditorWorldManager::GetGlobalEditorModulesManagerFast(const AEditorWorldManager * InEditorWorldManager)
{
	/* AEditorWorldManager의 내부 Getter를 이용하여 반환합니다 */
	return InEditorWorldManager->GetEditorModulesManager();
}
