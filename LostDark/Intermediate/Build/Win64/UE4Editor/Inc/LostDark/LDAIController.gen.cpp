// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/Public/LDAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDAIController() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALDAIController_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALDAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ALDAIController::StaticRegisterNativesALDAIController()
	{
	}
	UClass* Z_Construct_UClass_ALDAIController_NoRegister()
	{
		return ALDAIController::StaticClass();
	}
	struct Z_Construct_UClass_ALDAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BBAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BBAsset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BTAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BTAsset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALDAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDAIController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SH/Public/LDAIController.h" },
		{ "ModuleRelativePath", "SH/Public/LDAIController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDAIController_Statics::NewProp_BBAsset_MetaData[] = {
		{ "ModuleRelativePath", "SH/Public/LDAIController.h" },
		{ "ToolTip", "???????? ?\xd6\xbc? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALDAIController_Statics::NewProp_BBAsset = { UE4CodeGen_Private::EPropertyClass::Object, "BBAsset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ALDAIController, BBAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALDAIController_Statics::NewProp_BBAsset_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDAIController_Statics::NewProp_BBAsset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDAIController_Statics::NewProp_BTAsset_MetaData[] = {
		{ "ModuleRelativePath", "SH/Public/LDAIController.h" },
		{ "ToolTip", "?????\xcc\xba??? \xc6\xae?? ?\xd6\xbc? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALDAIController_Statics::NewProp_BTAsset = { UE4CodeGen_Private::EPropertyClass::Object, "BTAsset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ALDAIController, BTAsset), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALDAIController_Statics::NewProp_BTAsset_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDAIController_Statics::NewProp_BTAsset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALDAIController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDAIController_Statics::NewProp_BBAsset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDAIController_Statics::NewProp_BTAsset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALDAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALDAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALDAIController_Statics::ClassParams = {
		&ALDAIController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		nullptr, 0,
		Z_Construct_UClass_ALDAIController_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALDAIController_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALDAIController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALDAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALDAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALDAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALDAIController, 1889496052);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALDAIController(Z_Construct_UClass_ALDAIController, &ALDAIController::StaticClass, TEXT("/Script/LostDark"), TEXT("ALDAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALDAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
