// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef UEPROTOTYPE_VPPlayerController_generated_h
#error "VPPlayerController.generated.h already included, missing '#pragma once' in VPPlayerController.h"
#endif
#define UEPROTOTYPE_VPPlayerController_generated_h

#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_RPC_WRAPPERS
#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_RPC_WRAPPERS_NO_PURE_DECLS
#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_EVENT_PARMS \
	struct VPPlayerController_eventReceiveFocusEvent_Parms \
	{ \
		AActor* Target; \
		float DeltaTime; \
	};


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_CALLBACK_WRAPPERS
#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVPPlayerController(); \
	friend struct Z_Construct_UClass_AVPPlayerController_Statics; \
public: \
	DECLARE_CLASS(AVPPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AVPPlayerController)


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_INCLASS \
private: \
	static void StaticRegisterNativesAVPPlayerController(); \
	friend struct Z_Construct_UClass_AVPPlayerController_Statics; \
public: \
	DECLARE_CLASS(AVPPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AVPPlayerController)


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVPPlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVPPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVPPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVPPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVPPlayerController(AVPPlayerController&&); \
	NO_API AVPPlayerController(const AVPPlayerController&); \
public:


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVPPlayerController(AVPPlayerController&&); \
	NO_API AVPPlayerController(const AVPPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVPPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVPPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVPPlayerController)


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__EditorActionMetaInputInterpreter() { return STRUCT_OFFSET(AVPPlayerController, EditorActionMetaInputInterpreter); } \
	FORCEINLINE static uint32 __PPO__EditorFocusMetaInputInterpreter() { return STRUCT_OFFSET(AVPPlayerController, EditorFocusMetaInputInterpreter); } \
	FORCEINLINE static uint32 __PPO__EditorActionMultInputInterpreter() { return STRUCT_OFFSET(AVPPlayerController, EditorActionMultInputInterpreter); }


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_24_PROLOG \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_EVENT_PARMS


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_CALLBACK_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_CALLBACK_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Core_VPPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
