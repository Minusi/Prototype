// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EMoveType : uint8;
#ifdef UEPROTOTYPE_VPDirectorPawn_generated_h
#error "VPDirectorPawn.generated.h already included, missing '#pragma once' in VPDirectorPawn.h"
#endif
#define UEPROTOTYPE_VPDirectorPawn_generated_h

#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execMoveOrbitAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_GET_OBJECT(AActor,Z_Param_OrbitTarget); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveOrbitAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ,Z_Param_OrbitTarget); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveLocalAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveLocalAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveFixedAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveFixedAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveAbsoluteAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveAbsoluteAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveAround) \
	{ \
		P_GET_ENUM(EMoveType,Z_Param_InMoveType); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_GET_OBJECT(AActor,Z_Param_InOrbitTarget); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveAround(EMoveType(Z_Param_InMoveType),Z_Param_InX,Z_Param_InY,Z_Param_InZ,Z_Param_InOrbitTarget); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execMoveOrbitAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_GET_OBJECT(AActor,Z_Param_OrbitTarget); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveOrbitAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ,Z_Param_OrbitTarget); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveLocalAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveLocalAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveFixedAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveFixedAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveAbsoluteAxis) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveAbsoluteAxis(Z_Param_InX,Z_Param_InY,Z_Param_InZ); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoveAround) \
	{ \
		P_GET_ENUM(EMoveType,Z_Param_InMoveType); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InX); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InY); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InZ); \
		P_GET_OBJECT(AActor,Z_Param_InOrbitTarget); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MoveAround(EMoveType(Z_Param_InMoveType),Z_Param_InX,Z_Param_InY,Z_Param_InZ,Z_Param_InOrbitTarget); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVPDirectorPawn(); \
	friend struct Z_Construct_UClass_AVPDirectorPawn_Statics; \
public: \
	DECLARE_CLASS(AVPDirectorPawn, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AVPDirectorPawn)


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_INCLASS \
private: \
	static void StaticRegisterNativesAVPDirectorPawn(); \
	friend struct Z_Construct_UClass_AVPDirectorPawn_Statics; \
public: \
	DECLARE_CLASS(AVPDirectorPawn, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AVPDirectorPawn)


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVPDirectorPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVPDirectorPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVPDirectorPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVPDirectorPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVPDirectorPawn(AVPDirectorPawn&&); \
	NO_API AVPDirectorPawn(const AVPDirectorPawn&); \
public:


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVPDirectorPawn(AVPDirectorPawn&&); \
	NO_API AVPDirectorPawn(const AVPDirectorPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVPDirectorPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVPDirectorPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVPDirectorPawn)


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RootCollision() { return STRUCT_OFFSET(AVPDirectorPawn, RootCollision); } \
	FORCEINLINE static uint32 __PPO__VRRootTransform() { return STRUCT_OFFSET(AVPDirectorPawn, VRRootTransform); } \
	FORCEINLINE static uint32 __PPO__VRCamera() { return STRUCT_OFFSET(AVPDirectorPawn, VRCamera); } \
	FORCEINLINE static uint32 __PPO__MotionController() { return STRUCT_OFFSET(AVPDirectorPawn, MotionController); } \
	FORCEINLINE static uint32 __PPO__MCWidget() { return STRUCT_OFFSET(AVPDirectorPawn, MCWidget); } \
	FORCEINLINE static uint32 __PPO__FloatingPawnMovement() { return STRUCT_OFFSET(AVPDirectorPawn, FloatingPawnMovement); } \
	FORCEINLINE static uint32 __PPO__CurrentMoveType() { return STRUCT_OFFSET(AVPDirectorPawn, CurrentMoveType); } \
	FORCEINLINE static uint32 __PPO__FixedAxis() { return STRUCT_OFFSET(AVPDirectorPawn, FixedAxis); }


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_50_PROLOG
#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h_53_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Core_VPDirectorPawn_h


#define FOREACH_ENUM_EMOVETYPE(op) \
	op(EMoveType::MT_LOCALAXIS) \
	op(EMoveType::MT_FIXEDAXIS) \
	op(EMoveType::MT_ABSOLUTEAXIS) \
	op(EMoveType::MT_ORBITAXIS) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
