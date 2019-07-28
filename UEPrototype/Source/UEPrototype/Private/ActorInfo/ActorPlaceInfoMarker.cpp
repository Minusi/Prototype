// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPlaceInfoMarker.h"
#include "UEPrototype.h"

void UActorPlaceInfoMarker::MarkActor(AActor* Target, FActorPlaceContent Content)
{
	/* 액터의 유효성을 검사합니다 */
	if (IsValid(Target) == false)
	{
		VP_LOG(Warning, TEXT("Actor가 유효하지 않습니다"));
		return;
	}

	FActorPlaceInfo ActorPlaceInfo;
	ActorPlaceInfo.Target = Target;
	ActorPlaceInfo.TargetContent = Content;

	/* 브로드캐스트합니다*/
	ActorPlaceInfoMarkEventDispatcher.Broadcast(ActorPlaceInfo);
}
