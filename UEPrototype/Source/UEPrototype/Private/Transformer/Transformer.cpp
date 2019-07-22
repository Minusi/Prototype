// Fill out your copyright notice in the Description page of Project Settings.

#include "Transformer.h"
#include "UEPrototype.h"
#include "EditorGrid.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ATransformer::ATransformer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsSyncWithGridSnap = false;

	DefaultMoveSnapInterval = 0.1f;
	DefaultRotateSnapInterval = 0.1f;
	DefaultScaleSnapInterval = 0.1f;
}


// Called when the game starts or when spawned
void ATransformer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATransformer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}






void ATransformer::MoveObject(AActor* Target, FVector Direction, float SnapInterval, float Delta)
{
	FSnapStruct SnapElement;

	// 스냅 동기화가 켜져있지 않을 경우 디폴트 스냅값으로 스냅 간격 설정
	if (!bIsSyncWithGridSnap) SnapInterval = DefaultMoveSnapInterval;


	Snap(Delta, SnapInterval, SnapElement);

	if (SnapElement.bCanSnap) Target->SetActorLocation(Target->GetActorLocation() + Direction * SnapElement.SnappedDelta);
}



void ATransformer::MoveObjectToCurser(AActor * Target, FVector MousePosition)
{
	Target->SetActorLocation(MousePosition);
}


void ATransformer::RotateObject(AActor * Target, FVector Axis, float SnapInterval, float Delta)
{
	FSnapStruct SnapElement;

	// 스냅 동기화가 켜져있지 않을 경우 디폴트 스냅값으로 스냅 간격 설정
	if (!bIsSyncWithGridSnap) SnapInterval = DefaultRotateSnapInterval;

	Snap(Delta, SnapInterval, SnapElement);

	if (SnapElement.bCanSnap) Target->AddActorWorldRotation(UKismetMathLibrary::RotatorFromAxisAndAngle(Axis, SnapElement.SnappedDelta * -1));

}




void ATransformer::ScaleObject(AActor * Target, FVector Direction, float SnapInterval, float Delta)
{
	FSnapStruct SnapElement;
	FVector NewScale;

	// 스냅 동기화가 켜져있지 않을 경우 디폴트 스냅값으로 스냅 간격 설정
	if (!bIsSyncWithGridSnap)
		SnapInterval = DefaultScaleSnapInterval;

	Snap(Delta, SnapInterval, SnapElement);

	if (SnapElement.bCanSnap)
	{
		NewScale = Target->GetActorScale3D() + Direction * SnapElement.SnappedDelta;

		// 스케일의 값이 1보다 작아질 경우 1로 고정
		if (NewScale.X < 1)NewScale.X = 1;
		if (NewScale.Y < 1)NewScale.Y = 1;
		if (NewScale.Z < 1)NewScale.Z = 1;

		Target->SetActorScale3D(NewScale);
	}
}





void ATransformer::Snap(float Delta, float SnapInterval, FSnapStruct& SnapElement)
{
	float Ratio = Delta / SnapInterval;

	// 최소한 -1이나 1의 비율은 가져야 스냅이 가능
	SnapElement.bCanSnap = !UKismetMathLibrary::InRange_FloatFloat(Ratio, -1, 1, false, false);
	if (SnapElement.bCanSnap)
	{
		// 소숫점 부분은 제거
		Ratio -= UKismetMathLibrary::Fraction(Ratio);
		SnapElement.SnappedDelta = Ratio * SnapInterval;
	}
	else
		SnapElement.SnappedDelta = Delta;
}






void ATransformer::SyncWithGridSnap(bool bIsSyncWithGridSnap)
{
	this->bIsSyncWithGridSnap = bIsSyncWithGridSnap;
}