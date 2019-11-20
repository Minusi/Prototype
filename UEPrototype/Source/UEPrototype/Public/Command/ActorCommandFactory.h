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

#include "BlockedCommand.h"

#include "DeleteCommand.h"
#include "DuplicateCommand.h"
#include "TextureCommandStart.h"
#include "TextureCommandEnd.h"
#include "ShowContextCommand.h"
#include "CloseContextCommand.h"
#include "MaterialCommand.h"
#include "EmitterCommandStart.h"
#include "InactiveCommand.h"
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
	/* 액터 커맨드를 생성하여 후처리한 후 반환합니다. */
	template<typename CmdType>
	static CmdType* CreateActorCommand(const FActorConstraintInfo Target)
	{
		CmdType* ActorCommand = NewObject<CmdType>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	/* 액터 커맨드를 생성하여 후처리한 후 반환합니다.
	비 템플릿 버전입니다. */
	static UActorCommandBase* CreateActorCommandWithClass(const FActorConstraintInfo Target, const TSubclassOf<UCommandBase> CommandClass);

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UHighlightCommand* testCreateActorCommand_Highlight(const FActorConstraintInfo Target)
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

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UTextureCommandStart* testCreateActorCommand_TextureStart(const FActorConstraintInfo Target)
	{
		UTextureCommandStart* ActorCommand = NewObject<UTextureCommandStart>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UTextureCommandEnd* testCreateActorCommand_TextureEnd(const FActorConstraintInfo Target)
	{
		UTextureCommandEnd* ActorCommand = NewObject<UTextureCommandEnd>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UShowContextCommand* testCreateActorCommand_ShowContext(const FActorConstraintInfo Target)
	{
		UShowContextCommand* ActorCommand = NewObject<UShowContextCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UCloseContextCommand* testCreateActorCommand_CloseContext(const FActorConstraintInfo Target)
	{
		UCloseContextCommand* ActorCommand = NewObject<UCloseContextCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UMaterialCommand* testCreateActorCommand_Material(const FActorConstraintInfo Target)
	{
		UMaterialCommand* ActorCommand = NewObject<UMaterialCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UEmitterCommandStart* testCreateActorCommand_EmitterStart(const FActorConstraintInfo Target)
	{
		UEmitterCommandStart* ActorCommand = NewObject<UEmitterCommandStart>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}

	UFUNCTION(BlueprintCallable, Category = "ASD")
		static UInactiveCommand* testCreateActorCommand_InActivate(const FActorConstraintInfo Target)
	{
		UInactiveCommand* ActorCommand = NewObject<UInactiveCommand>();
		if (IsValid(ActorCommand) == false)
		{
			VP_LOG(Warning, TEXT("유효하지 않은 템플릿 타입입니다."));
			return nullptr;
		}
		ActorCommand->InitActorCommand(Target);
		return ActorCommand;
	}
};
