// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ConstructorHelpers.h"
#include "UEPrototype.h"
#include "Containers/Array.h"
#include "Engine/StaticMesh.h"
#include "GenericPlatform/GenericPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "GridMeshPool.generated.h"

// UGridMeshPool 내의 CreateObject에서 
// 생성 방식을 결정하기 위한 열거형입니다.
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
UCLASS(BlueprintType)
class UEPROTOTYPE_API UGridMeshPool : public UObject
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
	// UGridMeshPool 생성자입니다. 풀 초기화를 수행합니다.
	UGridMeshPool();



public:
	// 오브젝트를 풀에 삽입합니다.
	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Pool", meta = (AllowPrivateAccess = "true"))
	void PushObject(UStaticMeshComponent* InMeshComp);

	// 오브젝트를 풀에서 꺼냅니다.
	UFUNCTION(Blueprintable, BlueprintPure, Category = "Pool", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PopObject();

private:
	// 채울 메시를 생성합니다. ConstructorHelper 클래스를 사용하기 떄문에
	// 생성자 내에서만 호출되어야 합니다.
	UFUNCTION(Blueprintable, BlueprintCallable, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	void FillObject();

	// 오브젝트를 생성합니다. 인자를 잘못 설정하면 크래시가 날 수 있다는 점에서
	// 디폴트값을 NONE으로 설정하였으니 적절한 타입을 설정해 주시기 바랍니다.
	UStaticMeshComponent* CreateObject(ECreateType CreateType = ECreateType::NONE);

private:
	// 오브젝트 풀의 크기
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	int32 MaxPoolSize = 100;


	// 현재 생성한 오브젝트의 인덱스 넘버
	static int32 ObjectIndexNumber;

	// 오브젝트 풀이 오브젝트를 생성할 때 지어주는 이름입니다.
	FString DefaultMeshName;

	// 그리드 생성기에 의해 생성되는 메시 컴포넌트의 포인터 배열입니다.
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	TArray<class UStaticMeshComponent*> GridMeshArray;



	// 메시 설정에 사용할 메시입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	class UStaticMesh* GridMeshTemplate;

	// 그리드 생성기에 의해 생성된 메시 컴포넌트에 입힐 그리드 머티리얼 템플릿입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool|Grid", meta = (AllowPrivateAccess = "true"))
	class UMaterial* GridMaterialTemplate;
};