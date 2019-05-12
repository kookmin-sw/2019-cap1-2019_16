// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/GSCharacterStatComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGSCharacterStatComponent() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_UGSCharacterStatComponent_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_UGSCharacterStatComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void UGSCharacterStatComponent::StaticRegisterNativesUGSCharacterStatComponent()
	{
	}
	UClass* Z_Construct_UClass_UGSCharacterStatComponent_NoRegister()
	{
		return UGSCharacterStatComponent::StaticClass();
	}
	struct Z_Construct_UClass_UGSCharacterStatComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentHP_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Level;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGSCharacterStatComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSCharacterStatComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "GSCharacterStatComponent.h" },
		{ "ModuleRelativePath", "Public/GSCharacterStatComponent.h" },
		{ "ToolTip", "UI ?????? ???? ????????\xc6\xae(->GSCharacterWidget)" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_CurrentHP_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Public/GSCharacterStatComponent.h" },
		{ "ToolTip", "???? HP / Transient?? UPROPERTY ?\xd3\xbc??? ???????? ?\xca\xb4\xc2\xb4\xd9\xb4\xc2\xb0? ?\xc7\xb9??\xd1\xb4?. ???\xc3\xb7? ???\xd2\xbc? ?\xd6\xb4? ???????\xcc\xb1\xe2\xbf\xa1 ?????\xcf\xb4\xc2\xb0??? ?\xc7\xb9? ????." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_CurrentHP = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentHP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000022801, 1, nullptr, STRUCT_OFFSET(UGSCharacterStatComponent, CurrentHP), METADATA_PARAMS(Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_CurrentHP_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_CurrentHP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_Level_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "Public/GSCharacterStatComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_Level = { UE4CodeGen_Private::EPropertyClass::Int, "Level", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000801, 1, nullptr, STRUCT_OFFSET(UGSCharacterStatComponent, Level), METADATA_PARAMS(Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_Level_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_Level_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGSCharacterStatComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_CurrentHP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSCharacterStatComponent_Statics::NewProp_Level,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGSCharacterStatComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGSCharacterStatComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGSCharacterStatComponent_Statics::ClassParams = {
		&UGSCharacterStatComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A4u,
		nullptr, 0,
		Z_Construct_UClass_UGSCharacterStatComponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterStatComponent_Statics::PropPointers),
		"Engine",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UGSCharacterStatComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UGSCharacterStatComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGSCharacterStatComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGSCharacterStatComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGSCharacterStatComponent, 2885778610);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGSCharacterStatComponent(Z_Construct_UClass_UGSCharacterStatComponent, &UGSCharacterStatComponent::StaticClass, TEXT("/Script/LostDark"), TEXT("UGSCharacterStatComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGSCharacterStatComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
