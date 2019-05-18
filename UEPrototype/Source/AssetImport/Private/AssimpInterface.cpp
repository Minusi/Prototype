// Fill out your copyright notice in the Description page of Project Settings.

#include "AssimpInterface.h"
#include "AssetImporter.h"
#include "AssetModel.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "Misc/DateTime.h"




UAssimpInterface::UAssimpInterface()
{
	AI_CTOR;
	MeshCurrentlyProcessed = 0;
}





UAssetModel* UAssimpInterface::LoadModel(FString FilePath, FString ErrorString)
{
	// 로그 파일 이름에 필요한 시스템 시간을 불러옵니다.
	FDateTime Now = FDateTime::Now();
	
	// 로그 파일 이름을 생성하기 위한 문자열을 정의합니다.
	FString FileOrientName = TEXT("C:/Users/Utsuho/Desktop/General/Project/Prototype/UEPrototype/Saved/Logs/AssimpLog-");
	FString Date = Now.ToString();
	FString FileExtension = TEXT(".txt");
	FString FullName = FileOrientName + Date + FileExtension;

	// Assimp 로거가 없으면 생성합니다.
	if (Assimp::DefaultLogger::isNullLogger())
	{
		Assimp::DefaultLogger::create(TCHAR_TO_ANSI(*FullName));
		Assimp::DefaultLogger::get()->info("Test");
	}



	UAssetModel* Model = OpenAssetFile(FilePath, ErrorString);
	
	Assimp::DefaultLogger::kill();
	return Model;
}

UAssetModel* UAssimpInterface::OpenAssetFile(FString FilePath, FString ErrorString)
{
	AI_LOG(Log, TEXT("*****OpenAssetFile 진입점"));

	// 애셋 임포터가 유효하지 않으면 동적으로 생성합니다.
	if (IsValid(Importer) == false)
	{
		Importer = NewObject<UAssetImporter>();
	}


	aiScene const * Scene = Importer->ReadFile
	(
		FilePath, 
		aiProcess_ConvertToLeftHanded |
		aiProcess_Triangulate | 
		aiProcess_GenNormals |
		aiProcess_GenUVCoords |
		aiProcess_CalcTangentSpace |
		aiProcess_RemoveRedundantMaterials |
		aiProcess_OptimizeMeshes
	);
	if (Scene == nullptr)
	{
		ErrorString = Importer->GetErrorString();
		AI_LOG(Warning, TEXT("다음과 같은 문제로 성공하지 못했습니다 : %s"), *ErrorString);
		return nullptr;
	}

	AI_LOG(Log, TEXT("*****Critical Test 진입점"));


	// 빈 애셋 모델을 생성합니다.
	cModel = UAssetModel::MAKE(FilePath, Scene);
	if (IsValid(cModel) == false)
	{
		AI_LOG(Warning, TEXT("UAssetModel 생성에 실패하였습니다."));
		return nullptr;
	}

	ProcessNode(cModel->GetRootNode(), cModel->GetScene());

	AI_LOG(Log, TEXT("*****OpenAssetFile 종료점"));
	return cModel;
}

// 이 함수는 재귀 함수와 하위 함수로 인해서 캐시 모델을 통한 접근에 제한이 있습니다.
// 캐시 모델을 아규먼트로 전달함에 있어 기술적으로 캐시를 통한 전달이 어려우므로
// cModel을 이 함수에서 가급적 사용하지 말기를 권장합니다.
void UAssimpInterface::ProcessNode(aiNode const * Node, aiScene const * Scene)
{

	AI_LOG(Log, TEXT("*****ProcessNode 진입점"));
	if (Scene == nullptr)
	{
		return;
	}

	// 노드의 모든 메시에 대한 정보를 AssetMesh에 저장합니다.
	aiMesh* Mesh;
	for (uint32 index = 0; index < Node->mNumMeshes; ++index)
	{
		/* Tips :
		 * AIScene만이 mMeshes 멤버 변수를 통해 aiMesh에 대한 배열 포인터를
		 * 가지고 있으며, Node의 mMeshes는 단순히 배열의 인덱스를 저장하는 uint
		 * 형이므로 다음과 같이 작성하여 aiMesh를 얻어와야 합니다.
		 */
		Mesh = Scene->mMeshes[Node->mMeshes[index]];

		ProcessMesh(Mesh);
		++MeshCurrentlyProcessed;
	}

	// RootNode에서 자손 노드 순으로 순차 재귀 실행
	// 말단 노드에서 최종적으로 실행을 종료하게 됩니다.
	for (uint32 index = 0; index < Node->mNumChildren; ++index)
	{
		ProcessNode(Node->mChildren[index], Scene);
	}

	AI_LOG(Log, TEXT("*****ProcessNode 종료점"));
}

void UAssimpInterface::ProcessMesh(aiMesh const * Mesh)
{
	AI_LOG(Log, TEXT("*****ProcessMesh 진입점"));

	// cModel이 비어있는 상태이므로 Mesh에 빈 배열을 추가합니다.
	UAssetMesh* AssetMesh = NewObject<UAssetMesh>();

	FVector Vertex, Normal, Tangent;
	TArray<FLinearColor> VertexColor;
	TArray<FVector2D> UV;


	
	// 메시 요소에 대한 유효성 검증을 위한 부울 멤버 집합입니다.
	struct FMeshElementValidity
	{
	public:
		bool bVertexValid = true;
		bool bNormalValid = true;
		bool bTexCoordValid = true;
		bool bVertexColorValid = true;
		bool bTangentValid = true;
	} MeshElementValidity;

	struct FMeshElementChannel
	{
		uint8 NumVertexColorChannel = 0;
		uint8 NumUVCoordChannel = 0;
	} MeshElementChannel;

	/******** 점, 노말, 탄젠트, 정점 색상, UV에 대한 유효성 검증 시작 **********/
	{
		// 정점에 대한 유효성 검사 수행
		if (Mesh->HasPositions() == false)
		{
			AI_LOG(Error, TEXT("메시에 정점 정보가 존재하지 않습니다"));
			MeshElementValidity.bVertexValid = false;
		}

		// 노말에 대한 유효성 검사 수행
		if (Mesh->HasNormals() == false)
		{
			AI_LOG(Error, TEXT("메시에 노말 데이터가 존재하지 않습니다."));
			MeshElementValidity.bNormalValid = false;
		}

		// 텍스처 좌표에 대한 유효성 검사 수행
		for (int index = 0; ; ++index)
		{
			if(Mesh->HasTextureCoords(index) == false)
			{
				// UV 채널이 존재하지 않는다는 의미
				if(index == 0)
				{
					AI_LOG(Error, TEXT("메시에 텍스처 좌표 데이터가 존재하지 않습니다"));
					MeshElementValidity.bTexCoordValid = false;

					UV.AddZeroed();
				}

				break;
			}
			UV.AddZeroed();
			MeshElementChannel.NumUVCoordChannel++;
		}

		// 버텍스 컬러에 대한 유효성 검사 수행
		for (int index = 0; ; ++index)
		{
			if (Mesh->HasVertexColors(index) == false)
			{
				// 버텍스 채널이 존재하지 않는다는 의미
				if (index == 0)
				{
					AI_LOG(Log, TEXT("메시에 버텍스 컬러 데이터가 존재하지 않습니다"));
					MeshElementValidity.bVertexColorValid = false;

					VertexColor.AddZeroed();
				}

				break;
			}
			VertexColor.AddZeroed();
			MeshElementChannel.NumVertexColorChannel++;
		}

		// 탄젠트/바이탄젠트에 대한 유효성 검사 수행
		if (Mesh->HasTangentsAndBitangents() == false)
		{
			AI_LOG(Error, TEXT("메시에 탄젠트/바이탄젠트 데이터가 존재하지 않습니다"));
			MeshElementValidity.bTangentValid = false;
		}
	}
	AI_LOG(Log, TEXT("Vertex Color 채널 수 : %d, UV Coord 채널 수 : %d"),
		MeshElementChannel.NumVertexColorChannel, MeshElementChannel.NumUVCoordChannel);
	/******** 점, 노말, 탄젠트, 정점 색상, UV에 대한 유효성 검증 종료 **********/


	
	// 버텍스, 노말, 탄젠트, 버텍스 컬러, UV에 대한 변환을 수행합니다.
	for (uint32 index = 0; index < Mesh->mNumVertices; ++index)
	{
		// 정점 프로세스
		if (MeshElementValidity.bVertexValid)
		{
			Vertex.X = Mesh->mVertices[index].x;
			Vertex.Y = Mesh->mVertices[index].y;
			Vertex.Z = Mesh->mVertices[index].z;
		}
		else
		{
			AI_LOG(Fatal, TEXT("유효하지 않은 값으로 플로우를 수행하고 있습니다. MeshElementValidity를 참조하시기 바랍니다"));
			return;
		}
		AI_LOG(Log, TEXT("*****Vertex Process 종료 : %f %f %f"), Vertex.X, Vertex.Y, Vertex.Z);

		// 노말 프로세스
		if (MeshElementValidity.bNormalValid)
		{
			Normal.X = Mesh->mNormals[index].x;
			Normal.Y = Mesh->mNormals[index].y;
			Normal.Z = Mesh->mNormals[index].z;
		}
		else
		{
			AI_LOG(Fatal, TEXT("유효하지 않은 값으로 플로우를 수행하고 있습니다. MeshElementValidity를 참조하시기 바랍니다"));
			return;
		}
		AI_LOG(Log, TEXT("*****Normal Process 종료 : %f %f %f"), Normal.X, Normal.Y, Normal.Z);

		// 탄젠트 프로세스
		if (MeshElementValidity.bTangentValid)
		{
			Tangent.X = Mesh->mTangents[index].x;
			Tangent.Y = Mesh->mTangents[index].y;
			Tangent.Z = Mesh->mTangents[index].z;
		}
		else
		{
			Tangent.X = 0.f;
			Tangent.Y = 1.f;
			Tangent.Z = 0.f;
		}
		AI_LOG(Log, TEXT("*****Tangent Process 종료 : %f %f %f"), Tangent.X, Tangent.Y, Tangent.Z);

		// 버텍스 컬러 프로세스
		if (MeshElementChannel.NumVertexColorChannel > 0)
		{
			for (uint32 jndex = 0; jndex < MeshElementChannel.NumVertexColorChannel; ++jndex)
			{
				FLinearColor Color;
				Color.R = Mesh->mColors[jndex]->r;
				Color.G = Mesh->mColors[jndex]->g;
				Color.B = Mesh->mColors[jndex]->b;
				Color.A = Mesh->mColors[jndex]->a;

				VertexColor.Add(Color);
			}
		}
		else
		{
			FLinearColor DefaultColor;
			DefaultColor.R = 1.0f;
			DefaultColor.G = 1.0f;
			DefaultColor.B = 1.0f;
			DefaultColor.A = 1.0f;

			VertexColor.Add(DefaultColor);
		}
		AI_LOG(Log, TEXT("*****Vertex Color Process 종료"));



		// UV 좌표 프로세스
		if(MeshElementChannel.NumUVCoordChannel > 0)
		{
			for (uint32 texidx = 0; texidx < MeshElementChannel.NumUVCoordChannel; ++texidx)
			{
				FVector2D TempUV;
				TempUV.X = Mesh->mTextureCoords[texidx][index].x;
				TempUV.Y = Mesh->mTextureCoords[texidx][index].y;

				UV.Add(TempUV);
			}
		}
		else
		{
			FVector2D DefaultUV;
			DefaultUV.X = 0;
			DefaultUV.Y = 0;

			UV.Add(DefaultUV);
		}
		AI_LOG(Log, TEXT("*****UV Process 종료"));


		// Assimp->UE4로 포팅된 데이터들을 UAssetMesh 데이터에 추가합니다.
		AssetMesh->AddVertex(Vertex);
		AssetMesh->AddNormal(Normal);
		AssetMesh->AddTangent(Tangent);
		for (int uvchannel = 0; uvchannel < UV.Num(); ++uvchannel)
		{
			AssetMesh->AddUVCoord(UV[index], uvchannel);
		}
		for (int vcchannel = 0; vcchannel < VertexColor.Num(); ++vcchannel)
		{
			AssetMesh->AddVertexColor(VertexColor[index], vcchannel);
		}

		AI_LOG(Log, TEXT("*****UAssetMesh Process 종료"));
	}

	// 정점 인덱스 프로세스
	AI_LOG(Log, TEXT("mNumFaces : %d"), Mesh->mNumFaces);
	for (uint32 vertidx = 0; vertidx < Mesh->mNumFaces; ++vertidx)
	{
		aiFace Face = Mesh->mFaces[vertidx];
		AssetMesh->AddVertexIndex(Face.mIndices[2]);
		AssetMesh->AddVertexIndex(Face.mIndices[1]);
		AssetMesh->AddVertexIndex(Face.mIndices[0]);
	}
	AI_LOG(Log, TEXT("*****Vertex Index Process 종료"));

	cModel->SetMeshAt(AssetMesh, MeshCurrentlyProcessed);

	AI_LOG(Log, TEXT("*****ProcessMesh 종료점"));
}





void UAssimpInterface::Clear()
{
	cModel = nullptr;
	MeshCurrentlyProcessed = 0;
}
