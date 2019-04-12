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
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ChangeGridColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_InitializeTemplate();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AGridVisualizer_ToggleGridView();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AGridVisualizer::StaticRegisterNativesAGridVisualizer()
	{
		UClass* Class = AGridVisualizer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeGridColor", &AGridVisualizer::execChangeGridColor },
			{ "InitializeTemplate", &AGridVisualizer::execInitializeTemplate },
			{ "PostInitializeTemplate", &AGridVisualizer::execPostInitializeTemplate },
			{ "ToggleGridView", &AGridVisualizer::execToggleGridView },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics
	{
		struct GridVisualizer_eventChangeGridColor_Parms
		{
			FColor InColor;
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
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor = { UE4CodeGen_Private::EPropertyClass::Struct, "InColor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GridVisualizer_eventChangeGridColor_Parms, InColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InGridIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::NewProp_InColor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_ChangeGridColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Grid|Visual" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
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
	struct Z_Construct_UFunction_AGridVisualizer_InitializeTemplate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_InitializeTemplate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xec\x97\x90\xeb\x94\x94\xed\x84\xb0 \xec\x83\x81\xec\x97\x90\xec\x84\x9c \xec\x84\xa4\xec\xa0\x95\xeb\x90\x98\xec\xa7\x80 \xec\x95\x8a\xec\x9d\x80 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xeb\x93\xa4\xec\x9d\x84 \xeb\x94\x94\xed\x8f\xb4\xed\x8a\xb8\xeb\xa1\x9c \xec\x84\xa4\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_InitializeTemplate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "InitializeTemplate", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_InitializeTemplate_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_InitializeTemplate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_InitializeTemplate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_InitializeTemplate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xed\x85\x9c\xed\x94\x8c\xeb\xa6\xbf \xec\xb4\x88\xea\xb8\xb0\xed\x99\x94 \xec\x9d\xb4\xed\x9b\x84\xec\x97\x90 \xec\x84\xa4\xec\xa0\x95\xeb\x90\x98\xec\x96\xb4\xec\x95\xbc \xed\x95\x98\xeb\x8a\x94 \xed\x94\x84\xeb\xa1\x9c\xed\x8d\xbc\xed\x8b\xb0\xeb\x93\xa4\xec\x9d\x84 \xec\x84\xa4\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGridVisualizer, "PostInitializeTemplate", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bVisualize_MetaData[];
#endif
		static void NewProp_bVisualize_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bVisualize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CacheMID_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CacheMID;
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
		{ &Z_Construct_UFunction_AGridVisualizer_ChangeGridColor, "ChangeGridColor" }, // 1665142952
		{ &Z_Construct_UFunction_AGridVisualizer_InitializeTemplate, "InitializeTemplate" }, // 3234409923
		{ &Z_Construct_UFunction_AGridVisualizer_PostInitializeTemplate, "PostInitializeTemplate" }, // 1622627383
		{ &Z_Construct_UFunction_AGridVisualizer_ToggleGridView, "ToggleGridView" }, // 1895784651
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BuiltIn/Grid/GridVisualizer.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize_MetaData[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c\xea\xb0\x80 \xec\x8b\x9c\xea\xb0\x81\xed\x99\x94 \xec\x83\x81\xed\x83\x9c\xec\x9d\xb8\xec\xa7\x80 \xec\x97\xac\xeb\xb6\x80" },
	};
#endif
	void Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize_SetBit(void* Obj)
	{
		((AGridVisualizer*)Obj)->bVisualize = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize = { UE4CodeGen_Private::EPropertyClass::Bool, "bVisualize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AGridVisualizer), &Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize_SetBit, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CacheMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CacheMID = { UE4CodeGen_Private::EPropertyClass::Object, "CacheMID", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, CacheMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CacheMID_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CacheMID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Grid|Visual" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridVisualizer.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp = { UE4CodeGen_Private::EPropertyClass::Object, "GridComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AGridVisualizer, GridComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGridVisualizer_Statics::NewProp_GridComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridVisualizer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_bVisualize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridVisualizer_Statics::NewProp_CacheMID,
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
	IMPLEMENT_CLASS(AGridVisualizer, 4064364189);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGridVisualizer(Z_Construct_UClass_AGridVisualizer, &AGridVisualizer::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AGridVisualizer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridVisualizer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
