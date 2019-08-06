// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Containers/Map.h"
#include "Containers/Array.h"
#include "GameFramework/InputSettings.h"
#include "EditorActionMetaInputInterpreter.generated.h"



class UInputSettings;

/*
 * EInputMetadata는 특정 입력에 대한 메타데이터 정보를 제공합니다.
 * UE4에서는 Pressed와 Released 이벤트를 통한 단순한 입력을 제공하지만,
 * 그렇기 때문에 Charging, Triggering 등에 대한 세부 입력을 컨트롤할 수
 * 없는 문제가 있습니다. 이 열거형 클래스는 메타데이터 입력을 지원하기
 * 위해 만들어졌습니다.
 */
UENUM(BlueprintType)
enum class EInputMetadata : uint8
{
	/* 유효하지 않거나 초기화되지 않은 상태 */
	META_None		UMETA(DisplayName="None"),
	/* 유휴 입력 */
	META_Idle		UMETA(DisplayName="Idle"),
	/* 특정 입력이 Pressed 후 Released까지 짧은 시간 상태 */
	META_Trigger	UMETA(DisplayName = "Trigger"),
	/* 특정 입력이 Pressed 후 Released까지 중간 시간 상태 */
	META_Click		UMETA(DisplayName = "Click"),
	/* 특정 입력의 Pressed 후 Released까지 긴 시간 상태 */
	META_Charging	UMETA(DisplayName = "Charging"),
	/* 특정 2차원 입력이 Pressed되지 않은 채로 변동되는 상태 */
 	META_Tracking	UMETA(DisplayName = "Tracking"),
	/* 특정 2차원 입력이 Pressed된 채로 변동되는 상태 */
	META_Drag		UMETA(DisplayName = "Drag")
};





/*
 * FHighLevelInputData는 특정 매핑과 매핑에 대한 입력 메타데이터 정보를
 * 쌍으로 제공하기 위해 고안된 구조체입니다. 이 구조체는 Prototype 프로젝트
 * 의 입력 프레임워크에서 중요한 데이터 중 하나입니다. 이 데이터는 인터프리터
 * 에 의해 가공되어, 도구의 입력으로 들어가게 됩니다..
 */
USTRUCT(BlueprintType)
struct FHighLevelInputData
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	FHighLevelInputData()
	{
		MappingName = NAME_None;
		InputMetadata = EInputMetadata::META_None;
	}




public:
	/* 입력 매핑의 이름입니다. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName MappingName;

	/* 입력 매핑에 대한 입력 메타데이터 정보입니다. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EInputMetadata InputMetadata;
};



	/* 생성자 */
	FHighLevelInputData()
	{
		MappingName = NAME_None;
		InputMetadata = EInputMetadata::META_None;
	}
};



/**
 *	EditorActionMetaInputInterpreter는 액션 메핑에 들어온 입력에 대해
 *	누름(Pressed) 및 뗌(Released) 상태 이외의 트리거(Trigger), 차징(Charging)
 *	등의 메타 입력으로의 해석을 돕는 인터프리터입니다. 최종적으로, 들어온
 *	입력이 이 클래스에서 가공되어 도구의 입력으로 전달됩니다. 
 */
UCLASS()
class UEPROTOTYPE_API UEditorActionMetaInputInterpreter : public UObject
{
	GENERATED_BODY()
	
public:
	// 생성자
	UEditorActionMetaInputInterpreter();



	/* EditorActionMetaInputInterpreter를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Input", meta = (UnsafeDuringActorConstruction = "true"))
	static UEditorActionMetaInputInterpreter* GetGlobalEditorActionMetaInputInterpreter();



	// Action Input으로부터 Pressed 이벤트를 수신하였을 때, 이를 처리합니다.
	UFUNCTION(BlueprintCallable, Category = "Core|Input")
	void ReceivePressed(FName ActionName, FHighLevelInputData& MetadataResult);

	// Action Input으로부터 Released 이벤트를 수신하였을 때, 이를 처리합니다.
	UFUNCTION(BlueprintCallable, Category = "Core|Input")
	void ReceiveReleased(FName ActionName, FHighLevelInputData& MetadataResult);



private:
	/* 이벤트들에 함수들을 바인딩합니다 */
	UFUNCTION()
	void BindToEvents();

	// 새로운 액션 이름에 메타입력 기능을 제공하기 위해 등록합니다.
	UFUNCTION()
	void RegisterInputAction(FName AddedActionName, const TArray<FInputActionKeyMapping>& AddedActionKeyMappings);

	// 기존 액션에 메타입력 기능을 해제하기 위해 등록 해제합니다.
	UFUNCTION()
	void UnregisterInputAction(FName RemovedActionName);



private:
	// 입력을 메타 입력으로 해석합니다.
	UFUNCTION()
	EInputMetadata Interpret(float TotalActionTime);

	// 특정 액션 이름의 시간을 초기화합니다.
	UFUNCTION()
	void ResetTime(FName ActionName);
	
	// 액션이 입력 세팅 및 로컬 세팅에서 모두 유효한지 확인합니다.
	UFUNCTION()
	bool ValidateAction(FName ActionName);

	// 액션이 입력 세팅에서 유효한지 확인합니다.
	UFUNCTION()
	bool ValidateActionFast(FName ActionName);





private:
	/* 특정 입력 바인딩에 대한 메타인풋을 저장하는 컨테이너
	 * FName : 액션 이름
	 * float : 액션이 pressed된 게임 시간 */
	UPROPERTY(BlueprintReadWrite, Category = "Core|Input", meta=(AllowPrivateAccess=true))
	TMap<FName, float> ActionMetaInputs;

	/* 유효성 검증을 위한 캐시 */
	static const UInputSettings* InputSettings;

	/* 입력이 트리거로 인정되기까지의 임계시간 */
	UPROPERTY(EditDefaultsOnly, Category = "Core|Input", meta=(AllowPrivateAccess=true))
	float TriggerThreshold = 0.2f;
	
	/* 입력이 클릭으로 인정되지까지의 임계시간 */
	UPROPERTY(EditDefaultsOnly, Category = "Core|Input", meta=(AllowPrivateAccess=true))
	float ClickThreshold = 1.2f;

};
