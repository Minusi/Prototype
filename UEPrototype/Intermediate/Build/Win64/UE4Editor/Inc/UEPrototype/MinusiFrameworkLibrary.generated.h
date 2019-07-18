// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
struct FVector;
struct FHitResult;
class UObject;
class AActor;
struct FTransform;
struct FVector2D;
struct FColor;
enum class EBoolean : uint8;
#ifdef UEPROTOTYPE_MinusiFrameworkLibrary_generated_h
#error "MinusiFrameworkLibrary.generated.h already included, missing '#pragma once' in MinusiFrameworkLibrary.h"
#endif
#define UEPROTOTYPE_MinusiFrameworkLibrary_generated_h

#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTraceComponent) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_TheComp); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitOut); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::TraceComponent(Z_Param_TheComp,Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_HitOut); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTraceWithIgnoreArray) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_ActorsToIgnore); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitOut); \
		P_GET_PROPERTY(UByteProperty,Z_Param_CollisionChannel); \
		P_GET_UBOOL(Z_Param_ReturnPhysMat); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::TraceWithIgnoreArray(Z_Param_WorldContextObject,Z_Param_Out_ActorsToIgnore,Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_HitOut,ECollisionChannel(Z_Param_CollisionChannel),Z_Param_ReturnPhysMat); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrace) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(AActor,Z_Param_ActorToIgnore); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitOut); \
		P_GET_PROPERTY(UByteProperty,Z_Param_CollisionChannel); \
		P_GET_UBOOL(Z_Param_ReturnPhysMat); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::Trace(Z_Param_WorldContextObject,Z_Param_ActorToIgnore,Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_HitOut,ECollisionChannel(Z_Param_CollisionChannel),Z_Param_ReturnPhysMat); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTransformToTraceHitResult) \
	{ \
		P_GET_STRUCT(FHitResult,Z_Param_HitResult); \
		P_GET_UBOOL(Z_Param_IsHit); \
		P_GET_STRUCT(FVector,Z_Param_ActorLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=UMinusiFrameworkLibrary::GetTransformToTraceHitResult(Z_Param_HitResult,Z_Param_IsHit,Z_Param_ActorLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAngleBetweenTwoVector) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_A); \
		P_GET_STRUCT(FVector2D,Z_Param_B); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Angle); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::GetAngleBetweenTwoVector(Z_Param_A,Z_Param_B,Z_Param_Out_Angle); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSpecificAllActorWithTag) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_GET_OBJECT(UClass,Z_Param_ActorToFind); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AActor*>*)Z_Param__Result=UMinusiFrameworkLibrary::GetSpecificAllActorWithTag(Z_Param_WorldContextObject,Z_Param_Tag,Z_Param_ActorToFind); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSpecificFirstActorWithTag) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_GET_OBJECT(UClass,Z_Param_ActorToFind); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=UMinusiFrameworkLibrary::GetSpecificFirstActorWithTag(Z_Param_WorldContextObject,Z_Param_Tag,Z_Param_ActorToFind); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execScreenLongLog) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_GET_STRUCT(FColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::ScreenLongLog(Z_Param_Message,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execScreenLog) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_GET_STRUCT(FColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::ScreenLog(Z_Param_Message,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execScreenShortLog) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_GET_STRUCT(FColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::ScreenShortLog(Z_Param_Message,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofClass_Exec) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UClass,Z_Param_Compare); \
		P_GET_ENUM_REF(EBoolean,Z_Param_Out_Execs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::IsTypeofClass_Exec(Z_Param_Object,Z_Param_Compare,(EBoolean&)(Z_Param_Out_Execs)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofClass) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UClass,Z_Param_Compare); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::IsTypeofClass(Z_Param_Object,Z_Param_Compare); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofObject_Exec) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UObject,Z_Param_Compare); \
		P_GET_ENUM_REF(EBoolean,Z_Param_Out_Execs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::IsTypeofObject_Exec(Z_Param_Object,Z_Param_Compare,(EBoolean&)(Z_Param_Out_Execs)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UObject,Z_Param_Compare); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::IsTypeofObject(Z_Param_Object,Z_Param_Compare); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofActor_Exec) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_GET_OBJECT(AActor,Z_Param_Compare); \
		P_GET_ENUM_REF(EBoolean,Z_Param_Out_Execs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::IsTypeofActor_Exec(Z_Param_Actor,Z_Param_Compare,(EBoolean&)(Z_Param_Out_Execs)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_GET_OBJECT(AActor,Z_Param_Compare); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::IsTypeofActor(Z_Param_Actor,Z_Param_Compare); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTraceComponent) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_TheComp); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitOut); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::TraceComponent(Z_Param_TheComp,Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_HitOut); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTraceWithIgnoreArray) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_ActorsToIgnore); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitOut); \
		P_GET_PROPERTY(UByteProperty,Z_Param_CollisionChannel); \
		P_GET_UBOOL(Z_Param_ReturnPhysMat); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::TraceWithIgnoreArray(Z_Param_WorldContextObject,Z_Param_Out_ActorsToIgnore,Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_HitOut,ECollisionChannel(Z_Param_CollisionChannel),Z_Param_ReturnPhysMat); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrace) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(AActor,Z_Param_ActorToIgnore); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Start); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_End); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitOut); \
		P_GET_PROPERTY(UByteProperty,Z_Param_CollisionChannel); \
		P_GET_UBOOL(Z_Param_ReturnPhysMat); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::Trace(Z_Param_WorldContextObject,Z_Param_ActorToIgnore,Z_Param_Out_Start,Z_Param_Out_End,Z_Param_Out_HitOut,ECollisionChannel(Z_Param_CollisionChannel),Z_Param_ReturnPhysMat); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTransformToTraceHitResult) \
	{ \
		P_GET_STRUCT(FHitResult,Z_Param_HitResult); \
		P_GET_UBOOL(Z_Param_IsHit); \
		P_GET_STRUCT(FVector,Z_Param_ActorLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=UMinusiFrameworkLibrary::GetTransformToTraceHitResult(Z_Param_HitResult,Z_Param_IsHit,Z_Param_ActorLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAngleBetweenTwoVector) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param_A); \
		P_GET_STRUCT(FVector2D,Z_Param_B); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_Angle); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::GetAngleBetweenTwoVector(Z_Param_A,Z_Param_B,Z_Param_Out_Angle); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSpecificAllActorWithTag) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_GET_OBJECT(UClass,Z_Param_ActorToFind); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AActor*>*)Z_Param__Result=UMinusiFrameworkLibrary::GetSpecificAllActorWithTag(Z_Param_WorldContextObject,Z_Param_Tag,Z_Param_ActorToFind); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSpecificFirstActorWithTag) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_GET_OBJECT(UClass,Z_Param_ActorToFind); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=UMinusiFrameworkLibrary::GetSpecificFirstActorWithTag(Z_Param_WorldContextObject,Z_Param_Tag,Z_Param_ActorToFind); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execScreenLongLog) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_GET_STRUCT(FColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::ScreenLongLog(Z_Param_Message,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execScreenLog) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_GET_STRUCT(FColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::ScreenLog(Z_Param_Message,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execScreenShortLog) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Message); \
		P_GET_STRUCT(FColor,Z_Param_Color); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::ScreenShortLog(Z_Param_Message,Z_Param_Color); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofClass_Exec) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UClass,Z_Param_Compare); \
		P_GET_ENUM_REF(EBoolean,Z_Param_Out_Execs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::IsTypeofClass_Exec(Z_Param_Object,Z_Param_Compare,(EBoolean&)(Z_Param_Out_Execs)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofClass) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UClass,Z_Param_Compare); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::IsTypeofClass(Z_Param_Object,Z_Param_Compare); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofObject_Exec) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UObject,Z_Param_Compare); \
		P_GET_ENUM_REF(EBoolean,Z_Param_Out_Execs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::IsTypeofObject_Exec(Z_Param_Object,Z_Param_Compare,(EBoolean&)(Z_Param_Out_Execs)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_Object); \
		P_GET_OBJECT(UObject,Z_Param_Compare); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::IsTypeofObject(Z_Param_Object,Z_Param_Compare); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofActor_Exec) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_GET_OBJECT(AActor,Z_Param_Compare); \
		P_GET_ENUM_REF(EBoolean,Z_Param_Out_Execs); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UMinusiFrameworkLibrary::IsTypeofActor_Exec(Z_Param_Actor,Z_Param_Compare,(EBoolean&)(Z_Param_Out_Execs)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsTypeofActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_GET_OBJECT(AActor,Z_Param_Compare); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UMinusiFrameworkLibrary::IsTypeofActor(Z_Param_Actor,Z_Param_Compare); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMinusiFrameworkLibrary(); \
	friend struct Z_Construct_UClass_UMinusiFrameworkLibrary_Statics; \
public: \
	DECLARE_CLASS(UMinusiFrameworkLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UMinusiFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_INCLASS \
private: \
	static void StaticRegisterNativesUMinusiFrameworkLibrary(); \
	friend struct Z_Construct_UClass_UMinusiFrameworkLibrary_Statics; \
public: \
	DECLARE_CLASS(UMinusiFrameworkLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UMinusiFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMinusiFrameworkLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMinusiFrameworkLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMinusiFrameworkLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMinusiFrameworkLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMinusiFrameworkLibrary(UMinusiFrameworkLibrary&&); \
	NO_API UMinusiFrameworkLibrary(const UMinusiFrameworkLibrary&); \
public:


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMinusiFrameworkLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMinusiFrameworkLibrary(UMinusiFrameworkLibrary&&); \
	NO_API UMinusiFrameworkLibrary(const UMinusiFrameworkLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMinusiFrameworkLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMinusiFrameworkLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMinusiFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_PRIVATE_PROPERTY_OFFSET
#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_PROLOG
#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h


#define FOREACH_ENUM_EBOOLEAN(op) \
	op(EBoolean::T) \
	op(EBoolean::F) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
