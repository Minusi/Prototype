// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetImport/Public/AssetImporter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetImporter() {}
// Cross Module References
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetImporter_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetImporter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AssetImport();
// End Cross Module References
	void UAssetImporter::StaticRegisterNativesUAssetImporter()
	{
	}
	UClass* Z_Construct_UClass_UAssetImporter_NoRegister()
	{
		return UAssetImporter::StaticClass();
	}
	struct Z_Construct_UClass_UAssetImporter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAssetImporter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetImporter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AssetImporter.h" },
		{ "ModuleRelativePath", "Public/AssetImporter.h" },
		{ "ToolTip", "AssetImporter\xeb\x8a\x94 assimp\xec\x9d\x98 importer\xec\x9d\x98 \xea\xb8\xb0\xeb\x8a\xa5\xec\x9d\x84 Unreal Engine 4 \xed\x99\x98\xea\xb2\xbd\xec\x97\x90 \xeb\xa7\x9e\xea\xb2\x8c\n\xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d \xec\x96\xb4\xeb\x8c\x91\xed\x84\xb0 \xed\x8c\xa8\xed\x84\xb4\xec\x9d\x84 \xec\x9d\xb4\xec\x9a\xa9\xed\x95\x98\xec\x97\xac \xea\xb8\xb0\xeb\x8a\xa5\xec\x9d\x84 \xec\xa0\x9c\xea\xb3\xb5\xed\x95\x98\xeb\x8a\x94 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n\xeb\x94\xb0\xeb\x9d\xbc\xec\x84\x9c \xea\xb8\xb0\xeb\x8a\xa5\xec\x9d\x98 \xed\x99\x95\xec\x9e\xa5\xec\x8b\x9c\xec\x97\x90 ImporterAdapter\xec\x97\x90 \xec\x9a\xb0\xec\x84\xa0 \xea\xb8\xb0\xec\x9e\xac\xed\x95\xb4 \xec\xa3\xbc\xec\x8b\x9c\xea\xb8\xb0 \xeb\xb0\x94\xeb\x9e\x8d\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAssetImporter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetImporter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAssetImporter_Statics::ClassParams = {
		&UAssetImporter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAssetImporter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAssetImporter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAssetImporter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAssetImporter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssetImporter, 1145163848);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssetImporter(Z_Construct_UClass_UAssetImporter, &UAssetImporter::StaticClass, TEXT("/Script/AssetImport"), TEXT("UAssetImporter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetImporter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
