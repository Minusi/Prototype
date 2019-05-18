// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "assimp/Importer.hpp"

#include "Templates/UniquePtr.h"
#include "UObject/NoExportTypes.h"

#include "ImporterAdapter.h"
#include "AssetImporter.generated.h"





/**
 *	AssetImporter는 assimp의 importer의 기능을 Unreal Engine 4 환경에 맞게
 *	사용할 수 있도록 어댑터 패턴을 이용하여 기능을 제공하는 클래스입니다.
 *	따라서 기능의 확장시에 ImporterAdapter에 우선 기재해 주시기 바랍니다.
 */
UCLASS()
class ASSETIMPORT_API UAssetImporter : public UObject
{
	GENERATED_BODY()
	
public:
	/* 
	 *	ImporterAdapter 인터페이스로부터 상속받음.
	 */
	struct aiScene const * ReadFile(FString const FileName, uint32 pFlags);

	FString const GetErrorString() const;


private:
	TUniquePtr<Assimp::Importer> AIImporter;
};
