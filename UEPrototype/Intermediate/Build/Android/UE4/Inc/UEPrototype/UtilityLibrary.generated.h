// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UActorComponent;
class AActor;
#ifdef UEPROTOTYPE_UtilityLibrary_generated_h
#error "UtilityLibrary.generated.h already included, missing '#pragma once' in UtilityLibrary.h"
#endif
#define UEPROTOTYPE_UtilityLibrary_generated_h

#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTransferComponentToOtherActor) \
	{ \
		P_GET_OBJECT(UActorComponent,Z_Param_SourceComp); \
		P_GET_OBJECT(AActor,Z_Param_DestActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UUtilityLibrary::TransferComponentToOtherActor(Z_Param_SourceComp,Z_Param_DestActor); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTransferComponentToOtherActor) \
	{ \
		P_GET_OBJECT(UActorComponent,Z_Param_SourceComp); \
		P_GET_OBJECT(AActor,Z_Param_DestActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UUtilityLibrary::TransferComponentToOtherActor(Z_Param_SourceComp,Z_Param_DestActor); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUtilityLibrary(); \
	friend struct Z_Construct_UClass_UUtilityLibrary_Statics; \
public: \
	DECLARE_CLASS(UUtilityLibrary, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UUtilityLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUUtilityLibrary(); \
	friend struct Z_Construct_UClass_UUtilityLibrary_Statics; \
public: \
	DECLARE_CLASS(UUtilityLibrary, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UUtilityLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUtilityLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUtilityLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUtilityLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUtilityLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUtilityLibrary(UUtilityLibrary&&); \
	NO_API UUtilityLibrary(const UUtilityLibrary&); \
public:


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UUtilityLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UUtilityLibrary(UUtilityLibrary&&); \
	NO_API UUtilityLibrary(const UUtilityLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UUtilityLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUtilityLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUtilityLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_PRIVATE_PROPERTY_OFFSET
#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_14_PROLOG
#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Utility_UtilityLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
