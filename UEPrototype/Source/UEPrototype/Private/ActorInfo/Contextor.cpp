// Fill out your copyright notice in the Description page of Project Settings.

#include "Contextor.h"
#include "EditorModulesManager.h"
#include "UEPrototype.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "ActorInfo/HUDWorldPositioner.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"


// Sets default values
AContextor::AContextor()
{
	// DEBUG : 생성자 로그
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/* 위젯 컴포넌트 초기화 */
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(UWidgetComponent::StaticClass()->GetFName());
	WidgetComponent->SetupAttachment(RootComponent);
}



AContextor * AContextor::GetGlobalContextor()
{
	for (const auto& it : TObjectRange<AContextor>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}
	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *AContextor::StaticClass()->GetName());
	return nullptr;
}

// Called when the game starts or when spawned
void AContextor::BeginPlay()
{
	Super::BeginPlay();

	/* 상위 모듈을 받아 멤버 변수들을 초기화합니다 */
	UEditorModulesManager* EditorModulesManager =
		UEditorModulesManager::GetGlobalEditorModulesManager();
	if (IsValid(EditorModulesManager) == false)
	{
		return;
	}

	

	/* 컴포넌트들을 초기화합니다 */
	HUDWorldPositioner = UHUDWorldPositioner::GetGlobalHUDWorldPositioner();
	if (IsValid(HUDWorldPositioner) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UHUDWorldPositioner::StaticClass()->GetName());
		return;
	}



	/* 위젯이 등록되어 있는지 검사합니다 */
	UUserWidget* Widget = WidgetComponent->GetUserWidgetObject();
	if (IsValid(Widget) == false)
	{
		VP_LOG(Warning, TEXT("등록된 컨텍스트 위젯이 없습니다."));
		return;
	}

	/* 위젯이 동적 리스트 위젯을 상속받았는지 확인합니다. */
	UDynamicListWidget* DynamicWidget = Cast<UDynamicListWidget>(Widget);
	if (IsValid(DynamicWidget) == false)
	{
		VP_LOG(Warning, TEXT("위젯은 동적 리스트 위젯이어야 합니다."));
		return;
	}
}





void AContextor::ShowContext(AActor* InActor)
{
	/* 액터가 유효한지 검사합니다 */
	if (IsValid(InActor) == false)
	{
		VP_LOG(Warning, TEXT("액터가 유효하지 않습니다."));
		return;
	}

	/* 위젯 컴포넌트가 유효한지 검사합니다 */
	if (IsValid(WidgetComponent) == false)
	{
		VP_LOG(Warning, TEXT("위젯 컴포넌트가 유효하지 않습니다."));
		return;
	}

	/* 위젯이 등록되어 있는지 검사합니다 */
	UUserWidget* Widget = WidgetComponent->GetUserWidgetObject();
	if (IsValid(Widget) == false)
	{
		VP_LOG(Warning, TEXT("등록된 컨텍스트 위젯이 없습니다."));
		return;
	}

	/* 위젯이 동적 리스트 위젯을 상속받았는지 확인합니다. */
	UDynamicListWidget* DynamicWidget = Cast<UDynamicListWidget>(Widget);
	if (IsValid(DynamicWidget)==false)
	{
		VP_LOG(Warning, TEXT("위젯은 동적 리스트 위젯이어야 합니다."));
		return;
	}

	/* 배치를 결정하는 컴포넌트가 유효한지 검사합니다 */
	if (IsValid(HUDWorldPositioner) == false)
	{
		VP_LOG(Warning, TEXT("%s가 유효하지 않습니다."), *UHUDWorldPositioner::StaticClass()->GetName());
		return;
	}






	/* 위젯을 액터에 배치합니다. */
	HUDWorldPositioner->CalculateWidgetPosition(InActor, DynamicWidget);
	PrevContextedActor = InActor;
}

void AContextor::CloseContext(AActor * InActor)
{

}

void AContextor::ProcessContext(AActor * InActor)
{
}
