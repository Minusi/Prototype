// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/EditorFocusMetaInputInterpreter.h"
#include "UEPrototype.h"
#include "VPFrameworkLibrary.h"
#include "UObjectIterator.h"



UEditorFocusMetaInputInterpreter::UEditorFocusMetaInputInterpreter()
{
	// DEBUG : 생성자 로깅
	VP_CTOR;

	/* 유효하지 않은 싱글톤 CDO는 더이상 초기화를 진행하지 않습니다 */
	if (UVPFrameworkLibrary::IsValidSingletonCDO(this) == false)
	{
		return;
	}
	

	
	/* 초기화를 수행합니다 */
	FocusedActor = nullptr;
	FocusTime = 0.f;
	if (TimeToHighlight == 0.f)
	{
		TimeToHighlight = 1.5f;
	}
}



UEditorFocusMetaInputInterpreter * UEditorFocusMetaInputInterpreter::GetGlobalEditorFocusMetaInputInterpreter()
{
	for (const auto& it : TObjectRange<UEditorFocusMetaInputInterpreter>())
	{
		if (UVPFrameworkLibrary::IsValidSingletonCDO(it))
		{
			return it;
		}
	}

	/* 존재하지 않는다면 시스템에 큰 결함이 있다는 것입니다 */
	VP_LOG(Error, TEXT("%s가 유효하지 않습니다."), *UEditorFocusMetaInputInterpreter::StaticClass()->GetName());
	return nullptr;
}





void UEditorFocusMetaInputInterpreter::InterpreteFocus(AActor* Target, float DeltaTime, FHighLevelFocusData& MetadataResult)
{
	/* 델타타임 유효성 검사를 수행합니다 */
	if (DeltaTime < 0.f)
	{
		VP_LOG(Warning, TEXT("유효하지 않은 델타타임입니다 : %f."), DeltaTime);
		return ;
	}
	


	/* 둘 다 유효하지 않으면, 유휴 상태입니다 */
	if (IsValid(FocusedActor) == false && IsValid(Target) == false)
	{
		MetadataResult.FocusedActor = nullptr;
		MetadataResult.FocusMetadata = EFocusMetadata::META_Idle;
		return;
	}

	/* 이전 포커스 대상이 없는 상태에서 새 포커스가 발생하면, 등록합니다 */
	if (IsValid(FocusedActor) == false && IsValid(Target) == true)
	{
		FocusedActor = Target;

		MetadataResult.FocusedActor = FocusedActor;
		MetadataResult.FocusMetadata = EFocusMetadata::META_Focus;
		return;
	}

	/* 이전 포커스 대상이 있는 상태에서 포커스를 잃어버리면 리셋합니다. */
	if (IsValid(FocusedActor) == true && IsValid(Target) == false)
	{
		FocusedActor = nullptr;
		FocusTime = 0.f;

		MetadataResult.FocusedActor = FocusedActor;
		MetadataResult.FocusMetadata = EFocusMetadata::META_LostFocus;
		return;
	}

	if (IsValid(FocusedActor) == true && IsValid(Target) == true)
	{
		/* 같은 대상을 포커싱하면 시간을 갱신합니다 */
		if (FocusedActor == Target)
		{
			FocusTime += DeltaTime;
			if (FocusTime >= TimeToHighlight)
			{
				MetadataResult.FocusedActor = FocusedActor;
				MetadataResult.FocusMetadata = EFocusMetadata::META_Highlight;
				return;
			}
			else
			{
				MetadataResult.FocusedActor = FocusedActor;
				MetadataResult.FocusMetadata = EFocusMetadata::META_Focus;
				return;
			}
		}

		/* 다른 대상으로 포커싱 전환이 일어나면 포커스를 갱신합니다 */
		if (FocusedActor != Target)
		{
			FocusedActor = Target;
			FocusTime = 0.f;

			MetadataResult.FocusedActor = FocusedActor;
			MetadataResult.FocusMetadata = EFocusMetadata::META_ChangeFocus;
		}
	}
}
