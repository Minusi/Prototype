// Fill out your copyright notice in the Description page of Project Settings.

#include "MinusiFrameworkLibrary.h"
#include "UEPrototype.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"



bool UMinusiFrameworkLibrary::IsTypeofActor(AActor const * Actor, AActor const * Compare)
{
	if (Actor->GetClass() == Compare->GetClass())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UMinusiFrameworkLibrary::IsTypeofActor_Exec(AActor const * Actor, AActor const * Compare, EBoolean& Execs)
{
	if (Actor->GetClass() == Compare->GetClass())
	{
		Execs = EBoolean::T;
	}
	else
	{
		Execs = EBoolean::F;
	}
}

bool UMinusiFrameworkLibrary::IsTypeofObject(UObject const * Object, UObject const * Compare)
{
	if (Object->GetClass() == Compare->GetClass())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UMinusiFrameworkLibrary::IsTypeofObject_Exec(UObject const * Object, UObject const * Compare, EBoolean & Execs)
{
	if (Object->GetClass() == Compare->GetClass())
	{
		Execs = EBoolean::T;
	}
	else
	{
		Execs = EBoolean::F;
	}
}

bool UMinusiFrameworkLibrary::IsTypeofClass(UObject const * Object, TSubclassOf<UObject> const Compare)
{
	if (Object->GetClass() == *Compare)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UMinusiFrameworkLibrary::IsTypeofClass_Exec(UObject const * Object, TSubclassOf<UObject> const Compare, EBoolean & Execs)
{
	if (Object->GetClass() == *Compare)
	{
		Execs = EBoolean::T;
	}
	else
	{
		Execs = EBoolean::F;
	}
}





void UMinusiFrameworkLibrary::ScreenShortLog(FString const Message, FColor const Color)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, Color, Message);
	}
}

void UMinusiFrameworkLibrary::ScreenLog(FString const Message, FColor const Color)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, Color, Message);
	}

}

void UMinusiFrameworkLibrary::ScreenLongLog(FString const Message, FColor const Color)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, Color, Message);
	}
}





AActor * UMinusiFrameworkLibrary::GetSpecificFirstActorWithTag(const UObject* WorldContextObject, FName Tag, TSubclassOf<AActor> ActorToFind)
{
	TArray<AActor*> WorldActors;

	UGameplayStatics::GetAllActorsWithTag(WorldContextObject, Tag, WorldActors);

	for (auto ActorIt : WorldActors)
	{
		if (ActorIt->GetClass() == *ActorToFind)
		{
			return ActorIt;
		}
	}

	ScreenLog(FString::Printf(TEXT("%s :: 찾으려는 액터가 월드에 존재하지 않습니다."), *FString(__FUNCTION__)));
	return nullptr;
}

TArray<AActor*> UMinusiFrameworkLibrary::GetSpecificAllActorWithTag(const UObject * WorldContextObject, FName Tag, TSubclassOf<AActor> ActorToFind)
{
	TArray<AActor*> WorldActors;
	TArray<AActor*> SpecificActors;

	UGameplayStatics::GetAllActorsWithTag(WorldContextObject, Tag, WorldActors);

	for (auto ActorIt : WorldActors)
	{
		if (ActorIt->GetClass() == *ActorToFind)
		{
			SpecificActors.Add(ActorIt);
		}
	}

	return SpecificActors;
}

FVector UMinusiFrameworkLibrary::GetDirectionOffsetVector(FVector FromVector, FVector ToVector, float Offset)
{
	FVector Direction = UKismetMathLibrary::GetDirectionUnitVector(FromVector, ToVector);
	return Direction * Offset + ToVector;
}


FTransform UMinusiFrameworkLibrary::GetTransformToTraceHitResult(FHitResult HitResult, bool IsHit, FVector ActorLocation)
{
	FTransform NewTranfrom;
	NewTranfrom.SetLocation(ActorLocation);
	FVector NewVector = IsHit ? HitResult.ImpactPoint : HitResult.TraceEnd;
	FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(ActorLocation, NewVector);
	NewTranfrom.SetRotation(NewRotation.Quaternion());
	return NewTranfrom;
}

bool UMinusiFrameworkLibrary::Trace(
	UObject* WorldContextObject,
	AActor* ActorToIgnore,
	const FVector& Start,
	const FVector& End,
	FHitResult& HitOut,
	ECollisionChannel CollisionChannel,
	bool ReturnPhysMat
) {
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	if (!World)
	{
		return false;
	}

	FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), true, ActorToIgnore);
	TraceParams.bTraceComplex = true;
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = ReturnPhysMat;

	//Ignore Actors
	TraceParams.AddIgnoredActor(ActorToIgnore);

	//Re-initialize hit info
	HitOut = FHitResult(ForceInit);

	//Trace!
	World->LineTraceSingleByChannel(
		HitOut,		//result
		Start,	//start
		End, //end
		CollisionChannel, //collision channel
		TraceParams
	);

	//Hit any Actor?
	return (HitOut.GetActor() != NULL);
}


bool UMinusiFrameworkLibrary::TraceWithIgnoreArray(
	UObject* WorldContextObject,
	TArray<AActor*>& ActorsToIgnore,
	const FVector& Start,
	const FVector& End,
	FHitResult& HitOut,
	ECollisionChannel CollisionChannel,
	bool ReturnPhysMat
) {
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
	if (!World)
	{
		return false;
	}

	FCollisionQueryParams TraceParams(FName(TEXT("VictoryCore Trace")), true, ActorsToIgnore[0]);
	TraceParams.bTraceComplex = true;

	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = ReturnPhysMat;

	//Ignore Actors
	TraceParams.AddIgnoredActors(ActorsToIgnore);

	//Re-initialize hit info
	HitOut = FHitResult(ForceInit);

	World->LineTraceSingleByChannel(
		HitOut,		//result
		Start,	//start
		End, //end
		CollisionChannel, //collision channel
		TraceParams
	);

	return (HitOut.GetActor() != NULL);
}

bool UMinusiFrameworkLibrary::TraceComponent(
	UPrimitiveComponent* TheComp,
	const FVector& Start,
	const FVector& End,
	FHitResult& HitOut
) {
	if (!TheComp) return false;
	if (!TheComp->IsValidLowLevel()) return false;
	//~~~~~~~~~~~~~~~~~~~~~

	FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Comp Trace")), true, NULL);
	TraceParams.bTraceComplex = true;
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;

	//Ignore Actors
	//TraceParams.AddIgnoredActors(ActorsToIgnore);

	//Re-initialize hit info
	HitOut = FHitResult(ForceInit);

	return TheComp->LineTraceComponent(
		HitOut,
		Start,
		End,
		TraceParams
	);
}