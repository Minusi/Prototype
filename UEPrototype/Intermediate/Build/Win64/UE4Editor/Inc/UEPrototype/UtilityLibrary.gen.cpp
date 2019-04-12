// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Utility/UtilityLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUtilityLibrary() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UUtilityLibrary_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UUtilityLibrary();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent_NoRegister();
// End Cross Module References
	void UUtilityLibrary::StaticRegisterNativesUUtilityLibrary()
	{
		UClass* Class = UUtilityLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TransferComponentToOtherActor", &UUtilityLibrary::execTransferComponentToOtherActor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics
	{
		struct UtilityLibrary_eventTransferComponentToOtherActor_Parms
		{
			UActorComponent* SourceComp;
			AActor* DestActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DestActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SourceComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SourceComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_DestActor = { UE4CodeGen_Private::EPropertyClass::Object, "DestActor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(UtilityLibrary_eventTransferComponentToOtherActor_Parms, DestActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_SourceComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_SourceComp = { UE4CodeGen_Private::EPropertyClass::Object, "SourceComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(UtilityLibrary_eventTransferComponentToOtherActor_Parms, SourceComp), Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_SourceComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_SourceComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_DestActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::NewProp_SourceComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Util|Component" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Utility/UtilityLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUtilityLibrary, "TransferComponentToOtherActor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(UtilityLibrary_eventTransferComponentToOtherActor_Parms), Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUtilityLibrary_NoRegister()
	{
		return UUtilityLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UUtilityLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUtilityLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUtilityLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUtilityLibrary_TransferComponentToOtherActor, "TransferComponentToOtherActor" }, // 3818336632
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUtilityLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Utility/UtilityLibrary.h" },
		{ "ModuleRelativePath", "Public/Utility/UtilityLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUtilityLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUtilityLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUtilityLibrary_Statics::ClassParams = {
		&UUtilityLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UUtilityLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UUtilityLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUtilityLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUtilityLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUtilityLibrary, 2216747115);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUtilityLibrary(Z_Construct_UClass_UUtilityLibrary, &UUtilityLibrary::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UUtilityLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUtilityLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
