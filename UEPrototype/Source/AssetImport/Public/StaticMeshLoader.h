// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StaticMeshLoader.generated.h"



class UAssetModel;
class UAssetMesh;
class UStaticMesh;



/**
 *	StaticMeshLoader는 AssimpInterface 클래스를 통해서 UE4에서 이해할 수 있는 형태인
 *	UAssetModel을 입력으로 받아, Static Mesh로 로드하는 클래스입니다.
 */
UCLASS()
class ASSETIMPORT_API UStaticMeshLoader : public UObject
{
	GENERATED_BODY()

public:
	/** AssetModel을 입력으로 받아 StaticMesh를 생성하고 로드합니다. 
		@return	AssetModel의 정보를 바탕으로 구성된 UStaticMesh	*/
	UFUNCTION(BlueprintCallable, Category = Assimp, meta = (DefaultToSelf = Outer))
	UStaticMesh* LoadStaticMeshFromAssetModel(UObject* Outer, UAssetModel* Model);


};
