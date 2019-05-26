// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAssetMesh;
#ifdef ASSETIMPORT_AssetModel_generated_h
#error "AssetModel.generated.h already included, missing '#pragma once' in AssetModel.h"
#endif
#define ASSETIMPORT_AssetModel_generated_h

#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetMeshNum) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMeshNum(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshAt) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAssetMesh**)Z_Param__Result=P_THIS->GetMeshAt(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMeshAt) \
	{ \
		P_GET_OBJECT(UAssetMesh,Z_Param_InMesh); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMeshAt(Z_Param_InMesh,Z_Param_Index); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetMeshNum) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetMeshNum(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetMeshAt) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAssetMesh**)Z_Param__Result=P_THIS->GetMeshAt(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetMeshAt) \
	{ \
		P_GET_OBJECT(UAssetMesh,Z_Param_InMesh); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetMeshAt(Z_Param_InMesh,Z_Param_Index); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAssetModel(); \
	friend struct Z_Construct_UClass_UAssetModel_Statics; \
public: \
	DECLARE_CLASS(UAssetModel, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UAssetModel)


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_INCLASS \
private: \
	static void StaticRegisterNativesUAssetModel(); \
	friend struct Z_Construct_UClass_UAssetModel_Statics; \
public: \
	DECLARE_CLASS(UAssetModel, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UAssetModel)


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssetModel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssetModel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssetModel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssetModel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssetModel(UAssetModel&&); \
	NO_API UAssetModel(const UAssetModel&); \
public:


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssetModel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssetModel(UAssetModel&&); \
	NO_API UAssetModel(const UAssetModel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssetModel); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssetModel); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssetModel)


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Meshes() { return STRUCT_OFFSET(UAssetModel, Meshes); } \
	FORCEINLINE static uint32 __PPO__Directory() { return STRUCT_OFFSET(UAssetModel, Directory); } \
	FORCEINLINE static uint32 __PPO__FileName() { return STRUCT_OFFSET(UAssetModel, FileName); }


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_26_PROLOG
#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_RPC_WRAPPERS \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_INCLASS \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_AssetImport_Public_AssetModel_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_AssetModel_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_AssetImport_Public_AssetModel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
