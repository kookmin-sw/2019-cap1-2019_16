// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/Public/LostDarkPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLostDarkPlayerController() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALostDarkPlayerController_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALostDarkPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void ALostDarkPlayerController::StaticRegisterNativesALostDarkPlayerController()
	{
	}
	UClass* Z_Construct_UClass_ALostDarkPlayerController_NoRegister()
	{
		return ALostDarkPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ALostDarkPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALostDarkPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SH/Public/LostDarkPlayerController.h" },
		{ "ModuleRelativePath", "SH/Public/LostDarkPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALostDarkPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALostDarkPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALostDarkPlayerController_Statics::ClassParams = {
		&ALostDarkPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		nullptr, 0,
		nullptr, 0,
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALostDarkPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALostDarkPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALostDarkPlayerController, 218055961);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALostDarkPlayerController(Z_Construct_UClass_ALostDarkPlayerController, &ALostDarkPlayerController::StaticClass, TEXT("/Script/LostDark"), TEXT("ALostDarkPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALostDarkPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
