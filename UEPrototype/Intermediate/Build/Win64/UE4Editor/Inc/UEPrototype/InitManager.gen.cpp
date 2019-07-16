// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Init/InitManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInitManager() {}
// Cross Module References
	UEPROTOTYPE_API UFunction* Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UFunction* Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AInitManager_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AInitManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AInitManager_InitializeUniques();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AInitManager_OnEndInitEvent();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_UEPrototype, "ReferenceDelegate__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00120000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_UEPrototype, "InitEventDispatcher__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void AInitManager::StaticRegisterNativesAInitManager()
	{
		UClass* Class = AInitManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InitializeUniques", &AInitManager::execInitializeUniques },
			{ "OnEndInitEvent", &AInitManager::execOnEndInitEvent },
			{ "SafeRefUniqueToActor", &AInitManager::execSafeRefUniqueToActor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInitManager_InitializeUniques_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInitManager_InitializeUniques_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prototpe|Init" },
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
		{ "ToolTip", "?? ?? ???? ?????\xc7\xbe??? ?? ?\xcd\xb5??? ???? ?\xca\xb1?\xc8\xad(????)?\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AInitManager_InitializeUniques_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInitManager, "InitializeUniques", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInitManager_InitializeUniques_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AInitManager_InitializeUniques_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInitManager_InitializeUniques()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AInitManager_InitializeUniques_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInitManager_OnEndInitEvent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInitManager_OnEndInitEvent_Statics::Function_MetaDataParams[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Prototype|Init" },
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
		{ "ToolTip", "InitManager?? ??\xc5\xb0?? ?\xca\xb1?\xc8\xad?? ???? ???????? ?? ?\xdf\xbb???\xc5\xb3 ?\xcc\xba?\xc6\xae?\xd4\xb4\xcf\xb4?.\nbUniquesEndInit?? true?? ??\xc8\xaf?\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AInitManager_OnEndInitEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInitManager, "OnEndInitEvent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInitManager_OnEndInitEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AInitManager_OnEndInitEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInitManager_OnEndInitEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AInitManager_OnEndInitEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics
	{
		struct InitManager_eventSafeRefUniqueToActor_Parms
		{
			FScriptDelegate EventToBind;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_EventToBind;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::NewProp_EventToBind = { UE4CodeGen_Private::EPropertyClass::Delegate, "EventToBind", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(InitManager_eventSafeRefUniqueToActor_Parms, EventToBind), Z_Construct_UDelegateFunction_UEPrototype_ReferenceDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::NewProp_EventToBind,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prototpe|Init" },
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
		{ "ToolTip", "????\xc5\xa9 ??\xc3\xbc?? ?\xca\xbf??? ?\xcf\xb4? ??\xc3\xbc?? ?????\xcf\xb0? ???\xdb\xb7????\xcf\xb5??? ?\xd5\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInitManager, "SafeRefUniqueToActor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(InitManager_eventSafeRefUniqueToActor_Parms), Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AInitManager_NoRegister()
	{
		return AInitManager::StaticClass();
	}
	struct Z_Construct_UClass_AInitManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUniquesEndInit_MetaData[];
#endif
		static void NewProp_bUniquesEndInit_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUniquesEndInit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnUniquesEndInit_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUniquesEndInit;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInitManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AInitManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInitManager_InitializeUniques, "InitializeUniques" }, // 4079432796
		{ &Z_Construct_UFunction_AInitManager_OnEndInitEvent, "OnEndInitEvent" }, // 192800171
		{ &Z_Construct_UFunction_AInitManager_SafeRefUniqueToActor, "SafeRefUniqueToActor" }, // 964912081
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInitManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Init/InitManager.h" },
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
		{ "ToolTip", "*     AInitManager?? ?? ?\xcf\xb3??? ?????\xc7\xbe??? ?\xcf\xb4?, ?\xc7\xb4? ???? ???\xdb\xbd?\n*     ?\xca\xb1?\xc8\xad?\xc7\xbe??? ?\xcf\xb4? ?\xcd\xb5??? ?\xca\xb1?\xc8\xad?\xcf\xb4? \xc5\xac?????\xd4\xb4\xcf\xb4?." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Prototype|Init" },
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
		{ "ToolTip", "????\xc5\xa9???? ???? ?\xca\xb1?\xc8\xad?? ???\xc6\xb4??? ?????\xd4\xb4\xcf\xb4?." },
	};
#endif
	void Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit_SetBit(void* Obj)
	{
		((AInitManager*)Obj)->bUniquesEndInit = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit = { UE4CodeGen_Private::EPropertyClass::Bool, "bUniquesEndInit", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000010005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AInitManager), &Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit_SetBit, METADATA_PARAMS(Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit_MetaData, ARRAY_COUNT(Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInitManager_Statics::NewProp_OnUniquesEndInit_MetaData[] = {
		{ "Category", "Prototype|Init" },
		{ "ModuleRelativePath", "Public/Init/InitManager.h" },
		{ "ToolTip", "?\xca\xb1?\xc8\xad ?\xc5\xb4????? ????\xc5\xa9 ?\xca\xb1?\xc8\xad?? ?????? ???\xc4\xbf? ?\xcc\xb0\xcd\xb5??? ?\xca\xbf??? ?\xcf\xb4?\n???\xf3\xbf\xa1\xb0? ???\xce\xb5?\xc4\xb3??\xc6\xae?\xcf\xb1? ???? ?\xcc\xba?\xc6\xae ??????\xc3\xb3?\xd4\xb4\xcf\xb4?." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AInitManager_Statics::NewProp_OnUniquesEndInit = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnUniquesEndInit", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010100010080000, 1, nullptr, STRUCT_OFFSET(AInitManager, OnUniquesEndInit), Z_Construct_UDelegateFunction_UEPrototype_InitEventDispatcher__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AInitManager_Statics::NewProp_OnUniquesEndInit_MetaData, ARRAY_COUNT(Z_Construct_UClass_AInitManager_Statics::NewProp_OnUniquesEndInit_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInitManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInitManager_Statics::NewProp_bUniquesEndInit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInitManager_Statics::NewProp_OnUniquesEndInit,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInitManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInitManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInitManager_Statics::ClassParams = {
		&AInitManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A1u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AInitManager_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AInitManager_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AInitManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AInitManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInitManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInitManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInitManager, 1306676165);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInitManager(Z_Construct_UClass_AInitManager, &AInitManager::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AInitManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInitManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
