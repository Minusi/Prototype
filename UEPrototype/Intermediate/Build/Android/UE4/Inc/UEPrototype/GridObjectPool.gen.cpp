// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/BuiltIn/Grid/GridObjectPool.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridObjectPool() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridObjectPool_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UGridObjectPool();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UGridObjectPool_FillObject();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UGridObjectPool_PopObject();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UGridObjectPool_PushObject();
// End Cross Module References
	void UGridObjectPool::StaticRegisterNativesUGridObjectPool()
	{
		UClass* Class = UGridObjectPool::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FillObject", &UGridObjectPool::execFillObject },
			{ "PopObject", &UGridObjectPool::execPopObject },
			{ "PushObject", &UGridObjectPool::execPushObject },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGridObjectPool_FillObject_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridObjectPool_FillObject_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Grid|Pool" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
		{ "ToolTip", "GridMeshPool\xec\x97\x90 \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xec\xb1\x84\xec\x9a\xb0\xea\xb8\xb0 \xec\x8b\x9c\xec\x9e\x91\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridObjectPool_FillObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGridObjectPool, "FillObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGridObjectPool_FillObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_FillObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGridObjectPool_FillObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGridObjectPool_FillObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGridObjectPool_PopObject_Statics
	{
		struct GridObjectPool_eventPopObject_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080588, 1, nullptr, STRUCT_OFFSET(GridObjectPool_eventPopObject_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Grid|Pool" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
		{ "ToolTip", "\xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xed\x92\x80\xec\x97\x90\xec\x84\x9c \xea\xba\xbc\xeb\x83\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGridObjectPool, "PopObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(GridObjectPool_eventPopObject_Parms), Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGridObjectPool_PopObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGridObjectPool_PopObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGridObjectPool_PushObject_Statics
	{
		struct GridObjectPool_eventPushObject_Parms
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::NewProp_InMeshComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::NewProp_InMeshComp = { UE4CodeGen_Private::EPropertyClass::Object, "InMeshComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GridObjectPool_eventPushObject_Parms, InMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::NewProp_InMeshComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::NewProp_InMeshComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::NewProp_InMeshComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Grid|Pool" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
		{ "ToolTip", "\xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xed\x92\x80\xec\x97\x90 \xec\x82\xbd\xec\x9e\x85\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGridObjectPool, "PushObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(GridObjectPool_eventPushObject_Parms), Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGridObjectPool_PushObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGridObjectPool_PushObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGridObjectPool_NoRegister()
	{
		return UGridObjectPool::StaticClass();
	}
	struct Z_Construct_UClass_UGridObjectPool_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Template_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Template;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridObjectArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GridObjectArray;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GridObjectArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxPoolSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxPoolSize;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGridObjectPool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGridObjectPool_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGridObjectPool_FillObject, "FillObject" }, // 2432164648
		{ &Z_Construct_UFunction_UGridObjectPool_PopObject, "PopObject" }, // 1374726466
		{ &Z_Construct_UFunction_UGridObjectPool_PushObject, "PushObject" }, // 395964226
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridObjectPool_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Grid" },
		{ "IncludePath", "BuiltIn/Grid/GridObjectPool.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridObjectPool_Statics::NewProp_Template_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
		{ "ToolTip", "\xec\x9d\xb4 \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x92\x80\xec\x9d\xb4 \xea\xb0\x80\xec\xa7\x80\xea\xb3\xa0 \xec\x9e\x88\xeb\x8a\x94 \xea\xb0\x9d\xec\xb2\xb4\xec\x9d\x98 \xed\x85\x9c\xed\x94\x8c\xeb\xa6\xbf" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGridObjectPool_Statics::NewProp_Template = { UE4CodeGen_Private::EPropertyClass::Object, "Template", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(UGridObjectPool, Template), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGridObjectPool_Statics::NewProp_Template_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridObjectPool_Statics::NewProp_Template_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
		{ "ToolTip", "\xea\xb7\xb8\xeb\xa6\xac\xeb\x93\x9c \xec\x83\x9d\xec\x84\xb1\xea\xb8\xb0\xec\x97\x90 \xec\x9d\x98\xed\x95\xb4 \xec\x83\x9d\xec\x84\xb1\xeb\x90\x98\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\xec\x9d\x98 \xed\x8f\xac\xec\x9d\xb8\xed\x84\xb0 \xeb\xb0\xb0\xec\x97\xb4" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray = { UE4CodeGen_Private::EPropertyClass::Array, "GridObjectArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x004000800002000d, 1, nullptr, STRUCT_OFFSET(UGridObjectPool, GridObjectArray), METADATA_PARAMS(Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "GridObjectArray", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00000000000a0008, 1, nullptr, 0, Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGridObjectPool_Statics::NewProp_MaxPoolSize_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Pool|Grid" },
		{ "ModuleRelativePath", "Public/BuiltIn/Grid/GridObjectPool.h" },
		{ "ToolTip", "\xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xed\x92\x80\xec\x9d\x98 \xed\x81\xac\xea\xb8\xb0" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGridObjectPool_Statics::NewProp_MaxPoolSize = { UE4CodeGen_Private::EPropertyClass::Int, "MaxPoolSize", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000010005, 1, nullptr, STRUCT_OFFSET(UGridObjectPool, MaxPoolSize), METADATA_PARAMS(Z_Construct_UClass_UGridObjectPool_Statics::NewProp_MaxPoolSize_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGridObjectPool_Statics::NewProp_MaxPoolSize_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGridObjectPool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridObjectPool_Statics::NewProp_Template,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridObjectPool_Statics::NewProp_GridObjectArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGridObjectPool_Statics::NewProp_MaxPoolSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGridObjectPool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGridObjectPool>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGridObjectPool_Statics::ClassParams = {
		&UGridObjectPool::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UGridObjectPool_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UGridObjectPool_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGridObjectPool_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGridObjectPool_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGridObjectPool()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGridObjectPool_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGridObjectPool, 351323980);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGridObjectPool(Z_Construct_UClass_UGridObjectPool, &UGridObjectPool::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UGridObjectPool"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGridObjectPool);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
