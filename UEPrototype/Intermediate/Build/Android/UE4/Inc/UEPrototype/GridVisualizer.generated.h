// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLinearColor;
#ifdef UEPROTOTYPE_GridVisualizer_generated_h
#error "GridVisualizer.generated.h already included, missing '#pragma once' in GridVisualizer.h"
#endif
#define UEPROTOTYPE_GridVisualizer_generated_h

#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBeginGridTracing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BeginGridTracing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfigureGridOpacity) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InGridOpacity); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConfigureGridOpacity(Z_Param_InGridOpacity); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfigureGridFadeDistance) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InFadeLength); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConfigureGridFadeDistance(Z_Param_InFadeLength); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfigureGridScale) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InGridScale); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConfigureGridScale(Z_Param_InGridScale); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execChangeGridColor) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_InColor); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InGridIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ChangeGridColor(Z_Param_InColor,Z_Param_InGridIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleTracing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ToggleTracing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleGridView) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ToggleGridView(); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBeginGridTracing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BeginGridTracing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfigureGridOpacity) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InGridOpacity); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConfigureGridOpacity(Z_Param_InGridOpacity); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfigureGridFadeDistance) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InFadeLength); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConfigureGridFadeDistance(Z_Param_InFadeLength); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfigureGridScale) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InGridScale); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ConfigureGridScale(Z_Param_InGridScale); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execChangeGridColor) \
	{ \
		P_GET_STRUCT(FLinearColor,Z_Param_InColor); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InGridIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ChangeGridColor(Z_Param_InColor,Z_Param_InGridIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleTracing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ToggleTracing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleGridView) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ToggleGridView(); \
		P_NATIVE_END; \
	}


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGridVisualizer(); \
	friend struct Z_Construct_UClass_AGridVisualizer_Statics; \
public: \
	DECLARE_CLASS(AGridVisualizer, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AGridVisualizer)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_INCLASS \
private: \
	static void StaticRegisterNativesAGridVisualizer(); \
	friend struct Z_Construct_UClass_AGridVisualizer_Statics; \
public: \
	DECLARE_CLASS(AGridVisualizer, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEPrototype"), NO_API) \
	DECLARE_SERIALIZER(AGridVisualizer)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGridVisualizer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGridVisualizer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridVisualizer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridVisualizer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGridVisualizer(AGridVisualizer&&); \
	NO_API AGridVisualizer(const AGridVisualizer&); \
public:


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGridVisualizer(AGridVisualizer&&); \
	NO_API AGridVisualizer(const AGridVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGridVisualizer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGridVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGridVisualizer)


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GridComp() { return STRUCT_OFFSET(AGridVisualizer, GridComp); } \
	FORCEINLINE static uint32 __PPO__MITemplate() { return STRUCT_OFFSET(AGridVisualizer, MITemplate); } \
	FORCEINLINE static uint32 __PPO__MIDTemplate() { return STRUCT_OFFSET(AGridVisualizer, MIDTemplate); } \
	FORCEINLINE static uint32 __PPO__TraceTimerInterval() { return STRUCT_OFFSET(AGridVisualizer, TraceTimerInterval); } \
	FORCEINLINE static uint32 __PPO__CachedPlayer() { return STRUCT_OFFSET(AGridVisualizer, CachedPlayer); }


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_23_PROLOG
#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_RPC_WRAPPERS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_INCLASS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_PRIVATE_PROPERTY_OFFSET \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_INCLASS_NO_PURE_DECLS \
	UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_UEPrototype_Public_BuiltIn_Grid_GridVisualizer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
