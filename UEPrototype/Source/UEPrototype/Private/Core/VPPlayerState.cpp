// Fill out your copyright notice in the Description page of Project Settings.

#include "VPPlayerState.h"
#include "UEPrototype.h"
#include "CorePlayerModuleManager.h"
#include "PlayerTaskManager.h"



AVPPlayerState::AVPPlayerState()
{
	// DEBUG
	VP_CTOR;
}





void AVPPlayerState::BeginPlay()
{
	UPlayerTaskManager* LocalPlayerTaskManager = UPlayerTaskManager::GetGlobalPlayerTaskManager();
	if (IsValid(LocalPlayerTaskManager) == false)
	{
		return;
	}

	/* 참조합니다 */
	PlayerTaskManager = LocalPlayerTaskManager;
}
