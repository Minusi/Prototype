// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatform.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ConstructorHelpers.h"
#include "Containers/Array.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstance.h"
#include "UEPrototype.h"
#include "GridObjectPool.generated.h"

/* UGridObjectPool 내의 CreateObject에서
* 생성 방식을 결정하기 위한 열거형입니다.
*/
enum class ECreateType
{
	// 아무것도 하지 않습니다
	NONE,
	// CreateDefaultSubobject를 사용하여 정적으로 생성합니다.
	CDO,
	// NewObject를 사용하여 동적으로 생성합니다.
	DYNAMIC
};

/**
*
*/
UCLASS(BlueprintType, Blueprintable, ClassGroup = Grid)
class UEPROTOTYPE_API UGridObjectPool : public UObject
{
	GENERATED_BODY()

	private:
	/*****************************************************************/
	/*                   HARD CODING CONFIGURATION                   */
	/*****************************************************************/

	// BP에서 애셋을 지정하지 않았을 때 지정해주는 경로입니다.
	static TCHAR const * DefaultMeshPath;
	static TCHAR const * DefaultMaterialPath;

	/*****************************************************************/
	/*                   HARD CODING CONFIGURATION                   */
	/*****************************************************************/





public:
	// UGridObjectPool 생성자입니다. 풀 초기화를 수행합니다.
	UGridObjectPool();



	// 오브젝트를 풀에 삽입합니다.
	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Grid|Pool", meta = (AllowPrivateAccess = "true"))
	void PushObject(UStaticMeshComponent* InMeshComp);

	// 오브젝트를 풀에서 꺼냅니다.
	UFUNCTION(Blueprintable, BlueprintPure, Category = "Grid|Pool", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PopObject();

	//	GridMeshPool에 오브젝트를 채우기 시작합니다.
	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Grid|Pool", meta = (AllowPrivateAccess = "true"))
	void FillObject();


private:
	// GridMeshPool에 담기 위한 오브젝트의 템플릿을 초기화합니다.
	void InitializeTemplate();

	// 오브젝트를 생성합니다. 
	UStaticMeshComponent* CreateObject(ECreateType CreateType = ECreateType::NONE);





private:
	// 오브젝트 풀의 크기
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	int32 MaxPoolSize = 100;


	// 그리드 생성기에 의해 생성되는 메시 컴포넌트의 포인터 배열
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	TArray<class UStaticMeshComponent*> GridObjectArray;


	// 이 오브젝트 풀이 가지고 있는 객체의 템플릿
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Template;



	// 오브젝트 풀이 오브젝트를 생성할 때 지어질 이름
	FString DefaultMeshName;

	// 현재 생성한 오브젝트의 인덱스
	static int32 ObjectIndexNumber;

	// 메시 설정에 사용할 메시 템플릿
	class UStaticMesh* GridMeshTemplate;

	// 그리드 생성기에 의해 생성된 메시 컴포넌트에 입힐 그리드 머티리얼 템플릿.
	class UMaterialInstance* GridMaterialTemplate;
};