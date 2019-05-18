// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FLinearColor;
struct FVector2D;
#ifdef ASSETIMPORT_AssetMesh_generated_h
#error "AssetMesh.generated.h already included, missing '#pragma once' in AssetMesh.h"
#endif
#define ASSETIMPORT_AssetMesh_generated_h

#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_53_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FVertexColorChannel_Statics; \
	ASSETIMPORT_API static class UScriptStruct* StaticStruct();


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FUVChannel_Statics; \
	ASSETIMPORT_API static class UScriptStruct* StaticStruct();


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetMeshTangent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetMeshTangent(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshVertexColor) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FLinearColor*)Z_Param__Result=P_THIS->GetMeshVertexColor(Z_Param_Index,Z_Param_Channel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshUV) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=P_THIS->GetMeshUV(Z_Param_Index,Z_Param_Channel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshNormal) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetMeshNormal(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshVertex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetMeshVertex(Z_Param_Index); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetMeshTangent) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetMeshTangent(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshVertexColor) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FLinearColor*)Z_Param__Result=P_THIS->GetMeshVertexColor(Z_Param_Index,Z_Param_Channel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshUV) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Channel); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=P_THIS->GetMeshUV(Z_Param_Index,Z_Param_Channel); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshNormal) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetMeshNormal(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshVertex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=P_THIS->GetMeshVertex(Z_Param_Index); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAssetMesh(); \
	friend struct Z_Construct_UClass_UAssetMesh_Statics; \
public: \
	DECLARE_CLASS(UAssetMesh, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UAssetMesh)


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_INCLASS \
private: \
	static void StaticRegisterNativesUAssetMesh(); \
	friend struct Z_Construct_UClass_UAssetMesh_Statics; \
public: \
	DECLARE_CLASS(UAssetMesh, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UAssetMesh)


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssetMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssetMesh) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssetMesh); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssetMesh); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssetMesh(UAssetMesh&&); \
	NO_API UAssetMesh(const UAssetMesh&); \
public:


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssetMesh(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssetMesh(UAssetMesh&&); \
	NO_API UAssetMesh(const UAssetMesh&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssetMesh); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssetMesh); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssetMesh)


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Vertices() { return STRUCT_OFFSET(UAssetMesh, Vertices); } \
	FORCEINLINE static uint32 __PPO__Indices() { return STRUCT_OFFSET(UAssetMesh, Indices); } \
	FORCEINLINE static uint32 __PPO__Normals() { return STRUCT_OFFSET(UAssetMesh, Normals); } \
	FORCEINLINE static uint32 __PPO__UVs() { return STRUCT_OFFSET(UAssetMesh, UVs); } \
	FORCEINLINE static uint32 __PPO__VertexColors() { return STRUCT_OFFSET(UAssetMesh, VertexColors); } \
	FORCEINLINE static uint32 __PPO__Tangents() { return STRUCT_OFFSET(UAssetMesh, Tangents); } \
	FORCEINLINE static uint32 __PPO__Textures() { return STRUCT_OFFSET(UAssetMesh, Textures); }


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_82_PROLOG
#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_RPC_WRAPPERS \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_INCLASS \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_AssetMesh_h_85_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_AssetImport_Public_AssetMesh_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
