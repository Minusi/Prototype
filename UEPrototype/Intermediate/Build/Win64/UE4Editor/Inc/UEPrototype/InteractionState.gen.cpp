// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Core/InteractionState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractionState() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UInteractionState_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UInteractionState();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void UInteractionState::StaticRegisterNativesUInteractionState()
	{
	}
	UClass* Z_Construct_UClass_UInteractionState_NoRegister()
	{
		return UInteractionState::StaticClass();
	}
	struct Z_Construct_UClass_UInteractionState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInteractionState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInteractionState_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Core/InteractionState.h" },
		{ "ModuleRelativePath", "Public/Core/InteractionState.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInteractionState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInteractionState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInteractionState_Statics::ClassParams = {
		&UInteractionState::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A1u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UInteractionState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UInteractionState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInteractionState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInteractionState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInteractionState, 2504339978);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInteractionState(Z_Construct_UClass_UInteractionState, &UInteractionState::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UInteractionState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInteractionState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
