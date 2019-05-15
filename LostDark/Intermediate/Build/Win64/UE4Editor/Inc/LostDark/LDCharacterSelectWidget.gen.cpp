// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDCharacterSelectWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDCharacterSelectWidget() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ULDCharacterSelectWidget_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDCharacterSelectWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked();
	LOSTDARK_API UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
// End Cross Module References
	void ULDCharacterSelectWidget::StaticRegisterNativesULDCharacterSelectWidget()
	{
		UClass* Class = ULDCharacterSelectWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "NextCharacter", &ULDCharacterSelectWidget::execNextCharacter },
			{ "OnConfirmClicked", &ULDCharacterSelectWidget::execOnConfirmClicked },
			{ "OnNextClicked", &ULDCharacterSelectWidget::execOnNextClicked },
			{ "OnPrevClicked", &ULDCharacterSelectWidget::execOnPrevClicked },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics
	{
		struct LDCharacterSelectWidget_eventNextCharacter_Parms
		{
			bool bForward;
		};
		static void NewProp_bForward_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bForward;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward_SetBit(void* Obj)
	{
		((LDCharacterSelectWidget_eventNextCharacter_Parms*)Obj)->bForward = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward = { UE4CodeGen_Private::EPropertyClass::Bool, "bForward", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(LDCharacterSelectWidget_eventNextCharacter_Parms), &Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::NewProp_bForward,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_bForward", "true" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
		{ "ToolTip", "????????\xc6\xae???? ?? ?\xd4\xbc??? ?????\xcf\xb1? ???\xd8\xbc?." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDCharacterSelectWidget, "NextCharacter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04080401, sizeof(LDCharacterSelectWidget_eventNextCharacter_Parms), Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDCharacterSelectWidget, "OnConfirmClicked", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDCharacterSelectWidget, "OnNextClicked", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULDCharacterSelectWidget, "OnPrevClicked", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULDCharacterSelectWidget_NoRegister()
	{
		return ULDCharacterSelectWidget::StaticClass();
	}
	struct Z_Construct_UClass_ULDCharacterSelectWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConfirmButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConfirmButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TextBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TextBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NextButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NextButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrevButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PrevButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CurrentIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDCharacterSelectWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULDCharacterSelectWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULDCharacterSelectWidget_NextCharacter, "NextCharacter" }, // 1647179786
		{ &Z_Construct_UFunction_ULDCharacterSelectWidget_OnConfirmClicked, "OnConfirmClicked" }, // 1659403457
		{ &Z_Construct_UFunction_ULDCharacterSelectWidget_OnNextClicked, "OnNextClicked" }, // 3137174868
		{ &Z_Construct_UFunction_ULDCharacterSelectWidget_OnPrevClicked, "OnPrevClicked" }, // 2474696204
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LDCharacterSelectWidget.h" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
		{ "ToolTip", "???? ?????? ?\xd6\xb4? ???\xcc\xb7?\xc5\xbb ?\xde\xbd? ?????? ?????? ????????\n   ??\xc6\xb0?? ?????????? ???\xcc\xb7?\xc5\xbb ?\xde\xbd? ??????\xc6\xae?? ?????? ???\xcc\xb7?\xc5\xbb ?\xde\xbd\xc3\xb8? ?????\xcf\xb4? ?????? ????\n   ???? ???\xe5\xbf\xa1 ?\xd6\xb4? \xc6\xaf?? \xc5\xb8???? ???\xd3\xb9??? ?????? ?????? TActorIterator<????\xc5\xb8??> ???????? ?????\xc2\xb4?" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_ConfirmButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_ConfirmButton = { UE4CodeGen_Private::EPropertyClass::Object, "ConfirmButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDCharacterSelectWidget, ConfirmButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_ConfirmButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_ConfirmButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_TextBox_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_TextBox = { UE4CodeGen_Private::EPropertyClass::Object, "TextBox", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDCharacterSelectWidget, TextBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_TextBox_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_TextBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_NextButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_NextButton = { UE4CodeGen_Private::EPropertyClass::Object, "NextButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDCharacterSelectWidget, NextButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_NextButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_NextButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_PrevButton_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_PrevButton = { UE4CodeGen_Private::EPropertyClass::Object, "PrevButton", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000080008, 1, nullptr, STRUCT_OFFSET(ULDCharacterSelectWidget, PrevButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_PrevButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_PrevButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_MaxIndex_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_MaxIndex = { UE4CodeGen_Private::EPropertyClass::Int, "MaxIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000005, 1, nullptr, STRUCT_OFFSET(ULDCharacterSelectWidget, MaxIndex), METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_MaxIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_MaxIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_CurrentIndex_MetaData[] = {
		{ "Category", "Character" },
		{ "ModuleRelativePath", "Public/LDCharacterSelectWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_CurrentIndex = { UE4CodeGen_Private::EPropertyClass::Int, "CurrentIndex", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000000005, 1, nullptr, STRUCT_OFFSET(ULDCharacterSelectWidget, CurrentIndex), METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_CurrentIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_CurrentIndex_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULDCharacterSelectWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_ConfirmButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_TextBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_NextButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_PrevButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_MaxIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDCharacterSelectWidget_Statics::NewProp_CurrentIndex,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDCharacterSelectWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDCharacterSelectWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDCharacterSelectWidget_Statics::ClassParams = {
		&ULDCharacterSelectWidget::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B010A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ULDCharacterSelectWidget_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDCharacterSelectWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDCharacterSelectWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDCharacterSelectWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDCharacterSelectWidget, 2975690516);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDCharacterSelectWidget(Z_Construct_UClass_ULDCharacterSelectWidget, &ULDCharacterSelectWidget::StaticClass, TEXT("/Script/LostDark"), TEXT("ULDCharacterSelectWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDCharacterSelectWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
