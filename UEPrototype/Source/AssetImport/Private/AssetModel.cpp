// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetModel.h"



UAssetModel* UAssetModel::MAKE(FString FilePath, aiScene const * AIScene, UObject* Outer)
{
	if (AIScene == nullptr)
	{
		AI_LOG(Error, TEXT("aiScene이 유효하지 않아 UAssetModel을 생성할 수 없습니다"));
		return nullptr;
	}



	UAssetModel* Model = NewObject<UAssetModel>(Outer);
	Model->ConfigureModelInfo(FilePath, AIScene);



	// Scene에 존재하는 메시 수만큼 빈 배열로 초기화합니다.
	Model->InitEmpty(AIScene->mNumMeshes);
	AI_LOG(Log, TEXT("aiScene _ mNumMeshes : %d"), AIScene->mNumMeshes);
	AI_LOG(Log, TEXT("mRootNode _ mNumChildren : %d"), AIScene->mRootNode->mNumChildren);

	return Model;
}

void UAssetModel::ConfigureModelInfo(FString FilePath, aiScene const * InAIScene)
{
	// 파일 경로로부터 디렉토리와 파일명을 저장합니다.
	{
		if (FilePath.Len() == 0)
		{
			return;
		}

		int LastIndex;
		FilePath.FindLastChar(TEXT('/'), LastIndex);

		Directory = FilePath.Left(LastIndex);
		FileName = FilePath.Right((FilePath.Len() - LastIndex + 1) + 2);

		// 디버깅 용도
		AI_LOG(Log, TEXT("Directory : %s, FileName : %s"), *Directory, *FileName);
	}

	AIScene = InAIScene;
}

void UAssetModel::InitEmpty(int32 Count)
{
	if (Count <= 0)
	{
		AI_LOG(Error, TEXT("초기화하기 위한 숫자는 0 초과의 양수여야 합니다."));
		return;
	}

	if (Meshes.Num() > 0)
	{
		AI_LOG(Error, TEXT("메시가 이미 초기화되어 있습니다."));
		return;
	}
	
	Meshes.AddZeroed(Count);
}





void UAssetModel::SetMeshAt(UAssetMesh* InMesh, int32 Index)
{
	if (Index < 0)
	{
		AI_LOG(Error, TEXT("인덱스는 양수이어야 합니다."));
		return;
	}
	Meshes[Index] = InMesh;
}

UAssetMesh* const UAssetModel::GetMeshAt(int32 Index) const
{
	if (IsValid(Meshes[Index]))
	{
		return Meshes[Index];
	}

	AI_LOG(Error, TEXT("유효하지 않은 인덱스를 참조하고 있습니다"));
	return nullptr;
}

int32 UAssetModel::GetMeshNum() const
{
	return Meshes.Num();
}





#if WITH_EDITOR
void UAssetModel::DisplayModel() const
{
	int32 MeshIndex = 0, VertIndex = 0;
	for (auto Mesh : Meshes)
	{
		VertIndex = 0;
		TArray<FVector> Vertices = Mesh->GetVertices();
		for (auto Vertex : Vertices)
		{
			AI_LOG(Warning, TEXT("  %d : %s %s %s"), VertIndex, Vertex.X, Vertex.Y, Vertex.Z);
			VertIndex++;
		}

		AI_LOG(Log, TEXT("Mesh %d : "), MeshIndex);
		MeshIndex++;
	}

}
#endif