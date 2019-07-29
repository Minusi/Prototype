// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Utility/VPFrameworkLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVPFrameworkLibrary() {}
// Cross Module References
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UVPFrameworkLibrary_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UVPFrameworkLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AEditorWorldManager_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void UVPFrameworkLibrary::StaticRegisterNativesUVPFrameworkLibrary()
	{
		UClass* Class = UVPFrameworkLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetEditorWorldManager", &UVPFrameworkLibrary::execGetEditorWorldManager },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics
	{
		struct VPFrameworkLibrary_eventGetEditorWorldManager_Parms
		{
			const UObject* WorldContextObject;
			AEditorWorldManager* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(VPFrameworkLibrary_eventGetEditorWorldManager_Parms, ReturnValue), Z_Construct_UClass_AEditorWorldManager_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(VPFrameworkLibrary_eventGetEditorWorldManager_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_WorldContextObject_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "Category", "Utility" },
		{ "ModuleRelativePath", "Public/Utility/VPFrameworkLibrary.h" },
		{ "ToolTip", "AEditorWorldManager::GetGlobalEditorWorldManager\xec\x9d\x98 \xeb\x9e\x98\xed\x8d\xbc \xed\x95\xa8\xec\x88\x98\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4" },
		{ "UnsafeDuringActorConstruction", "true" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVPFrameworkLibrary, "GetEditorWorldManager", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(VPFrameworkLibrary_eventGetEditorWorldManager_Parms), Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVPFrameworkLibrary_NoRegister()
	{
		return UVPFrameworkLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UVPFrameworkLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVPFrameworkLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVPFrameworkLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVPFrameworkLibrary_GetEditorWorldManager, "GetEditorWorldManager" }, // 1548592041
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVPFrameworkLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Utility/VPFrameworkLibrary.h" },
		{ "ModuleRelativePath", "Public/Utility/VPFrameworkLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVPFrameworkLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVPFrameworkLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UVPFrameworkLibrary_Statics::ClassParams = {
		&UVPFrameworkLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UVPFrameworkLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UVPFrameworkLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVPFrameworkLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UVPFrameworkLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVPFrameworkLibrary, 541899359);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVPFrameworkLibrary(Z_Construct_UClass_UVPFrameworkLibrary, &UVPFrameworkLibrary::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UVPFrameworkLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVPFrameworkLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
