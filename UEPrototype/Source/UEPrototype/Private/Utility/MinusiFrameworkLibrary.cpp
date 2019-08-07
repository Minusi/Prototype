// Fill out your copyright notice in the Description page of Project Settings.

#include "Utility/MinusiFrameworkLibrary.h"
#include "UEPrototype.h"
#include "EngineUtils.h"
#include "AssetRegistry/Public/IAssetRegistry.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
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

void UMinusiFrameworkLibrary::GetAngleBetweenTwoVector(FVector2D A, FVector2D B, float& Angle)
{
	A.Normalize(); B.Normalize();
	Angle = UKismetMathLibrary::DegAcos(UKismetMathLibrary::DotProduct2D(A, B));
}

float UMinusiFrameworkLibrary::DistanceRatioByOneDimensionalFunction(AActor* StartActor, AActor* EndActor, float  RatioMul, float RatioPlus, float MinSize, float MaxSize)
{
	if (StartActor != nullptr && EndActor != nullptr)
	{
		return UKismetMathLibrary::FClamp(EndActor->GetDistanceTo(StartActor) * RatioMul + RatioPlus, MinSize, MaxSize);
	}
	return 1;
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

void UMinusiFrameworkLibrary::Snap(float Delta, float SnapInterval, bool& bCanSnap, float& SnappedDelta)
{
	float Ratio = Delta / SnapInterval;

	// 최소한 -1이나 1의 비율은 가져야 스냅이 가능
	bCanSnap = !UKismetMathLibrary::InRange_FloatFloat(Ratio, -1, 1, false, false);
	if (bCanSnap)
	{
		// 소숫점 부분은 제거
		Ratio -= UKismetMathLibrary::Fraction(Ratio);
		SnappedDelta = Ratio * SnapInterval;
	}
	else
		SnappedDelta = Delta;
}
void UMinusiFrameworkLibrary::ProjectWorldDirectionToScreenFromOrigin(class APlayerController* PC, FVector InDirection, FVector2D &ProjectedUnitDirectionToScreen)
{
	FVector2D OriginVector;
	if (PC != nullptr)
	{
		UGameplayStatics::ProjectWorldToScreen(PC, InDirection, ProjectedUnitDirectionToScreen);
		UGameplayStatics::ProjectWorldToScreen(PC, FVector::ZeroVector, OriginVector);
		ProjectedUnitDirectionToScreen -= OriginVector;
		ProjectedUnitDirectionToScreen.Normalize();
	}
}

TArray<struct FAssetData> UMinusiFrameworkLibrary::GetAssetDataByObjectType(TSubclassOf<UObject> ObjectType)
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<struct FAssetData> NewAssetData;

	FString ClassName = ObjectType->GetName();
	TArray< FStringFormatArg > args;
	args.Add(FStringFormatArg(ClassName));

	FARFilter Filter;
	Filter.ClassNames.Add(*ClassName);
	// 임포트 경로 밑의 컨텐츠만 들고오도록 수정
	Filter.PackagePaths.Add("/Game/Import/CoreTemplate/Shapes");
	Filter.PackagePaths.Add("/Game/Import/MobileStarterContent/Materials");
	Filter.PackagePaths.Add("/Game/Import/MobileStarterContent/Textures");

	AssetRegistryModule.Get().GetAssets(Filter, NewAssetData);
	UE_LOG(LogTemp, Warning, TEXT("%s 타입의 Asset Data 찾는중..."), *FString::Format(TEXT("Name = {0}"), args));

	//AssetRegistryModule.Get().GetAssetsByClass(*ClassName, NewAssetData);
	if (!NewAssetData.IsValidIndex(0))
		UE_LOG(LogTemp, Warning, TEXT("%s 타입의 에셋이 하나도 없습니다"), *FString::Format(TEXT("Name = {0}"), args));
	return NewAssetData;
}



void UMinusiFrameworkLibrary::GetInfoWithOuterChain(const UObject * Object)
{
	VP_LOG(Warning, TEXT("CoreInputManager : %s(%d)"), *Object->GetName(), Object->GetUniqueID());
	VP_LOG(Log, TEXT("ObjectFlags : %x"), (uint8)Object->GetFlags());

	UObject* ObjectIt = Object->GetOuter();
	while (IsValid(ObjectIt) == true)
	{
		VP_LOG(Log, TEXT("Outer : %s"), *ObjectIt->GetName());
		ObjectIt = ObjectIt->GetOuter();
	}
}



void UMinusiFrameworkLibrary::GetInfo(const UObject * Object)
{
	VP_LOG(Warning, TEXT("%s(%d)"), *Object->GetName(), Object->GetUniqueID());
	VP_LOG(Log, TEXT("ObjectFlags(hex) : %x"), (uint8)Object->GetFlags());
	VP_LOG(Log, TEXT("ObjectFlags(dec) : %d"), (uint8)Object->GetFlags());
	if (IsValid(Object->GetOuter()) == true)
	{
		VP_LOG(Log, TEXT("Outer : %s"), *Object->GetName());
	}
}
