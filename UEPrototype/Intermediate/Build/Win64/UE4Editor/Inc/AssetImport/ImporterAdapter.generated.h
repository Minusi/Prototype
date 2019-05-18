// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ASSETIMPORT_ImporterAdapter_generated_h
#error "ImporterAdapter.generated.h already included, missing '#pragma once' in ImporterAdapter.h"
#endif
#define ASSETIMPORT_ImporterAdapter_generated_h

#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_RPC_WRAPPERS
#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UImporterAdapter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UImporterAdapter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UImporterAdapter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UImporterAdapter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UImporterAdapter(UImporterAdapter&&); \
	NO_API UImporterAdapter(const UImporterAdapter&); \
public:


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UImporterAdapter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UImporterAdapter(UImporterAdapter&&); \
	NO_API UImporterAdapter(const UImporterAdapter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UImporterAdapter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UImporterAdapter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UImporterAdapter)


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUImporterAdapter(); \
	friend struct Z_Construct_UClass_UImporterAdapter_Statics; \
public: \
	DECLARE_CLASS(UImporterAdapter, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/AssetImport"), NO_API) \
	DECLARE_SERIALIZER(UImporterAdapter)


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_GENERATED_UINTERFACE_BODY() \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_GENERATED_UINTERFACE_BODY() \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IImporterAdapter() {} \
public: \
	typedef UImporterAdapter UClassType; \
	typedef IImporterAdapter ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_INCLASS_IINTERFACE \
protected: \
	virtual ~IImporterAdapter() {} \
public: \
	typedef UImporterAdapter UClassType; \
	typedef IImporterAdapter ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_20_PROLOG
#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_RPC_WRAPPERS \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	UEPrototype_Source_AssetImport_Public_ImporterAdapter_h_23_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UEPrototype_Source_AssetImport_Public_ImporterAdapter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
