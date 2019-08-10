// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWorldPositioner.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"



UHUDWorldPositioner::UHUDWorldPositioner()
{
	// DEBUG : 생성자 로그
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
}



UHUDWorldPositioner * UHUDWorldPositioner::GetGlobalHUDWorldPositioner()
{
	for (const auto& it : TObjectRange<UHUDWorldPositioner>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}



	/* 반복자에서 찾지 못하면 시스템에 큰 결함이 있는 것입니다. */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다"), *UHUDWorldPositioner::StaticClass()->GetName());
	return nullptr;
}
