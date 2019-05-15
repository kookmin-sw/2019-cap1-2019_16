// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDGamePlayResultWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDGamePlayResultWidget() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayResultWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayResultWidget();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayWidget();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void ULDGamePlayResultWidget::StaticRegisterNativesULDGamePlayResultWidget()
	{
	}
	UClass* Z_Construct_UClass_ULDGamePlayResultWidget_NoRegister()
	{
		return ULDGamePlayResultWidget::StaticClass();
	}
	struct Z_Construct_UClass_ULDGamePlayResultWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDGamePlayResultWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULDGamePlayWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGamePlayResultWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LDGamePlayResultWidget.h" },
		{ "ModuleRelativePath", "Public/LDGamePlayResultWidget.h" },
		{ "ToolTip", "LDGamePlayWidget \xc5\xac?????? ???\xd3\xb9\xde\xb4? \xc5\xac????.\n   ???? ???? UI?? \xc7\xa5????." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDGamePlayResultWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDGamePlayResultWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDGamePlayResultWidget_Statics::ClassParams = {
		&ULDGamePlayResultWidget::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B010A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDGamePlayResultWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDGamePlayResultWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDGamePlayResultWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDGamePlayResultWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDGamePlayResultWidget, 1059680381);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDGamePlayResultWidget(Z_Construct_UClass_ULDGamePlayResultWidget, &ULDGamePlayResultWidget::StaticClass, TEXT("/Script/LostDark"), TEXT("ULDGamePlayResultWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDGamePlayResultWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
