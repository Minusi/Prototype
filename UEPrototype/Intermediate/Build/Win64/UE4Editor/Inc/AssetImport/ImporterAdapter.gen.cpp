// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetImport/Public/ImporterAdapter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeImporterAdapter() {}
// Cross Module References
	ASSETIMPORT_API UClass* Z_Construct_UClass_UImporterAdapter_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UImporterAdapter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_AssetImport();
// End Cross Module References
	void UImporterAdapter::StaticRegisterNativesUImporterAdapter()
	{
	}
	UClass* Z_Construct_UClass_UImporterAdapter_NoRegister()
	{
		return UImporterAdapter::StaticClass();
	}
	struct Z_Construct_UClass_UImporterAdapter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UImporterAdapter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UImporterAdapter_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ImporterAdapter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UImporterAdapter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IImporterAdapter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UImporterAdapter_Statics::ClassParams = {
		&UImporterAdapter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001040A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UImporterAdapter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UImporterAdapter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UImporterAdapter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UImporterAdapter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UImporterAdapter, 3395832521);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UImporterAdapter(Z_Construct_UClass_UImporterAdapter, &UImporterAdapter::StaticClass, TEXT("/Script/AssetImport"), TEXT("UImporterAdapter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UImporterAdapter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
