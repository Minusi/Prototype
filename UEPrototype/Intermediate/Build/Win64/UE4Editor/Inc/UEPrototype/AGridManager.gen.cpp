// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/Grid/AGridManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAGridManager() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AAGridManager_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AAGridManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void AAGridManager::StaticRegisterNativesAAGridManager()
	{
	}
	UClass* Z_Construct_UClass_AAGridManager_NoRegister()
	{
		return AAGridManager::StaticClass();
	}
	struct Z_Construct_UClass_AAGridManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAGridManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAGridManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/Grid/AGridManager.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/AGridManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAGridManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAGridManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAGridManager_Statics::ClassParams = {
		&AAGridManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AAGridManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AAGridManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAGridManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAGridManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAGridManager, 2630853897);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAGridManager(Z_Construct_UClass_AAGridManager, &AAGridManager::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AAGridManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAGridManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
