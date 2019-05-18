// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "assimp/scene.h"

#include "Templates/UniquePtr.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"

#include "AssetImport.h"
#include "ImporterAdapter.generated.h"

/**
 *	IImporterAdapter는 Assimp 라이브러리의 Importer 클래스를 
 *	Unreal Engine 4 환경에 맞게 사용하기 위해 제공되어지는 
 *	어댑터 인터페이스 클래스입니다.
 */
UINTERFACE()
class ASSETIMPORT_API UImporterAdapter : public UInterface
{
	GENERATED_BODY()
	
};

class IImporterAdapter
{
	GENERATED_BODY()
	
public:
	// 타겟 플랫폼의 지정된 파일경로로부터 모델을 읽어옵니다.
	virtual aiScene const * ReadFile(FString const FileName, uint32 pFlags) PURE_VIRTUAL(__FUNCTION__, return nullptr;);

	// ReadFile()에서 발생한 오류에 대한 자세한 문자열을 반환합니다.
	virtual FString const GetErrorString() const PURE_VIRTUAL(__FUNCTION__, return TEXT(""););
	
};