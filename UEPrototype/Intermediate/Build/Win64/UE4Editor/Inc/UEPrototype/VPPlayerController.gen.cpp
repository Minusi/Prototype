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
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UEditorActionMultInputInterpreter_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UEditorFocusMetaInputInterpreter_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UEditorActionMetaInputInterpreter_NoRegister();
// End Cross Module References
	static FName NAME_AVPPlayerController_ReceiveFocusEvent = FName(TEXT("ReceiveFocusEvent"));
	void AVPPlayerController::ReceiveFocusEvent(AActor* Target, float DeltaTime)
	{
		VPPlayerController_eventReceiveFocusEvent_Parms Parms;
		Parms.Target=Target;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_AVPPlayerController_ReceiveFocusEvent),&Parms);
	}
	void AVPPlayerController::StaticRegisterNativesAVPPlayerController()
	{
	}
	struct Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::NewProp_DeltaTime = { UE4CodeGen_Private::EPropertyClass::Float, "DeltaTime", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPPlayerController_eventReceiveFocusEvent_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::NewProp_Target = { UE4CodeGen_Private::EPropertyClass::Object, "Target", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPPlayerController_eventReceiveFocusEvent_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::NewProp_DeltaTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::NewProp_Target,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Core|Player" },
		{ "ModuleRelativePath", "Public/Core/VPPlayerController.h" },
		{ "ToolTip", "DirectorPawn\xec\x9d\x98 \xed\x8f\xac\xec\xbb\xa4\xec\x8a\xa4 \xeb\xb8\x8c\xeb\xa1\x9c\xeb\x93\x9c\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8\xeb\xa5\xbc \xec\x88\x98\xec\x8b\xa0\xed\x95\x98\xec\x97\xac \xec\xb2\x98\xeb\xa6\xac\xed\x95\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n              EditorFocusMetaInputInterpreter\xec\x9d\x98 \xeb\x9e\x98\xed\x8d\xbc \xed\x95\xa8\xec\x88\x98\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPPlayerController, "ReceiveFocusEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(VPPlayerController_eventReceiveFocusEvent_Parms), Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVPPlayerController_NoRegister()
	{
		return AVPPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AVPPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EditorActionMultInputInterpreter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EditorActionMultInputInterpreter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EditorFocusMetaInputInterpreter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EditorFocusMetaInputInterpreter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EditorActionMetaInputInterpreter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EditorActionMetaInputInterpreter;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVPPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVPPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVPPlayerController_ReceiveFocusEvent, "ReceiveFocusEvent" }, // 3979792849
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Core/VPPlayerController.h" },
		{ "ModuleRelativePath", "Public/Core/VPPlayerController.h" },
		{ "ToolTip", "AVPPlayerController\xeb\x8a\x94 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xeb\xa5\xbc \xeb\xb0\x98\xec\x98\x81\xed\x95\x98\xeb\x8a\x94 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\nVirtual Prototype\xec\x97\x90 \xec\xa0\x91\xec\x86\x8d\xed\x95\x9c \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xeb\xa5\xbc \xeb\x8c\x80\xed\x91\x9c\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMultInputInterpreter_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Core|Player" },
		{ "ModuleRelativePath", "Public/Core/VPPlayerController.h" },
		{ "ToolTip", "\xeb\xa9\x80\xed\x8b\xb0\xed\x82\xa4 \xec\x9e\x85\xeb\xa0\xa5\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xeb\xa9\x94\xed\x83\x80\xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\xb2\x98\xeb\xa6\xac\xea\xb8\xb0\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMultInputInterpreter = { UE4CodeGen_Private::EPropertyClass::Object, "EditorActionMultInputInterpreter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000030015, 1, nullptr, STRUCT_OFFSET(AVPPlayerController, EditorActionMultInputInterpreter), Z_Construct_UClass_UEditorActionMultInputInterpreter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMultInputInterpreter_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMultInputInterpreter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorFocusMetaInputInterpreter_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Core|Player" },
		{ "ModuleRelativePath", "Public/Core/VPPlayerController.h" },
		{ "ToolTip", "\xed\x8f\xac\xec\xbb\xa4\xec\x8a\xa4 \xec\x9e\x85\xeb\xa0\xa5\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xeb\xa9\x94\xed\x83\x80\xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\xb2\x98\xeb\xa6\xac\xea\xb8\xb0\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorFocusMetaInputInterpreter = { UE4CodeGen_Private::EPropertyClass::Object, "EditorFocusMetaInputInterpreter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000030015, 1, nullptr, STRUCT_OFFSET(AVPPlayerController, EditorFocusMetaInputInterpreter), Z_Construct_UClass_UEditorFocusMetaInputInterpreter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorFocusMetaInputInterpreter_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorFocusMetaInputInterpreter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMetaInputInterpreter_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Core|Player" },
		{ "ModuleRelativePath", "Public/Core/VPPlayerController.h" },
		{ "ToolTip", "\xed\x82\xa4 \xec\x9e\x85\xeb\xa0\xa5\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xeb\xa9\x94\xed\x83\x80\xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xec\xb2\x98\xeb\xa6\xac\xea\xb8\xb0\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMetaInputInterpreter = { UE4CodeGen_Private::EPropertyClass::Object, "EditorActionMetaInputInterpreter", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000030015, 1, nullptr, STRUCT_OFFSET(AVPPlayerController, EditorActionMetaInputInterpreter), Z_Construct_UClass_UEditorActionMetaInputInterpreter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMetaInputInterpreter_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMetaInputInterpreter_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVPPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMultInputInterpreter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorFocusMetaInputInterpreter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPPlayerController_Statics::NewProp_EditorActionMetaInputInterpreter,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVPPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVPPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVPPlayerController_Statics::ClassParams = {
		&AVPPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVPPlayerController_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVPPlayerController_Statics::PropPointers),
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
	IMPLEMENT_CLASS(AVPPlayerController, 1518023761);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVPPlayerController(Z_Construct_UClass_AVPPlayerController, &AVPPlayerController::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AVPPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVPPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
