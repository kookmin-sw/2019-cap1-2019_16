// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDUIPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDUIPlayerController() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALDUIPlayerController_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALDUIPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	void ALDUIPlayerController::StaticRegisterNativesALDUIPlayerController()
	{
	}
	UClass* Z_Construct_UClass_ALDUIPlayerController_NoRegister()
	{
		return ALDUIPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ALDUIPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UIWidgetInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_UIWidgetInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UIWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_UIWidgetClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALDUIPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDUIPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LDUIPlayerController.h" },
		{ "ModuleRelativePath", "Public/LDUIPlayerController.h" },
		{ "ToolTip", "*     UI ???? ?\xc3\xb7??\xcc\xbe? ??\xc6\xae?\xd1\xb7? \xc5\xac????.\n      ?????? ???\xdb\xb5\xc7\xb8? ?\xd8\xb4? \xc5\xac?????\xce\xba??? UI?? ?????\xcf\xb0? ?\xcc\xb8? Viewport?? ?????? ?\xd4\xb7??? UI???? ?????\xcf\xb5??? ?????\xd1\xb4?." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetInstance_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDUIPlayerController.h" },
		{ "ToolTip", "???? ?\xce\xbd??\xcf\xbd?" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetInstance = { UE4CodeGen_Private::EPropertyClass::Object, "UIWidgetInstance", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ALDUIPlayerController, UIWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetInstance_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/LDUIPlayerController.h" },
		{ "ToolTip", "???? \xc5\xac????????" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetClass = { UE4CodeGen_Private::EPropertyClass::Class, "UIWidgetClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ALDUIPlayerController, UIWidgetClass), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALDUIPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDUIPlayerController_Statics::NewProp_UIWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALDUIPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALDUIPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALDUIPlayerController_Statics::ClassParams = {
		&ALDUIPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		nullptr, 0,
		Z_Construct_UClass_ALDUIPlayerController_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALDUIPlayerController_Statics::PropPointers),
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALDUIPlayerController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALDUIPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALDUIPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALDUIPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALDUIPlayerController, 3115271015);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALDUIPlayerController(Z_Construct_UClass_ALDUIPlayerController, &ALDUIPlayerController::StaticClass, TEXT("/Script/LostDark"), TEXT("ALDUIPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALDUIPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
