// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/Public/GSCharacterWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGSCharacterWidget() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_UGSCharacterWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_UGSCharacterWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
// End Cross Module References
	void UGSCharacterWidget::StaticRegisterNativesUGSCharacterWidget()
	{
	}
	UClass* Z_Construct_UClass_UGSCharacterWidget_NoRegister()
	{
		return UGSCharacterWidget::StaticClass();
	}
	struct Z_Construct_UClass_UGSCharacterWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HPProgressBar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HPProgressBar;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGSCharacterWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSCharacterWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SH/Public/GSCharacterWidget.h" },
		{ "ModuleRelativePath", "SH/Public/GSCharacterWidget.h" },
		{ "ToolTip", "UserWidget \xc5\xac?????? Anim Instance?? ??????????, UI?\xca\xbf??? ?????? ?????\xcf\xb4? \xc5\xac?????\xcc\xb4?. ?\xf0\xb8\xae\xbe\xf3\xbf\xa1\xbc? ?\xcc\xb8? ????????.\n   UI?? ?????\xcd\xb8? ?????\xcf\xb0? ??\xc8\xa3?\xdb\xbf??\xcf\xb4\xc2\xb0? ???? ???\xe2\xbc\xad ?\xcc\xb7????\xc2\xb0???.\n   ???\xe2\xbc\xad?? \xc4\xb3???? ???? ?????? ?????\xc7\xbe? ?\xd6\xb4? GSCharacterStatComponent (Actor Component)?? ??????,\n   \xc4\xb3?????? ?????? ??\xc8\xad?? ?????? Progress Bar?? ?????? ??????\xc6\xae?? ????. (?????\xca\xbf? ????????\xc6\xae?? ?????\xd8\xbc?, ??????.)" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSCharacterWidget_Statics::NewProp_HPProgressBar_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SH/Public/GSCharacterWidget.h" },
		{ "ToolTip", "Progress Bar UI ?????? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGSCharacterWidget_Statics::NewProp_HPProgressBar = { UE4CodeGen_Private::EPropertyClass::Object, "HPProgressBar", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(UGSCharacterWidget, HPProgressBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UGSCharacterWidget_Statics::NewProp_HPProgressBar_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterWidget_Statics::NewProp_HPProgressBar_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGSCharacterWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSCharacterWidget_Statics::NewProp_HPProgressBar,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGSCharacterWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGSCharacterWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGSCharacterWidget_Statics::ClassParams = {
		&UGSCharacterWidget::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B010A0u,
		nullptr, 0,
		Z_Construct_UClass_UGSCharacterWidget_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterWidget_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGSCharacterWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGSCharacterWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGSCharacterWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGSCharacterWidget, 2910472856);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGSCharacterWidget(Z_Construct_UClass_UGSCharacterWidget, &UGSCharacterWidget::StaticClass, TEXT("/Script/LostDark"), TEXT("UGSCharacterWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGSCharacterWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
