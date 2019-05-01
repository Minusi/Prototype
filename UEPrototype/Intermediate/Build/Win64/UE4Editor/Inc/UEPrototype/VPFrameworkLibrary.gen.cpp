// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Utility/VPFrameworkLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVPFrameworkLibrary() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UVPFrameworkLibrary_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UVPFrameworkLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void UVPFrameworkLibrary::StaticRegisterNativesUVPFrameworkLibrary()
	{
	}
	UClass* Z_Construct_UClass_UVPFrameworkLibrary_NoRegister()
	{
		return UVPFrameworkLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UVPFrameworkLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVPFrameworkLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVPFrameworkLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Utility/VPFrameworkLibrary.h" },
		{ "ModuleRelativePath", "Public/Utility/VPFrameworkLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVPFrameworkLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVPFrameworkLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVPFrameworkLibrary_Statics::ClassParams = {
		&UVPFrameworkLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVPFrameworkLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVPFrameworkLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVPFrameworkLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVPFrameworkLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVPFrameworkLibrary, 2295668798);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVPFrameworkLibrary(Z_Construct_UClass_UVPFrameworkLibrary, &UVPFrameworkLibrary::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UVPFrameworkLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVPFrameworkLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
