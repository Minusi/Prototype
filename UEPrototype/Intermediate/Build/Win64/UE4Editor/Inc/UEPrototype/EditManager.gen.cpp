// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Module/Edit/EditManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEditManager() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AEditManager_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AEditManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AMeshFactory_NoRegister();
// End Cross Module References
	void AEditManager::StaticRegisterNativesAEditManager()
	{
	}
	UClass* Z_Construct_UClass_AEditManager_NoRegister()
	{
		return AEditManager::StaticClass();
	}
	struct Z_Construct_UClass_AEditManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshFactory_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshFactory;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEditManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Module/Edit/EditManager.h" },
		{ "ModuleRelativePath", "Public/Module/Edit/EditManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditManager_Statics::NewProp_MeshFactory_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Prototype|Edit" },
		{ "ModuleRelativePath", "Public/Module/Edit/EditManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEditManager_Statics::NewProp_MeshFactory = { UE4CodeGen_Private::EPropertyClass::Object, "MeshFactory", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000030005, 1, nullptr, STRUCT_OFFSET(AEditManager, MeshFactory), Z_Construct_UClass_AMeshFactory_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEditManager_Statics::NewProp_MeshFactory_MetaData, ARRAY_COUNT(Z_Construct_UClass_AEditManager_Statics::NewProp_MeshFactory_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEditManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEditManager_Statics::NewProp_MeshFactory,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEditManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEditManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEditManager_Statics::ClassParams = {
		&AEditManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AEditManager_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AEditManager_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AEditManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AEditManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEditManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEditManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEditManager, 3132815768);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEditManager(Z_Construct_UClass_AEditManager, &AEditManager::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AEditManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEditManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
