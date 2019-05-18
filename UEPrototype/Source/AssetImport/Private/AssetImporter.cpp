// Fill out your copyright notice in the Description page of Project Settings.

#include "AssetImporter.h"
#include "AssetImport.h"

#include "assimp/scene.h"

#include "HAL/PlatformFilemanager.h"
#include "GenericPlatform/GenericPlatformFile.h"



aiScene const * UAssetImporter::ReadFile(FString const FileName, uint32 pFlags)
{
	AI_LOG(Log, TEXT("*****ReadFile 진입점"));

	if (AIImporter == nullptr)
	{
		Assimp::Importer* RawImporter = new Assimp::Importer();
		AIImporter.Reset(RawImporter);
	}

	std::string StrFileName(TCHAR_TO_UTF8(*FileName));
	aiScene const * Scene = AIImporter->ReadFile(StrFileName, pFlags);

	AI_LOG(Log, TEXT("*****ReadFile 종료점"));

	return Scene;
}

FString const UAssetImporter::GetErrorString() const
{
	return AIImporter->GetErrorString();
}
