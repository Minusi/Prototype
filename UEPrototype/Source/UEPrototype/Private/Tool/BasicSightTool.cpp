// Fill out your copyright notice in the Description page of Project Settings.

#include "Tool/BasicSightTool.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"



UBasicSightTool::UBasicSightTool()
{
	// DEBUG : 생성자 로그
	VP_CTOR;



	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}



	/* 사용 가능한 기능과 요구 입력을 추가하여 매핑합니다. */
	// TODO : 매핑 작성할 것
}



UBasicSightTool * UBasicSightTool::GetGlobalBasicSightTool()
{
	for (const auto& it : TObjectRange<UBasicSightTool>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UBasicSightTool::StaticClass()->GetName());
	return nullptr;
}
