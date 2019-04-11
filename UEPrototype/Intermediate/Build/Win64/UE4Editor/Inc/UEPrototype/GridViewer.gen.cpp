// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/GridViewer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridViewer() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridViewer_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridViewer();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void UGridViewer::StaticRegisterNativesUGridViewer()
	{
	}
	UClass* Z_Construct_UClass_UGridViewer_NoRegister()
	{
		return UGridViewer::StaticClass();
	}
	struct Z_Construct_UClass_UGridViewer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGridViewer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridViewer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/GridViewer.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridViewer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGridViewer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGridViewer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGridViewer_Statics::ClassParams = {
		&UGridViewer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGridViewer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGridViewer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGridViewer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGridViewer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGridViewer, 3815010087);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGridViewer(Z_Construct_UClass_UGridViewer, &UGridViewer::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UGridViewer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGridViewer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
