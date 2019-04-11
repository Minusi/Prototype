// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/GridMeshPool.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridMeshPool() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridMeshPool_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridMeshPool();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UGridMeshPool_FillObject();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UGridMeshPool_PopObject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UGridMeshPool_PushObject();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	void UGridMeshPool::StaticRegisterNativesUGridMeshPool()
	{
		UClass* Class = UGridMeshPool::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FillObject", &UGridMeshPool::execFillObject },
			{ "PopObject", &UGridMeshPool::execPopObject },
			{ "PushObject", &UGridMeshPool::execPushObject },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGridMeshPool_FillObject_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridMeshPool_FillObject_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Pool|Grid" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xec\xb1\x84\xec\x9a\xb8 \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xec\x83\x9d\xec\x84\xb1\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4. ConstructorHelper \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xea\xb8\xb0 \xeb\x96\x84\xeb\xac\xb8\xec\x97\x90\n\xec\x83\x9d\xec\x84\xb1\xec\x9e\x90 \xeb\x82\xb4\xec\x97\x90\xec\x84\x9c\xeb\xa7\x8c \xed\x98\xb8\xec\xb6\x9c\xeb\x90\x98\xec\x96\xb4\xec\x95\xbc \xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridMeshPool_FillObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGridMeshPool, "FillObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGridMeshPool_FillObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_FillObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGridMeshPool_FillObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGridMeshPool_FillObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGridMeshPool_PopObject_Statics
	{
		struct GridMeshPool_eventPopObject_Parms
		{
			UStaticMeshComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080588, 1, nullptr, STRUCT_OFFSET(GridMeshPool_eventPopObject_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Pool" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xed\x92\x80\xec\x97\x90\xec\x84\x9c \xea\xba\xbc\xeb\x83\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGridMeshPool, "PopObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(GridMeshPool_eventPopObject_Parms), Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGridMeshPool_PopObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGridMeshPool_PopObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGridMeshPool_PushObject_Statics
	{
		struct GridMeshPool_eventPushObject_Parms
		{
			UStaticMeshComponent* InMeshComp;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InMeshComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InMeshComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::NewProp_InMeshComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::NewProp_InMeshComp = { UE4CodeGen_Private::EPropertyClass::Object, "InMeshComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GridMeshPool_eventPushObject_Parms, InMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::NewProp_InMeshComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::NewProp_InMeshComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::NewProp_InMeshComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Pool" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xed\x92\x80\xec\x97\x90 \xec\x82\xbd\xec\x9e\x85\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGridMeshPool, "PushObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridMeshPool_eventPushObject_Parms), Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGridMeshPool_PushObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGridMeshPool_PushObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGridMeshPool_NoRegister()
	{
		return UGridMeshPool::StaticClass();
	}
	struct Z_Construct_UClass_UGridMeshPool_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridMaterialTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GridMaterialTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridMeshTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GridMeshTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridMeshArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GridMeshArray;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GridMeshArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxPoolSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxPoolSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGridMeshPool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGridMeshPool_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGridMeshPool_FillObject, "FillObject" }, // 1542871603
		{ &Z_Construct_UFunction_UGridMeshPool_PopObject, "PopObject" }, // 313406568
		{ &Z_Construct_UFunction_UGridMeshPool_PushObject, "PushObject" }, // 2785591414
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridMeshPool_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "BuiltIn/GridMeshPool.h" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMaterialTemplate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xec\x83\x9d\xec\x84\xb1\xea\xb8\xb0\xec\x97\x90 \xec\x9d\x98\xed\x95\xb4 \xec\x83\x9d\xec\x84\xb1\xeb\x90\x9c \xeb\xa9\x94\xec\x8b\x9c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xec\x97\x90 \xec\x9e\x85\xed\x9e\x90 \xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xeb\xa8\xb8\xed\x8b\xb0\xeb\xa6\xac\xec\x96\xbc \xed\x85\x9c\xed\x94\x8c\xeb\xa6\xbf\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMaterialTemplate = { UE4CodeGen_Private::EPropertyClass::Object, "GridMaterialTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UGridMeshPool, GridMaterialTemplate), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMaterialTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMaterialTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshTemplate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xeb\xa9\x94\xec\x8b\x9c \xec\x84\xa4\xec\xa0\x95\xec\x97\x90 \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xeb\xa9\x94\xec\x8b\x9c\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshTemplate = { UE4CodeGen_Private::EPropertyClass::Object, "GridMeshTemplate", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UGridMeshPool, GridMeshTemplate), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xec\x83\x9d\xec\x84\xb1\xea\xb8\xb0\xec\x97\x90 \xec\x9d\x98\xed\x95\xb4 \xec\x83\x9d\xec\x84\xb1\xeb\x90\x98\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xec\x9d\x98 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray = { UE4CodeGen_Private::EPropertyClass::Array, "GridMeshArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x004000800001000d, 1, nullptr, STRUCT_OFFSET(UGridMeshPool, GridMeshArray), METADATA_PARAMS(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "GridMeshArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000080008, 1, nullptr, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridMeshPool_Statics::NewProp_MaxPoolSize_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "ModuleRelativePath", "Public/BuiltIn/GridMeshPool.h" },
		{ "ToolTip", "\xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x92\x80\xec\x9d\x98 \xed\x81\xac\xea\xb8\xb0" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGridMeshPool_Statics::NewProp_MaxPoolSize = { UE4CodeGen_Private::EPropertyClass::Int, "MaxPoolSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000010005, 1, nullptr, STRUCT_OFFSET(UGridMeshPool, MaxPoolSize), METADATA_PARAMS(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_MaxPoolSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridMeshPool_Statics::NewProp_MaxPoolSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGridMeshPool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMaterialTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridMeshPool_Statics::NewProp_GridMeshArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridMeshPool_Statics::NewProp_MaxPoolSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGridMeshPool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGridMeshPool>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGridMeshPool_Statics::ClassParams = {
		&UGridMeshPool::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UGridMeshPool_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UGridMeshPool_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGridMeshPool_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGridMeshPool_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGridMeshPool()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGridMeshPool_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGridMeshPool, 3309265200);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGridMeshPool(Z_Construct_UClass_UGridMeshPool, &UGridMeshPool::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UGridMeshPool"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGridMeshPool);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
