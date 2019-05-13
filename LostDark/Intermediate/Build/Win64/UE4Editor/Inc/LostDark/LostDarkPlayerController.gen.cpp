// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LostDarkPlayerController.h"
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
	LOSTDARK_API UClass* Z_Construct_UClass_ALDPlayerState_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDHUDWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LDPlayerState_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LDPlayerState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUDWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HUDWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
		{ "IncludePath", "LostDarkPlayerController.h" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_LDPlayerState_MetaData[] = {
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_LDPlayerState = { UE4CodeGen_Private::EPropertyClass::Object, "LDPlayerState", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, LDPlayerState), Z_Construct_UClass_ALDPlayerState_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_LDPlayerState_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_LDPlayerState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidget = { UE4CodeGen_Private::EPropertyClass::Object, "HUDWidget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, HUDWidget), Z_Construct_UClass_ULDHUDWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidget_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
		{ "ToolTip", "virtual void SetupInputComponent() override;" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass = { UE4CodeGen_Private::EPropertyClass::Class, "HUDWidgetClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, HUDWidgetClass), Z_Construct_UClass_ULDHUDWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALostDarkPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_LDPlayerState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALostDarkPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALostDarkPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALostDarkPlayerController_Statics::ClassParams = {
		&ALostDarkPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		nullptr, 0,
		Z_Construct_UClass_ALostDarkPlayerController_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::PropPointers),
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
	IMPLEMENT_CLASS(ALostDarkPlayerController, 4257533641);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALostDarkPlayerController(Z_Construct_UClass_ALostDarkPlayerController, &ALostDarkPlayerController::StaticClass, TEXT("/Script/LostDark"), TEXT("ALostDarkPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALostDarkPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
