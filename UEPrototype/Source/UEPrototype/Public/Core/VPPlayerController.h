// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "VPPlayerController.generated.h"

/**
 *	AVPPlayerController는 플레이어를 반영하는 클래스입니다.
 *	Virtual Prototype에 접속한 플레이어를 대표합니다.
 */
UCLASS()
class UEPROTOTYPE_API AVPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AVPPlayerController();
};
