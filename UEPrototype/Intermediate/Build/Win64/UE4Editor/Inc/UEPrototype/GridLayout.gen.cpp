// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/GridLayout.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridLayout() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridLayout_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridLayout();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void UGridLayout::StaticRegisterNativesUGridLayout()
	{
	}
	UClass* Z_Construct_UClass_UGridLayout_NoRegister()
	{
		return UGridLayout::StaticClass();
	}
	struct Z_Construct_UClass_UGridLayout_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGridLayout_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridLayout_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/GridLayout.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridLayout.h" },
		{ "ToolTip", "GridLayout \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\x8a\x94 GridMeshPool\xeb\xa1\x9c\xeb\xb6\x80\xed\x84\xb0 \xea\xb5\xac\xec\x84\xb1\xec\x9a\x94\xec\x86\x8c\xeb\x93\xa4\xec\x9d\x84 \xec\xa0\x9c\xea\xb3\xb5\xeb\xb0\x9b\xec\x95\x84\n\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xec\x8b\x9c\xec\x8a\xa4\xed\x85\x9c\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x82\xb4\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xeb\xb0\xb0\xec\xb9\x98 \xeb\xb0\xa9\xeb\xb2\x95\xec\x9d\x84 \xec\xa0\x9c\xea\xb3\xb5\xed\x95\x98\xeb\x8a\x94 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n\n\xed\x98\x84\xec\x9e\xac \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xeb\xa0\x88\xec\x9d\xb4\xec\x95\x84\xec\x9b\x83\xec\x9d\x80 \xeb\x8b\xa4\xec\x9d\x8c\xea\xb3\xbc \xea\xb0\x99\xec\x8a\xb5\xeb\x8b\x88\xeb\x8b\xa4:\n- LatticeLayout : \xea\xb2\xa9\xec\x9e\x90\xed\x98\x95\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa7\x9e\xec\xb6\x94\xeb\x93\xaf\xec\x9d\xb4 \xeb\xb0\xb0\xec\x97\xb4\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGridLayout_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGridLayout>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGridLayout_Statics::ClassParams = {
		&UGridLayout::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGridLayout_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGridLayout_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGridLayout()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGridLayout_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGridLayout, 2497353041);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGridLayout(Z_Construct_UClass_UGridLayout, &UGridLayout::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UGridLayout"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGridLayout);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
