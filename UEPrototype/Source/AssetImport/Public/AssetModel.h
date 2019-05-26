// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "assimp/scene.h"

#include "Containers/Array.h"
#include "Templates/UniquePtr.h"
#include "UObject/NoExportTypes.h"

#include "AssetImport.h"
#include "AssetMesh.h"
#include "AssetModel.generated.h"

class UAssetMesh;
struct aiScene;
struct aiNode;

/**
 *	AssetModel 클래스는 하나의 애셋이라고 할 수 있는 메시들의 집합입니다.
 *	일반적으로 메시를 모델로 취급하기도 하지만, 여기서 의미하는 모델은
 *	메시들의 결합으로 의미를 부여받는 객체, 메시 컨테이너로 취급할 수도 있습니다.
 */
UCLASS(BlueprintType, ClassGroup=Assimp)
class ASSETIMPORT_API UAssetModel : public UObject
{
	GENERATED_BODY()
	
public:
	// 커스텀 생성 및 초기화를 수행합니다.
	static UAssetModel* MAKE(FString FilePath, int32 NumInit, UObject* Outer = (UObject*)GetTransientPackage());

private:
	// 주어진 인자들로 AssetModel의 프로퍼티들을 초기화합니다.
	void ConfigureModelInfo(FString FilePath);

	// 인자로 받은 수만큼 배열을 추가합니다.
	void InitMeshArray(int32 NumInit);



public:
	// 특정 인덱스에 새로운 메시를 설정합니다.	
	UFUNCTION(BlueprintCallable, Category="Assimp|Model")
	void SetMeshAt(UAssetMesh* InMesh,int32 Index);

	// 특정 인덱스의 메시를 반환합니다. (읽기 전용)
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Assimp|Model")
	UAssetMesh * const GetMeshAt(int32 Index) const;
	
	// 메시 배열의 요소 개수를 반환합니다.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Assimp|Model")
	int32 GetMeshNum() const;






private:
	// 모델을 구성하는 메시들의 집합입니다.
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Assimp", meta=(AllowPrivateAccess="true"))
	TArray<UAssetMesh*> Meshes;

	// 모델 파일에 대한 디렉토리입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Assimp", meta=(AllowPrivateAccess="true"))
	FString Directory;

	// 모델 파일의 이름과 확장자를 포함합니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Assimp", meta=(AllowPrivateAccess="true"))
	FString FileName;
};
