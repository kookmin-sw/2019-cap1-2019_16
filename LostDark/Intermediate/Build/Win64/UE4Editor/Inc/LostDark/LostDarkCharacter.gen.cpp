// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/LostDarkCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLostDarkCharacter() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALostDarkCharacter_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALostDarkCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded();
	LOSTDARK_API UClass* Z_Construct_UClass_UGSCharacterStatComponent_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_AGSWeapon_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_UGSAnimInstance_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void ALostDarkCharacter::StaticRegisterNativesALostDarkCharacter()
	{
		UClass* Class = ALostDarkCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnAttackMontageEnded", &ALostDarkCharacter::execOnAttackMontageEnded },
			{ "OnDodgeMontageEnded", &ALostDarkCharacter::execOnDodgeMontageEnded },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics
	{
		struct LostDarkCharacter_eventOnAttackMontageEnded_Parms
		{
			UAnimMontage* Montage;
			bool bInterrupted;
		};
		static void NewProp_bInterrupted_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Montage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::NewProp_bInterrupted_SetBit(void* Obj)
	{
		((LostDarkCharacter_eventOnAttackMontageEnded_Parms*)Obj)->bInterrupted = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::NewProp_bInterrupted = { UE4CodeGen_Private::EPropertyClass::Bool, "bInterrupted", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LostDarkCharacter_eventOnAttackMontageEnded_Parms), &Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::NewProp_Montage = { UE4CodeGen_Private::EPropertyClass::Object, "Montage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LostDarkCharacter_eventOnAttackMontageEnded_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::NewProp_bInterrupted,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::NewProp_Montage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "BP?? ???\xc3\xb5? C++?\xd4\xbc??? ?\xdd\xb5??? UFUNCTION ??\xc5\xa9?\xce\xb8? ?????\xd8\xbe??\xd1\xb4?. ???\xcc\xb3??? ????????\xc6\xae.\n??\xc5\xb8?? ???? ????????\xc6\xae ?\xd4\xbc?. UAnimMontage?? ????????!" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALostDarkCharacter, "OnAttackMontageEnded", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(LostDarkCharacter_eventOnAttackMontageEnded_Parms), Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics
	{
		struct LostDarkCharacter_eventOnDodgeMontageEnded_Parms
		{
			UAnimMontage* Montage;
			bool bInterrupted;
		};
		static void NewProp_bInterrupted_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Montage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::NewProp_bInterrupted_SetBit(void* Obj)
	{
		((LostDarkCharacter_eventOnDodgeMontageEnded_Parms*)Obj)->bInterrupted = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::NewProp_bInterrupted = { UE4CodeGen_Private::EPropertyClass::Bool, "bInterrupted", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LostDarkCharacter_eventOnDodgeMontageEnded_Parms), &Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::NewProp_Montage = { UE4CodeGen_Private::EPropertyClass::Object, "Montage", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LostDarkCharacter_eventOnDodgeMontageEnded_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::NewProp_bInterrupted,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::NewProp_Montage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALostDarkCharacter, "OnDodgeMontageEnded", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(LostDarkCharacter_eventOnDodgeMontageEnded_Parms), Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALostDarkCharacter_NoRegister()
	{
		return ALostDarkCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ALostDarkCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterStat_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharacterStat;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GSAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GSAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxCombo_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxCombo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentCombo_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CurrentCombo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsComboInputOn_MetaData[];
#endif
		static void NewProp_IsComboInputOn_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsComboInputOn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CanNextCombo_MetaData[];
#endif
		static void NewProp_CanNextCombo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CanNextCombo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttacking_MetaData[];
#endif
		static void NewProp_IsAttacking_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAttacking;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HPBarWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HPBarWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Weapon;
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
	UObject* (*const Z_Construct_UClass_ALostDarkCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ALostDarkCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALostDarkCharacter_OnAttackMontageEnded, "OnAttackMontageEnded" }, // 3364632732
		{ &Z_Construct_UFunction_ALostDarkCharacter_OnDodgeMontageEnded, "OnDodgeMontageEnded" }, // 2778691889
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SH/LostDarkCharacter.h" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "\xc5\xac???? ?????? : Config = ConfigName\n?? \xc5\xac?????? \xc8\xaf?\xe6\xbc\xb3??(.ini)???\xcf\xbf? ?????\xcd\xb8? ?????? ?? ?????? ??\xc5\xb8????.\n?? ?????\xda\xb4? ?? ??????\xc6\xbc?? ?\xd8\xb4? ?\xcc\xb8??? \xc8\xaf?\xe6\xbc\xb3?? ???\xcf\xbf? ?????\xcf\xb5??? ?\xd1\xb4?.\n???? ?\xda\xbd? \xc5\xac?????? ???\xc4\xb5\xc7\xb8?, ?\xda\xbd? \xc5\xac???????? \xc8\xaf?\xe6\xbc\xb3?? ?????? ?\xd9\xb2? ?? ?\xd6\xb4?." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CharacterStat_MetaData[] = {
		{ "Category", "Stat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "\xc4\xb3???? ???? ??????\xc6\xae ???\xe6\xbc\xb1??" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CharacterStat = { UE4CodeGen_Private::EPropertyClass::Object, "CharacterStat", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, CharacterStat), Z_Construct_UClass_UGSCharacterStatComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CharacterStat_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CharacterStat_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentWeapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "???? \xc5\xac?????? ???? ???\xe6\xbc\xb1??" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentWeapon = { UE4CodeGen_Private::EPropertyClass::Object, "CurrentWeapon", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000020001, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, CurrentWeapon), Z_Construct_UClass_AGSWeapon_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentWeapon_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRadius_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "???? ?\xdd\xb0? (??????)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRadius = { UE4CodeGen_Private::EPropertyClass::Float, "AttackRadius", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, AttackRadius), METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRadius_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRange_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRange = { UE4CodeGen_Private::EPropertyClass::Float, "AttackRange", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, AttackRange), METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRange_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_GSAnim_MetaData[] = {
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "???\xd6\xbb????? ?\xd6\xb4? ?\xce\xbd??\xcf\xbd? \xc5\xac?????? ?????\xcd\xb7? ?\xc6\xbf? ????????. (???\xe6\xbc\xb1??)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_GSAnim = { UE4CodeGen_Private::EPropertyClass::Object, "GSAnim", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, GSAnim), Z_Construct_UClass_UGSAnimInstance_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_GSAnim_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_GSAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_MaxCombo_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "?\xde\xba? \xc4\xab??\xc6\xae ?\xd6\xb4?\xc4\xa1" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_MaxCombo = { UE4CodeGen_Private::EPropertyClass::Int, "MaxCombo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, MaxCombo), METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_MaxCombo_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_MaxCombo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentCombo_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "???? ???????? ?\xde\xba? \xc4\xab??\xc6\xae" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentCombo = { UE4CodeGen_Private::EPropertyClass::Int, "CurrentCombo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, CurrentCombo), METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentCombo_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentCombo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "?\xde\xba? ?\xd4\xb7\xc2\xbf???" },
	};
#endif
	void Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn_SetBit(void* Obj)
	{
		((ALostDarkCharacter*)Obj)->IsComboInputOn = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn = { UE4CodeGen_Private::EPropertyClass::Bool, "IsComboInputOn", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ALostDarkCharacter), &Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn_SetBit, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "???? ?\xde\xba??? ?\xcc\xb5? ???? ????" },
	};
#endif
	void Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo_SetBit(void* Obj)
	{
		((ALostDarkCharacter*)Obj)->CanNextCombo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo = { UE4CodeGen_Private::EPropertyClass::Bool, "CanNextCombo", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ALostDarkCharacter), &Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo_SetBit, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "?\xce\xbd??\xcf\xbd? ?\xd3\xbc??? ?????\xd6\xb4? ?????? ????\xc6\xae?????? ???????? VisibleInstanceOnly.\n ???? ?????????? \xc8\xae???\xcf\xb4? ????." },
	};
#endif
	void Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking_SetBit(void* Obj)
	{
		((ALostDarkCharacter*)Obj)->IsAttacking = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking = { UE4CodeGen_Private::EPropertyClass::Bool, "IsAttacking", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000020815, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ALostDarkCharacter), &Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking_SetBit, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_HPBarWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "UI ???? ???\xe6\xbc\xb1??. ???\xcd\xbf? UI ?????? ?????? ?? ?\xd6\xb4? UWidgetComponent \xc5\xac??????.\n?\xdc\xba? ???? ????????\xc6\xae \xc5\xac???? ?????? ???? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_HPBarWidget = { UE4CodeGen_Private::EPropertyClass::Object, "HPBarWidget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, HPBarWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_HPBarWidget_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_HPBarWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_Weapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "?????? ???? ?\xd6\xbc? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_Weapon = { UE4CodeGen_Private::EPropertyClass::Object, "Weapon", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, Weapon), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_Weapon_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_Weapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_FollowCamera = { UE4CodeGen_Private::EPropertyClass::Object, "FollowCamera", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_FollowCamera_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SH/LostDarkCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ALostDarkCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CameraBoom_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CameraBoom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALostDarkCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CharacterStat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_AttackRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_GSAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_MaxCombo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CurrentCombo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsComboInputOn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CanNextCombo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_IsAttacking,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_HPBarWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_Weapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkCharacter_Statics::NewProp_CameraBoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALostDarkCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALostDarkCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALostDarkCharacter_Statics::ClassParams = {
		&ALostDarkCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ALostDarkCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::PropPointers),
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALostDarkCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALostDarkCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALostDarkCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALostDarkCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALostDarkCharacter, 1577363829);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALostDarkCharacter(Z_Construct_UClass_ALostDarkCharacter, &ALostDarkCharacter::StaticClass, TEXT("/Script/LostDark"), TEXT("ALostDarkCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALostDarkCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
