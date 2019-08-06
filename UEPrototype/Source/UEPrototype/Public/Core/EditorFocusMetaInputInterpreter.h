// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EditorFocusMetaInputInterpreter.generated.h"



UENUM(BlueprintType)
enum class EFocusMetadata : uint8
{
	/* 유효하지 않은 상태 */
	META_None		UMETA(DisplayName = "None"),
	/* 유휴 입력 */
	META_Idle		UMETA(DisplayName = "Idle"),
	/* 포커스 잃음 */
	META_LostFocus	UMETA(DisplayName = "LostFocus"),
	/* 포커스 */
	META_Focus		UMETA(DisplayName = "Focus"),
	/* 포커스 변경 */
	META_ChangeFocus	UMETA(DisplayName = "ChangeFocus"),
	/* 하이라이트 */
	META_Highlight	UMETA(DisplayName = "Highlight")
};





class AActor;

USTRUCT(BlueprintType)
struct FHighLevelFocusData
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	FHighLevelFocusData()
	{
		FocusedActor = nullptr;
		FocusMetadata = EFocusMetadata::META_None;
	}

	/* == 연산자 오버로딩 */
	bool operator==(const FHighLevelFocusData& Rhs)
	{
		return (FocusedActor == Rhs.FocusedActor) && (FocusMetadata == Rhs.FocusMetadata);
	}

	friend bool operator==(const FHighLevelFocusData& Lhs, const FHighLevelFocusData& Rhs)
	{
		return (Lhs.FocusedActor == Rhs.FocusedActor) && (Lhs.FocusMetadata == Rhs.FocusMetadata);
	}

	/* 해시 타입 반환 */
	friend uint32 GetTypeHash(const FHighLevelFocusData& Other)
	{
		return GetTypeHash(Other.FocusedActor) + GetTypeHash(Other.FocusMetadata);
	}





public:
	/* 포커스 메타데이터에 해당하는 액터입니다 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor * FocusedActor;

	/* 포커스에 대한 메타데이터 정보입니다. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EFocusMetadata FocusMetadata;
};





/**
 *	EditorFocusMetaInputInterpreter는 사용자의 시선 입력에 대한 메타데이터
 *	정보를 제공합니다.
 */
UCLASS()
class UEPROTOTYPE_API UEditorFocusMetaInputInterpreter : public UObject
{
	GENERATED_BODY()
	
public:
	/* 생성자 */
	UEditorFocusMetaInputInterpreter();

	/* EditorFocusMetaInputInterpreter를 반환합니다(전역 접근 가능). */
	UFUNCTION(BlueprintCallable, Category = "Core|Input", meta = (UnsafeDuringActorConstruction = "true"))
	static UEditorFocusMetaInputInterpreter* GetGlobalEditorFocusMetaInputInterpreter();

	

public:
	/* 포커스 입력을 해석합니다 */
	UFUNCTION(BlueprintCallable, Category="Core|Input")
	void InterpreteFocus(AActor* Target, float DeltaTime, FHighLevelFocusData& MetadataResult);

	

public:
	/* 포커싱 중인 액터를 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Core|Input")
	FORCEINLINE AActor* GetFocusedActor() const
	{
		return FocusedActor;
	}

	/* 포커스 타임을 반환합니다 */
	UFUNCTION(BlueprintGetter, Category="Core|Input")
	FORCEINLINE float GetFocusTime() const
	{
		return FocusTime;
	}

	/* 하이라이트에 필요한 시간을 반환합니다 */
	UFUNCTION(BlueprintGetter, Category = "Core|Input")
	FORCEINLINE float GetTimeToHighlight() const
	{
		return TimeToHighlight;
	}





private:
	/* 포커싱당한 액터입니다 */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Input", meta = (AllowPrivateAccess = true),
		BlueprintGetter = GetFocusedActor)
	AActor* FocusedActor;
	
	/* 특정 물체를 응시하고 있는 시간입니다. */
	UPROPERTY(BlueprintReadOnly, Category="Core|Input", meta=(AllowPrivateAccess = true),
		BlueprintGetter=GetFocusTime)
	float FocusTime;


	/* 하이라이팅으로 인식하기까지의 시간입니다. */
	UPROPERTY(BlueprintReadOnly, Category = "Core|Input", meta = (AllowPrivateAccess = true),
		BlueprintGetter = GetTimeToHighlight)
	float TimeToHighlight;
};
