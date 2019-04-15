// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Core/VPPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVPPlayerController() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPPlayerController_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
// End Cross Module References
	void AVPPlayerController::StaticRegisterNativesAVPPlayerController()
	{
	}
	UClass* Z_Construct_UClass_AVPPlayerController_NoRegister()
	{
		return AVPPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AVPPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVPPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Core/VPPlayerController.h" },
		{ "ModuleRelativePath", "Public/Core/VPPlayerController.h" },
		{ "ToolTip", "AVPPlayerController\xeb\x8a\x94 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xeb\xa5\xbc \xeb\xb0\x98\xec\x98\x81\xed\x95\x98\xeb\x8a\x94 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\nVirtual Prototype\xec\x97\x90 \xec\xa0\x91\xec\x86\x8d\xed\x95\x9c \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xeb\xa5\xbc \xeb\x8c\x80\xed\x91\x9c\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVPPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVPPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVPPlayerController_Statics::ClassParams = {
		&AVPPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		nullptr, 0,
		nullptr, 0,
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVPPlayerController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVPPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVPPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVPPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVPPlayerController, 793223842);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVPPlayerController(Z_Construct_UClass_AVPPlayerController, &AVPPlayerController::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AVPPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVPPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
