// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDGamePlayWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDGamePlayWidget() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGamePlayWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	void ULDGamePlayWidget::StaticRegisterNativesULDGamePlayWidget()
	{
		UClass* Class = ULDGamePlayWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnResumeClicked", &ULDGamePlayWidget::execOnResumeClicked },
			{ "OnRetryGameClicked", &ULDGamePlayWidget::execOnRetryGameClicked },
			{ "OnReturnToTitleClicked", &ULDGamePlayWidget::execOnReturnToTitleClicked },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDGamePlayWidget, "OnResumeClicked", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00080401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDGamePlayWidget, "OnRetryGameClicked", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00080401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDGamePlayWidget, "OnReturnToTitleClicked", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00080401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULDGamePlayWidget_NoRegister()
	{
		return ULDGamePlayWidget::StaticClass();
	}
	struct Z_Construct_UClass_ULDGamePlayWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RetryGameButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RetryGameButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnToTitleButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnToTitleButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResumeButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResumeButton;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDGamePlayWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULDGamePlayWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULDGamePlayWidget_OnResumeClicked, "OnResumeClicked" }, // 2270282735
		{ &Z_Construct_UFunction_ULDGamePlayWidget_OnRetryGameClicked, "OnRetryGameClicked" }, // 1322474940
		{ &Z_Construct_UFunction_ULDGamePlayWidget_OnReturnToTitleClicked, "OnReturnToTitleClicked" }, // 1423723494
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGamePlayWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LDGamePlayWidget.h" },
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
		{ "ToolTip", "UI_Menu ?\xd6\xbc??? ?????? \xc5\xac????\n   UI_Result ?\xd6\xbc??? ?????? \xc5\xac????" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_RetryGameButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
		{ "ToolTip", "Result UI???? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_RetryGameButton = { UE4CodeGen_Private::EPropertyClass::Object, "RetryGameButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDGamePlayWidget, RetryGameButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_RetryGameButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_RetryGameButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ReturnToTitleButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
		{ "ToolTip", "?\xd1\xb4? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ReturnToTitleButton = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnToTitleButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDGamePlayWidget, ReturnToTitleButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ReturnToTitleButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ReturnToTitleButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ResumeButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDGamePlayWidget.h" },
		{ "ToolTip", "?\xd1\xb4? ????" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ResumeButton = { UE4CodeGen_Private::EPropertyClass::Object, "ResumeButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDGamePlayWidget, ResumeButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ResumeButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ResumeButton_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULDGamePlayWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_RetryGameButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ReturnToTitleButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDGamePlayWidget_Statics::NewProp_ResumeButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDGamePlayWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDGamePlayWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDGamePlayWidget_Statics::ClassParams = {
		&ULDGamePlayWidget::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B010A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ULDGamePlayWidget_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULDGamePlayWidget_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDGamePlayWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDGamePlayWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDGamePlayWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDGamePlayWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDGamePlayWidget, 2866341232);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDGamePlayWidget(Z_Construct_UClass_ULDGamePlayWidget, &ULDGamePlayWidget::StaticClass, TEXT("/Script/LostDark"), TEXT("ULDGamePlayWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDGamePlayWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
