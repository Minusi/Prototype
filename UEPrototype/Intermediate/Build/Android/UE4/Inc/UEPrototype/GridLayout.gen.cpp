// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/Grid/GridLayout.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridLayout() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AGridLayout_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AGridLayout();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AGridLayout::StaticRegisterNativesAGridLayout()
	{
	}
	UClass* Z_Construct_UClass_AGridLayout_NoRegister()
	{
		return AGridLayout::StaticClass();
	}
	struct Z_Construct_UClass_AGridLayout_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TestComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TestComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridLayout_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridLayout_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/Grid/GridLayout.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridLayout.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridLayout_Statics::NewProp_TargetActor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "GridLayout" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridLayout.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridLayout_Statics::NewProp_TargetActor = { UE4CodeGen_Private::EPropertyClass::Object, "TargetActor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020005, 1, nullptr, STRUCT_OFFSET(AGridLayout, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridLayout_Statics::NewProp_TargetActor_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridLayout_Statics::NewProp_TargetActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridLayout_Statics::NewProp_TestComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "GridLayout" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridLayout.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridLayout_Statics::NewProp_TestComp = { UE4CodeGen_Private::EPropertyClass::Object, "TestComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AGridLayout, TestComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridLayout_Statics::NewProp_TestComp_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridLayout_Statics::NewProp_TestComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridLayout_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridLayout_Statics::NewProp_TargetActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridLayout_Statics::NewProp_TestComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridLayout_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridLayout>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGridLayout_Statics::ClassParams = {
		&AGridLayout::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AGridLayout_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGridLayout_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGridLayout_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGridLayout_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGridLayout()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGridLayout_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGridLayout, 1434452766);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGridLayout(Z_Construct_UClass_AGridLayout, &AGridLayout::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AGridLayout"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridLayout);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
