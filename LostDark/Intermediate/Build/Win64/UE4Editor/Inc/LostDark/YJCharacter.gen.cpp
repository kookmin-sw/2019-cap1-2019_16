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
	LOSTDARK_API UFunction* Z_Construct_UFunction_AYJCharacter_AddHP();
	LOSTDARK_API UFunction* Z_Construct_UFunction_AYJCharacter_AddMP();
	LOSTDARK_API UFunction* Z_Construct_UFunction_AYJCharacter_ReduceHP();
	LOSTDARK_API UFunction* Z_Construct_UFunction_AYJCharacter_ReduceMP();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	static FName NAME_AYJCharacter_AddHP = FName(TEXT("AddHP"));
	void AYJCharacter::AddHP()
	{
		ProcessEvent(FindFunctionChecked(NAME_AYJCharacter_AddHP),NULL);
	}
	static FName NAME_AYJCharacter_AddMP = FName(TEXT("AddMP"));
	void AYJCharacter::AddMP()
	{
		ProcessEvent(FindFunctionChecked(NAME_AYJCharacter_AddMP),NULL);
	}
	static FName NAME_AYJCharacter_ReduceHP = FName(TEXT("ReduceHP"));
	void AYJCharacter::ReduceHP()
	{
		ProcessEvent(FindFunctionChecked(NAME_AYJCharacter_ReduceHP),NULL);
	}
	static FName NAME_AYJCharacter_ReduceMP = FName(TEXT("ReduceMP"));
	void AYJCharacter::ReduceMP()
	{
		ProcessEvent(FindFunctionChecked(NAME_AYJCharacter_ReduceMP),NULL);
	}
	void AYJCharacter::StaticRegisterNativesAYJCharacter()
	{
		UClass* Class = AYJCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddHP", &AYJCharacter::execAddHP },
			{ "AddMP", &AYJCharacter::execAddMP },
			{ "ReduceHP", &AYJCharacter::execReduceHP },
			{ "ReduceMP", &AYJCharacter::execReduceMP },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AYJCharacter_AddHP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYJCharacter_AddHP_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AYJCharacter_AddHP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYJCharacter, "AddHP", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AYJCharacter_AddHP_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_AddHP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AYJCharacter_AddHP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AYJCharacter_AddHP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYJCharacter_AddMP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYJCharacter_AddMP_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AYJCharacter_AddMP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYJCharacter, "AddMP", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AYJCharacter_AddMP_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_AddMP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AYJCharacter_AddMP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AYJCharacter_AddMP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYJCharacter_ReduceHP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYJCharacter_ReduceHP_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AYJCharacter_ReduceHP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYJCharacter, "ReduceHP", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AYJCharacter_ReduceHP_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_ReduceHP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AYJCharacter_ReduceHP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AYJCharacter_ReduceHP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AYJCharacter_ReduceMP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AYJCharacter_ReduceMP_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AYJCharacter_ReduceMP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AYJCharacter, "ReduceMP", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AYJCharacter_ReduceMP_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AYJCharacter_ReduceMP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AYJCharacter_ReduceMP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AYJCharacter_ReduceMP_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FInt16PropertyParams NewProp_MentalPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FInt16PropertyParams NewProp_HealthPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AYJCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AYJCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AYJCharacter_AddHP, "AddHP" }, // 2526815433
		{ &Z_Construct_UFunction_AYJCharacter_AddMP, "AddMP" }, // 1760442985
		{ &Z_Construct_UFunction_AYJCharacter_ReduceHP, "ReduceHP" }, // 3637882055
		{ &Z_Construct_UFunction_AYJCharacter_ReduceMP, "ReduceMP" }, // 2508925403
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
	const UE4CodeGen_Private::FInt16PropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint = { UE4CodeGen_Private::EPropertyClass::Int16, "MentalPoint", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AYJCharacter, MentalPoint), METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FInt16PropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint = { UE4CodeGen_Private::EPropertyClass::Int16, "HealthPoint", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(AYJCharacter, HealthPoint), METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_FollowCamera = { UE4CodeGen_Private::EPropertyClass::Object, "FollowCamera", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AYJCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_FollowCamera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AYJCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "YJ/YJCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AYJCharacter_Statics::NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(AYJCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AYJCharacter_Statics::NewProp_CameraBoom_MetaData, ARRAY_COUNT(Z_Construct_UClass_AYJCharacter_Statics::NewProp_CameraBoom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AYJCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_MentalPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_HealthPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AYJCharacter_Statics::NewProp_CameraBoom,
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
	IMPLEMENT_CLASS(AYJCharacter, 2600462719);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AYJCharacter(Z_Construct_UClass_AYJCharacter, &AYJCharacter::StaticClass, TEXT("/Script/LostDark"), TEXT("AYJCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AYJCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
