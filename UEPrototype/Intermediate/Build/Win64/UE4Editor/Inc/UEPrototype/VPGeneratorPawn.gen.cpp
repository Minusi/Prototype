// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Core/VPGeneratorPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVPGeneratorPawn() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPGeneratorPawn_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPGeneratorPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void AVPGeneratorPawn::StaticRegisterNativesAVPGeneratorPawn()
	{
	}
	UClass* Z_Construct_UClass_AVPGeneratorPawn_NoRegister()
	{
		return AVPGeneratorPawn::StaticClass();
	}
	struct Z_Construct_UClass_AVPGeneratorPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVPGeneratorPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPGeneratorPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Core/VPGeneratorPawn.h" },
		{ "ModuleRelativePath", "Public/Core/VPGeneratorPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVPGeneratorPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVPGeneratorPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVPGeneratorPawn_Statics::ClassParams = {
		&AVPGeneratorPawn::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVPGeneratorPawn_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVPGeneratorPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVPGeneratorPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVPGeneratorPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVPGeneratorPawn, 955407170);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVPGeneratorPawn(Z_Construct_UClass_AVPGeneratorPawn, &AVPGeneratorPawn::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AVPGeneratorPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVPGeneratorPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
