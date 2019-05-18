// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetImport/Public/AssetMesh.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetMesh() {}
// Cross Module References
	ASSETIMPORT_API UScriptStruct* Z_Construct_UScriptStruct_FVertexColorChannel();
	UPackage* Z_Construct_UPackage__Script_AssetImport();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	ASSETIMPORT_API UScriptStruct* Z_Construct_UScriptStruct_FUVChannel();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetMesh_NoRegister();
	ASSETIMPORT_API UClass* Z_Construct_UClass_UAssetMesh();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshNormal();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshTangent();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshUV();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshVertex();
	ASSETIMPORT_API UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor();
	ENGINE_API UClass* Z_Construct_UClass_UTexture_NoRegister();
// End Cross Module References
class UScriptStruct* FVertexColorChannel::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ASSETIMPORT_API uint32 Get_Z_Construct_UScriptStruct_FVertexColorChannel_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FVertexColorChannel, Z_Construct_UPackage__Script_AssetImport(), TEXT("VertexColorChannel"), sizeof(FVertexColorChannel), Get_Z_Construct_UScriptStruct_FVertexColorChannel_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FVertexColorChannel(FVertexColorChannel::StaticStruct, TEXT("/Script/AssetImport"), TEXT("VertexColorChannel"), false, nullptr, nullptr);
static struct FScriptStruct_AssetImport_StaticRegisterNativesFVertexColorChannel
{
	FScriptStruct_AssetImport_StaticRegisterNativesFVertexColorChannel()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("VertexColorChannel")),new UScriptStruct::TCppStructOps<FVertexColorChannel>);
	}
} ScriptStruct_AssetImport_StaticRegisterNativesFVertexColorChannel;
	struct Z_Construct_UScriptStruct_FVertexColorChannel_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexColorChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_VertexColorChannel;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VertexColorChannel_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexColorChannel_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "*     VertexColorChannel\xec\x9d\x80 \xeb\x8b\xa8\xec\x9d\xbc \xeb\xb2\x84\xed\x85\x8d\xec\x8a\xa4 \xec\xbb\xac\xeb\x9f\xac \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x82\xb4\xeb\x8a\x94\xeb\x8d\xb0 \xec\x82\xac\xec\x9a\xa9\xeb\x90\x98\xeb\x8a\x94 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n*     Multi-VertexColor \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x82\xb4\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c nested array\xeb\x8a\x94 \xea\xb5\xac\xed\x98\x84\xed\x95\xa0 \xec\x88\x98 \xec\x97\x86\xea\xb8\xb0 \xeb\x95\x8c\xeb\xac\xb8\xec\x97\x90\n*     VertexColorChannel\xec\x9d\x98 Container\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4\xec\x84\x9c \xea\xb5\xac\xed\x98\x84\xed\x95\x98\xec\x8b\x9c\xea\xb8\xb0 \xeb\xb0\x94\xeb\x9e\x8d\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	void* Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVertexColorChannel>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel_MetaData[] = {
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xeb\x8b\xa8\xec\x9d\xbc \xeb\xb2\x84\xed\x85\x8d\xec\x8a\xa4 \xec\xbb\xac\xeb\x9f\xac \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x83\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel = { UE4CodeGen_Private::EPropertyClass::Array, "VertexColorChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(FVertexColorChannel, VertexColorChannel), METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "VertexColorChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVertexColorChannel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVertexColorChannel_Statics::NewProp_VertexColorChannel_Inner,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVertexColorChannel_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
		nullptr,
		&NewStructOps,
		"VertexColorChannel",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FVertexColorChannel),
		alignof(FVertexColorChannel),
		Z_Construct_UScriptStruct_FVertexColorChannel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexColorChannel_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVertexColorChannel_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FVertexColorChannel_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVertexColorChannel()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FVertexColorChannel_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_AssetImport();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("VertexColorChannel"), sizeof(FVertexColorChannel), Get_Z_Construct_UScriptStruct_FVertexColorChannel_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FVertexColorChannel_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FVertexColorChannel_CRC() { return 75550896U; }
class UScriptStruct* FUVChannel::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ASSETIMPORT_API uint32 Get_Z_Construct_UScriptStruct_FUVChannel_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FUVChannel, Z_Construct_UPackage__Script_AssetImport(), TEXT("UVChannel"), sizeof(FUVChannel), Get_Z_Construct_UScriptStruct_FUVChannel_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FUVChannel(FUVChannel::StaticStruct, TEXT("/Script/AssetImport"), TEXT("UVChannel"), false, nullptr, nullptr);
static struct FScriptStruct_AssetImport_StaticRegisterNativesFUVChannel
{
	FScriptStruct_AssetImport_StaticRegisterNativesFUVChannel()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("UVChannel")),new UScriptStruct::TCppStructOps<FUVChannel>);
	}
} ScriptStruct_AssetImport_StaticRegisterNativesFUVChannel;
	struct Z_Construct_UScriptStruct_FUVChannel_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UVChannel_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_UVChannel;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UVChannel_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUVChannel_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "* UVChannel\xec\x9d\x80 \xeb\x8b\xa8\xec\x9d\xbc UV \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x82\xb4\xeb\x8a\x94\xeb\x8d\xb0 \xec\x82\xac\xec\x9a\xa9\xeb\x90\x98\xeb\x8a\x94 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n* Multi-UV \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x82\xb4\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c nested array\xeb\x8a\x94 \xea\xb5\xac\xed\x98\x84\xed\x95\xa0 \xec\x88\x98 \xec\x97\x86\xea\xb8\xb0\n* \xeb\x95\x8c\xeb\xac\xb8\xec\x97\x90 UVChannel\xec\x9d\x98 Container\xeb\xa5\xbc \xed\x86\xb5\xed\x95\xb4\xec\x84\x9c \xea\xb5\xac\xed\x98\x84\xed\x95\x98\xec\x8b\x9c\xea\xb8\xb0 \xeb\xb0\x94\xeb\x9e\x8d\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	void* Z_Construct_UScriptStruct_FUVChannel_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FUVChannel>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel_MetaData[] = {
		{ "Category", "Assimp" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xeb\x8b\xa8\xec\x9d\xbc UV \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xeb\x82\x98\xed\x83\x80\xeb\x83\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel = { UE4CodeGen_Private::EPropertyClass::Array, "UVChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000004, 1, nullptr, STRUCT_OFFSET(FUVChannel, UVChannel), METADATA_PARAMS(Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "UVChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FUVChannel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUVChannel_Statics::NewProp_UVChannel_Inner,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FUVChannel_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
		nullptr,
		&NewStructOps,
		"UVChannel",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FUVChannel),
		alignof(FUVChannel),
		Z_Construct_UScriptStruct_FUVChannel_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FUVChannel_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FUVChannel_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FUVChannel_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FUVChannel()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FUVChannel_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_AssetImport();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("UVChannel"), sizeof(FUVChannel), Get_Z_Construct_UScriptStruct_FUVChannel_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FUVChannel_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FUVChannel_CRC() { return 404194502U; }
	void UAssetMesh::StaticRegisterNativesUAssetMesh()
	{
		UClass* Class = UAssetMesh::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMeshNormal", &UAssetMesh::execGetMeshNormal },
			{ "GetMeshTangent", &UAssetMesh::execGetMeshTangent },
			{ "GetMeshUV", &UAssetMesh::execGetMeshUV },
			{ "GetMeshVertex", &UAssetMesh::execGetMeshVertex },
			{ "GetMeshVertexColor", &UAssetMesh::execGetMeshVertexColor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics
	{
		struct AssetMesh_eventGetMeshNormal_Parms
		{
			int32 Index;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshNormal_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshNormal_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9d\x98 \xeb\x85\xb8\xeb\xa7\x90 \xeb\xb2\xa1\xed\x84\xb0\xec\x9d\x98 \xec\x82\xac\xeb\xb3\xb8\xec\x9d\x84 \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetMesh, "GetMeshNormal", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(AssetMesh_eventGetMeshNormal_Parms), Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshNormal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetMesh_GetMeshNormal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics
	{
		struct AssetMesh_eventGetMeshTangent_Parms
		{
			int32 Index;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshTangent_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshTangent_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9d\x98 \xed\x83\x84\xec\xa0\xa0\xed\x8a\xb8 \xeb\xb2\xa1\xed\x84\xb0\xec\x9d\x98 \xec\x82\xac\xeb\xb3\xb8\xec\x9d\x84 \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetMesh, "GetMeshTangent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(AssetMesh_eventGetMeshTangent_Parms), Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshTangent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetMesh_GetMeshTangent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics
	{
		struct AssetMesh_eventGetMeshUV_Parms
		{
			int32 Index;
			int32 Channel;
			FVector2D ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Channel;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshUV_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::NewProp_Channel = { UE4CodeGen_Private::EPropertyClass::Int, "Channel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshUV_Parms, Channel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshUV_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::NewProp_Channel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x99\x80 \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xea\xb0\x80\xec\xa7\x84 UV \xec\xa2\x8c\xed\x91\x9c\xec\x9d\x98 \xec\x82\xac\xeb\xb3\xb8\xec\x9d\x84 \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetMesh, "GetMeshUV", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(AssetMesh_eventGetMeshUV_Parms), Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshUV()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetMesh_GetMeshUV_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics
	{
		struct AssetMesh_eventGetMeshVertex_Parms
		{
			int32 Index;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshVertex_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshVertex_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9d\x98 \xec\xa0\x95\xec\xa0\x90 \xec\x9c\x84\xec\xb9\x98\xec\x9d\x98 \xec\x82\xac\xeb\xb3\xb8\xec\x9d\x84 \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetMesh, "GetMeshVertex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(AssetMesh_eventGetMeshVertex_Parms), Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshVertex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetMesh_GetMeshVertex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics
	{
		struct AssetMesh_eventGetMeshVertexColor_Parms
		{
			int32 Index;
			int32 Channel;
			FLinearColor ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Channel;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshVertexColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::NewProp_Channel = { UE4CodeGen_Private::EPropertyClass::Int, "Channel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshVertexColor_Parms, Channel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::NewProp_Index = { UE4CodeGen_Private::EPropertyClass::Int, "Index", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(AssetMesh_eventGetMeshVertexColor_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::NewProp_Channel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xec\xa7\x80\xec\xa0\x95\xeb\x90\x9c \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4\xec\x9d\x98 \xec\xb1\x84\xeb\x84\x90\xec\x9d\x84 \xea\xb0\x80\xec\xa7\x84 \xeb\xb2\x84\xed\x85\x8d\xec\x8a\xa4 \xec\xbb\xac\xeb\x9f\xac\xec\x9d\x98 \xec\x82\xac\xeb\xb3\xb8\xec\x9d\x84 \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAssetMesh, "GetMeshVertexColor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(AssetMesh_eventGetMeshVertexColor_Parms), Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAssetMesh_NoRegister()
	{
		return UAssetMesh::StaticClass();
	}
	struct Z_Construct_UClass_UAssetMesh_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Textures_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Textures;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Textures_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tangents_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Tangents;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VertexColors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_VertexColors;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VertexColors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UVs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_UVs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_UVs_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Indices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Indices;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Indices_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAssetMesh_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_AssetImport,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAssetMesh_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAssetMesh_GetMeshNormal, "GetMeshNormal" }, // 2337370123
		{ &Z_Construct_UFunction_UAssetMesh_GetMeshTangent, "GetMeshTangent" }, // 3500465054
		{ &Z_Construct_UFunction_UAssetMesh_GetMeshUV, "GetMeshUV" }, // 1492927523
		{ &Z_Construct_UFunction_UAssetMesh_GetMeshVertex, "GetMeshVertex" }, // 222873360
		{ &Z_Construct_UFunction_UAssetMesh_GetMeshVertexColor, "GetMeshVertexColor" }, // 3242913610
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Assimp" },
		{ "IncludePath", "AssetMesh.h" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "AssetMesh \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xeb\x8a\x94 \xeb\xaa\xa8\xeb\x8d\xb8\xec\x9d\x84 \xea\xb5\xac\xec\x84\xb1\xed\x95\x98\xeb\x8a\x94 \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xed\x91\x9c\xed\x98\x84\xed\x95\x98\xeb\x8a\x94 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\n\xec\x9d\xbc\xeb\xb0\x98\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xeb\xaa\xa8\xeb\x8d\xb8\xeb\xa1\x9c \xec\xb7\xa8\xea\xb8\x89\xed\x95\x98\xea\xb8\xb0\xeb\x8f\x84 \xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4. \xec\x9d\xb4 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xb9\xec\x97\x90\xec\x84\x9c \xec\x9d\x98\xeb\xaf\xb8\xed\x95\x98\xeb\x8a\x94\n\xeb\xa9\x94\xec\x8b\x9c\xeb\x8a\x94 UE4\xec\x97\x90\xec\x84\x9c\xec\x9d\x98 MeshSection\xea\xb3\xbc \xea\xb6\xa4\xeb\xa5\xbc \xea\xb0\x99\xec\x9d\xb4\xed\x95\x9c\xeb\x8b\xa4\xea\xb3\xa0 \xeb\xb3\xb4\xec\x95\x84\xeb\x8f\x84 \xeb\xac\xb4\xeb\xb0\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xeb\xa9\x94\xec\x8b\x9c\xec\x97\x90 \xec\x82\xac\xec\x9a\xa9\xeb\x90\x98\xeb\x8a\x94 \xed\x85\x8d\xec\x8a\xa4\xec\xb2\x98\xeb\x93\xa4\xec\x9d\x98 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures = { UE4CodeGen_Private::EPropertyClass::Array, "Textures", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, Textures), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Textures", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_UTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xed\x83\x84\xec\xa0\xa0\xed\x8a\xb8 \xeb\xb2\xa1\xed\x84\xb0\xeb\x93\xa4\xec\x9d\x98 \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents = { UE4CodeGen_Private::EPropertyClass::Array, "Tangents", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, Tangents), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Tangents", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "8 \xec\xb1\x84\xeb\x84\x90\xea\xb9\x8c\xec\xa7\x80 \xec\xa0\x95\xec\xa0\x90 \xec\x83\x89\xec\x83\x81\xec\x9d\x84 \xec\xa7\x80\xec\x9b\x90\xed\x95\x98\xeb\x8a\x94 assimp\xec\x99\x80\n1 \xec\xb1\x84\xeb\x84\x90\xea\xb9\x8c\xec\xa7\x80 \xec\xa0\x95\xec\xa0\x90 \xec\x83\x89\xec\x83\x81\xec\x9d\x84 \xec\xa7\x80\xec\x9b\x90\xed\x95\x98\xeb\x8a\x94 ue4\xec\x9d\x98 \xed\x98\xb8\xed\x99\x98\xec\x9d\x84 \xeb\xa7\x9e\xec\xb6\x94\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4.\nTODO : \xeb\x9f\xb0\xed\x83\x80\xec\x9e\x84\xec\x97\x90 \xec\xa0\x95\xec\xa0\x90 \xec\x83\x89\xec\x83\x81\xec\x9d\x84 \xeb\xb3\x80\xea\xb2\xbd\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xeb\x8a\x94\xec\xa7\x80 \xed\x99\x95\xec\x9d\xb8\xed\x95\x98\xec\x8b\x9c\xea\xb8\xb0 \xeb\xb0\x94\xeb\x9e\x8d\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors = { UE4CodeGen_Private::EPropertyClass::Array, "VertexColors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, VertexColors), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "VertexColors", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVertexColorChannel, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "UV \xec\xa2\x8c\xed\x91\x9c\xeb\x93\xa4\xec\x9d\x98 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs = { UE4CodeGen_Private::EPropertyClass::Array, "UVs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, UVs), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "UVs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FUVChannel, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xeb\x85\xb8\xeb\xa7\x90 \xeb\xb2\xa1\xed\x84\xb0\xeb\x93\xa4\xec\x9d\x98 \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals = { UE4CodeGen_Private::EPropertyClass::Array, "Normals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, Normals), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Normals", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xec\xa0\x95\xec\xa0\x90\xeb\x93\xa4\xec\x9d\x98 \xec\x9d\xb8\xeb\x8d\xb1\xec\x8a\xa4 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices = { UE4CodeGen_Private::EPropertyClass::Array, "Indices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, Indices), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "Indices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Assimp|Mesh" },
		{ "ModuleRelativePath", "Public/AssetMesh.h" },
		{ "ToolTip", "\xeb\xa9\x94\xec\x8b\x9c\xeb\xa5\xbc \xea\xb5\xac\xec\x84\xb1\xed\x95\x98\xeb\x8a\x94 \xec\xa0\x95\xec\xa0\x90\xeb\x93\xa4\xec\x9d\x98 \xeb\xb0\xb0\xec\x97\xb4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices = { UE4CodeGen_Private::EPropertyClass::Array, "Vertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(UAssetMesh, Vertices), METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Vertices", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAssetMesh_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Textures_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Tangents_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_VertexColors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_UVs_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Normals_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Indices_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetMesh_Statics::NewProp_Vertices_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAssetMesh_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetMesh>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAssetMesh_Statics::ClassParams = {
		&UAssetMesh::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UAssetMesh_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UAssetMesh_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAssetMesh_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAssetMesh()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAssetMesh_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAssetMesh, 1353845867);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAssetMesh(Z_Construct_UClass_UAssetMesh, &UAssetMesh::StaticClass, TEXT("/Script/AssetImport"), TEXT("UAssetMesh"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetMesh);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
