// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/Grid/GridVisualizer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridVisualizer() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AGridVisualizer_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AGridVisualizer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_BeginGridTracing();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ChangeGridColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ToggleGridView();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ToggleTracing();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstance_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AGridVisualizer::StaticRegisterNativesAGridVisualizer()
	{
		UClass* Class = AGridVisualizer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginGridTracing", &AGridVisualizer::execBeginGridTracing },
			{ "ChangeGridColor", &AGridVisualizer::execChangeGridColor },
			{ "ConfigureGridFadeDistance", &AGridVisualizer::execConfigureGridFadeDistance },
			{ "ConfigureGridOpacity", &AGridVisualizer::execConfigureGridOpacity },
			{ "ConfigureGridScale", &AGridVisualizer::execConfigureGridScale },
			{ "ToggleGridView", &AGridVisualizer::execToggleGridView },
			{ "ToggleTracing", &AGridVisualizer::execToggleTracing },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGridVisualizer_BeginGridTracing_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_BeginGridTracing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c\xea\xb0\x80 \xec\x82\xac\xec\x9a\xa9\xec\x9e\x90 \xec\xb6\x94\xec\xa0\x81\xec\x9d\x84 \xec\x8b\x9c\xec\x9e\x91\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_BeginGridTracing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "BeginGridTracing", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_BeginGridTracing_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_BeginGridTracing_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_BeginGridTracing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_BeginGridTracing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics
	{
		struct GridVisualizer_eventChangeGridColor_Parms
		{
			FLinearColor InColor;
			int32 InGridIndex;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InGridIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_InGridIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InColor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InGridIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InGridIndex = { UE4CodeGen_Private::EPropertyClass::Int, "InGridIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GridVisualizer_eventChangeGridColor_Parms, InGridIndex), METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InGridIndex_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InGridIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor = { UE4CodeGen_Private::EPropertyClass::Struct, "InColor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GridVisualizer_eventChangeGridColor_Parms, InColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InGridIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9d\x98 \xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xec\x83\x89\xec\x83\x81\xec\x9d\x84 \xeb\xb3\x80\xea\xb2\xbd\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "ChangeGridColor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(GridVisualizer_eventChangeGridColor_Parms), Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_ChangeGridColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics
	{
		struct GridVisualizer_eventConfigureGridFadeDistance_Parms
		{
			float InFadeLength;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InFadeLength_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InFadeLength;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::NewProp_InFadeLength_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::NewProp_InFadeLength = { UE4CodeGen_Private::EPropertyClass::Float, "InFadeLength", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GridVisualizer_eventConfigureGridFadeDistance_Parms, InFadeLength), METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::NewProp_InFadeLength_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::NewProp_InFadeLength_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::NewProp_InFadeLength,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c\xec\x9d\x98 \xed\x8e\x98\xec\x9d\xb4\xeb\x93\x9c \xec\x8b\x9c\xec\x9e\x91 \xea\xb1\xb0\xeb\xa6\xac\xeb\xa5\xbc \xec\xa1\xb0\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "ConfigureGridFadeDistance", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridVisualizer_eventConfigureGridFadeDistance_Parms), Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics
	{
		struct GridVisualizer_eventConfigureGridOpacity_Parms
		{
			float InGridOpacity;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InGridOpacity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InGridOpacity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::NewProp_InGridOpacity_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::NewProp_InGridOpacity = { UE4CodeGen_Private::EPropertyClass::Float, "InGridOpacity", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GridVisualizer_eventConfigureGridOpacity_Parms, InGridOpacity), METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::NewProp_InGridOpacity_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::NewProp_InGridOpacity_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::NewProp_InGridOpacity,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c\xec\x9d\x98 \xec\x98\xa4\xed\x8c\x8c\xec\x8b\x9c\xed\x8b\xb0\xeb\xa5\xbc \xec\xa1\xb0\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "ConfigureGridOpacity", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridVisualizer_eventConfigureGridOpacity_Parms), Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics
	{
		struct GridVisualizer_eventConfigureGridScale_Parms
		{
			float InGridScale;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InGridScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InGridScale;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::NewProp_InGridScale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::NewProp_InGridScale = { UE4CodeGen_Private::EPropertyClass::Float, "InGridScale", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GridVisualizer_eventConfigureGridScale_Parms, InGridScale), METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::NewProp_InGridScale_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::NewProp_InGridScale_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::NewProp_InGridScale,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xea\xb2\xa9\xec\x9e\x90 \xea\xb0\x84\xea\xb2\xa9\xec\x9d\x84 \xec\xa1\xb0\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "ConfigureGridScale", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridVisualizer_eventConfigureGridScale_Parms), Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics
	{
		struct GridVisualizer_eventToggleGridView_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GridVisualizer_eventToggleGridView_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GridVisualizer_eventToggleGridView_Parms), &Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xed\x91\x9c\xec\x8b\x9c \xec\x97\xac\xeb\xb6\x80\xeb\xa5\xbc \xed\x86\xa0\xea\xb8\x80\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "ToggleGridView", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridVisualizer_eventToggleGridView_Parms), Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_ToggleGridView()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_ToggleGridView_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics
	{
		struct GridVisualizer_eventToggleTracing_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GridVisualizer_eventToggleTracing_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GridVisualizer_eventToggleTracing_Parms), &Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "ToggleTracing", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridVisualizer_eventToggleTracing_Parms), Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_ToggleTracing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_ToggleTracing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGridVisualizer_NoRegister()
	{
		return AGridVisualizer::StaticClass();
	}
	struct Z_Construct_UClass_AGridVisualizer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CachedPlayer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CachedPlayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TraceTimerInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TraceTimerInterval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MIDTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MIDTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MITemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MITemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GridComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridVisualizer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGridVisualizer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGridVisualizer_BeginGridTracing, "BeginGridTracing" }, // 73687080
		{ &Z_Construct_UFunction_AGridVisualizer_ChangeGridColor, "ChangeGridColor" }, // 3821784948
		{ &Z_Construct_UFunction_AGridVisualizer_ConfigureGridFadeDistance, "ConfigureGridFadeDistance" }, // 3883305964
		{ &Z_Construct_UFunction_AGridVisualizer_ConfigureGridOpacity, "ConfigureGridOpacity" }, // 1947529550
		{ &Z_Construct_UFunction_AGridVisualizer_ConfigureGridScale, "ConfigureGridScale" }, // 128077793
		{ &Z_Construct_UFunction_AGridVisualizer_ToggleGridView, "ToggleGridView" }, // 1895784651
		{ &Z_Construct_UFunction_AGridVisualizer_ToggleTracing, "ToggleTracing" }, // 98959989
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/Grid/GridVisualizer.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CachedPlayer_MetaData[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "NativeConst", "" },
		{ "ToolTip", "\xeb\xa1\x9c\xec\xbb\xac \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\xba\x90\xec\x8b\x9c" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CachedPlayer = { UE4CodeGen_Private::EPropertyClass::Object, "CachedPlayer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, CachedPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CachedPlayer_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CachedPlayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_TraceTimerInterval_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grid" },
		{ "ClampMin", "1.0" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "UIMin", "1.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_TraceTimerInterval = { UE4CodeGen_Private::EPropertyClass::Float, "TraceTimerInterval", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, TraceTimerInterval), METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_TraceTimerInterval_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_TraceTimerInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MIDTemplate_MetaData[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "SM Comp\xec\x97\x90 \xec\x9e\x85\xed\x9e\x90 \xeb\xa8\xb8\xed\x8b\xb0\xeb\xa6\xac\xec\x96\xbc" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MIDTemplate = { UE4CodeGen_Private::EPropertyClass::Object, "MIDTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, MIDTemplate), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MIDTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MIDTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MITemplate_MetaData[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "SM Comp\xec\x97\x90 \xec\x9e\x85\xed\x9e\x88\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xeb\xa8\xb8\xed\x8b\xb0\xeb\xa6\xac\xec\x96\xbc\xec\x9d\x98 \xed\x85\x9c\xed\x94\x8c\xeb\xa6\xbf" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MITemplate = { UE4CodeGen_Private::EPropertyClass::Object, "MITemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, MITemplate), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MITemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MITemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c\xeb\xa5\xbc \xeb\x82\x98\xed\x83\x80\xeb\x82\xbc SMComponent" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp = { UE4CodeGen_Private::EPropertyClass::Object, "GridComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, GridComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridVisualizer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CachedPlayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_TraceTimerInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MIDTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_MITemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridVisualizer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridVisualizer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGridVisualizer_Statics::ClassParams = {
		&AGridVisualizer::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AGridVisualizer_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGridVisualizer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGridVisualizer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGridVisualizer, 1675931273);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGridVisualizer(Z_Construct_UClass_AGridVisualizer, &AGridVisualizer::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AGridVisualizer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridVisualizer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
