// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/GSAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGSAnimInstance() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_UGSAnimInstance_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_UGSAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	LOSTDARK_API UFunction* Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck();
	LOSTDARK_API UFunction* Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo();
	LOSTDARK_API UFunction* Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
// End Cross Module References
	void UGSAnimInstance::StaticRegisterNativesUGSAnimInstance()
	{
		UClass* Class = UGSAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimNotify_AttackHitCheck", &UGSAnimInstance::execAnimNotify_AttackHitCheck },
			{ "AnimNotify_IsInputCombo", &UGSAnimInstance::execAnimNotify_IsInputCombo },
			{ "AnimNotify_NextAttackCheck", &UGSAnimInstance::execAnimNotify_NextAttackCheck },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "??\xc6\xbc???? ?\xd4\xbc?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGSAnimInstance, "AnimNotify_AttackHitCheck", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "?? ??\xc6\xbc???\xcc\xb0? ?\xd2\xb7??? ???\xc4\xbf? ?????? ???\xdd\xb8? ?\xde\xba??? ?\xde\xbe\xc6\xb5???" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGSAnimInstance, "AnimNotify_IsInputCombo", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "???? ???? ?\xde\xba??? ?\xd1\xbe\xee\xb0\xa1???? \xc3\xbc\xc5\xa9?\xcf\xb4? ?\xd4\xbc?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGSAnimInstance, "AnimNotify_NextAttackCheck", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGSAnimInstance_NoRegister()
	{
		return UGSAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UGSAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsInputCombo_MetaData[];
#endif
		static void NewProp_IsInputCombo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsInputCombo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DodgeMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DodgeMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackMontage_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackMontage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsDead_MetaData[];
#endif
		static void NewProp_IsDead_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsDead;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsInAir_MetaData[];
#endif
		static void NewProp_IsInAir_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsInAir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentPawnSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentPawnSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGSAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGSAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGSAnimInstance_AnimNotify_AttackHitCheck, "AnimNotify_AttackHitCheck" }, // 2427124280
		{ &Z_Construct_UFunction_UGSAnimInstance_AnimNotify_IsInputCombo, "AnimNotify_IsInputCombo" }, // 39452795
		{ &Z_Construct_UFunction_UGSAnimInstance_AnimNotify_NextAttackCheck, "AnimNotify_NextAttackCheck" }, // 2898517785
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "GSAnimInstance.h" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "GS = GreyStone" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "?\xde\xba? ?\xd4\xb7? ?????\xd4\xb4??? \xc8\xae????" },
	};
#endif
	void Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo_SetBit(void* Obj)
	{
		((UGSAnimInstance*)Obj)->IsInputCombo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo = { UE4CodeGen_Private::EPropertyClass::Bool, "IsInputCombo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000030015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UGSAnimInstance), &Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_DodgeMontage_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "??\xc5\xb8?? ?\xd6\xbc? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_DodgeMontage = { UE4CodeGen_Private::EPropertyClass::Object, "DodgeMontage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000030015, 1, nullptr, STRUCT_OFFSET(UGSAnimInstance, DodgeMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_DodgeMontage_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_DodgeMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_AttackMontage_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "??\xc5\xb8?? ?\xd6\xbc? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_AttackMontage = { UE4CodeGen_Private::EPropertyClass::Object, "AttackMontage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000030015, 1, nullptr, STRUCT_OFFSET(UGSAnimInstance, AttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_AttackMontage_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_AttackMontage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "?\xda\xbd??? ???????????? \xc8\xae???\xcf\xb4? ????" },
	};
#endif
	void Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead_SetBit(void* Obj)
	{
		((UGSAnimInstance*)Obj)->IsDead = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead = { UE4CodeGen_Private::EPropertyClass::Bool, "IsDead", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UGSAnimInstance), &Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "???? ???\xdf\xbf? ???\xd6\xb4??? \xc8\xae???\xcf\xb4? ?\xd2\xb0? ???? (???? ???\xcf\xb4???)" },
	};
#endif
	void Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir_SetBit(void* Obj)
	{
		((UGSAnimInstance*)Obj)->IsInAir = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir = { UE4CodeGen_Private::EPropertyClass::Bool, "IsInAir", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000015, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(UGSAnimInstance), &Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "Public/GSAnimInstance.h" },
		{ "ToolTip", "???? \xc4\xb3???? ?\xd3\xb5? ??????\xc6\xbc(????????) (???????\xcf\xb4???)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentPawnSpeed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000015, 1, nullptr, STRUCT_OFFSET(UGSAnimInstance, CurrentPawnSpeed), METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGSAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInputCombo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_DodgeMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_AttackMontage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsDead,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_IsInAir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGSAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGSAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGSAnimInstance_Statics::ClassParams = {
		&UGSAnimInstance::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A8u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_UGSAnimInstance_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGSAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGSAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGSAnimInstance, 372182571);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGSAnimInstance(Z_Construct_UClass_UGSAnimInstance, &UGSAnimInstance::StaticClass, TEXT("/Script/LostDark"), TEXT("UGSAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGSAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
