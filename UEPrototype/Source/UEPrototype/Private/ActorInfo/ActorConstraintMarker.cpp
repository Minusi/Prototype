// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorConstraintMarker.h"
#include "UEPrototype.h"



void UActorConstraintMarker::MarkActor(AActor* Target, EActorConstraintState State)
{
	/* 액터에 대한 유효성 검사를 수행합니다 */
	if (IsValid(Target) == false)
	{
		VP_LOG(Warning, TEXT("Actor가 유효하지 않습니다"));
		return;
	}

	FActorConstraintInfo ActorConstraintInfo;
	ActorConstraintInfo.Target = Target;
	ActorConstraintInfo.TargetState = State;

	/* 브로드캐스트합니다 */
	ActorConstraintMarkEventDispatcher.Broadcast(ActorConstraintInfo);
}