// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAssetModel;
class UObject;
class UAssimpInterface;
#ifdef ASSETIMPORT_AssimpInterface_generated_h
#error "AssimpInterface.generated.h already included, missing '#pragma once' in AssimpInterface.h"
#endif
#define ASSETIMPORT_AssimpInterface_generated_h

#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_38_DELEGATE \
struct AssimpInterface_eventOnModelLoadCompleted_Parms \
{ \
	UAssetModel* AssetModel; \
}; \
static inline void FOnModelLoadCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnModelLoadCompleted, UAssetModel* AssetModel) \
{ \
	AssimpInterface_eventOnModelLoadCompleted_Parms Parms; \
	Parms.AssetModel=AssetModel; \
	OnModelLoadCompleted.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLoadModelFromDisk) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_ModelPath); \
		P_GET_OBJECT(UObject,Z_Param_Outer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAssetModel**)Z_Param__Result=UAssimpInterface::LoadModelFromDisk(Z_Param_Out_ModelPath,Z_Param_Outer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadModelFromDiskAsync) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_ModelPath); \
		P_GET_OBJECT(UObject,Z_Param_Outer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAssimpInterface**)Z_Param__Result=UAssimpInterface::LoadModelFromDiskAsync(Z_Param_Out_ModelPath,Z_Param_Outer); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadModelFromDisk) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_ModelPath); \
		P_GET_OBJECT(UObject,Z_Param_Outer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAssetModel**)Z_Param__Result=UAssimpInterface::LoadModelFromDisk(Z_Param_Out_ModelPath,Z_Param_Outer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadModelFromDiskAsync) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_ModelPath); \
		P_GET_OBJECT(UObject,Z_Param_Outer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UAssimpInterface**)Z_Param__Result=UAssimpInterface::LoadModelFromDiskAsync(Z_Param_Out_ModelPath,Z_Param_Outer); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAssimpInterface(); \
	friend struct Z_Construct_UClass_UAssimpInterface_Statics; \
public: \
	DECLARE_CLASS(UAssimpInterface, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UAssimpInterface)


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_INCLASS \
private: \
	static void StaticRegisterNativesUAssimpInterface(); \
	friend struct Z_Construct_UClass_UAssimpInterface_Statics; \
public: \
	DECLARE_CLASS(UAssimpInterface, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UAssimpInterface)


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssimpInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssimpInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssimpInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssimpInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssimpInterface(UAssimpInterface&&); \
	NO_API UAssimpInterface(const UAssimpInterface&); \
public:


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAssimpInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAssimpInterface(UAssimpInterface&&); \
	NO_API UAssimpInterface(const UAssimpInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAssimpInterface); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAssimpInterface); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAssimpInterface)


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__LoadCompleted() { return STRUCT_OFFSET(UAssimpInterface, LoadCompleted); }


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_31_PROLOG
#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_RPC_WRAPPERS \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_INCLASS \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_AssimpInterface_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_AssetImport_Public_AssimpInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
