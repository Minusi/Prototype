// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetModel.h"



UAssetModel* UAssetModel::MAKE(FString FilePath, int32 NumInit, UObject* Outer)
{
	UAssetModel* Model = NewObject<UAssetModel>(Outer);
	Model->ConfigureModelInfo(FilePath);
	Model->InitMeshArray(NumInit);
	return Model;
}

void UAssetModel::ConfigureModelInfo(FString FilePath)
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
}

void UAssetModel::InitMeshArray(int32 NumInit)
{
	if (NumInit <= 0)
	{
		AI_LOG(Error, TEXT("배열의 초기화 값은 0 초과여야 합니다."));
		return;
	}

	Meshes.AddZeroed(NumInit);
}





void UAssetModel::SetMeshAt(UAssetMesh* InMesh, int32 Index)
{
	if (Index < 0)
	{
		AI_LOG(Error, TEXT("인덱스는 양수이어야 합니다."));
		return;
	}

	if (Meshes.Num() == 0)
	{
		AI_LOG(Error, TEXT("모델의 메시 배열이 초기화되지 않은 상태에서 유효하지 않은 접근을 수행하려고 합니다"));
		return;
	}
	
	if (Index >= Meshes.Num())
	{
		AI_LOG(Error, TEXT("유효하지 않은 메시 접근을 수행하려고 합니다"));
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
