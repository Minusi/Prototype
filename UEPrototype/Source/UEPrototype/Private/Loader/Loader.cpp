// Fill out your copyright notice in the Description page of Project Settings.

#include "Loader/Loader.h"
#include "UEPrototype.h"
// Sets default values
ALoader::ALoader()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALoader::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALoader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 루트 경로에서 부터 긁어서 모든 에셋을 찾아낸 다음에, 캐스팅 여부에 따라 분류됨
//bool ALoader::CreateLibraryTable()
//{
//	//UObjectLibrary* ObjectLibrary = UObjectLibrary::CreateLibrary(UClass::StaticClass(), false, GIsEditor);
//	//ObjectLibrary->AddToRoot();
//	//ObjectLibrary->LoadAssetDataFromPath("/Game"); // 루트 경로
//
//
//	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
//
//	VP_LOG(Error, TEXT("Create LibraryTable..."));
//	if (!AssetDataTable.IsValidIndex(0))
//	{
//		VP_LOG(Error, TEXT("Fail to Create LibraryTable"));
//		return false;
//	}
//	for (auto &Data : AssetDataTable)
//	{
//		FString ClassName = Data.ObjectType->GetName();
//		TArray< FStringFormatArg > args;
//		args.Add(FStringFormatArg(ClassName));
//		FString string = FString::Format(TEXT("Name = {0}"), args);
//		UE_LOG(LogTemp, Warning, TEXT("Your string: %s"), *string);
//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("ClassName : %d"), ));
//
//		FARFilter Filter;
//		Filter.bRecursiveClasses = true;
//		Filter.ClassNames.Add(Data.ObjectType->GetFName());
//		Filter.PackagePaths.Add("/Game");
//
//		AssetRegistryModule.Get().GetAssets(Filter, Data.AssetData);
//		if (!Data.AssetData.IsValidIndex(0))
//		{
//			TArray< FStringFormatArg > args;
//			args.Add(FStringFormatArg(Data.ObjectType->GetName()));
//			FString string = FString::Format(TEXT("Name = {0}"), args);
//			UE_LOG(LogTemp, Warning, TEXT("%s 타입의 에셋이 하나도 없습니다"), *string);
//		}
//	}
//	return true;
//}

bool ALoader::GetListOfBlueprintInPath(FName Path, TArray<UClass*>& Result, UClass* Class)
{
	UObjectLibrary* Library = UObjectLibrary::CreateLibrary(Class, true, GIsEditor);
	int32 NumOfAssetDatas = Library->LoadBlueprintAssetDataFromPath(Path.ToString());

	if (NumOfAssetDatas == 0)
		return false;

	TArray<FAssetData> Assets;
	Library->GetAssetDataList(Assets);

	for (auto &Asset : Assets)
	{
		UBlueprint* bp = Cast<UBlueprint>(Asset.GetAsset());
		if (bp)
		{
			auto gc = bp->GeneratedClass;
			if (gc)
			{
				Result.Add(gc);
			}
		}
		else
		{
			auto GeneratedClassName = (Asset.AssetName.ToString() + "_C");

			UClass* Clazz = FindObject<UClass>(Asset.GetPackage(), *GeneratedClassName);
			if (Clazz)
			{
				Result.Add(Clazz);
			}
			else
			{
				UObjectRedirector* RenamedClassRedirector = FindObject<UObjectRedirector>(Asset.GetPackage(), *GeneratedClassName);
				if (RenamedClassRedirector)
				{
					Result.Add(CastChecked<UClass>(RenamedClassRedirector->DestinationObject));
				}
			}
		}
	}
	return true;
}

//
//bool ULoader::GetAssetByClass(const TSubclassOf<UClass*> Class, TArray<TSubclassOf<UClass*>>& OutAssetArray)
//{
//	if (!AssetDataTable.Contains(Class))
//	{
//		VP_LOG(Error, TEXT("해당 타입의 에셋은 존재하지 않습니다."));
//		//VP_LOG(Error, *FString::Printf(TEXT("%s 타입의 에셋은 존재하지 않습니다."), Class->GetName()));
//		return false;
//	}
//	else
//	{
//		for (auto &Asset : AssetDataTable[Class])
//		{
//			T* CastedAsset = Cast<T>(Asset.GetAsset());
//			if (CastedAsset != nullptr)
//				OutAssetArray.Add(CastedAsset);
//		}
//	}
//
//	if (OutAssetArray.Empty)
//	{
//		VP_LOG(Error, TEXT("해당 타입의 에셋은 존재하지 않습니다."));
//		//VP_LOG(Error, *FString::Printf(TEXT("%s 타입의 에셋은 존재하지 않습니다."), Class->GetName()));
//		return false;
//	}
//	return true;
//	/*FARFilter Filter;
//	Filter.ClassNames.Add(UStaticMesh::StaticClass());*/
//	//Filter.PackagePaths.Add("/Game/Meshes");
//}

/*
	UObjectLibrary* ObjectLibrary;
	ObjectLibrary->GetAssetDataList(AssetDatas);
*/
