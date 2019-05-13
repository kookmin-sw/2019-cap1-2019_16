// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/Public/LDGameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDGameState() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ALDGameState_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ALDGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void ALDGameState::StaticRegisterNativesALDGameState()
	{
	}
	UClass* Z_Construct_UClass_ALDGameState_NoRegister()
	{
		return ALDGameState::StaticClass();
	}
	struct Z_Construct_UClass_ALDGameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TotalGameScore_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TotalGameScore;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALDGameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDGameState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "LDGameState.h" },
		{ "ModuleRelativePath", "Public/LDGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALDGameState_Statics::NewProp_TotalGameScore_MetaData[] = {
		{ "ModuleRelativePath", "Public/LDGameState.h" },
		{ "ToolTip", "??\xc3\xbc ???? ???\xda\xbe?" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ALDGameState_Statics::NewProp_TotalGameScore = { UE4CodeGen_Private::EPropertyClass::Int, "TotalGameScore", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000002000, 1, nullptr, STRUCT_OFFSET(ALDGameState, TotalGameScore), METADATA_PARAMS(Z_Construct_UClass_ALDGameState_Statics::NewProp_TotalGameScore_MetaData, ARRAY_COUNT(Z_Construct_UClass_ALDGameState_Statics::NewProp_TotalGameScore_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALDGameState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALDGameState_Statics::NewProp_TotalGameScore,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALDGameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALDGameState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALDGameState_Statics::ClassParams = {
		&ALDGameState::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A0u,
		nullptr, 0,
		Z_Construct_UClass_ALDGameState_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ALDGameState_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ALDGameState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ALDGameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALDGameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALDGameState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALDGameState, 2300976390);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALDGameState(Z_Construct_UClass_ALDGameState, &ALDGameState::StaticClass, TEXT("/Script/LostDark"), TEXT("ALDGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALDGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
