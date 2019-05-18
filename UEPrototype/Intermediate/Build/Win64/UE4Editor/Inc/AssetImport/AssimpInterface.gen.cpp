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
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssimpInterface_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssimpInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AssetImport();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssimpInterface_LoadModel();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetModel_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetImporter_NoRegister();
// End Cross Module References
	void UAssimpInterface::StaticRegisterNativesUAssimpInterface()
	{
		UClass* Class = UAssimpInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadModel", &UAssimpInterface::execLoadModel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics
	{
		struct AssimpInterface_eventLoadModel_Parms
		{
			FString FilePath;
			FString ErrorString;
			UAssetModel* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ErrorString;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModel_Parms, ReturnValue), Z_Construct_UClass_UAssetModel_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::NewProp_ErrorString = { UE4CodeGen_Private::EPropertyClass::Str, "ErrorString", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModel_Parms, ErrorString), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::NewProp_FilePath = { UE4CodeGen_Private::EPropertyClass::Str, "FilePath", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssimpInterface_eventLoadModel_Parms, FilePath), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::NewProp_ErrorString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::NewProp_FilePath,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xea\xb2\xbd\xeb\xa1\x9c\xec\x97\x90\xec\x84\x9c \xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\x84 \xec\x9d\xbd\xec\x96\xb4\xeb\x93\xa4\xec\x97\xac\xec\x98\xb5\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssimpInterface, "LoadModel", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(AssimpInterface_eventLoadModel_Parms), Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssimpInterface_LoadModel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssimpInterface_LoadModel_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cModel_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_cModel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Importer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Importer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshCurrentlyProcessed_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MeshCurrentlyProcessed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAssimpInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAssimpInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAssimpInterface_LoadModel, "LoadModel" }, // 2471167813
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpInterface_Statics::NewProp_cModel_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xec\x95\xa0\xec\x85\x8b \xeb\xaa\xa8\xeb\x8d\xb8\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xec\xba\x90\xec\x8b\x9c \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAssimpInterface_Statics::NewProp_cModel = { UE4CodeGen_Private::EPropertyClass::Object, "cModel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020015, 1, nullptr, STRUCT_OFFSET(UAssimpInterface, cModel), Z_Construct_UClass_UAssetModel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_cModel_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_cModel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpInterface_Statics::NewProp_Importer_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\x84 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c UE4 \xed\x98\xb8\xed\x99\x98 \xec\x95\xa0\xec\x85\x8b \xec\x9e\x84\xed\x8f\xac\xed\x84\xb0\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAssimpInterface_Statics::NewProp_Importer = { UE4CodeGen_Private::EPropertyClass::Object, "Importer", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020015, 1, nullptr, STRUCT_OFFSET(UAssimpInterface, Importer), Z_Construct_UClass_UAssetImporter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_Importer_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_Importer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpInterface_Statics::NewProp_MeshCurrentlyProcessed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssimpInterface.h" },
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xec\xb2\x98\xeb\xa6\xac \xec\xa4\x91\xec\x9d\xb8 \xeb\xa9\x94\xec\x8b\x9c\xec\x9d\x98 \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAssimpInterface_Statics::NewProp_MeshCurrentlyProcessed = { UE4CodeGen_Private::EPropertyClass::Int, "MeshCurrentlyProcessed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020015, 1, nullptr, STRUCT_OFFSET(UAssimpInterface, MeshCurrentlyProcessed), METADATA_PARAMS(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_MeshCurrentlyProcessed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssimpInterface_Statics::NewProp_MeshCurrentlyProcessed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAssimpInterface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssimpInterface_Statics::NewProp_cModel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssimpInterface_Statics::NewProp_Importer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssimpInterface_Statics::NewProp_MeshCurrentlyProcessed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAssimpInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssimpInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAssimpInterface_Statics::ClassParams = {
		&UAssimpInterface::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
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
	IMPLEMENT_CLASS(UAssimpInterface, 1045680187);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssimpInterface(Z_Construct_UClass_UAssimpInterface, &UAssimpInterface::StaticClass, TEXT("/Script/AssetImport"), TEXT("UAssimpInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssimpInterface);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
