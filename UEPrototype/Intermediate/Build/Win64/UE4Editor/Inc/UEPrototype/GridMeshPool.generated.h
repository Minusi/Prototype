// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMeshComponent;
#ifdef UEPROTOTYPE_GridMeshPool_generated_h
#error "GridMeshPool.generated.h already included, missing '#pragma once' in GridMeshPool.h"
#endif
#define UEPROTOTYPE_GridMeshPool_generated_h

#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFillObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FillObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPopObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UStaticMeshComponent**)Z_Param__Result=P_THIS->PopObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPushObject) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_InMeshComp); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PushObject(Z_Param_InMeshComp); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFillObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->FillObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPopObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UStaticMeshComponent**)Z_Param__Result=P_THIS->PopObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPushObject) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_InMeshComp); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PushObject(Z_Param_InMeshComp); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGridMeshPool(); \
	friend struct Z_Construct_UClass_UGridMeshPool_Statics; \
public: \
	DECLARE_CLASS(UGridMeshPool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UGridMeshPool)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_INCLASS \
private: \
	static void StaticRegisterNativesUGridMeshPool(); \
	friend struct Z_Construct_UClass_UGridMeshPool_Statics; \
public: \
	DECLARE_CLASS(UGridMeshPool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UGridMeshPool)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGridMeshPool(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGridMeshPool) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGridMeshPool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGridMeshPool); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGridMeshPool(UGridMeshPool&&); \
	NO_API UGridMeshPool(const UGridMeshPool&); \
public:


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGridMeshPool(UGridMeshPool&&); \
	NO_API UGridMeshPool(const UGridMeshPool&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGridMeshPool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGridMeshPool); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGridMeshPool)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MaxPoolSize() { return STRUCT_OFFSET(UGridMeshPool, MaxPoolSize); } \
	FORCEINLINE static uint32 __PPO__GridMeshArray() { return STRUCT_OFFSET(UGridMeshPool, GridMeshArray); } \
	FORCEINLINE static uint32 __PPO__GridMeshTemplate() { return STRUCT_OFFSET(UGridMeshPool, GridMeshTemplate); } \
	FORCEINLINE static uint32 __PPO__GridMaterialTemplate() { return STRUCT_OFFSET(UGridMeshPool, GridMaterialTemplate); }


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_31_PROLOG
#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_INCLASS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h_34_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_BuiltIn_GridMeshPool_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
