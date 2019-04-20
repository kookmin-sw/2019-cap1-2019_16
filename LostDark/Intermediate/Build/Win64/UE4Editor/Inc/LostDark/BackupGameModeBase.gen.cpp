// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/BackupGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBackupGameModeBase() {}
// Cross Module References
	LOSTDARK_API UClass* Z_Construct_UClass_ABackupGameModeBase_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ABackupGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_LostDark();
// End Cross Module References
	void ABackupGameModeBase::StaticRegisterNativesABackupGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABackupGameModeBase_NoRegister()
	{
		return ABackupGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABackupGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABackupGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABackupGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SH/BackupGameModeBase.h" },
		{ "ModuleRelativePath", "SH/BackupGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "minimalapi = \xc5\xac???? ??????.\n????, ?????? ???? ???????? ?\xee\xb6\xbb?? ?\xdb\xb5??\xcf\xb4??? ???\xee\xb0\xa1??.\n\xc5\xac?????? ?? ?????? ?\xd9\xb8? ?????? ?????? ?? ?\xd6\xb5??? ????.\n?? \xc5\xac?????? ????\xc8\xaf?? ??????????, ?? ?\xd4\xbc??? \xc8\xa3???? ?? ????.\n?????? ?\xc3\xb0??? ??????.\nhttp://api.unrealengine.com/KOR/Programming/UnrealArchitecture/Reference/Classes/" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABackupGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABackupGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABackupGameModeBase_Statics::ClassParams = {
		&ABackupGameModeBase::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002A8u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ABackupGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ABackupGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABackupGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABackupGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABackupGameModeBase, 3465801573);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABackupGameModeBase(Z_Construct_UClass_ABackupGameModeBase, &ABackupGameModeBase::StaticClass, TEXT("/Script/LostDark"), TEXT("ABackupGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABackupGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
