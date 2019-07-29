// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class AEditorWorldManager;
#ifdef UEPROTOTYPE_VPFrameworkLibrary_generated_h
#error "VPFrameworkLibrary.generated.h already included, missing '#pragma once' in VPFrameworkLibrary.h"
#endif
#define UEPROTOTYPE_VPFrameworkLibrary_generated_h

#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetEditorWorldManager) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AEditorWorldManager**)Z_Param__Result=UVPFrameworkLibrary::GetEditorWorldManager(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetEditorWorldManager) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AEditorWorldManager**)Z_Param__Result=UVPFrameworkLibrary::GetEditorWorldManager(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVPFrameworkLibrary(); \
	friend struct Z_Construct_UClass_UVPFrameworkLibrary_Statics; \
public: \
	DECLARE_CLASS(UVPFrameworkLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UVPFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUVPFrameworkLibrary(); \
	friend struct Z_Construct_UClass_UVPFrameworkLibrary_Statics; \
public: \
	DECLARE_CLASS(UVPFrameworkLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UVPFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVPFrameworkLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVPFrameworkLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVPFrameworkLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVPFrameworkLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVPFrameworkLibrary(UVPFrameworkLibrary&&); \
	NO_API UVPFrameworkLibrary(const UVPFrameworkLibrary&); \
public:


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVPFrameworkLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVPFrameworkLibrary(UVPFrameworkLibrary&&); \
	NO_API UVPFrameworkLibrary(const UVPFrameworkLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVPFrameworkLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVPFrameworkLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVPFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_PRIVATE_PROPERTY_OFFSET
#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_16_PROLOG
#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Utility_VPFrameworkLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
