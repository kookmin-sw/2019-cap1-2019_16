// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDSaveGame.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDSaveGame() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ULDSaveGame_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDSaveGame();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void ULDSaveGame::StaticRegisterNativesULDSaveGame()
	{
	}
	UClass* Z_Construct_UClass_ULDSaveGame_NoRegister()
	{
		return ULDSaveGame::StaticClass();
	}
	struct Z_Construct_UClass_ULDSaveGame_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HighScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_HighScore;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PlayerName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Exp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Exp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Level;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDSaveGame_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDSaveGame_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LDSaveGame.h" },
		{ "ModuleRelativePath", "Public/LDSaveGame.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDSaveGame_Statics::NewProp_HighScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULDSaveGame_Statics::NewProp_HighScore = { UE4CodeGen_Private::EPropertyClass::Int, "HighScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULDSaveGame, HighScore), METADATA_PARAMS(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_HighScore_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_HighScore_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDSaveGame_Statics::NewProp_PlayerName_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULDSaveGame_Statics::NewProp_PlayerName = { UE4CodeGen_Private::EPropertyClass::Str, "PlayerName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULDSaveGame, PlayerName), METADATA_PARAMS(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_PlayerName_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_PlayerName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Exp_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Exp = { UE4CodeGen_Private::EPropertyClass::Int, "Exp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULDSaveGame, Exp), METADATA_PARAMS(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Exp_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Exp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Level_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Level = { UE4CodeGen_Private::EPropertyClass::Int, "Level", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000000, 1, nullptr, STRUCT_OFFSET(ULDSaveGame, Level), METADATA_PARAMS(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Level_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Level_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULDSaveGame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDSaveGame_Statics::NewProp_HighScore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDSaveGame_Statics::NewProp_PlayerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Exp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDSaveGame_Statics::NewProp_Level,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDSaveGame_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDSaveGame>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDSaveGame_Statics::ClassParams = {
		&ULDSaveGame::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A0u,
		nullptr, 0,
		Z_Construct_UClass_ULDSaveGame_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULDSaveGame_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDSaveGame_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDSaveGame_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDSaveGame()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDSaveGame_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDSaveGame, 2848614502);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDSaveGame(Z_Construct_UClass_ULDSaveGame, &ULDSaveGame::StaticClass, TEXT("/Script/LostDark"), TEXT("ULDSaveGame"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDSaveGame);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
