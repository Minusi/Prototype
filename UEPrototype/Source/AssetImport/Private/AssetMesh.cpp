// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetMesh.h"
#include "AssetImport.h"
#include "Engine/Texture.h"



TArray<FVector2D> FUVChannel::GetUVChannel() const
{
	return UVChannel;
}





TArray<FLinearColor> FVertexColorChannel::GetVertexColorChannel() const
{
	return VertexColorChannel;
}





void UAssetMesh::AddVertex(FVector Vertex)
{
	Vertices.Add(Vertex);
}

void UAssetMesh::AddNormal(FVector Normal)
{
	Normals.Add(Normal);
}

void UAssetMesh::AddUVCoord(FVector2D UV, int32 Channel)
{
	if (Channel < 0)
	{
		AI_LOG(Error, TEXT("채널 입력이 음이 아닌 정수여야 합니다."));
		return;
	}

	for (int index = UVs.Num(); index < Channel + 1; ++index)
	{
		UVs.Add(FUVChannel());
	}

	UVs[Channel].UVChannel.Add(UV);
}

void UAssetMesh::AddVertexColor(FLinearColor VertexColor, int32 Channel)
{
	if (Channel < 0)
	{
		AI_LOG(Error, TEXT("채널 입력이 음이 아닌 정수여야 합니다."));
		return;
	}

	for (int index = VertexColors.Num(); index < Channel + 1; ++index)
	{
		VertexColors.Add(FVertexColorChannel());
	}

	VertexColors[Channel].VertexColorChannel.Add(VertexColor);
}

void UAssetMesh::AddTangent(FVector Tangent)
{
	Tangents.Add(Tangent);
}

void UAssetMesh::AddVertexIndex(int32 Index)
{
	if (Index < 0)
	{
		AI_LOG(Error, TEXT("인덱스 입력이 양수여야 합니다."));
		return;
	}
	Indices.Add(Index);
}

FVector UAssetMesh::GetMeshVertex(int32 Index) const
{
	return Vertices[Index];
}

FVector UAssetMesh::GetMeshNormal(int32 Index) const
{
	return Normals[Index];
}

FVector2D UAssetMesh::GetMeshUV(int32 Index, int32 Channel) const
{
	return UVs[Channel][Index];
}

FLinearColor UAssetMesh::GetMeshVertexColor(int32 Index, int32 Channel) const
{
	return VertexColors[Channel][Index];
}

FVector UAssetMesh::GetMeshTangent(int32 Index) const
{
	return Tangents[Index];
}