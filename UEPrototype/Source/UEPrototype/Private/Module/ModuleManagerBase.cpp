// Fill out your copyright notice in the Description page of Project Settings.

#include "Module/ModuleManagerBase.h"
#include "UEPrototype.h"



UModuleManagerBase::UModuleManagerBase()
{
	bInitialized = false;
}



void UModuleManagerBase::Initialized()
{
	return;
}





void UModuleManagerBase::RegisterIf(FEventToRegister EventToRegister)
{
	// 이벤트 함수에 바인딩 된 함수가 있는 지 확인합니다.
	if (EventToRegister.IsBound() == false)
	{
		VP_LOG(Warning, TEXT("델리게이트에 바인딩 된 함수가 존재하지 않습니다."));
		return;
	}
	
	// DEBUG
	VP_LOG(Log, TEXT("RegisterIf : bInitialized : %d"), bInitialized);
	VP_LOG(Log, TEXT("RegisterIf : %s::%s 함수가 등록 준비중입니다."), *EventToRegister.GetUObject()->GetName() , *EventToRegister.GetFunctionName().ToString());

	// 이미 모듈 초기화가 끝났다면 지체없이 이벤트를 트리거 합니다.
	if (bInitialized == true)
	{
		VP_LOG(Log, TEXT("RegisterIf : %s::%s 함수를 실행합니다."), *EventToRegister.GetUObject()->GetName(), *EventToRegister.GetFunctionName().ToString());
		EventToRegister.ExecuteIfBound();
	}
	// 모듈 초기화가 진행중이거나 시작하지 않았다면, 이벤트를 디스패처에 등록합니다.
	else
	{
		ModuleEndInitEventDispatcher.Add(EventToRegister);
	}
}
