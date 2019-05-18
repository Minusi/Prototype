// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "assimp/scene.h"

#include "Containers/Array.h"
#include "UObject/NoExportTypes.h"
#include "AssetMesh.generated.h"



/*
 * UVChannel은 단일 UV 채널을 나타내는데 사용되는 구조체입니다.
 * Multi-UV 채널을 나타내기 위한 nested array는 구현할 수 없기
 * 때문에 UVChannel의 Container를 통해서 구현하시기 바랍니다
 */
USTRUCT(BlueprintType)
struct FUVChannel
{
	GENERATED_BODY()
	
public:
	FORCEINLINE FVector2D operator[](int32 Index) const
	{
		return UVChannel[Index];
	}

	// UVChannel 배열의 사본을 반환합니다.
	TArray<FVector2D> GetUVChannel() const;





public:
	// 단일 UV 채널을 나타냅니다.
	UPROPERTY(BlueprintReadWrite, Category="Assimp")
	TArray<FVector2D> UVChannel;
};



/*
 *	VertexColorChannel은 단일 버텍스 컬러 채널을 나타내는데 사용되는 구조체입니다.
 *	Multi-VertexColor 채널을 나타내기 위한 nested array는 구현할 수 없기 때문에
 *	VertexColorChannel의 Container를 통해서 구현하시기 바랍니다.
 */
USTRUCT(BlueprintType)
struct FVertexColorChannel
{
	GENERATED_BODY()
	
public:
	FORCEINLINE FLinearColor operator[](int32 Index) const
	{
		return VertexColorChannel[Index];
	}

	// VertexColorChannel 배열의 사본을 반환합니다.
	TArray<FLinearColor> GetVertexColorChannel() const;




public:
	// 단일 버텍스 컬러 채널을 나타냅니다.
	UPROPERTY(BlueprintReadWrite, Category = "Assimp")
	TArray<FLinearColor> VertexColorChannel;
};





/**
 *	AssetMesh 클래스는 모델을 구성하는 메시를 표현하는 클래스입니다. 
 *	일반적으로 메시를 모델로 취급하기도 합니다. 이 클래승에서 의미하는
 *	메시는 UE4에서의 MeshSection과 궤를 같이한다고 보아도 무방합니다.
 */
UCLASS(BlueprintType, ClassGroup=Assimp)
class ASSETIMPORT_API UAssetMesh : public UObject
{
	GENERATED_BODY()
	
public:
	// 정점 위치를 프로퍼티에 추가합니다.
	void AddVertex(FVector Vertex);

	// 노말 위치를 프로퍼티에 추가합니다.
	void AddNormal(FVector Normal);
	
	// UV 좌표를 프로퍼티에 추가합니다.
	void AddUVCoord(FVector2D UV, int32 Channel = 0);

	// 버택스 컬러를 프로퍼티에 추가합니다.
	void AddVertexColor(FLinearColor VertexColor, int32 Channel = 0);

	// 탄젠트를 프로퍼티에 추가합니다.
	void AddTangent(FVector Tangent);

	// 정점 인덱스를 UAssetMesh에 추가합니다.
	void AddVertexIndex(int32 Index);



public:
	// 정점 배열의 사본을 반환합니다.
	FORCEINLINE UFUNCTION(BlueprintCallable, BlueprintPure, Category="Assimp|Mesh")
	TArray<FVector> GetVertices() const
	{
		return Vertices;
	}

	// 노말 벡터 배열의 사본을 반환합니다.
	FORCEINLINE UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	TArray<FVector> GetNormals() const
	{
		return Normals;
	}

	// 주어진 채널에 대한 UV 좌표 배열의 사본을 반환합니다.
	FORCEINLINE UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FUVChannel GetUVs(int32 Channel) const
	{
		return UVs[Channel];
	}

	// 주어진 채널에 대한 버텍스 컬러 배열의 사본을 반환합니다.
	FORCEINLINE UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FVertexColorChannel GetVertexColors(int32 Channel) const
	{
		return VertexColors[Channel];
	}

	// 탄젠트 벡터 배열의 사본을 반환합니다.
	FORCEINLINE UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	TArray<FVector> GetTangents() const
	{
		return Tangents;
	}



public:
	// 지정된 인덱스의 정점 위치의 사본을 반환합니다.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FVector GetMeshVertex(int32 Index) const;

	// 지정된 인덱스의 노말 벡터의 사본을 반환합니다.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FVector GetMeshNormal(int32 Index) const;

	// 지정된 인덱스와 채널을 가진 UV 좌표의 사본을 반환합니다.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FVector2D GetMeshUV(int32 Index, int32 Channel) const;

	// 지정된 인덱스의 채널을 가진 버텍스 컬러의 사본을 반환합니다.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FLinearColor GetMeshVertexColor(int32 Index, int32 Channel) const;

	// 지정된 인덱스의 탄젠트 벡터의 사본을 반환합니다.
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Assimp|Mesh")
	FVector GetMeshTangent(int32 Index) const;



private:
	// 메시를 구성하는 정점들의 배열입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Assimp|Mesh", meta=(AllowPrivateAccess="true"))
	TArray<FVector> Vertices;

	// 정점들의 인덱스 배열입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assimp|Mesh", meta = (AllowPrivateAccess = "true"))
	TArray<int32> Indices;


	// 노말 벡터들의 인덱스 배열입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assimp|Mesh", meta = (AllowPrivateAccess = "true"))
	TArray<FVector> Normals;

	// UV 좌표들의 배열입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assimp|Mesh", meta = (AllowPrivateAccess = "true"))
	TArray<FUVChannel> UVs;

	// 8 채널까지 정점 색상을 지원하는 assimp와
	// 1 채널까지 정점 색상을 지원하는 ue4의 호환을 맞추기 위한 배열입니다.
	// TODO : 런타임에 정점 색상을 변경할 수 있는지 확인하시기 바랍니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assimp|Mesh", meta = (AllowPrivateAccess = "true"))
	TArray<FVertexColorChannel> VertexColors;

	// 탄젠트 벡터들의 인덱스 배열입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assimp|Mesh", meta = (AllowPrivateAccess = "true"))
	TArray<FVector> Tangents;


	
	// 메시에 사용되는 텍스처들의 배열입니다.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Assimp|Mesh", meta = (AllowPrivateAccess = "true"))
	TArray<class UTexture*> Textures;
};
