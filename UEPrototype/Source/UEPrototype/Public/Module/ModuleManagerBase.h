// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModuleManagerBase.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FModuleEndInitEventDispatcher);
DECLARE_DYNAMIC_DELEGATE(FEventToRegister);



/**
 *	모듈을 관리하는 관리자 클래스들이 상속받아야 하는 모듈 매니저
 *	클래스입니다. 모듈 내 컴포넌트(클래스)들의 생성 및 생성 이후,
 *	컴포넌트(클래스) 간 이벤트 바인딩 및 레퍼런스에 도움을 줄 수 
 *	있는 기능 세트로 구성되어 있습니다.
 *
 *	하나의 모듈에는 반드시 하나의 UModuleManagerBase 파생 클래스를
 *	소유하고 있어야 합니다. 이것은 참조 의존성을 제거하고 의존성이
 *	파편화되는 것을 막기 위함입니다.
 *
 *	자세한 사항은 drawio의 Module 섹션을 참고하시기 바랍니다.
 */
UCLASS()
class UEPROTOTYPE_API UModuleManagerBase : public UObject
{
	GENERATED_BODY()
	
	
	
public:
	/* 생성자 */
	UModuleManagerBase();

	/* 모듈 매니저가 초기화를 모두 마쳤는지 여부입니다 */
	UFUNCTION(BlueprintGetter, Category="Module")
	FORCEINLINE bool IsInitialized() const
	{
		return bInitialized;
	}


	
	/* ModuleEndInitEventDispatcher의 Getter함수입니다 */
	FORCEINLINE FModuleEndInitEventDispatcher& OnModuleEndInit()
	{
		return ModuleEndInitEventDispatcher;
	}
	


protected:
	/* 모듈 초기화를 수행합니다. 반드시 파생 클래스에서 구현되어야 합니다 */
	UFUNCTION()
	virtual void Initialized();

public:
	/*	모듈 초기화 완료 이벤트가 발생했을 때 수신할 이벤트를 등록합니다.
		일반적으로 이벤트 바인딩은 해당 함수에서 이벤트 디스패처를 받아와
		직접 바운드하는 것을 원칙으로 삼고 있지만, 모듈의 경우는 다릅니다.
		
		바운드하고자 하는 함수가 진입했을 때 이미 모듈 초기화가 끝난 상태
		이면 영원히 바운드 된 이벤트는 트리거되지 못하는 점을 고려하여, 이
		벤트 디스패처에 대한 Getter를 제공하는 것을 삭제한 대신, 좀더 안정
		적으로 이벤트를 트리거할 수 있도록 하는 것이 이 함수의 목표입니다 */
	UFUNCTION(BlueprintCallable, Category="Module")
	virtual void RegisterIf(FEventToRegister EventToRegister);





protected:
	/* 초기화되었는 지 여부입니다 */
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, BlueprintGetter=IsInitialized,
				Category="Module", meta=(AllowPrivateAccess=true))
	bool bInitialized = false;



	/* 초기화가 완료되었을 때 브로드캐스트하는 이벤트 디스패처입니다 */
	UPROPERTY(BlueprintAssignable, Category="Module|Delegate", meta=(AllowPrivateAccess=true))
	FModuleEndInitEventDispatcher ModuleEndInitEventDispatcher;
};
