// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Templates/UniquePtr.h"

#include "UObject/NoExportTypes.h"

#include "assimp/DefaultLogger.hpp"
#include "AssimpInterface.generated.h"



struct aiScene;
struct aiNode;
struct aiMesh;
/**
 *	AssimpInterface는 UE4 프레임워크를 통해서 Assimp 라이브러리를 호출하고
 *	결과를 Unreal Engine 4에서 사용할 수 있도록 제공하는 UE4-Assimp 인터페이스
 *	입니다.
 */
UCLASS(BlueprintType, ClassGroup=Assimp)
class ASSETIMPORT_API UAssimpInterface : public UObject
{
	GENERATED_BODY()
	
public:
	UAssimpInterface();



public:
	// 지정된 경로에서 모델을 읽어들여옵니다.
	UFUNCTION(BlueprintCallable, Category = "Assimp")
	class UAssetModel* LoadModel(FString FilePath, FString ErrorString);

private:
	// 애셋 파일을 엽니다.
	class UAssetModel * OpenAssetFile(FString FilePath, FString ErrorString);

	void ProcessNode(aiNode const * Node, aiScene const * Scene);

	void ProcessMesh(aiMesh const * Mesh);
	
	// 현재 클래스의 프로퍼티들을 초기화합니다.
	void Clear();
	
private:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Assimp", meta=(AllowPrivateAccess ="true"))
	// 현재 처리 중인 메시의 인덱스입니다.
	int32 MeshCurrentlyProcessed;



	// 모델을 가져오기 위한 UE4 호환 애셋 임포터입니다.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Assimp", meta = (AllowPrivateAccess = "true"))
	class UAssetImporter * Importer;

	// 애셋 모델에 대한 캐시 데이터
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Assimp", meta = (AllowPrivateAccess = "true"))
	class UAssetModel* cModel;

};
