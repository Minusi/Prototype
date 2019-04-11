// Fill out your copyright notice in the Description page of Project Settings.

#include "GridMeshPool.h"

TCHAR const * UGridMeshPool::DefaultMeshPath = TEXT("/Game/Import/MobileStarterContent/Shapes/Shape_Plane.Shape_Plane");
TCHAR const * UGridMeshPool::DefaultMaterialPath = TEXT("/Game/Material/M_WorldGrid_Master.M_WorldGrid_Master");

int32 UGridMeshPool::ObjectIndexNumber = 0;



UGridMeshPool::UGridMeshPool()
{
	DefaultMeshName = FString("GridMesh" + FString::FromInt(ObjectIndexNumber));

	FillObject();
}

void UGridMeshPool::PushObject(UStaticMeshComponent* InMeshComp)
{
	// Guard Clause 패턴을 사용하여 일련의 유효성 검사를 수행합니다.

	if (InMeshComp == nullptr)
	{
		VP_LOG(Warning, TEXT("Input Param is nullptr"));
		return;
	}

	if (GridMeshArray.Num() >= MaxPoolSize)
	{
		return;
	}

	// TODO : 
	//	입력된 애셋이 템플릿 애셋인지를 확인할 것
	//	또한, 템플릿 프로퍼티들을 static 키워드 삽입을 고려할 것

	// 컨테이너에 오브젝트를 삽입합니다.
	GridMeshArray.Add(InMeshComp);
}

UStaticMeshComponent* UGridMeshPool::PopObject()
{
	UStaticMeshComponent* OutMeshComponent = GridMeshArray.Pop();

	// 풀이 비어있으면, 일시적으로 객체를 동적으로 생성합니다.
	if (OutMeshComponent == nullptr)
	{
		// 런타임 중 동적으로 객체를 생성합니다.
		OutMeshComponent = CreateObject(ECreateType::DYNAMIC);
		if (OutMeshComponent != nullptr)
		{
			return OutMeshComponent;
		}
	}
	else
	{
		return OutMeshComponent;
	}

	VP_LOG(Warning, TEXT("Function does not work in purpose"));
	return nullptr;
}

void UGridMeshPool::FillObject()
{
	UStaticMeshComponent* InstancedSMComp;
	for (int32 i = 0; i < MaxPoolSize; ++i)
	{
		InstancedSMComp = CreateObject(ECreateType::CDO);
		//GridMeshArray.Add(InstancedSMComp);
	}
}

UStaticMeshComponent * UGridMeshPool::CreateObject(ECreateType CreateType)
{
	// 생성할 오브젝트에 대한 사전 설정을 수행합니다.
	UStaticMeshComponent* InstancedSMComp;
	DefaultMeshName = FString("GridMesh" + FString::FromInt(ObjectIndexNumber));

	VP_LOG(Log, TEXT("ObjectIndexNumber : %d"), ObjectIndexNumber);
	VP_LOG(Log, TEXT("%s"), *DefaultMeshName);



	// 생성 타입에 따른 오브젝트 생성 수행
	{
		if (CreateType == ECreateType::NONE)
		{
			VP_LOG(Warning, TEXT("Parameter is not set"));
			return nullptr;
		}
		else if (CreateType == ECreateType::CDO)
		{
			InstancedSMComp = CreateDefaultSubobject<UStaticMeshComponent>(*DefaultMeshName);
		}
		else if (CreateType == ECreateType::DYNAMIC)
		{
			InstancedSMComp = NewObject<UStaticMeshComponent>(this, *DefaultMeshName);
		}
		else
		{
			VP_LOG(Error, TEXT("Arrive at Unreachable Area"));
			return nullptr;
		}
	}


	// 오브젝트 설정을 위한 구성요소들에 대한 생성 수행
	{
		// GridMeshTemplate이 설정되지 않았다면, 컨텐츠를 이용하여 생성합니다.
		if (GridMeshTemplate == nullptr)
		{
			static ConstructorHelpers::FObjectFinder<UStaticMesh>
				DefaultGridMeshTemplate(DefaultMeshPath);

			GridMeshTemplate = DefaultGridMeshTemplate.Object;
		}

		// GridMaterialTemplate가 설정되지 않았다면, 컨텐츠를 이용하여 생성합니다.
		if (GridMaterialTemplate == nullptr)
		{
			static ConstructorHelpers::FObjectFinder<UMaterial>
				DefaultGridMaterialTemplate(DefaultMaterialPath);

			GridMaterialTemplate = DefaultGridMaterialTemplate.Object;
		}
	}


	// 구성요소들에 대한 유효성 검사 수행
	{
		if (InstancedSMComp == nullptr)
		{
			VP_LOG(Warning, TEXT("컴포넌트가 생성되지 않았습니다"));
			return nullptr;
		}

		if (GridMeshTemplate == nullptr)
		{
			VP_LOG(Warning, TEXT("스태틱 메시가 생성되지 않았습니다"));
			return nullptr;
		}

		if (GridMaterialTemplate == nullptr)
		{
			VP_LOG(Warning, TEXT("머티리얼이 생성되지 않았습니다."));
			return nullptr;
		}
	}


	// 오브젝트 생성 이후 설정 수행
	{
		InstancedSMComp->SetStaticMesh(GridMeshTemplate);
		InstancedSMComp->SetMaterial(0, GridMaterialTemplate);

		// TODO : 테스트용으로 모듈러를 사용중이니 반드시 제거하세요.
		if (ObjectIndexNumber % 100 != 1)
		{
			// 콜리전 기능을 비활성화합니다.
			InstancedSMComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			// 로직 기능을 비활성화합니다.
			InstancedSMComp->SetComponentTickEnabled(false);

			// 가시성 기능을 비활성화합니다.
			InstancedSMComp->SetVisibility(false);
		}
	}

	ObjectIndexNumber++;
	VP_LOG(Log, TEXT("%d : Test"), ObjectIndexNumber);
	return InstancedSMComp;
}