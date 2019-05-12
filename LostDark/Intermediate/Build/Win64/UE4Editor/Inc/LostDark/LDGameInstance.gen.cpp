// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LostDark/SH/Public/LDGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDGameInstance() {}
// Cross Module References
	LOSTDARK_API UScriptStruct* Z_Construct_UScriptStruct_FGSCharacterData();
	UPackage* Z_Construct_UPackage__Script_LostDark();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGameInstance_NoRegister();
	LOSTDARK_API UClass* Z_Construct_UClass_ULDGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
// End Cross Module References
class UScriptStruct* FGSCharacterData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern LOSTDARK_API uint32 Get_Z_Construct_UScriptStruct_FGSCharacterData_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FGSCharacterData, Z_Construct_UPackage__Script_LostDark(), TEXT("GSCharacterData"), sizeof(FGSCharacterData), Get_Z_Construct_UScriptStruct_FGSCharacterData_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FGSCharacterData(FGSCharacterData::StaticStruct, TEXT("/Script/LostDark"), TEXT("GSCharacterData"), false, nullptr, nullptr);
static struct FScriptStruct_LostDark_StaticRegisterNativesFGSCharacterData
{
	FScriptStruct_LostDark_StaticRegisterNativesFGSCharacterData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("GSCharacterData")),new UScriptStruct::TCppStructOps<FGSCharacterData>);
	}
} ScriptStruct_LostDark_StaticRegisterNativesFGSCharacterData;
	struct Z_Construct_UScriptStruct_FGSCharacterData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NextExp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NextExp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DropExp_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_DropExp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Attack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHP_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Level;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGSCharacterData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
		{ "ToolTip", "????\xc3\xbc ???????\xd8\xb4?.\nFTableRowBase ????\xc3\xbc?? ???\xd3\xb9\xde\xbe\xc6\xbe??\xd1\xb4?." },
	};
#endif
	void* Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGSCharacterData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_NextExp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
		{ "ToolTip", "???? ????\xc4\xa1" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_NextExp = { UE4CodeGen_Private::EPropertyClass::Int, "NextExp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGSCharacterData, NextExp), METADATA_PARAMS(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_NextExp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_NextExp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_DropExp_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
		{ "ToolTip", "???????? ????\xc4\xa1" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_DropExp = { UE4CodeGen_Private::EPropertyClass::Int, "DropExp", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGSCharacterData, DropExp), METADATA_PARAMS(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_DropExp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_DropExp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Attack_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
		{ "ToolTip", "???\xdd\xb7?" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Attack = { UE4CodeGen_Private::EPropertyClass::Float, "Attack", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGSCharacterData, Attack), METADATA_PARAMS(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Attack_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Attack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_MaxHP_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
		{ "ToolTip", "?\xd6\xb4? ??????" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_MaxHP = { UE4CodeGen_Private::EPropertyClass::Float, "MaxHP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGSCharacterData, MaxHP), METADATA_PARAMS(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_MaxHP_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_MaxHP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Level_MetaData[] = {
		{ "Category", "Data" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Level = { UE4CodeGen_Private::EPropertyClass::Int, "Level", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FGSCharacterData, Level), METADATA_PARAMS(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Level_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Level_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGSCharacterData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_NextExp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_DropExp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Attack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_MaxHP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGSCharacterData_Statics::NewProp_Level,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGSCharacterData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"GSCharacterData",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FGSCharacterData),
		alignof(FGSCharacterData),
		Z_Construct_UScriptStruct_FGSCharacterData_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGSCharacterData_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FGSCharacterData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGSCharacterData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FGSCharacterData_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_LostDark();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("GSCharacterData"), sizeof(FGSCharacterData), Get_Z_Construct_UScriptStruct_FGSCharacterData_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FGSCharacterData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FGSCharacterData_CRC() { return 3140597635U; }
	void ULDGameInstance::StaticRegisterNativesULDGameInstance()
	{
	}
	UClass* Z_Construct_UClass_ULDGameInstance_NoRegister()
	{
		return ULDGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_ULDGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GSCharacterTable_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GSCharacterTable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULDGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_LostDark,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGameInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SH/Public/LDGameInstance.h" },
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULDGameInstance_Statics::NewProp_GSCharacterTable_MetaData[] = {
		{ "ModuleRelativePath", "SH/Public/LDGameInstance.h" },
		{ "ToolTip", "?????? ???\xcc\xba? ?????\xcf\xb1? ???? ????. ???? ?????? ?? ?????? ??." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULDGameInstance_Statics::NewProp_GSCharacterTable = { UE4CodeGen_Private::EPropertyClass::Object, "GSCharacterTable", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ULDGameInstance, GSCharacterTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULDGameInstance_Statics::NewProp_GSCharacterTable_MetaData, ARRAY_COUNT(Z_Construct_UClass_ULDGameInstance_Statics::NewProp_GSCharacterTable_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULDGameInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULDGameInstance_Statics::NewProp_GSCharacterTable,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULDGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULDGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULDGameInstance_Statics::ClassParams = {
		&ULDGameInstance::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x001000A8u,
		nullptr, 0,
		Z_Construct_UClass_ULDGameInstance_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ULDGameInstance_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ULDGameInstance_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ULDGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULDGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULDGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULDGameInstance, 4269155188);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULDGameInstance(Z_Construct_UClass_ULDGameInstance, &ULDGameInstance::StaticClass, TEXT("/Script/LostDark"), TEXT("ULDGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULDGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
