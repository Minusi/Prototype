// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Outliner.generated.h"


class AActor;
UCLASS(Blueprintable, BlueprintType)
class UEPROTOTYPE_API UOutliner : public UObject
{
	GENERATED_BODY()
public:
	UOutliner();
public:

	FORCEINLINE AActor* GetLastOutlinedActor()const { return LastOutlinedActor; }

	UFUNCTION(BlueprintCallable, Category ="Outliner")
	void DrawActorOutline(const AActor* actor);

	UFUNCTION(BlueprintCallable, Category = "Outliner")
	void EraseActorOutline();

	


private:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category ="Outliner", meta =(AllowPrivateAccess="true"))
	AActor* LastOutlinedActor;



	const FString OutlinerLabelName = "OutLiner";

};
