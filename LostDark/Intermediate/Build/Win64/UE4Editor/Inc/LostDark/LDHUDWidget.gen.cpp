// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDHUDWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDHUDWidget() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ULDHUDWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDHUDWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
// End Cross Module References
	void ULDHUDWidget::StaticRegisterNativesULDHUDWidget()
	{
	}
	UClass* Z_Construct_UClass_ULDHUDWidget_NoRegister()
	{
		return ULDHUDWidget::StaticClass();
	}
	struct Z_Construct_UClass_ULDHUDWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HighScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HighScore;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CurrentScore;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerLevel_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerLevel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExpBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ExpBar;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HPBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HPBar;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDHUDWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LDHUDWidget.h" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HighScore_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HighScore = { UE4CodeGen_Private::EPropertyClass::Object, "HighScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ULDHUDWidget, HighScore), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HighScore_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HighScore_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_CurrentScore_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_CurrentScore = { UE4CodeGen_Private::EPropertyClass::Object, "CurrentScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ULDHUDWidget, CurrentScore), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_CurrentScore_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_CurrentScore_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerLevel_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerLevel = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerLevel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ULDHUDWidget, PlayerLevel), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerLevel_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerLevel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerName_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerName = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ULDHUDWidget, PlayerName), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerName_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_ExpBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_ExpBar = { UE4CodeGen_Private::EPropertyClass::Object, "ExpBar", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ULDHUDWidget, ExpBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_ExpBar_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_ExpBar_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HPBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDHUDWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HPBar = { UE4CodeGen_Private::EPropertyClass::Object, "HPBar", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ULDHUDWidget, HPBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HPBar_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HPBar_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULDHUDWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HighScore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_CurrentScore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerLevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_PlayerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_ExpBar,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDHUDWidget_Statics::NewProp_HPBar,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDHUDWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDHUDWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDHUDWidget_Statics::ClassParams = {
		&ULDHUDWidget::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B010A0u,
		nullptr, 0,
		Z_Construct_UClass_ULDHUDWidget_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDHUDWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDHUDWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDHUDWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDHUDWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDHUDWidget, 3140297393);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDHUDWidget(Z_Construct_UClass_ULDHUDWidget, &ULDHUDWidget::StaticClass, TEXT("/Script/LostDark"), TEXT("ULDHUDWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDHUDWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
