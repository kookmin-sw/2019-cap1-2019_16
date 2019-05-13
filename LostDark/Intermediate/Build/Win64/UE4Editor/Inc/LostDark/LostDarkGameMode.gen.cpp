// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LostDarkGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLostDarkGameMode() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALostDarkGameMode_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALostDarkGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	LOSTDARK_API UClass* Z_Construct_UClass_ALDGameState_NoRegister();
// End Cross Module References
	void ALostDarkGameMode::StaticRegisterNativesALostDarkGameMode()
	{
	}
	UClass* Z_Construct_UClass_ALostDarkGameMode_NoRegister()
	{
		return ALostDarkGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ALostDarkGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LDGameState_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LDGameState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALostDarkGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LostDarkGameMode.h" },
		{ "ModuleRelativePath", "Public/LostDarkGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "minimalapi = \xc5\xac???? ??????.\n????, ?????? ???? ???????? ?\xee\xb6\xbb?? ?\xdb\xb5??\xcf\xb4??? ???\xee\xb0\xa1??.\n\xc5\xac?????? ?? ?????? ?\xd9\xb8? ?????? ?????? ?? ?\xd6\xb5??? ????.\n?? \xc5\xac?????? ????\xc8\xaf?? ??????????, ?? ?\xd4\xbc??? \xc8\xa3???? ?? ????.\n?????? ?\xc3\xb0??? ??????.\nhttp://api.unrealengine.com/KOR/Programming/UnrealArchitecture/Reference/Classes/" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALostDarkGameMode_Statics::NewProp_LDGameState_MetaData[] = {
		{ "ModuleRelativePath", "Public/LostDarkGameMode.h" },
		{ "ToolTip", "??\xc3\xbc ???? ??????\xc6\xae (??\xc3\xbc ???? ???\xda\xbe\xee\xb8\xa6 ????)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALostDarkGameMode_Statics::NewProp_LDGameState = { UE4CodeGen_Private::EPropertyClass::Object, "LDGameState", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ALostDarkGameMode, LDGameState), Z_Construct_UClass_ALDGameState_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALostDarkGameMode_Statics::NewProp_LDGameState_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALostDarkGameMode_Statics::NewProp_LDGameState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALostDarkGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALostDarkGameMode_Statics::NewProp_LDGameState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALostDarkGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALostDarkGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALostDarkGameMode_Statics::ClassParams = {
		&ALostDarkGameMode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008802A8u,
		nullptr, 0,
		Z_Construct_UClass_ALostDarkGameMode_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALostDarkGameMode_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALostDarkGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALostDarkGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALostDarkGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALostDarkGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALostDarkGameMode, 156917324);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALostDarkGameMode(Z_Construct_UClass_ALostDarkGameMode, &ALostDarkGameMode::StaticClass, TEXT("/Script/LostDark"), TEXT("ALostDarkGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALostDarkGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
