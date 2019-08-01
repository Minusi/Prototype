// Fill out your copyright notice in the Description page of Project Settings.

#include "VPFrameworkLibrary.h"
#include "EditorWorldManager.h"



AEditorWorldManager* UVPFrameworkLibrary::GetEditorWorldManager(const UObject* WorldContextObject)
{
	return AEditorWorldManager::GetGlobalEditorWorldManager(WorldContextObject);
}