// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ActorConstraintMarker.h"
#include "UEPrototype.h"
#include "ActorCommandBase.h"
#include "Kismet/GameplayStatics.h"
#include "HighlightCommand.h"
#include "UnfocusedCommand.h"
#include "ActivateCommand.h"
#include "FocusCommand.h"
#include "TranslateStartCommand.h"
#include "TranslateEndCommand.h"
#include "RotateStartCommand.h"
#include "RotateEndCommand.h"
#include "ScaleStartCommand.h"
#include "ScaleEndCommand.h"
#include "BlockedCommand.h"
#include "SoundCommand.h"
#include "EmitterCommand.h"
#include "DeleteCommand.h"
#include "DuplicateCommand.h"
#include "ActorCommandFactory.generated.h"



/**
 *	ActorCommandBase 파생 클래스들을 생성하는 팩토리 클래스
 *	입니다. 액터 커맨드를 생성하면서 동시에 초기화까지 담당
 *	합니다.
 */
UCLASS()
class UEPROTOTYPE_API UActorCommandFactory : public UObject
{
	GENERATED_BODY()
	
public:
	/* 액터 커맨드를 생성하여 후처리한 후 반환합니다 */
	template<typename CmdType>
	static FORCEINLINE CmdType* CreateActorCommand(const FActorConstraintInfo Target)
	{
		UActorCommandBase* ActorCommand = Cast<UActorCommandBase>(NewObject<CmdType>());
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}
	
	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UHighlightCommand* testCreateActorCommand(const FActorConstraintInfo Target)
	{
		

		UHighlightCommand* ActorCommand = NewObject<UHighlightCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UUnfocusedCommand* testCreateActorCommand_Unfocused(const FActorConstraintInfo Target)
	{


		UUnfocusedCommand* ActorCommand = NewObject<UUnfocusedCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UActivateCommand* testCreateActorCommand_Activate(const FActorConstraintInfo Target)
	{


		UActivateCommand* ActorCommand = NewObject<UActivateCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UFocusCommand* testCreateActorCommand_Focus(const FActorConstraintInfo Target)
	{


		UFocusCommand* ActorCommand = NewObject<UFocusCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UTranslateStartCommand* testCreateActorCommand_StartTrans(const FActorConstraintInfo Target)
	{


		UTranslateStartCommand* ActorCommand = NewObject<UTranslateStartCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UTranslateEndCommand* testCreateActorCommand_EndTrans(const FActorConstraintInfo Target)
	{


		UTranslateEndCommand* ActorCommand = NewObject<UTranslateEndCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static URotateStartCommand* testCreateActorCommand_RotateStart(const FActorConstraintInfo Target)
	{
		URotateStartCommand* ActorCommand = NewObject<URotateStartCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static URotateEndCommand* testCreateActorCommand_RotateEnd(const FActorConstraintInfo Target)
	{
		URotateEndCommand* ActorCommand = NewObject<URotateEndCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UScaleStartCommand* testCreateActorCommand_ScaleStart(const FActorConstraintInfo Target)
	{
		UScaleStartCommand* ActorCommand = NewObject<UScaleStartCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UScaleEndCommand* testCreateActorCommand_ScaleEnd(const FActorConstraintInfo Target)
	{
		UScaleEndCommand* ActorCommand = NewObject<UScaleEndCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UBlockedCommand* testCreateActorCommand_Blocked(const FActorConstraintInfo Target)
	{
		UBlockedCommand* ActorCommand = NewObject<UBlockedCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static USoundCommand* testCreateActorCommand_Sound(const FActorConstraintInfo Target)
	{
		USoundCommand* ActorCommand = NewObject<USoundCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UEmitterCommand* testCreateActorCommand_Emitter(const FActorConstraintInfo Target)
	{
		UEmitterCommand* ActorCommand = NewObject<UEmitterCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UDeleteCommand* testCreateActorCommand_Delete(const FActorConstraintInfo Target)
	{
		UDeleteCommand* ActorCommand = NewObject<UDeleteCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
	static UDuplicateCommand* testCreateActorCommand_Duplicate(const FActorConstraintInfo Target)
	{
		UDuplicateCommand* ActorCommand = NewObject<UDuplicateCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}
};
