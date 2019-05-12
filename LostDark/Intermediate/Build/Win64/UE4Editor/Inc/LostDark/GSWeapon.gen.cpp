// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/GSWeapon.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGSWeapon() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_AGSWeapon_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_AGSWeapon();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	void AGSWeapon::StaticRegisterNativesAGSWeapon()
	{
	}
	UClass* Z_Construct_UClass_AGSWeapon_NoRegister()
	{
		return AGSWeapon::StaticClass();
	}
	struct Z_Construct_UClass_AGSWeapon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Weapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGSWeapon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGSWeapon_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GSWeapon.h" },
		{ "ModuleRelativePath", "Public/GSWeapon.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGSWeapon_Statics::NewProp_Weapon_MetaData[] = {
		{ "Category", "Weapon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GSWeapon.h" },
		{ "ToolTip", "???? ?\xd6\xbc? ???\xcc\xb7?\xc5\xbb ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGSWeapon_Statics::NewProp_Weapon = { UE4CodeGen_Private::EPropertyClass::Object, "Weapon", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AGSWeapon, Weapon), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGSWeapon_Statics::NewProp_Weapon_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGSWeapon_Statics::NewProp_Weapon_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGSWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGSWeapon_Statics::NewProp_Weapon,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGSWeapon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGSWeapon>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGSWeapon_Statics::ClassParams = {
		&AGSWeapon::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		Z_Construct_UClass_AGSWeapon_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGSWeapon_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGSWeapon_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGSWeapon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGSWeapon()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGSWeapon_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGSWeapon, 3714566258);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGSWeapon(Z_Construct_UClass_AGSWeapon, &AGSWeapon::StaticClass, TEXT("/Script/LostDark"), TEXT("AGSWeapon"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGSWeapon);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
