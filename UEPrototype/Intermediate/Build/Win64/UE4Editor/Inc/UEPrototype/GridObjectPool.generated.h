// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMeshComponent;
#ifdef UEPROTOTYPE_GridObjectPool_generated_h
#error "GridObjectPool.generated.h already included, missing '#pragma once' in GridObjectPool.h"
#endif
#define UEPROTOTYPE_GridObjectPool_generated_h

#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_RPC_WRAPPERS \
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


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGridObjectPool(); \
	friend struct Z_Construct_UClass_UGridObjectPool_Statics; \
public: \
	DECLARE_CLASS(UGridObjectPool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UGridObjectPool)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_INCLASS \
private: \
	static void StaticRegisterNativesUGridObjectPool(); \
	friend struct Z_Construct_UClass_UGridObjectPool_Statics; \
public: \
	DECLARE_CLASS(UGridObjectPool, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UGridObjectPool)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGridObjectPool(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGridObjectPool) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGridObjectPool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGridObjectPool); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGridObjectPool(UGridObjectPool&&); \
	NO_API UGridObjectPool(const UGridObjectPool&); \
public:


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGridObjectPool(UGridObjectPool&&); \
	NO_API UGridObjectPool(const UGridObjectPool&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGridObjectPool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGridObjectPool); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGridObjectPool)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MaxPoolSize() { return STRUCT_OFFSET(UGridObjectPool, MaxPoolSize); } \
	FORCEINLINE static uint32 __PPO__GridObjectArray() { return STRUCT_OFFSET(UGridObjectPool, GridObjectArray); } \
	FORCEINLINE static uint32 __PPO__Template() { return STRUCT_OFFSET(UGridObjectPool, Template); }


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_32_PROLOG
#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_INCLASS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridObjectPool_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
