// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDarkSetting/Public/LDCharacterSetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDCharacterSetting() {}
// Cross Module References
	LOSTDARKSETTING_API UClass* Z_Construct_UClass_ULDCharacterSetting_NoRegister();
	LOSTDARKSETTING_API UClass* Z_Construct_UClass_ULDCharacterSetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_LostDarkSetting();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
// End Cross Module References
	void ULDCharacterSetting::StaticRegisterNativesULDCharacterSetting()
	{
	}
	UClass* Z_Construct_UClass_ULDCharacterSetting_NoRegister()
	{
		return ULDCharacterSetting::StaticClass();
	}
	struct Z_Construct_UClass_ULDCharacterSetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterAssets_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_CharacterAssets;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CharacterAssets_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDCharacterSetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDarkSetting,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSetting_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LDCharacterSetting.h" },
		{ "ModuleRelativePath", "Public/LDCharacterSetting.h" },
		{ "ToolTip", "?????? ?????? \xc4\xb3???? ?\xd6\xbc??? ?????? ?????\xcf\xb4? \xc5\xac????" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDCharacterSetting.h" },
		{ "ToolTip", "?\xd6\xbc? ?????? ????." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets = { UE4CodeGen_Private::EPropertyClass::Array, "CharacterAssets", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000004000, 1, nullptr, STRUCT_OFFSET(ULDCharacterSetting, CharacterAssets), METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "CharacterAssets", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000004000, 1, nullptr, 0, Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULDCharacterSetting_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSetting_Statics::NewProp_CharacterAssets_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDCharacterSetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDCharacterSetting>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDCharacterSetting_Statics::ClassParams = {
		&ULDCharacterSetting::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A4u,
		nullptr, 0,
		Z_Construct_UClass_ULDCharacterSetting_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSetting_Statics::PropPointers),
		"LostDark",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSetting_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDCharacterSetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDCharacterSetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDCharacterSetting, 1252211008);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDCharacterSetting(Z_Construct_UClass_ULDCharacterSetting, &ULDCharacterSetting::StaticClass, TEXT("/Script/LostDarkSetting"), TEXT("ULDCharacterSetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDCharacterSetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
