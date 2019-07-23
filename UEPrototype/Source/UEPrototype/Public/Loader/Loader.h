// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetRegistry/Public/AssetData.h"
#include "AssetRegistry/Public/IAssetRegistry.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "UObject/ObjectRedirector.h"
#include "Modules/ModuleManager.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/Blueprint.h"
#include "Loader.generated.h"

USTRUCT(BlueprintType)
struct FAssetDataInfo
{
	GENERATED_BODY()

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Loader|AssetData", meta = (AllowPrivateAccess = "true"))
	//TSubclassOf<UObject> ObjectType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Loader|AssetData", meta = (AllowPrivateAccess = "true"))
	TArray<FAssetData> AssetData;
};

UCLASS(BlueprintType)
class UEPROTOTYPE_API ALoader : public AActor
{
	GENERATED_BODY()
		// Sets default values for this actor's properties
public:
	ALoader();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//UFUNCTION(BlueprintCallable, Category = "Loader")
	//bool CreateLibraryTable();

	UFUNCTION(BlueprintCallable, Category = "Loader|Blueprint")
	bool GetListOfBlueprintInPath(FName Path, TArray<UClass*>& Result, UClass* Class);
	/*
		UFUNCTION(BlueprintCallable, Category = "Loader")
		bool GetAssetByClass(const TSubclassOf<UClass*> Class, TArray<TSubclassOf<UClass*>>& OutAssetArray);
	*/
private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Loader|Data", meta = (AllowPrivateAccess = "true"))
	TMap<TSubclassOf<UObject>, FAssetDataInfo> AssetDataTable;
};