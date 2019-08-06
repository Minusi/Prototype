// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(VRPrototype, Log, All);

#define VP_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

#define VP_CALLLOG(Verbosity) UE_LOG(VRPrototype, Verbosity, Text("%s"), *VP_LOG_CALLINFO))
#define VP_CTOR UE_LOG(VRPrototype, Log, TEXT("%s %s : %s"), *VP_LOG_CALLINFO, TEXT("생성자 초기화 시작"), *this->GetName())
#define VP_LOG(Verbosity, Format, ...) UE_LOG(VRPrototype, Verbosity, TEXT("%s %s"), *VP_LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))