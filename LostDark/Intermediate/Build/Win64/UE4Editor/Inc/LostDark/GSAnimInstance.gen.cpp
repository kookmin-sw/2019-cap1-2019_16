// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/GSAnimInstance.h"
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
// End Cross Module References
	void UGSAnimInstance::StaticRegisterNativesUGSAnimInstance()
	{
	}
	UClass* Z_Construct_UClass_UGSAnimInstance_NoRegister()
	{
		return UGSAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UGSAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "SH/GSAnimInstance.h" },
		{ "ModuleRelativePath", "SH/GSAnimInstance.h" },
		{ "ToolTip", "GS = GreyStone" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Pawn" },
		{ "ModuleRelativePath", "SH/GSAnimInstance.h" },
		{ "ToolTip", "???? \xc4\xb3???? ?\xd3\xb5? ??????\xc6\xbc(????????)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentPawnSpeed", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000015, 1, nullptr, STRUCT_OFFSET(UGSAnimInstance, CurrentPawnSpeed), METADATA_PARAMS(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGSAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGSAnimInstance_Statics::NewProp_CurrentPawnSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGSAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGSAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGSAnimInstance_Statics::ClassParams = {
		&UGSAnimInstance::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A8u,
		nullptr, 0,
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
	IMPLEMENT_CLASS(UGSAnimInstance, 2583085786);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGSAnimInstance(Z_Construct_UClass_UGSAnimInstance, &UGSAnimInstance::StaticClass, TEXT("/Script/LostDark"), TEXT("UGSAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGSAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
