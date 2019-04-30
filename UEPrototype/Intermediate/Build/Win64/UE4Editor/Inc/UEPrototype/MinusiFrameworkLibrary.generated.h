// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class AActor;
struct FColor;
enum class EBoolean : uint8;
#ifdef UEPROTOTYPE_MinusiFrameworkLibrary_generated_h
#error "MinusiFrameworkLibrary.generated.h already included, missing '#pragma once' in MinusiFrameworkLibrary.h"
#endif
#define UEPROTOTYPE_MinusiFrameworkLibrary_generated_h

#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_RPC_WRAPPERS \
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


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
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


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMinusiFrameworkLibrary(); \
	friend struct Z_Construct_UClass_UMinusiFrameworkLibrary_Statics; \
public: \
	DECLARE_CLASS(UMinusiFrameworkLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UMinusiFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_INCLASS \
private: \
	static void StaticRegisterNativesUMinusiFrameworkLibrary(); \
	friend struct Z_Construct_UClass_UMinusiFrameworkLibrary_Statics; \
public: \
	DECLARE_CLASS(UMinusiFrameworkLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(UMinusiFrameworkLibrary)


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_STANDARD_CONSTRUCTORS \
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


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_ENHANCED_CONSTRUCTORS \
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


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_PRIVATE_PROPERTY_OFFSET
#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_27_PROLOG
#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_INCLASS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_Utility_MinusiFrameworkLibrary_h


#define FOREACH_ENUM_EBOOLEAN(op) \
	op(EBoolean::T) \
	op(EBoolean::F) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
