// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Edit/TestProceduralActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestProceduralActor() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_ATestProceduralActor_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_ATestProceduralActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_ATestProceduralActor_CreateTriangle();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void ATestProceduralActor::StaticRegisterNativesATestProceduralActor()
	{
		UClass* Class = ATestProceduralActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateTriangle", &ATestProceduralActor::execCreateTriangle },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATestProceduralActor_CreateTriangle_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATestProceduralActor_CreateTriangle_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Edit/TestProceduralActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATestProceduralActor_CreateTriangle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATestProceduralActor, "CreateTriangle", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATestProceduralActor_CreateTriangle_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATestProceduralActor_CreateTriangle_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATestProceduralActor_CreateTriangle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATestProceduralActor_CreateTriangle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATestProceduralActor_NoRegister()
	{
		return ATestProceduralActor::StaticClass();
	}
	struct Z_Construct_UClass_ATestProceduralActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestProceduralActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATestProceduralActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATestProceduralActor_CreateTriangle, "CreateTriangle" }, // 1014623017
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestProceduralActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Edit/TestProceduralActor.h" },
		{ "ModuleRelativePath", "Public/Edit/TestProceduralActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestProceduralActor_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "TestProceduralActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Edit/TestProceduralActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATestProceduralActor_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(ATestProceduralActor, Mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATestProceduralActor_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATestProceduralActor_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATestProceduralActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATestProceduralActor_Statics::NewProp_Mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestProceduralActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestProceduralActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATestProceduralActor_Statics::ClassParams = {
		&ATestProceduralActor::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ATestProceduralActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ATestProceduralActor_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ATestProceduralActor_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATestProceduralActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATestProceduralActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATestProceduralActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATestProceduralActor, 1969456167);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATestProceduralActor(Z_Construct_UClass_ATestProceduralActor, &ATestProceduralActor::StaticClass, TEXT("/Script/UEPrototype"), TEXT("ATestProceduralActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestProceduralActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
