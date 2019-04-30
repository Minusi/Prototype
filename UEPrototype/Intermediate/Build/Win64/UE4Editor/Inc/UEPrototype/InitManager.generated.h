// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UEPROTOTYPE_InitManager_generated_h
#error "InitManager.generated.h already included, missing '#pragma once' in InitManager.h"
#endif
#define UEPROTOTYPE_InitManager_generated_h

#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_13_DELEGATE \
static inline void FReferenceDelegate_DelegateWrapper(const FScriptDelegate& ReferenceDelegate) \
{ \
	ReferenceDelegate.ProcessDelegate<UObject>(NULL); \
}


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_12_DELEGATE \
static inline void FInitEventDispatcher_DelegateWrapper(const FMulticastScriptDelegate& InitEventDispatcher) \
{ \
	InitEventDispatcher.ProcessMulticastDelegate<UObject>(NULL); \
}


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEndInitEvent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEndInitEvent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSafeRefUniqueToActor) \
	{ \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_EventToBind); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SafeRefUniqueToActor(FReferenceDelegate(Z_Param_EventToBind)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitializeUniques) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InitializeUniques(); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEndInitEvent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEndInitEvent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSafeRefUniqueToActor) \
	{ \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_EventToBind); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SafeRefUniqueToActor(FReferenceDelegate(Z_Param_EventToBind)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitializeUniques) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->InitializeUniques(); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInitManager(); \
	friend struct Z_Construct_UClass_AInitManager_Statics; \
public: \
	DECLARE_CLASS(AInitManager, AActor, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AInitManager)


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAInitManager(); \
	friend struct Z_Construct_UClass_AInitManager_Statics; \
public: \
	DECLARE_CLASS(AInitManager, AActor, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AInitManager)


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AInitManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AInitManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInitManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInitManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInitManager(AInitManager&&); \
	NO_API AInitManager(const AInitManager&); \
public:


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInitManager(AInitManager&&); \
	NO_API AInitManager(const AInitManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInitManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInitManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInitManager)


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bUniquesEndInit() { return STRUCT_OFFSET(AInitManager, bUniquesEndInit); }


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_20_PROLOG
#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Module_Init_InitManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
