// Fill out your copyright notice in the Description page of Project Settings.

#include "VPFrameworkLibrary.h"
#include "EditorWorldManager.h"



AEditorWorldManager* UVPFrameworkLibrary::GetEditorWorldManager(const UObject* WorldContextObject)
{
	return AEditorWorldManager::GetGlobalEditorWorldManager(WorldContextObject);
}



bool UVPFrameworkLibrary::IsValidSingletonCDO(UObject* Target)
{
	/* OuterChain을 거슬러 올라가면서, AEditorWorldManager가 있는지 탐색합니다 */
	UObject* OuterChain = Target;
	while ((OuterChain = OuterChain->GetOuter()) != nullptr)
	{
		/* OuterChain에 AEditorWorldManager가 있으면서 아키타입이 아닐 때 참을 반환합니다. */
		if (OuterChain->GetClass() == AEditorWorldManager::StaticClass()
			&& ((OuterChain->GetFlags() | EObjectFlags::RF_ArchetypeObject) == false))
		{
			return true;
		}
	}

	return false;
}
