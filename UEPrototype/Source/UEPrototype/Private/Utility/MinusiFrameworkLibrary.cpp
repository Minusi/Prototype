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



