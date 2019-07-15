// Fill out your copyright notice in the Description page of Project Settings.

#include "Grid/EditorGrid.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "UEPrototype.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"


// Sets default values
AEditorGrid::AEditorGrid()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	EditorGridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EditorGridMesh"));
	RootComponent = EditorGridMesh;

	bSyncWithGridSnap = false;
	GridInterval = 100.f;
	GridIntervalCache = GridInterval;

	bGridTracing = false;
	bGridVisualize = true;
	TraceTimerInterval = 5.f;

}


// Called when the game starts or when spawned
void AEditorGrid::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TraceTimerHandle;

	if (EditorGridMesh == nullptr)
		return;
	
	auto GridMaterial = EditorGridMesh->GetMaterial(0);
	if (GridMaterial == nullptr)
		return;

	MIDTemplate = UMaterialInstanceDynamic::Create(GridMaterial, nullptr);
	if (MIDTemplate == nullptr)
	{
		VP_LOG(Warning, TEXT("플레이어 컨트롤러가 유효하지 않습니다."));
		return;
	}

	EditorGridMesh->SetMaterial(0, MIDTemplate);


	CachedPlayer = GetWorld()->GetFirstPlayerController();
	GetWorldTimerManager().SetTimer
	(
		TraceTimerHandle, this, &AEditorGrid::UpdateGridPosition, TraceTimerInterval, true
	);

	
}





// 그리드스냅의 동기화를 on/off 설정 합니다.
void AEditorGrid::SetSyncWithGridSnapEnabled(bool bSyncWithGridSnap)
{
	if (bSyncWithGridSnap)
	{
		GridIntervalCache = GridInterval;
		this->bSyncWithGridSnap = bSyncWithGridSnap;
	}

}

// 그리드 스냅의 동기화 여부를 반환합니다.
bool AEditorGrid::IsSyncWithGridSnap() const
{
	return bSyncWithGridSnap;
}

// 그리드 간격을 설정합니다
void AEditorGrid::SetGridInterval(float GridInterval)
{
	this->GridInterval = GridInterval;
}

// 그리드 간격 값을 반환합니다.
float AEditorGrid::GetGridInterval() const
{
	return GridInterval;
}





void AEditorGrid::SetGridColor(FLinearColor const InColor, int const InGridIndex)
{
	FString ParamString = FString::FromInt(InGridIndex) + TEXT("LevelTint");
	FName ParamName(*ParamString);
	MIDTemplate->SetVectorParameterValue(ParamName, InColor);
}

void AEditorGrid::SetGridScale(float const InGridScale)
{
	MIDTemplate->SetScalarParameterValue(TEXT("GridScale"), InGridScale);
}

void AEditorGrid::SetGridFadeDistance(float const InFadeDistance)
{
	MIDTemplate->SetScalarParameterValue(TEXT("FadeDistance"), InFadeDistance);
}

void AEditorGrid::SetGridOpacity(float const InGridOpacity)
{
	MIDTemplate->SetScalarParameterValue(TEXT("GridOpacity"), InGridOpacity);
}






void AEditorGrid::UpdateGridPosition()
{
	if (bGridTracing == false)
	{
		VP_LOG(Warning, TEXT("그리드 추적 기능이 꺼져있습니다."));
		return;
	}
	else if (CachedPlayer == nullptr)
	{
		VP_LOG(Warning, TEXT("플레이어 컨트롤러가 유효하지 않습니다."));
		return;
	}

	VP_LOG(Log, TEXT("플레이어 컨트룰러가 참조되었습니다."));
	FVector LocalPlayerLoc = CachedPlayer->GetPawn()->GetActorLocation();
	LocalPlayerLoc.Z = 0;
	SetActorLocation(LocalPlayerLoc);

	VP_LOG(Log, TEXT("%f %f %f"), LocalPlayerLoc.X, LocalPlayerLoc.Y, LocalPlayerLoc.Z);
}

