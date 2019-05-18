// Fill out your copyright notice in the Description page of Project Settings. 

#pragma once 

#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(AssetImport, Log, All);

#define AI_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

#define AI_CALLLOG(Verbosity) UE_LOG(AssetImport, Verbosity, Text("%s"), *AI_LOG_CALLINFO))
#define AI_CTOR UE_LOG(AssetImport, Log, TEXT("%s %s"), *AI_LOG_CALLINFO, TEXT("생성자 초기화 시작"))
#define AI_LOG(Verbosity, Format, ...) UE_LOG(AssetImport, Verbosity, TEXT("%s %s"), *AI_LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))