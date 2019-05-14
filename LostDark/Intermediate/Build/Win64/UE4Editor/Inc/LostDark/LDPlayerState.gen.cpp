// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDPlayerState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDPlayerState() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALDPlayerState_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALDPlayerState();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void ALDPlayerState::StaticRegisterNativesALDPlayerState()
	{
	}
	UClass* Z_Construct_UClass_ALDPlayerState_NoRegister()
	{
		return ALDPlayerState::StaticClass();
	}
	struct Z_Construct_UClass_ALDPlayerState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Exp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Exp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterLevel_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CharacterLevel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameHighScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_GameHighScore;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_GameScore;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALDPlayerState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerState,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDPlayerState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LDPlayerState.h" },
		{ "ModuleRelativePath", "Public/LDPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDPlayerState_Statics::NewProp_Exp_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDPlayerState.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALDPlayerState_Statics::NewProp_Exp = { UE4CodeGen_Private::EPropertyClass::Int, "Exp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000002000, 1, nullptr, STRUCT_OFFSET(ALDPlayerState, Exp), METADATA_PARAMS(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_Exp_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_Exp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDPlayerState_Statics::NewProp_CharacterLevel_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDPlayerState.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALDPlayerState_Statics::NewProp_CharacterLevel = { UE4CodeGen_Private::EPropertyClass::Int, "CharacterLevel", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000002000, 1, nullptr, STRUCT_OFFSET(ALDPlayerState, CharacterLevel), METADATA_PARAMS(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_CharacterLevel_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_CharacterLevel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameHighScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDPlayerState.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameHighScore = { UE4CodeGen_Private::EPropertyClass::Int, "GameHighScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000002000, 1, nullptr, STRUCT_OFFSET(ALDPlayerState, GameHighScore), METADATA_PARAMS(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameHighScore_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameHighScore_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDPlayerState.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameScore = { UE4CodeGen_Private::EPropertyClass::Int, "GameScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0020080000002000, 1, nullptr, STRUCT_OFFSET(ALDPlayerState, GameScore), METADATA_PARAMS(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameScore_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameScore_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALDPlayerState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDPlayerState_Statics::NewProp_Exp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDPlayerState_Statics::NewProp_CharacterLevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameHighScore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDPlayerState_Statics::NewProp_GameScore,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALDPlayerState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALDPlayerState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALDPlayerState_Statics::ClassParams = {
		&ALDPlayerState::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		nullptr, 0,
		Z_Construct_UClass_ALDPlayerState_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALDPlayerState_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALDPlayerState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALDPlayerState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALDPlayerState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALDPlayerState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALDPlayerState, 1403620570);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALDPlayerState(Z_Construct_UClass_ALDPlayerState, &ALDPlayerState::StaticClass, TEXT("/Script/LostDark"), TEXT("ALDPlayerState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALDPlayerState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
