// Fill out your copyright notice in the Description page of Project Settings.

#include "GridVisualizer.h"

TCHAR const * AGridVisualizer::DefaultMesh = TEXT("/Game/Import/CoreTemplate/Shapes/Shape_Plane.Shape_Plane");
TCHAR const * AGridVisualizer::DefaultMaterialInstance = TEXT("/Game/Material/MI_WorldGrid_Inst.MI_WorldGrid_Inst");

// Sets default values
AGridVisualizer::AGridVisualizer()
{
	VP_CTOR;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GridComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GridComp"));
	RootComponent = GridComp;

	InitializeTemplate();
	PostInitializeTemplate();

	bVisualizeGrid = false;
	bGridTracing = false;
	TraceTimerInterval = 5.f;
}

void AGridVisualizer::InitializeTemplate()
{
	if (GridComp->GetStaticMesh() != nullptr)
	{
		return;
	}


	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultMeshTemplate(DefaultMesh);
		checkf(DefaultMeshTemplate.Object != nullptr,
			TEXT("%s 지정된 경로에서 애셋을 생성하지 못했습니다."), *VP_LOG_CALLINFO);

		ConstructorHelpers::FObjectFinder<UMaterialInstance> DefaultMITemplate(DefaultMaterialInstance);
		checkf(DefaultMITemplate.Object != nullptr,
			TEXT("%s 지정된 경로에서 머티리얼 인스턴스를 생성하지 못했습니다."), *VP_LOG_CALLINFO);

		GridComp->SetStaticMesh(DefaultMeshTemplate.Object);
		GridComp->SetWorldScale3D(FVector(200, 200, 1));
		MITemplate = DefaultMITemplate.Object;
	}


}

void AGridVisualizer::PostInitializeTemplate()
{
	if (GridComp == nullptr)
	{
		VP_LOG(Error, TEXT("스테틱 메시 컴포넌트가 유효하지 않습니다"));
		return;
	}

	if ( MITemplate == nullptr)
	{
		VP_LOG(Error, TEXT("머티리얼이 유효하지 않습니다"));
		return;
	}

	MIDTemplate = UMaterialInstanceDynamic::Create(MITemplate, nullptr);
	checkf(MIDTemplate != nullptr,
		TEXT("%s 머티리얼로부터 동적 머티리얼 인스턴스를 생성하지 못했습니다"), *VP_LOG_CALLINFO);
//	MIDTemplate->SetFlags(RF_Transient);

	GridComp->SetMaterial(0, MIDTemplate);

}





// Called when the game starts or when spawned
void AGridVisualizer::BeginPlay()
{
	Super::BeginPlay();

	CachedPlayer = GetWorld()->GetFirstPlayerController();

	GetWorldTimerManager().SetTimer
	(
		TraceTimerHandle, this, &AGridVisualizer::BeginGridTracing, TraceTimerInterval, true
	);
}





void AGridVisualizer::ChangeGridColor(FLinearColor const InColor, int const InGridIndex)
{
	FString ParamString = FString::FromInt(InGridIndex) + TEXT("LevelTint");
	FName ParamName(*ParamString);
	MIDTemplate->SetVectorParameterValue(ParamName, InColor);
}

void AGridVisualizer::ConfigureGridScale(float const InGridScale)
{
	MIDTemplate->SetScalarParameterValue(TEXT("GridScale"), InGridScale);
}

void AGridVisualizer::ConfigureGridFadeDistance(float const InFadeDistance)
{
	MIDTemplate->SetScalarParameterValue(TEXT("FadeDistance"), InFadeDistance);
}

void AGridVisualizer::ConfigureGridOpacity(float const InGridOpacity)
{
	MIDTemplate->SetScalarParameterValue(TEXT("GridOpacity"), InGridOpacity);
}

void AGridVisualizer::BeginGridTracing()
{
	if (CachedPlayer == nullptr)
	{
		VP_LOG(Warning, TEXT("플레이어 컨트롤러가 참조되지 않습니다"));
		return;
	}
	FVector LocalPlayerLoc = CachedPlayer->GetPawn()->GetActorLocation();
	LocalPlayerLoc.Z = 0;
	SetActorLocation(LocalPlayerLoc);
}
