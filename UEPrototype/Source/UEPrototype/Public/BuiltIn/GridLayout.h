// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridMeshPool.h"
#include "Containers/Array.h"
#include "GridLayout.generated.h"

/*
 *	ArrangeType은 배치를 하는 방법을 결정하는 데 사용되는
 *	열거형 클래스입니다. 새로운 배치 방법을 추가하기 위해서
 *	우선 이 열거형에 컴포넌트를 추가해야 합니다.
 */
enum class EArrangeType
{
	// 디폴트, 아무것도 하지 않습니다.
	AT_NONE,
	// 격자형으로 정렬합니다.
	AT_LATTICE
};

/**
 *	GridLayout 클래스는 GridMeshPool로부터 구성요소들을 제공받아
 *  그리드 시스템을 나타내기 위한 배치 방법을 제공하는 클래스입니다.
 *
 *	현재 사용할 수 있는 레이아웃은 다음과 같습니다:
 *	- LatticeLayout : 격자형으로 맞추듯이 배열합니다.
 */
UCLASS()
class UEPROTOTYPE_API UGridLayout : public UObject
{
	GENERATED_BODY()
	
	
	
private:
	// 배치하려는 구성요소들을 담고 있는 오브젝트 풀입니다.
	UGridMeshPool * UGridMeshPool;
	
	// 배치할 구성요소들을 담고 있는 컨테이너입니다.
	TArray<UStaticMeshComponent*> LayoutSMComp;
};
