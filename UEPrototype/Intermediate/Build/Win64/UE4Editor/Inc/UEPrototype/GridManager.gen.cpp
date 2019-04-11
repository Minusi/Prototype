// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/GridManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridManager() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AGridManager_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AGridManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridMeshPool_NoRegister();
// End Cross Module References
	void AGridManager::StaticRegisterNativesAGridManager()
	{
	}
	UClass* Z_Construct_UClass_AGridManager_NoRegister()
	{
		return AGridManager::StaticClass();
	}
	struct Z_Construct_UClass_AGridManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TestPool_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TestPool;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/GridManager.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridManager_Statics::NewProp_TestPool_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Test" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridManager.h" },
		{ "ToolTip", "\xed\x85\x8c\xec\x8a\xa4\xed\x8a\xb8. \xeb\x82\x98\xec\xa4\x91\xec\x97\x90 \xec\x82\xad\xec\xa0\x9c\xed\x95\x98\xec\x8b\x9c\xec\x98\xa4." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridManager_Statics::NewProp_TestPool = { UE4CodeGen_Private::EPropertyClass::Object, "TestPool", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000010005, 1, nullptr, STRUCT_OFFSET(AGridManager, TestPool), Z_Construct_UClass_UGridMeshPool_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridManager_Statics::NewProp_TestPool_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridManager_Statics::NewProp_TestPool_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridManager_Statics::NewProp_TestPool,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGridManager_Statics::ClassParams = {
		&AGridManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AGridManager_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGridManager_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGridManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGridManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGridManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGridManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGridManager, 3742035561);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGridManager(Z_Construct_UClass_AGridManager, &AGridManager::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AGridManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
