// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Async/Future.h"
#include "Templates/UniquePtr.h"

#include "UObject/NoExportTypes.h"

#include "assimp/DefaultLogger.hpp"
#include "AssimpInterface.generated.h"



struct aiScene;
struct aiNode;
struct aiMesh;

class UAssetModel;
class UAssetMesh;



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
	/** 모델의 생성이 끝났을 때 브로드캐스트하는 멀티캐스트입니다. */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModelLoadCompleted, UAssetModel*, AssetModel);



public:
	/**	지정된 경로에서 모델링 파일을 불러옵니다.
		모델이 비동기식으로 로드되므로, 로드가 완료되었을 때 이벤트를 통해 필요로 하는 모든 객체에게 노티파이합니다.
		@return 모델이 로드되었음을 알리는 이벤트에 등록할 수 있는 UAssimpInterface를 반환합니다. */
	UFUNCTION(BlueprintCallable, Category = "Assimp")
	static UAssimpInterface* LoadModelFromDiskAsync(FString const & ModelPath, UObject* Outer);

	/** 지정된 경로에서 모델링 파일을 불러옵니다.
		@return 성공적인 경우, UE4 형식의 정점 정보를 저장하는 UAssetModel을 반환합니다. */
	UFUNCTION(BlueprintCallable, Category = Assimp)
	static UAssetModel * LoadModelFromDisk(FString const & ModelPath, UObject* Outer);

private:
	// 비동기 로드 작업을 수행하고 값을 TFuture에 반환합니다.
	void LoadModelAsyncAndReturn(UObject* Outer, FString const & ModelPath);
	

private:
	/** aiScene의 루트 노드 및 모든 하위 노드의 메시 섹션 대해 ProcessMesh를 호출합니다. */
	static void ProcessNode(UObject* Outer, aiNode const * Node, aiScene const * Scene, UAssetModel* IOModel);

	/** 메시 구조체의 모든 정점을 ue4 정점으로 변환합니다. 
		@return 성공한 경우, 정점 정보들이 담긴 AssetMesh를 반환합니다. */
	static UAssetMesh* ProcessMesh(UObject* Outer, aiMesh const * Mesh);



public:
	/** 다이내믹 멀티캐스트 델리게이트를 반환합니다. */
	FOnModelLoadCompleted OnModelLoadCompleted()
	{
		return LoadCompleted;
	}

	



private:
	/** 모델 로드 완료시 브로드캐스트하는 이벤트 델리게이트입니다 */
	UPROPERTY(BlueprintAssignable, Category=Assimp, meta=(AllowPrivateAccess=true))
	FOnModelLoadCompleted LoadCompleted;

	/** 비동기 연산 이후 값이 저장되는 Future 객체입니다. */
	TFuture<UAssetModel*> Future;
};
