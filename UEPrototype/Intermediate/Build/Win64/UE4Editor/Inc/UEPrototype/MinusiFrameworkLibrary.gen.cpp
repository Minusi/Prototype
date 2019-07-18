// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Utility/MinusiFrameworkLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMinusiFrameworkLibrary() {}
// Cross Module References
	UEPROTOTYPE_API UEnum* Z_Construct_UEnum_UEPrototype_EBoolean();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UMinusiFrameworkLibrary_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_UMinusiFrameworkLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray();
// End Cross Module References
	static UEnum* EBoolean_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_UEPrototype_EBoolean, Z_Construct_UPackage__Script_UEPrototype(), TEXT("EBoolean"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EBoolean(EBoolean_StaticEnum, TEXT("/Script/UEPrototype"), TEXT("EBoolean"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_UEPrototype_EBoolean_CRC() { return 4224400082U; }
	UEnum* Z_Construct_UEnum_UEPrototype_EBoolean()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_UEPrototype();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EBoolean"), 0, Get_Z_Construct_UEnum_UEPrototype_EBoolean_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EBoolean::T", (int64)EBoolean::T },
				{ "EBoolean::F", (int64)EBoolean::F },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "F.DisplayName", "False" },
				{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
				{ "T.DisplayName", "True" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_UEPrototype,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EBoolean",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EBoolean",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UMinusiFrameworkLibrary::StaticRegisterNativesUMinusiFrameworkLibrary()
	{
		UClass* Class = UMinusiFrameworkLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAngleBetweenTwoVector", &UMinusiFrameworkLibrary::execGetAngleBetweenTwoVector },
			{ "GetSpecificAllActorWithTag", &UMinusiFrameworkLibrary::execGetSpecificAllActorWithTag },
			{ "GetSpecificFirstActorWithTag", &UMinusiFrameworkLibrary::execGetSpecificFirstActorWithTag },
			{ "GetTransformToTraceHitResult", &UMinusiFrameworkLibrary::execGetTransformToTraceHitResult },
			{ "IsTypeofActor", &UMinusiFrameworkLibrary::execIsTypeofActor },
			{ "IsTypeofActor_Exec", &UMinusiFrameworkLibrary::execIsTypeofActor_Exec },
			{ "IsTypeofClass", &UMinusiFrameworkLibrary::execIsTypeofClass },
			{ "IsTypeofClass_Exec", &UMinusiFrameworkLibrary::execIsTypeofClass_Exec },
			{ "IsTypeofObject", &UMinusiFrameworkLibrary::execIsTypeofObject },
			{ "IsTypeofObject_Exec", &UMinusiFrameworkLibrary::execIsTypeofObject_Exec },
			{ "ScreenLog", &UMinusiFrameworkLibrary::execScreenLog },
			{ "ScreenLongLog", &UMinusiFrameworkLibrary::execScreenLongLog },
			{ "ScreenShortLog", &UMinusiFrameworkLibrary::execScreenShortLog },
			{ "Trace", &UMinusiFrameworkLibrary::execTrace },
			{ "TraceComponent", &UMinusiFrameworkLibrary::execTraceComponent },
			{ "TraceWithIgnoreArray", &UMinusiFrameworkLibrary::execTraceWithIgnoreArray },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics
	{
		struct MinusiFrameworkLibrary_eventGetAngleBetweenTwoVector_Parms
		{
			FVector2D A;
			FVector2D B;
			float Angle;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Angle;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_B;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_A;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::NewProp_Angle = { UE4CodeGen_Private::EPropertyClass::Float, "Angle", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetAngleBetweenTwoVector_Parms, Angle), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::NewProp_B = { UE4CodeGen_Private::EPropertyClass::Struct, "B", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetAngleBetweenTwoVector_Parms, B), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::NewProp_A = { UE4CodeGen_Private::EPropertyClass::Struct, "A", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetAngleBetweenTwoVector_Parms, A), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::NewProp_Angle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::NewProp_B,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::NewProp_A,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi|Math" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "GetAngleBetweenTwoVector", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(MinusiFrameworkLibrary_eventGetAngleBetweenTwoVector_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics
	{
		struct MinusiFrameworkLibrary_eventGetSpecificAllActorWithTag_Parms
		{
			const UObject* WorldContextObject;
			FName Tag;
			TSubclassOf<AActor>  ActorToFind;
			TArray<AActor*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ActorToFind;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Tag;
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
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificAllActorWithTag_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_ActorToFind = { UE4CodeGen_Private::EPropertyClass::Class, "ActorToFind", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificAllActorWithTag_Parms, ActorToFind), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_Tag = { UE4CodeGen_Private::EPropertyClass::Name, "Tag", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificAllActorWithTag_Parms, Tag), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificAllActorWithTag_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_WorldContextObject_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_ActorToFind,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_Tag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DeterminesOutputType", "ActorToFind" },
		{ "Keywords", "GetTag" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xed\x83\x80\xec\x9e\x85\xec\x9d\x98 \xeb\xaa\xa8\xeb\x93\xa0 \xec\x95\xa1\xed\x84\xb0\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4. \xec\x9d\xb4\xed\x9b\x84 \xed\x98\x95\xeb\xb3\x80\xed\x99\x98\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\x98\xec\x97\xac \xed\x8a\xb9\xec\xa0\x95 \xed\x83\x80\xec\x9e\x85\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb3\x80\xed\x99\x98\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xec\x8a\xb5\xeb\x8b\x88\xeb\x8b\xa4." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "GetSpecificAllActorWithTag", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(MinusiFrameworkLibrary_eventGetSpecificAllActorWithTag_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics
	{
		struct MinusiFrameworkLibrary_eventGetSpecificFirstActorWithTag_Parms
		{
			const UObject* WorldContextObject;
			FName Tag;
			TSubclassOf<AActor>  ActorToFind;
			AActor* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ActorToFind;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Tag;
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
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificFirstActorWithTag_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_ActorToFind = { UE4CodeGen_Private::EPropertyClass::Class, "ActorToFind", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificFirstActorWithTag_Parms, ActorToFind), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_Tag = { UE4CodeGen_Private::EPropertyClass::Name, "Tag", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificFirstActorWithTag_Parms, Tag), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetSpecificFirstActorWithTag_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_WorldContextObject_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_ActorToFind,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_Tag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DeterminesOutputType", "ActorToFind" },
		{ "Keywords", "GetTag" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xed\x83\x80\xec\x9e\x85\xec\x9d\x98 \xec\xb2\xab \xeb\xb2\x88\xec\xa7\xb8 \xec\x95\xa1\xed\x84\xb0\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4. \xec\x9d\xb4\xed\x9b\x84 \xed\x98\x95\xeb\xb3\x80\xed\x99\x98\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\x98\xec\x97\xac \xed\x8a\xb9\xec\xa0\x95 \xed\x83\x80\xec\x9e\x85\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb3\x80\xed\x99\x98\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xec\x8a\xb5\xeb\x8b\x88\xeb\x8b\xa4." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "GetSpecificFirstActorWithTag", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(MinusiFrameworkLibrary_eventGetSpecificFirstActorWithTag_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics
	{
		struct MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms
		{
			FHitResult HitResult;
			bool IsHit;
			FVector ActorLocation;
			FTransform ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActorLocation;
		static void NewProp_IsHit_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsHit;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_ActorLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "ActorLocation", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms, ActorLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_IsHit_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms*)Obj)->IsHit = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_IsHit = { UE4CodeGen_Private::EPropertyClass::Bool, "IsHit", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_IsHit_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_HitResult = { UE4CodeGen_Private::EPropertyClass::Struct, "HitResult", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010008000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_ActorLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_IsHit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::NewProp_HitResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi|Trace" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "GetTransformToTraceHitResult", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(MinusiFrameworkLibrary_eventGetTransformToTraceHitResult_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics
	{
		struct MinusiFrameworkLibrary_eventIsTypeofActor_Parms
		{
			AActor* Actor;
			AActor* Compare;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Compare_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Compare;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventIsTypeofActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventIsTypeofActor_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Compare_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Compare = { UE4CodeGen_Private::EPropertyClass::Object, "Compare", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofActor_Parms, Compare), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Compare_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Compare_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Actor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Actor_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Actor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Compare,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::NewProp_Actor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DisplayName", "IsTypeofActor" },
		{ "Keywords", "==Actor" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81 \xec\x95\xa1\xed\x84\xb0\xec\x99\x80 UClass\xeb\xa5\xbc \xeb\xb9\x84\xea\xb5\x90\xed\x95\x9c \xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "IsTypeofActor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(MinusiFrameworkLibrary_eventIsTypeofActor_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics
	{
		struct MinusiFrameworkLibrary_eventIsTypeofActor_Exec_Parms
		{
			AActor* Actor;
			AActor* Compare;
			EBoolean Execs;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Execs;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Execs_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Compare_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Compare;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Execs = { UE4CodeGen_Private::EPropertyClass::Enum, "Execs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofActor_Exec_Parms, Execs), Z_Construct_UEnum_UEPrototype_EBoolean, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Execs_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Compare_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Compare = { UE4CodeGen_Private::EPropertyClass::Object, "Compare", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofActor_Exec_Parms, Compare), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Compare_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Compare_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Actor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofActor_Exec_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Actor_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Actor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Execs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Execs_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Compare,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::NewProp_Actor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DisplayName", "IsTypeofActor" },
		{ "ExpandEnumAsExecs", "Execs" },
		{ "Keywords", "==Actor" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81 \xec\x95\xa1\xed\x84\xb0\xec\x99\x80 UClass\xeb\xa5\xbc \xeb\xb9\x84\xea\xb5\x90\xed\x95\x9c \xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc Exec \xec\xb6\x9c\xeb\xa0\xa5\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "IsTypeofActor_Exec", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(MinusiFrameworkLibrary_eventIsTypeofActor_Exec_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics
	{
		struct MinusiFrameworkLibrary_eventIsTypeofClass_Parms
		{
			UObject* Object;
			const TSubclassOf<UObject>  Compare;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Compare_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Compare;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventIsTypeofClass_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventIsTypeofClass_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Compare_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Compare = { UE4CodeGen_Private::EPropertyClass::Class, "Compare", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofClass_Parms, Compare), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Compare_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Compare_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofClass_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Object_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Object_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Compare,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DisplayName", "IsTypeofClass" },
		{ "Keywords", "==Class" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81 \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xec\x99\x80 UClass\xeb\xa5\xbc \xeb\xb9\x84\xea\xb5\x90\xed\x95\x9c \xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "IsTypeofClass", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(MinusiFrameworkLibrary_eventIsTypeofClass_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics
	{
		struct MinusiFrameworkLibrary_eventIsTypeofClass_Exec_Parms
		{
			UObject* Object;
			const TSubclassOf<UObject>  Compare;
			EBoolean Execs;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Execs;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Execs_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Compare_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Compare;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Execs = { UE4CodeGen_Private::EPropertyClass::Enum, "Execs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofClass_Exec_Parms, Execs), Z_Construct_UEnum_UEPrototype_EBoolean, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Execs_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Compare_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Compare = { UE4CodeGen_Private::EPropertyClass::Class, "Compare", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0014000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofClass_Exec_Parms, Compare), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Compare_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Compare_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofClass_Exec_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Object_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Object_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Execs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Execs_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Compare,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DisplayName", "IsTypeofClass" },
		{ "ExpandEnumAsExecs", "Execs" },
		{ "Keywords", "==Class" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81 \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xec\x99\x80 UClass\xeb\xa5\xbc \xeb\xb9\x84\xea\xb5\x90\xed\x95\x9c \xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc Exec \xec\xb6\x9c\xeb\xa0\xa5\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "IsTypeofClass_Exec", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(MinusiFrameworkLibrary_eventIsTypeofClass_Exec_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics
	{
		struct MinusiFrameworkLibrary_eventIsTypeofObject_Parms
		{
			UObject* Object;
			UObject* Compare;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Compare_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Compare;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventIsTypeofObject_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventIsTypeofObject_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Compare_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Compare = { UE4CodeGen_Private::EPropertyClass::Object, "Compare", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofObject_Parms, Compare), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Compare_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Compare_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofObject_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Object_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Object_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Compare,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DisplayName", "IsTypeofObject" },
		{ "Keywords", "==Object" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81 \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xec\x99\x80 UClass\xeb\xa5\xbc \xeb\xb9\x84\xea\xb5\x90\xed\x95\x9c \xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "IsTypeofObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(MinusiFrameworkLibrary_eventIsTypeofObject_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics
	{
		struct MinusiFrameworkLibrary_eventIsTypeofObject_Exec_Parms
		{
			UObject* Object;
			UObject* Compare;
			EBoolean Execs;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Execs;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Execs_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Compare_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Compare;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Object_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Execs = { UE4CodeGen_Private::EPropertyClass::Enum, "Execs", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofObject_Exec_Parms, Execs), Z_Construct_UEnum_UEPrototype_EBoolean, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Execs_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Compare_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Compare = { UE4CodeGen_Private::EPropertyClass::Object, "Compare", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofObject_Exec_Parms, Compare), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Compare_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Compare_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Object_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventIsTypeofObject_Exec_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Object_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Object_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Execs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Execs_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Compare,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::NewProp_Object,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "DisplayName", "IsTypeofObject" },
		{ "ExpandEnumAsExecs", "Execs" },
		{ "Keywords", "==Object" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81 \xec\x96\xb8\xeb\xa6\xac\xec\x96\xbc \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xec\x99\x80 UClass\xeb\xa5\xbc \xeb\xb9\x84\xea\xb5\x90\xed\x95\x9c \xea\xb2\xb0\xea\xb3\xbc\xeb\xa5\xbc Exec \xec\xb6\x9c\xeb\xa0\xa5\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\x98\xed\x99\x98\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "IsTypeofObject_Exec", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(MinusiFrameworkLibrary_eventIsTypeofObject_Exec_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics
	{
		struct MinusiFrameworkLibrary_eventScreenLog_Parms
		{
			FString Message;
			FColor Color;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Color_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventScreenLog_Parms, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Color_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventScreenLog_Parms, Message), METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Message_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::NewProp_Message,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "CPP_Default_Color", "(R=243,G=156,B=18,A=255)" },
		{ "Keywords", "Log" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "Print String\xec\x9d\x98 \xea\xb0\x84\xec\x86\x8c\xed\x99\x94\xeb\x90\x9c \xeb\xa1\x9c\xea\xb7\xb8 \xeb\xb2\x84\xec\xa0\x84\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4. 5\xec\xb4\x88\xea\xb0\x84 \xec\xa7\x80\xec\x86\x8d\xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "ScreenLog", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(MinusiFrameworkLibrary_eventScreenLog_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics
	{
		struct MinusiFrameworkLibrary_eventScreenLongLog_Parms
		{
			FString Message;
			FColor Color;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Color_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventScreenLongLog_Parms, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Color_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventScreenLongLog_Parms, Message), METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Message_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::NewProp_Message,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "CPP_Default_Color", "(R=243,G=156,B=18,A=255)" },
		{ "Keywords", "LLog" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "Print String\xec\x9d\x98 \xea\xb0\x84\xec\x86\x8c\xed\x99\x94\xeb\x90\x9c \xeb\xa1\x9c\xea\xb7\xb8 \xeb\xb2\x84\xec\xa0\x84\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4. 10\xec\xb4\x88\xea\xb0\x84 \xec\xa7\x80\xec\x86\x8d\xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "ScreenLongLog", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(MinusiFrameworkLibrary_eventScreenLongLog_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics
	{
		struct MinusiFrameworkLibrary_eventScreenShortLog_Parms
		{
			FString Message;
			FColor Color;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Color_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventScreenShortLog_Parms, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Color_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Color_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Message = { UE4CodeGen_Private::EPropertyClass::Str, "Message", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventScreenShortLog_Parms, Message), METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Message_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Message_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Color,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::NewProp_Message,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi" },
		{ "CPP_Default_Color", "(R=243,G=156,B=18,A=255)" },
		{ "Keywords", "SLog" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "Print String\xec\x9d\x98 \xea\xb0\x84\xec\x86\x8c\xed\x99\x94\xeb\x90\x9c \xeb\xa1\x9c\xea\xb7\xb8 \xeb\xb2\x84\xec\xa0\x84\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4. 2\xec\xb4\x88\xea\xb0\x84 \xec\xa7\x80\xec\x86\x8d\xeb\x90\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "ScreenShortLog", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04822401, sizeof(MinusiFrameworkLibrary_eventScreenShortLog_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics
	{
		struct MinusiFrameworkLibrary_eventTrace_Parms
		{
			UObject* WorldContextObject;
			AActor* ActorToIgnore;
			FVector Start;
			FVector End;
			FHitResult HitOut;
			TEnumAsByte<ECollisionChannel> CollisionChannel;
			bool ReturnPhysMat;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static void NewProp_ReturnPhysMat_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnPhysMat;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitOut;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_End_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_End;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Start_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorToIgnore;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventTrace_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventTrace_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnPhysMat_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventTrace_Parms*)Obj)->ReturnPhysMat = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnPhysMat = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnPhysMat", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventTrace_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnPhysMat_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_CollisionChannel = { UE4CodeGen_Private::EPropertyClass::Byte, "CollisionChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTrace_Parms, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_HitOut = { UE4CodeGen_Private::EPropertyClass::Struct, "HitOut", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010008000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTrace_Parms, HitOut), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_End_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_End = { UE4CodeGen_Private::EPropertyClass::Struct, "End", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTrace_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_End_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_End_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_Start_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_Start = { UE4CodeGen_Private::EPropertyClass::Struct, "Start", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTrace_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_Start_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_Start_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ActorToIgnore = { UE4CodeGen_Private::EPropertyClass::Object, "ActorToIgnore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTrace_Parms, ActorToIgnore), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTrace_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ReturnPhysMat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_CollisionChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_HitOut,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_End,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_Start,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_ActorToIgnore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi|Trace" },
		{ "CPP_Default_CollisionChannel", "ECC_Pawn" },
		{ "CPP_Default_ReturnPhysMat", "false" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "Trace", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(MinusiFrameworkLibrary_eventTrace_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics
	{
		struct MinusiFrameworkLibrary_eventTraceComponent_Parms
		{
			UPrimitiveComponent* TheComp;
			FVector Start;
			FVector End;
			FHitResult HitOut;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitOut;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_End_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_End;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Start_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Start;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TheComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TheComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventTraceComponent_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventTraceComponent_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_HitOut = { UE4CodeGen_Private::EPropertyClass::Struct, "HitOut", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010008000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceComponent_Parms, HitOut), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_End_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_End = { UE4CodeGen_Private::EPropertyClass::Struct, "End", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceComponent_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_End_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_End_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_Start_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_Start = { UE4CodeGen_Private::EPropertyClass::Struct, "Start", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceComponent_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_Start_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_Start_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_TheComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_TheComp = { UE4CodeGen_Private::EPropertyClass::Object, "TheComp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceComponent_Parms, TheComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_TheComp_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_TheComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_HitOut,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_End,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_Start,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::NewProp_TheComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi|Trace" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "TraceComponent", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(MinusiFrameworkLibrary_eventTraceComponent_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics
	{
		struct MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms
		{
			UObject* WorldContextObject;
			TArray<AActor*> ActorsToIgnore;
			FVector Start;
			FVector End;
			FHitResult HitOut;
			TEnumAsByte<ECollisionChannel> CollisionChannel;
			bool ReturnPhysMat;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static void NewProp_ReturnPhysMat_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnPhysMat;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_HitOut;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_End_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_End;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Start_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Start;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorsToIgnore;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorsToIgnore_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnPhysMat_SetBit(void* Obj)
	{
		((MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms*)Obj)->ReturnPhysMat = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnPhysMat = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnPhysMat", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms), &Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnPhysMat_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_CollisionChannel = { UE4CodeGen_Private::EPropertyClass::Byte, "CollisionChannel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_HitOut = { UE4CodeGen_Private::EPropertyClass::Struct, "HitOut", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010008000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms, HitOut), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_End_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_End = { UE4CodeGen_Private::EPropertyClass::Struct, "End", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_End_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_End_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_Start_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_Start = { UE4CodeGen_Private::EPropertyClass::Struct, "Start", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_Start_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_Start_MetaData)) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ActorsToIgnore = { UE4CodeGen_Private::EPropertyClass::Array, "ActorsToIgnore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms, ActorsToIgnore), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ActorsToIgnore_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ActorsToIgnore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ReturnPhysMat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_CollisionChannel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_HitOut,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_End,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_Start,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ActorsToIgnore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_ActorsToIgnore_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Minusi|Trace" },
		{ "CPP_Default_CollisionChannel", "ECC_Pawn" },
		{ "CPP_Default_ReturnPhysMat", "false" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMinusiFrameworkLibrary, "TraceWithIgnoreArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14C22401, sizeof(MinusiFrameworkLibrary_eventTraceWithIgnoreArray_Parms), Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMinusiFrameworkLibrary_NoRegister()
	{
		return UMinusiFrameworkLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UMinusiFrameworkLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_GetAngleBetweenTwoVector, "GetAngleBetweenTwoVector" }, // 1732538104
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificAllActorWithTag, "GetSpecificAllActorWithTag" }, // 2845932865
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_GetSpecificFirstActorWithTag, "GetSpecificFirstActorWithTag" }, // 3739611449
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_GetTransformToTraceHitResult, "GetTransformToTraceHitResult" }, // 3203618619
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor, "IsTypeofActor" }, // 2100958895
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofActor_Exec, "IsTypeofActor_Exec" }, // 3477991090
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass, "IsTypeofClass" }, // 3221798006
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofClass_Exec, "IsTypeofClass_Exec" }, // 2844146777
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject, "IsTypeofObject" }, // 3731516030
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_IsTypeofObject_Exec, "IsTypeofObject_Exec" }, // 3402968250
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLog, "ScreenLog" }, // 752282461
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenLongLog, "ScreenLongLog" }, // 3864539865
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_ScreenShortLog, "ScreenShortLog" }, // 3192756805
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_Trace, "Trace" }, // 833294288
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceComponent, "TraceComponent" }, // 931992837
		{ &Z_Construct_UFunction_UMinusiFrameworkLibrary_TraceWithIgnoreArray, "TraceWithIgnoreArray" }, // 26664727
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "Minusi" },
		{ "IncludePath", "Utility/MinusiFrameworkLibrary.h" },
		{ "ModuleRelativePath", "Public/Utility/MinusiFrameworkLibrary.h" },
		{ "ToolTip", "*     \xea\xb2\x8c\xec\x9e\x84\xed\x94\x84\xeb\xa0\x88\xec\x9e\x84\xec\x9b\x8c\xed\x81\xac\xec\x97\x90\xec\x84\x9c \xec\xa0\x9c\xea\xb3\xb5\xed\x95\x98\xec\xa7\x80 \xec\x95\x8a\xeb\x8a\x94 \xea\xb8\xb0\xeb\x8a\xa5\xeb\x93\xa4\xec\x9d\x84 \xed\x99\x95\xec\x9e\xa5\xed\x95\x98\xec\x97\xac \xec\x9c\xa0\xed\x8b\xb8\xec\x84\xb1\xec\x9d\x84 \xec\xa0\x9c\xea\xb3\xb5\xed\x95\x98\xeb\x8a\x94 \xeb\x9d\xbc\xec\x9d\xb4\xeb\xb8\x8c\xeb\x9f\xac\xeb\xa6\xac \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMinusiFrameworkLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::ClassParams = {
		&UMinusiFrameworkLibrary::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMinusiFrameworkLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMinusiFrameworkLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMinusiFrameworkLibrary, 993805379);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMinusiFrameworkLibrary(Z_Construct_UClass_UMinusiFrameworkLibrary, &UMinusiFrameworkLibrary::StaticClass, TEXT("/Script/UEPrototype"), TEXT("UMinusiFrameworkLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMinusiFrameworkLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
