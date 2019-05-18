// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetImport/Public/AssetModel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetModel() {}
// Cross Module References
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetModel_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetModel();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_AssetImport();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetModel_GetMeshAt();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetMesh_NoRegister();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetModel_GetMeshNum();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetModel_SetMeshAt();
// End Cross Module References
	void UAssetModel::StaticRegisterNativesUAssetModel()
	{
		UClass* Class = UAssetModel::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMeshAt", &UAssetModel::execGetMeshAt },
			{ "GetMeshNum", &UAssetModel::execGetMeshNum },
			{ "SetMeshAt", &UAssetModel::execSetMeshAt },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics
	{
		struct AssetModel_eventGetMeshAt_Parms
		{
			int32 Index;
			const UAssetMesh* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000582, 1, nullptr, STRUCT_OFFSET(AssetModel_eventGetMeshAt_Parms, ReturnValue), Z_Construct_UClass_UAssetMesh_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetModel_eventGetMeshAt_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Model" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9d\x98 \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4. (\xec\x9d\xbd\xea\xb8\xb0 \xec\xa0\x84\xec\x9a\xa9)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetModel, "GetMeshAt", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(AssetModel_eventGetMeshAt_Parms), Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetModel_GetMeshAt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetModel_GetMeshAt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics
	{
		struct AssetModel_eventGetMeshNum_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssetModel_eventGetMeshNum_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Model" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "\xeb\xa9\x94\xec\x8b\x9c \xeb\xb0\xb0\xec\x97\xb4\xec\x9d\x98 \xec\x9a\x94\xec\x86\x8c \xea\xb0\x9c\xec\x88\x98\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetModel, "GetMeshNum", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(AssetModel_eventGetMeshNum_Parms), Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetModel_GetMeshNum()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetModel_GetMeshNum_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics
	{
		struct AssetModel_eventSetMeshAt_Parms
		{
			UAssetMesh* InMesh;
			int32 Index;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetModel_eventSetMeshAt_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::NewProp_InMesh = { UE4CodeGen_Private::EPropertyClass::Object, "InMesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetModel_eventSetMeshAt_Parms, InMesh), Z_Construct_UClass_UAssetMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::NewProp_InMesh,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Model" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x97\x90 \xec\x83\x88\xeb\xa1\x9c\xec\x9a\xb4 \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xec\x84\xa4\xec\xa0\x95\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetModel, "SetMeshAt", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(AssetModel_eventSetMeshAt_Parms), Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetModel_SetMeshAt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetModel_SetMeshAt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAssetModel_NoRegister()
	{
		return UAssetModel::StaticClass();
	}
	struct Z_Construct_UClass_UAssetModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Directory_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Directory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Meshes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Meshes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Meshes_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAssetModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAssetModel_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAssetModel_GetMeshAt, "GetMeshAt" }, // 3034005985
		{ &Z_Construct_UFunction_UAssetModel_GetMeshNum, "GetMeshNum" }, // 3866153685
		{ &Z_Construct_UFunction_UAssetModel_SetMeshAt, "SetMeshAt" }, // 1871685227
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetModel_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Assimp" },
		{ "IncludePath", "AssetModel.h" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "AssetModel \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\x8a\x94 \xed\x95\x98\xeb\x82\x98\xec\x9d\x98 \xec\x95\xa0\xec\x85\x8b\xec\x9d\xb4\xeb\x9d\xbc\xea\xb3\xa0 \xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xeb\x93\xa4\xec\x9d\x98 \xec\xa7\x91\xed\x95\xa9\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n\xec\x9d\xbc\xeb\xb0\x98\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xeb\xaa\xa8\xeb\x8d\xb8\xeb\xa1\x9c \xec\xb7\xa8\xea\xb8\x89\xed\x95\x98\xea\xb8\xb0\xeb\x8f\x84 \xed\x95\x98\xec\xa7\x80\xeb\xa7\x8c, \xec\x97\xac\xea\xb8\xb0\xec\x84\x9c \xec\x9d\x98\xeb\xaf\xb8\xed\x95\x98\xeb\x8a\x94 \xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\x80\n\xeb\xa9\x94\xec\x8b\x9c\xeb\x93\xa4\xec\x9d\x98 \xea\xb2\xb0\xed\x95\xa9\xec\x9c\xbc\xeb\xa1\x9c \xec\x9d\x98\xeb\xaf\xb8\xeb\xa5\xbc \xeb\xb6\x80\xec\x97\xac\xeb\xb0\x9b\xeb\x8a\x94 \xea\xb0\x9d\xec\xb2\xb4, \xeb\xa9\x94\xec\x8b\x9c \xec\xbb\xa8\xed\x85\x8c\xec\x9d\xb4\xeb\x84\x88\xeb\xa1\x9c \xec\xb7\xa8\xea\xb8\x89\xed\x95\xa0 \xec\x88\x98\xeb\x8f\x84 \xec\x9e\x88\xec\x8a\xb5\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetModel_Statics::NewProp_FileName_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x8d\xb8 \xed\x8c\x8c\xec\x9d\xbc\xec\x9d\x98 \xec\x9d\xb4\xeb\xa6\x84\xea\xb3\xbc \xed\x99\x95\xec\x9e\xa5\xec\x9e\x90\xeb\xa5\xbc \xed\x8f\xac\xed\x95\xa8\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAssetModel_Statics::NewProp_FileName = { UE4CodeGen_Private::EPropertyClass::Str, "FileName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetModel, FileName), METADATA_PARAMS(Z_Construct_UClass_UAssetModel_Statics::NewProp_FileName_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetModel_Statics::NewProp_FileName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetModel_Statics::NewProp_Directory_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x8d\xb8 \xed\x8c\x8c\xec\x9d\xbc\xec\x97\x90 \xeb\x8c\x80\xed\x95\x9c \xeb\x94\x94\xeb\xa0\x89\xed\x86\xa0\xeb\xa6\xac\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UAssetModel_Statics::NewProp_Directory = { UE4CodeGen_Private::EPropertyClass::Str, "Directory", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetModel, Directory), METADATA_PARAMS(Z_Construct_UClass_UAssetModel_Statics::NewProp_Directory_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetModel_Statics::NewProp_Directory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssetModel.h" },
		{ "ToolTip", "\xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\x84 \xea\xb5\xac\xec\x84\xb1\xed\x95\x98\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xeb\x93\xa4\xec\x9d\x98 \xec\xa7\x91\xed\x95\xa9\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes = { UE4CodeGen_Private::EPropertyClass::Array, "Meshes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020015, 1, nullptr, STRUCT_OFFSET(UAssetModel, Meshes), METADATA_PARAMS(Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Meshes", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000020000, 1, nullptr, 0, Z_Construct_UClass_UAssetMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAssetModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetModel_Statics::NewProp_FileName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetModel_Statics::NewProp_Directory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetModel_Statics::NewProp_Meshes_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAssetModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetModel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAssetModel_Statics::ClassParams = {
		&UAssetModel::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UAssetModel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UAssetModel_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAssetModel_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAssetModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAssetModel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAssetModel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssetModel, 2366071582);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssetModel(Z_Construct_UClass_UAssetModel, &UAssetModel::StaticClass, TEXT("/Script/AssetImport"), TEXT("UAssetModel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetModel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
