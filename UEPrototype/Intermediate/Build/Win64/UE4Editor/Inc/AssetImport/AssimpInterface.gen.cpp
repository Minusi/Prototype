// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetImport/Public/AssimpInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssimpInterface() {}
// Cross Module References
	ASSETIMPORT_API UFunction* Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssimpInterface();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetModel_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssimpInterface_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AssetImport();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics
	{
		struct AssimpInterface_eventOnModelLoadCompleted_Parms
		{
			UAssetModel* AssetModel;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AssetModel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::NewProp_AssetModel = { UE4CodeGen_Private::EPropertyClass::Object, "AssetModel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventOnModelLoadCompleted_Parms, AssetModel), Z_Construct_UClass_UAssetModel_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::NewProp_AssetModel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\x98 \xec\x83\x9d\xec\x84\xb1\xec\x9d\xb4 \xeb\x81\x9d\xeb\x82\xac\xec\x9d\x84 \xeb\x95\x8c \xeb\xb8\x8c\xeb\xa1\x9c\xeb\x93\x9c\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8\xed\x95\x98\xeb\x8a\x94 \xeb\xa9\x80\xed\x8b\xb0\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssimpInterface, "OnModelLoadCompleted__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(AssimpInterface_eventOnModelLoadCompleted_Parms), Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UAssimpInterface::StaticRegisterNativesUAssimpInterface()
	{
		UClass* Class = UAssimpInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadModelFromDisk", &UAssimpInterface::execLoadModelFromDisk },
			{ "LoadModelFromDiskAsync", &UAssimpInterface::execLoadModelFromDiskAsync },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics
	{
		struct AssimpInterface_eventLoadModelFromDisk_Parms
		{
			FString ModelPath;
			UObject* Outer;
			UAssetModel* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Outer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModelPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ModelPath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModelFromDisk_Parms, ReturnValue), Z_Construct_UClass_UAssetModel_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_Outer = { UE4CodeGen_Private::EPropertyClass::Object, "Outer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModelFromDisk_Parms, Outer), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ModelPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ModelPath = { UE4CodeGen_Private::EPropertyClass::Str, "ModelPath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModelFromDisk_Parms, ModelPath), METADATA_PARAMS(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ModelPath_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ModelPath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_Outer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::NewProp_ModelPath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xea\xb2\xbd\xeb\xa1\x9c\xec\x97\x90\xec\x84\x9c \xeb\xaa\xa8\xeb\x8d\xb8\xeb\xa7\x81 \xed\x8c\x8c\xec\x9d\xbc\xec\x9d\x84 \xeb\xb6\x88\xeb\x9f\xac\xec\x98\xb5\xeb\x8b\x88\xeb\x8b\xa4.\n              @return \xec\x84\xb1\xea\xb3\xb5\xec\xa0\x81\xec\x9d\xb8 \xea\xb2\xbd\xec\x9a\xb0, UE4 \xed\x98\x95\xec\x8b\x9d\xec\x9d\x98 \xec\xa0\x95\xec\xa0\x90 \xec\xa0\x95\xeb\xb3\xb4\xeb\xa5\xbc \xec\xa0\x80\xec\x9e\xa5\xed\x95\x98\xeb\x8a\x94 UAssetModel\xec\x9d\x84 \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssimpInterface, "LoadModelFromDisk", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AssimpInterface_eventLoadModelFromDisk_Parms), Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics
	{
		struct AssimpInterface_eventLoadModelFromDiskAsync_Parms
		{
			FString ModelPath;
			UObject* Outer;
			UAssimpInterface* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Outer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModelPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ModelPath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModelFromDiskAsync_Parms, ReturnValue), Z_Construct_UClass_UAssimpInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_Outer = { UE4CodeGen_Private::EPropertyClass::Object, "Outer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModelFromDiskAsync_Parms, Outer), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ModelPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ModelPath = { UE4CodeGen_Private::EPropertyClass::Str, "ModelPath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModelFromDiskAsync_Parms, ModelPath), METADATA_PARAMS(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ModelPath_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ModelPath_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_Outer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::NewProp_ModelPath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xea\xb2\xbd\xeb\xa1\x9c\xec\x97\x90\xec\x84\x9c \xeb\xaa\xa8\xeb\x8d\xb8\xeb\xa7\x81 \xed\x8c\x8c\xec\x9d\xbc\xec\x9d\x84 \xeb\xb6\x88\xeb\x9f\xac\xec\x98\xb5\xeb\x8b\x88\xeb\x8b\xa4.\n       \xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\xb4 \xeb\xb9\x84\xeb\x8f\x99\xea\xb8\xb0\xec\x8b\x9d\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa1\x9c\xeb\x93\x9c\xeb\x90\x98\xeb\xaf\x80\xeb\xa1\x9c, \xeb\xa1\x9c\xeb\x93\x9c\xea\xb0\x80 \xec\x99\x84\xeb\xa3\x8c\xeb\x90\x98\xec\x97\x88\xec\x9d\x84 \xeb\x95\x8c \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4 \xed\x95\x84\xec\x9a\x94\xeb\xa1\x9c \xed\x95\x98\xeb\x8a\x94 \xeb\xaa\xa8\xeb\x93\xa0 \xea\xb0\x9d\xec\xb2\xb4\xec\x97\x90\xea\xb2\x8c \xeb\x85\xb8\xed\x8b\xb0\xed\x8c\x8c\xec\x9d\xb4\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4.\n       @return \xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\xb4 \xeb\xa1\x9c\xeb\x93\x9c\xeb\x90\x98\xec\x97\x88\xec\x9d\x8c\xec\x9d\x84 \xec\x95\x8c\xeb\xa6\xac\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\xec\x97\x90 \xeb\x93\xb1\xeb\xa1\x9d\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 UAssimpInterface\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssimpInterface, "LoadModelFromDiskAsync", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(AssimpInterface_eventLoadModelFromDiskAsync_Parms), Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAssimpInterface_NoRegister()
	{
		return UAssimpInterface::StaticClass();
	}
	struct Z_Construct_UClass_UAssimpInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LoadCompleted_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_LoadCompleted;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAssimpInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAssimpInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAssimpInterface_LoadModelFromDisk, "LoadModelFromDisk" }, // 2566266687
		{ &Z_Construct_UFunction_UAssimpInterface_LoadModelFromDiskAsync, "LoadModelFromDiskAsync" }, // 4282963484
		{ &Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature, "OnModelLoadCompleted__DelegateSignature" }, // 3362984016
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpInterface_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Assimp" },
		{ "IncludePath", "AssimpInterface.h" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "AssimpInterface\xeb\x8a\x94 UE4 \xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x9b\x8c\xed\x81\xac\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4\xec\x84\x9c Assimp \xeb\x9d\xbc\xec\x9d\xb4\xeb\xb8\x8c\xeb\x9f\xac\xeb\xa6\xac\xeb\xa5\xbc \xed\x98\xb8\xec\xb6\x9c\xed\x95\x98\xea\xb3\xa0\n\xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc Unreal Engine 4\xec\x97\x90\xec\x84\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8f\x84\xeb\xa1\x9d \xec\xa0\x9c\xea\xb3\xb5\xed\x95\x98\xeb\x8a\x94 UE4-Assimp \xec\x9d\xb8\xed\x84\xb0\xed\x8e\x98\xec\x9d\xb4\xec\x8a\xa4\n\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpInterface_Statics::NewProp_LoadCompleted_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x8d\xb8 \xeb\xa1\x9c\xeb\x93\x9c \xec\x99\x84\xeb\xa3\x8c\xec\x8b\x9c \xeb\xb8\x8c\xeb\xa1\x9c\xeb\x93\x9c\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8\xed\x95\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAssimpInterface_Statics::NewProp_LoadCompleted = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "LoadCompleted", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000010080000, 1, nullptr, STRUCT_OFFSET(UAssimpInterface, LoadCompleted), Z_Construct_UDelegateFunction_UAssimpInterface_OnModelLoadCompleted__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_LoadCompleted_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_LoadCompleted_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAssimpInterface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssimpInterface_Statics::NewProp_LoadCompleted,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAssimpInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssimpInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAssimpInterface_Statics::ClassParams = {
		&UAssimpInterface::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UAssimpInterface_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UAssimpInterface_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAssimpInterface_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAssimpInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAssimpInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAssimpInterface_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssimpInterface, 2065223271);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssimpInterface(Z_Construct_UClass_UAssimpInterface, &UAssimpInterface::StaticClass, TEXT("/Script/AssetImport"), TEXT("UAssimpInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssimpInterface);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
