// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorCommandFactory.h"

UActorCommandBase * CreateActorCommandWithClass(const FActorConstraintInfo Target, const TSubclassOf<UCommandBase> CommandClass)
{
	// TODO : 새로운 명령 클래스를 생성할 때마다 이곳에 추가할 것
	UActorCommandBase* ActorCommand;

	/* 액터 상호작용 커맨드 구간 */
	if (CommandClass.Get() == UHighlightCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UHighlightCommand>(Target);
	}
	else if (CommandClass.Get() == UFocusCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UFocusCommand>(Target);
	}
	else if (CommandClass.Get() == UUnfocusedCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UUnfocusedCommand>(Target);
	}
	else if (CommandClass.Get() == UActivateCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UActivateCommand>(Target);
	}
	else if (CommandClass.Get() == UBlockedCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UBlockedCommand>(Target);
	}

	/* 컨텍스트 커맨드 구간 */
	else if (CommandClass.Get() == UDuplicateCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UDuplicateCommand>(Target);
	}
	else if (CommandClass.Get() == UDeleteCommand::StaticClass())
	{
		ActorCommand = UActorCommandFactory::CreateActorCommand<UDeleteCommand>(Target);
	}
	/* 이미터 커맨드 구간 */

	else
	{
		return nullptr;
	}

	/* 생성된 커맨드가 유효한지 확인합니다. */
	if (IsValid(ActorCommand) == false)
	{
		return nullptr;
	}

	return ActorCommand;
}