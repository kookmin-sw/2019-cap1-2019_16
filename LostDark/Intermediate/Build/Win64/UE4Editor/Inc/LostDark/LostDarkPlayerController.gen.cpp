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
	LOSTDARK_API UFunction* Z_Construct_UFunction_ALostDarkPlayerController_AddScore();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayResultWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALDPlayerState_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDHUDWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	void ALostDarkPlayerController::StaticRegisterNativesALostDarkPlayerController()
	{
		UClass* Class = ALostDarkPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddScore", &ALostDarkPlayerController::execAddScore },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics
	{
		struct LostDarkPlayerController_eventAddScore_Parms
		{
			int32 Score;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Score;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::NewProp_Score = { UE4CodeGen_Private::EPropertyClass::Int, "Score", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LostDarkPlayerController_eventAddScore_Parms, Score), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::NewProp_Score,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
		{ "ToolTip", "????????\xc6\xae???? ???? ?\xd7\xbf????? ????\xc4\xa1?? ?\xde\xbe\xc6\xbf??? ?\xd4\xbc?" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALostDarkPlayerController, "AddScore", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x44020401, sizeof(LostDarkPlayerController_eventAddScore_Parms), Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALostDarkPlayerController_AddScore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ALostDarkPlayerController_AddScore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALostDarkPlayerController_NoRegister()
	{
		return ALostDarkPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ALostDarkPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResultWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResultWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MenuWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MenuWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LDPlayerState_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LDPlayerState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HUDWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HUDWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResultWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResultWidgetClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MenuWidgetClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_MenuWidgetClass;
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
	const FClassFunctionLinkInfo Z_Construct_UClass_ALostDarkPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALostDarkPlayerController_AddScore, "AddScore" }, // 787074867
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LostDarkPlayerController.h" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidget = { UE4CodeGen_Private::EPropertyClass::Object, "ResultWidget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, ResultWidget), Z_Construct_UClass_ULDGamePlayResultWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidget_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidget = { UE4CodeGen_Private::EPropertyClass::Object, "MenuWidget", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000080008, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, MenuWidget), Z_Construct_UClass_ULDGamePlayWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidget_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidget_MetaData)) };
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidgetClass = { UE4CodeGen_Private::EPropertyClass::Class, "ResultWidgetClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, ResultWidgetClass), Z_Construct_UClass_ULDGamePlayResultWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidgetClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidgetClass = { UE4CodeGen_Private::EPropertyClass::Class, "MenuWidgetClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, MenuWidgetClass), Z_Construct_UClass_ULDGamePlayWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidgetClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidgetClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/LostDarkPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass = { UE4CodeGen_Private::EPropertyClass::Class, "HUDWidgetClass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0024080000010005, 1, nullptr, STRUCT_OFFSET(ALostDarkPlayerController, HUDWidgetClass), Z_Construct_UClass_ULDHUDWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALostDarkPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_LDPlayerState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_ResultWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_MenuWidgetClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkPlayerController_Statics::NewProp_HUDWidgetClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALostDarkPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALostDarkPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALostDarkPlayerController_Statics::ClassParams = {
		&ALostDarkPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A4u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(ALostDarkPlayerController, 1119934669);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALostDarkPlayerController(Z_Construct_UClass_ALostDarkPlayerController, &ALostDarkPlayerController::StaticClass, TEXT("/Script/LostDark"), TEXT("ALostDarkPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALostDarkPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
