// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UParticleSystemComponent;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef LOSTDARK_SH_ItemBox_generated_h
#error "SH_ItemBox.generated.h already included, missing '#pragma once' in SH_ItemBox.h"
#endif
#define LOSTDARK_SH_ItemBox_generated_h

#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEffectFinished) \
	{ \
		P_GET_OBJECT(UParticleSystemComponent,Z_Param_PSystem); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEffectFinished(Z_Param_PSystem); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnCharacterOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnCharacterOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEffectFinished) \
	{ \
		P_GET_OBJECT(UParticleSystemComponent,Z_Param_PSystem); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEffectFinished(Z_Param_PSystem); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnCharacterOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnCharacterOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASH_ItemBox(); \
	friend struct Z_Construct_UClass_ASH_ItemBox_Statics; \
public: \
	DECLARE_CLASS(ASH_ItemBox, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ASH_ItemBox)


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASH_ItemBox(); \
	friend struct Z_Construct_UClass_ASH_ItemBox_Statics; \
public: \
	DECLARE_CLASS(ASH_ItemBox, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ASH_ItemBox)


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASH_ItemBox(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASH_ItemBox) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASH_ItemBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASH_ItemBox); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASH_ItemBox(ASH_ItemBox&&); \
	NO_API ASH_ItemBox(const ASH_ItemBox&); \
public:


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASH_ItemBox(ASH_ItemBox&&); \
	NO_API ASH_ItemBox(const ASH_ItemBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASH_ItemBox); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASH_ItemBox); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASH_ItemBox)


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_PRIVATE_PROPERTY_OFFSET
#define LostDark_Source_LostDark_Public_SH_ItemBox_h_9_PROLOG
#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_RPC_WRAPPERS \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_INCLASS \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_Public_SH_ItemBox_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_SH_ItemBox_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_Public_SH_ItemBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
