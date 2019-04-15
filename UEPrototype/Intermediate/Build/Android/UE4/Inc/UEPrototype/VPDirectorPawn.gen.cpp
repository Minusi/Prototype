// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Core/VPDirectorPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVPDirectorPawn() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPDirectorPawn_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPDirectorPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers();
	HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
// End Cross Module References
	void AVPDirectorPawn::StaticRegisterNativesAVPDirectorPawn()
	{
		UClass* Class = AVPDirectorPawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ModifyVisualizeMControllers", &AVPDirectorPawn::execModifyVisualizeMControllers },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom|Director" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x93\xa0 \xeb\xaa\xa8\xec\x85\x98 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac\xec\x9d\x98 \xec\x9c\xa0\xed\x9a\xa8\xec\x84\xb1\xec\x9d\x84 \xed\x99\x95\xec\x9d\xb8\xed\x95\x98\xec\x97\xac \xec\x8b\x9c\xea\xb0\x81\xed\x99\x94\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n\xec\x9d\xb4 \xec\x9e\x91\xec\x97\x85\xec\x9d\x80 \xeb\x8b\xa8\xec\x88\x9c\xed\x9e\x88 \xeb\xaa\xa8\xec\x85\x98 \xed\x8a\xb8\xeb\x9e\x98\xed\x82\xb9 \xeb\x90\x98\xec\xa7\x80 \xec\x95\x8a\xeb\x8a\x94 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xec\x9d\x98 \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xeb\x82\xa0\xeb\xa0\xa4\xeb\xb2\x84\xeb\xa6\xbd\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPDirectorPawn, "ModifyVisualizeMControllers", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVPDirectorPawn_NoRegister()
	{
		return AVPDirectorPawn::StaticClass();
	}
	struct Z_Construct_UClass_AVPDirectorPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightMController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RightMController;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftMController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LeftMController;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VRCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VRCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VRRootTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VRRootTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootCollision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RootCollision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVPDirectorPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVPDirectorPawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVPDirectorPawn_ModifyVisualizeMControllers, "ModifyVisualizeMControllers" }, // 3789152275
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Core/VPDirectorPawn.h" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "*     DirectorPawn\xec\x9d\x80 \xed\x94\x84\xeb\xa1\x9c\xed\x86\xa0\xed\x83\x80\xec\x9e\x85 \xec\x9b\x94\xeb\x93\x9c\xec\x97\x90\xec\x84\x9c \xed\x94\x84\xeb\xa1\x9c\xed\x86\xa0\xed\x83\x80\xec\x9e\x85\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9\xed\x95\x98\xeb\x8a\x94 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xea\xb0\x80\n*     \xea\xb8\xb0\xeb\xb3\xb8\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb9\x99\xec\x9d\x98\xed\x95\x98\xeb\x8a\x94 \xed\x8f\xb0\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4. VR \xea\xb8\xb0\xea\xb8\xb0\xec\x99\x80 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xeb\x8a\x94 \xec\x9c\xa0\xec\xa0\x80\xec\x9d\x98\n*     \xeb\xaa\xa8\xec\x8a\xb5\xec\x9d\x84 \xea\xb5\xac\xed\x98\x84\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RightMController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x9a\xb0\xec\xb8\xa1 \xeb\xaa\xa8\xec\x85\x98 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RightMController = { UE4CodeGen_Private::EPropertyClass::Object, "RightMController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, RightMController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RightMController_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RightMController_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_LeftMController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\xa2\x8c\xec\xb8\xa1 \xeb\xaa\xa8\xec\x85\x98 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_LeftMController = { UE4CodeGen_Private::EPropertyClass::Object, "LeftMController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, LeftMController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_LeftMController_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_LeftMController_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera = { UE4CodeGen_Private::EPropertyClass::Object, "VRCamera", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, VRCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform = { UE4CodeGen_Private::EPropertyClass::Object, "VRRootTransform", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, VRRootTransform), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\xbd\x9c\xeb\xa6\xac\xec\xa0\x84" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision = { UE4CodeGen_Private::EPropertyClass::Object, "RootCollision", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, RootCollision), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVPDirectorPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RightMController,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_LeftMController,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVPDirectorPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVPDirectorPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVPDirectorPawn_Statics::ClassParams = {
		&AVPDirectorPawn::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVPDirectorPawn_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVPDirectorPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVPDirectorPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVPDirectorPawn, 3417901298);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVPDirectorPawn(Z_Construct_UClass_AVPDirectorPawn, &AVPDirectorPawn::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AVPDirectorPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVPDirectorPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
