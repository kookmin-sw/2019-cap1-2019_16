// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/YJ/YJCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYJCharacter() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_AYJCharacter_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_AYJCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	LOSTDARK_API UFunction* Z_Construct_UFunction_AYJCharacter_GetHP();
	LOSTDARK_API UFunction* Z_Construct_UFunction_AYJCharacter_GetMP();
// End Cross Module References
	void AYJCharacter::StaticRegisterNativesAYJCharacter()
	{
		UClass* Class = AYJCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHP", &AYJCharacter::execGetHP },
			{ "GetMP", &AYJCharacter::execGetMP },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AYJCharacter_GetHP_Statics
	{
		struct YJCharacter_eventGetHP_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AYJCharacter_GetHP_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(YJCharacter_eventGetHP_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYJCharacter_GetHP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYJCharacter_GetHP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYJCharacter_GetHP_Statics::Function_MetaDataParams[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AYJCharacter_GetHP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYJCharacter, "GetHP", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(YJCharacter_eventGetHP_Parms), Z_Construct_UFunction_AYJCharacter_GetHP_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_GetHP_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AYJCharacter_GetHP_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_GetHP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AYJCharacter_GetHP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AYJCharacter_GetHP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYJCharacter_GetMP_Statics
	{
		struct YJCharacter_eventGetMP_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AYJCharacter_GetMP_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(YJCharacter_eventGetMP_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AYJCharacter_GetMP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AYJCharacter_GetMP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYJCharacter_GetMP_Statics::Function_MetaDataParams[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AYJCharacter_GetMP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYJCharacter, "GetMP", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(YJCharacter_eventGetMP_Parms), Z_Construct_UFunction_AYJCharacter_GetMP_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_GetMP_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AYJCharacter_GetMP_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_GetMP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AYJCharacter_GetMP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AYJCharacter_GetMP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AYJCharacter_NoRegister()
	{
		return AYJCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AYJCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MentalPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MentalPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_HealthPoint;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYJCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AYJCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AYJCharacter_GetHP, "GetHP" }, // 1243921386
		{ &Z_Construct_UFunction_AYJCharacter_GetMP, "GetMP" }, // 601150967
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "YJ/YJCharacter.h" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint = { UE4CodeGen_Private::EPropertyClass::Int, "MentalPoint", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000005, 1, nullptr, STRUCT_OFFSET(AYJCharacter, MentalPoint), METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint = { UE4CodeGen_Private::EPropertyClass::Int, "HealthPoint", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000005, 1, nullptr, STRUCT_OFFSET(AYJCharacter, HealthPoint), METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYJCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AYJCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYJCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AYJCharacter_Statics::ClassParams = {
		&AYJCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AYJCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AYJCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AYJCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AYJCharacter, 687801617);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AYJCharacter(Z_Construct_UClass_AYJCharacter, &AYJCharacter::StaticClass, TEXT("/Script/LostDark"), TEXT("AYJCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AYJCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
