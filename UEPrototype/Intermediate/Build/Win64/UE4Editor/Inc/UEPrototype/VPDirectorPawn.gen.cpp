// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEPrototype/Public/Core/VPDirectorPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVPDirectorPawn() {}
// Cross Module References
	UEPROTOTYPE_API UEnum* Z_Construct_UEnum_UEPrototype_EMoveType();
	UPackage* Z_Construct_UPackage__Script_UEPrototype();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPDirectorPawn_NoRegister();
	UEPROTOTYPE_API UClass* Z_Construct_UClass_AVPDirectorPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveAround();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis();
	UEPROTOTYPE_API UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
// End Cross Module References
	static UEnum* EMoveType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_UEPrototype_EMoveType, Z_Construct_UPackage__Script_UEPrototype(), TEXT("EMoveType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMoveType(EMoveType_StaticEnum, TEXT("/Script/UEPrototype"), TEXT("EMoveType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_UEPrototype_EMoveType_CRC() { return 1772506542U; }
	UEnum* Z_Construct_UEnum_UEPrototype_EMoveType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_UEPrototype();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMoveType"), 0, Get_Z_Construct_UEnum_UEPrototype_EMoveType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EMoveType::MT_LOCALAXIS", (int64)EMoveType::MT_LOCALAXIS },
				{ "EMoveType::MT_FIXEDAXIS", (int64)EMoveType::MT_FIXEDAXIS },
				{ "EMoveType::MT_ABSOLUTEAXIS", (int64)EMoveType::MT_ABSOLUTEAXIS },
				{ "EMoveType::MT_ORBITAXIS", (int64)EMoveType::MT_ORBITAXIS },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
				{ "MT_ABSOLUTEAXIS.DisplayName", "WorldAxis" },
				{ "MT_ABSOLUTEAXIS.ToolTip", "\xec\x9b\x94\xeb\x93\x9c \xea\xb8\xb0\xec\xa4\x80 \xec\xb6\x95\xec\x9c\xbc\xeb\xa1\x9c \xec\x9d\xb4\xeb\x8f\x99\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
				{ "MT_FIXEDAXIS.DisplayName", "FixedAxis" },
				{ "MT_FIXEDAXIS.ToolTip", "\xed\x8f\xb0\xec\x9d\x98 \xed\x8a\xb9\xec\xa0\x95 \xec\x8b\x9c\xec\xa0\x90 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4 \xeb\xa1\x9c\xed\x85\x8c\xec\x9d\xb4\xec\x85\x98\xec\x9d\x84 \xec\xb6\x95\xec\x9c\xbc\xeb\xa1\x9c \xec\x9d\xb4\xeb\x8f\x99\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
				{ "MT_LOCALAXIS.DisplayName", "LocalAxis" },
				{ "MT_LOCALAXIS.ToolTip", "\xed\x8f\xb0\xec\x9d\x98 \xed\x98\x84\xec\x9e\xac \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4 \xeb\xa1\x9c\xed\x85\x8c\xec\x9d\xb4\xec\x85\x98\xec\x9d\x84 \xec\xb6\x95\xec\x9c\xbc\xeb\xa1\x9c \xec\x9d\xb4\xeb\x8f\x99\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
				{ "MT_ORBITAXIS.DisplayName", "OrbitAxis" },
				{ "MT_ORBITAXIS.ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8\xeb\xa5\xbc \xec\xa4\x91\xec\x8b\xac\xec\x9c\xbc\xeb\xa1\x9c, \xec\x9b\x94\xeb\x93\x9c \xec\xb6\x95\xec\x9d\x84 \xea\xb8\xb0\xec\xa4\x80\xec\x9c\xbc\xeb\xa1\x9c \xea\xb3\xb5\xec\xa0\x84\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
				{ "ToolTip", "*     \xed\x8f\xb0\xec\x9d\x98 \xec\x9d\xb4\xeb\x8f\x99 \xea\xb8\xb0\xec\xa4\x80 \xec\xb6\x95\xec\x9d\x84 \xec\xa7\x80\xec\xa0\x95\xed\x95\xb4\xec\xa3\xbc\xeb\x8a\x94 \xec\x97\xb4\xea\xb1\xb0\xed\x98\x95 \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_UEPrototype,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"EMoveType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"EMoveType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void AVPDirectorPawn::StaticRegisterNativesAVPDirectorPawn()
	{
		UClass* Class = AVPDirectorPawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MoveAbsoluteAxis", &AVPDirectorPawn::execMoveAbsoluteAxis },
			{ "MoveAround", &AVPDirectorPawn::execMoveAround },
			{ "MoveFixedAxis", &AVPDirectorPawn::execMoveFixedAxis },
			{ "MoveLocalAxis", &AVPDirectorPawn::execMoveLocalAxis },
			{ "MoveOrbitAxis", &AVPDirectorPawn::execMoveOrbitAxis },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics
	{
		struct VPDirectorPawn_eventMoveAbsoluteAxis_Parms
		{
			float InX;
			float InY;
			float InZ;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InZ;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InY;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::NewProp_InZ = { UE4CodeGen_Private::EPropertyClass::Float, "InZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAbsoluteAxis_Parms, InZ), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::NewProp_InY = { UE4CodeGen_Private::EPropertyClass::Float, "InY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAbsoluteAxis_Parms, InY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::NewProp_InX = { UE4CodeGen_Private::EPropertyClass::Float, "InX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAbsoluteAxis_Parms, InX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::NewProp_InZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::NewProp_InY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::NewProp_InX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xec\xa0\x88\xeb\x8c\x80 \xec\xa2\x8c\xed\x91\x9c \xea\xb8\xb0\xec\xa4\x80\xec\x9c\xbc\xeb\xa1\x9c \xed\x8f\xb0\xec\x9d\x98 \xec\x9d\xb4\xeb\x8f\x99\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPDirectorPawn, "MoveAbsoluteAxis", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(VPDirectorPawn_eventMoveAbsoluteAxis_Parms), Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics
	{
		struct VPDirectorPawn_eventMoveAround_Parms
		{
			EMoveType InMoveType;
			float InX;
			float InY;
			float InZ;
			AActor* InOrbitTarget;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InOrbitTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InOrbitTarget;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InZ;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InY;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InX;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InMoveType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InMoveType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InOrbitTarget_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InOrbitTarget = { UE4CodeGen_Private::EPropertyClass::Object, "InOrbitTarget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAround_Parms, InOrbitTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InOrbitTarget_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InOrbitTarget_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InZ = { UE4CodeGen_Private::EPropertyClass::Float, "InZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAround_Parms, InZ), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InY = { UE4CodeGen_Private::EPropertyClass::Float, "InY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAround_Parms, InY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InX = { UE4CodeGen_Private::EPropertyClass::Float, "InX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAround_Parms, InX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InMoveType = { UE4CodeGen_Private::EPropertyClass::Enum, "InMoveType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveAround_Parms, InMoveType), Z_Construct_UEnum_UEPrototype_EMoveType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InMoveType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InOrbitTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InMoveType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::NewProp_InMoveType_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom" },
		{ "CPP_Default_InOrbitTarget", "None" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5\xed\x95\x9c \xeb\xac\xb4\xeb\xb8\x8c \xed\x83\x80\xec\x9e\x85 \xeb\xb0\xa9\xec\x8b\x9d\xec\x9c\xbc\xeb\xa1\x9c \xec\x9d\xb4\xeb\x8f\x99\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPDirectorPawn, "MoveAround", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VPDirectorPawn_eventMoveAround_Parms), Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveAround()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPDirectorPawn_MoveAround_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics
	{
		struct VPDirectorPawn_eventMoveFixedAxis_Parms
		{
			float InX;
			float InY;
			float InZ;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InZ;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InY;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::NewProp_InZ = { UE4CodeGen_Private::EPropertyClass::Float, "InZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveFixedAxis_Parms, InZ), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::NewProp_InY = { UE4CodeGen_Private::EPropertyClass::Float, "InY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveFixedAxis_Parms, InY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::NewProp_InX = { UE4CodeGen_Private::EPropertyClass::Float, "InX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveFixedAxis_Parms, InX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::NewProp_InZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::NewProp_InY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::NewProp_InX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xec\x88\x9c\xea\xb0\x84 \xed\x8f\xb0\xec\x9d\x98 \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xec\xb6\x95\xec\x9d\x84 \xea\xb3\xa0\xec\xa0\x95\xed\x95\x98\xec\x97\xac \xec\x9d\xb4\xeb\x8f\x99\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPDirectorPawn, "MoveFixedAxis", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(VPDirectorPawn_eventMoveFixedAxis_Parms), Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics
	{
		struct VPDirectorPawn_eventMoveLocalAxis_Parms
		{
			float InX;
			float InY;
			float InZ;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InZ;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InY;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::NewProp_InZ = { UE4CodeGen_Private::EPropertyClass::Float, "InZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveLocalAxis_Parms, InZ), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::NewProp_InY = { UE4CodeGen_Private::EPropertyClass::Float, "InY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveLocalAxis_Parms, InY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::NewProp_InX = { UE4CodeGen_Private::EPropertyClass::Float, "InX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveLocalAxis_Parms, InX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::NewProp_InZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::NewProp_InY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::NewProp_InX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x8f\xb0\xec\x9d\x98 \xec\x98\xa4\xeb\xb8\x8c\xec\xa0\x9d\xed\x8a\xb8 \xec\xb6\x95 \xea\xb8\xb0\xeb\xb0\x98 \xec\x9d\xb4\xeb\x8f\x99\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPDirectorPawn, "MoveLocalAxis", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(VPDirectorPawn_eventMoveLocalAxis_Parms), Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics
	{
		struct VPDirectorPawn_eventMoveOrbitAxis_Parms
		{
			float InX;
			float InY;
			float InZ;
			AActor* OrbitTarget;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OrbitTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OrbitTarget;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InZ;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InY;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_OrbitTarget_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_OrbitTarget = { UE4CodeGen_Private::EPropertyClass::Object, "OrbitTarget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveOrbitAxis_Parms, OrbitTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_OrbitTarget_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_OrbitTarget_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_InZ = { UE4CodeGen_Private::EPropertyClass::Float, "InZ", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveOrbitAxis_Parms, InZ), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_InY = { UE4CodeGen_Private::EPropertyClass::Float, "InY", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveOrbitAxis_Parms, InY), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_InX = { UE4CodeGen_Private::EPropertyClass::Float, "InX", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VPDirectorPawn_eventMoveOrbitAxis_Parms, InX), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_OrbitTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_InZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_InY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::NewProp_InX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xeb\x8c\x80\xec\x83\x81\xec\x9d\x84 \xec\xa4\x91\xec\x8b\xac\xec\x9c\xbc\xeb\xa1\x9c, \xec\x9b\x94\xeb\x93\x9c \xec\xb6\x95\xec\x9d\x84 \xea\xb8\xb0\xeb\xb0\x98\xec\x9c\xbc\xeb\xa1\x9c \xea\xb3\xb5\xec\xa0\x84 \xec\x9d\xb4\xeb\x8f\x99\xec\x9d\x84 \xec\x88\x98\xed\x96\x89\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVPDirectorPawn, "MoveOrbitAxis", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(VPDirectorPawn_eventMoveOrbitAxis_Parms), Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AVPDirectorPawn_NoRegister()
	{
		return AVPDirectorPawn::StaticClass();
	}
	struct Z_Construct_UClass_AVPDirectorPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FixedAxis_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FixedAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentMoveType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CurrentMoveType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CurrentMoveType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloatingPawnMovement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FloatingPawnMovement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MCWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MCWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MotionController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MotionController;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VRCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VRCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VRRootTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VRRootTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootCollision_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RootCollision;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVPDirectorPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_UEPrototype,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AVPDirectorPawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVPDirectorPawn_MoveAbsoluteAxis, "MoveAbsoluteAxis" }, // 2373195368
		{ &Z_Construct_UFunction_AVPDirectorPawn_MoveAround, "MoveAround" }, // 2015482300
		{ &Z_Construct_UFunction_AVPDirectorPawn_MoveFixedAxis, "MoveFixedAxis" }, // 21941984
		{ &Z_Construct_UFunction_AVPDirectorPawn_MoveLocalAxis, "MoveLocalAxis" }, // 3932231737
		{ &Z_Construct_UFunction_AVPDirectorPawn_MoveOrbitAxis, "MoveOrbitAxis" }, // 2036689145
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Core/VPDirectorPawn.h" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "*     DirectorPawn\xec\x9d\x80 \xed\x94\x84\xeb\xa1\x9c\xed\x86\xa0\xed\x83\x80\xec\x9e\x85 \xec\x9b\x94\xeb\x93\x9c\xec\x97\x90\xec\x84\x9c \xed\x94\x84\xeb\xa1\x9c\xed\x86\xa0\xed\x83\x80\xec\x9e\x85\xec\x9d\x84 \xeb\x8b\xb4\xeb\x8b\xb9\xed\x95\x98\xeb\x8a\x94 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xea\xb0\x80\n*     \xea\xb8\xb0\xeb\xb3\xb8\xec\xa0\x81\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb9\x99\xec\x9d\x98\xed\x95\x98\xeb\x8a\x94 \xed\x8f\xb0\xec\x9e\x85\xeb\x8b\x88\xeb\x8b\xa4. VR \xea\xb8\xb0\xea\xb8\xb0\xec\x99\x80 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac\xeb\xa5\xbc \xec\x82\xac\xec\x9a\xa9\xed\x95\x98\xeb\x8a\x94 \xec\x9c\xa0\xec\xa0\x80\xec\x9d\x98\n*     \xeb\xaa\xa8\xec\x8a\xb5\xec\x9d\x84 \xea\xb5\xac\xed\x98\x84\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FixedAxis_MetaData[] = {
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FixedAxis = { UE4CodeGen_Private::EPropertyClass::Struct, "FixedAxis", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, FixedAxis), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FixedAxis_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FixedAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Bitmask", "" },
		{ "Category", "VPDirectorPawn" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4\xec\x9d\x98 \xed\x98\x84\xec\x9e\xac \xec\x9d\xb4\xeb\x8f\x99 \xed\x83\x80\xec\x9e\x85" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType = { UE4CodeGen_Private::EPropertyClass::Enum, "CurrentMoveType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000005, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, CurrentMoveType), Z_Construct_UEnum_UEPrototype_EMoveType, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FloatingPawnMovement_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\x9d\xb4\xeb\x8f\x99 \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FloatingPawnMovement = { UE4CodeGen_Private::EPropertyClass::Object, "FloatingPawnMovement", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, FloatingPawnMovement), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FloatingPawnMovement_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FloatingPawnMovement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MCWidget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xeb\xaa\xa8\xec\x85\x98 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac \xec\x9c\x84\xec\xa0\xaf" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MCWidget = { UE4CodeGen_Private::EPropertyClass::Object, "MCWidget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, MCWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MCWidget_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MCWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MotionController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xeb\xaa\xa8\xec\x85\x98 \xec\xbb\xa8\xed\x8a\xb8\xeb\xa1\xa4\xeb\x9f\xac" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MotionController = { UE4CodeGen_Private::EPropertyClass::Object, "MotionController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, MotionController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MotionController_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MotionController_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 VR \xec\xb9\xb4\xeb\xa9\x94\xeb\x9d\xbc" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera = { UE4CodeGen_Private::EPropertyClass::Object, "VRCamera", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, VRCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 VR \xeb\xa3\xa8\xed\x8a\xb8 \xed\x8a\xb8\xeb\x9e\x9c\xec\x8a\xa4\xed\x8f\xbc" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform = { UE4CodeGen_Private::EPropertyClass::Object, "VRRootTransform", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, VRRootTransform), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Director" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/VPDirectorPawn.h" },
		{ "ToolTip", "\xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xec\xbd\x9c\xeb\xa6\xac\xec\xa0\x84" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision = { UE4CodeGen_Private::EPropertyClass::Object, "RootCollision", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00400000000a000d, 1, nullptr, STRUCT_OFFSET(AVPDirectorPawn, RootCollision), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision_MetaData, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVPDirectorPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FixedAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_CurrentMoveType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_FloatingPawnMovement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MCWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_MotionController,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_VRRootTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVPDirectorPawn_Statics::NewProp_RootCollision,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVPDirectorPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVPDirectorPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AVPDirectorPawn_Statics::ClassParams = {
		&AVPDirectorPawn::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AVPDirectorPawn_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AVPDirectorPawn_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AVPDirectorPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AVPDirectorPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AVPDirectorPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AVPDirectorPawn, 534804095);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVPDirectorPawn(Z_Construct_UClass_AVPDirectorPawn, &AVPDirectorPawn::StaticClass, TEXT("/Script/UEPrototype"), TEXT("AVPDirectorPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVPDirectorPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
