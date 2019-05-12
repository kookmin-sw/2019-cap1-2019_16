// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOSTDARK_GSAnimInstance_generated_h
#error "GSAnimInstance.generated.h already included, missing '#pragma once' in GSAnimInstance.h"
#endif
#define LOSTDARK_GSAnimInstance_generated_h

#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAnimNotify_IsInputCombo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AnimNotify_IsInputCombo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAnimNotify_NextAttackCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AnimNotify_NextAttackCheck(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAnimNotify_AttackHitCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AnimNotify_AttackHitCheck(); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAnimNotify_IsInputCombo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AnimNotify_IsInputCombo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAnimNotify_NextAttackCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AnimNotify_NextAttackCheck(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAnimNotify_AttackHitCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AnimNotify_AttackHitCheck(); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGSAnimInstance(); \
	friend struct Z_Construct_UClass_UGSAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UGSAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(UGSAnimInstance)


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUGSAnimInstance(); \
	friend struct Z_Construct_UClass_UGSAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UGSAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(UGSAnimInstance)


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGSAnimInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGSAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGSAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGSAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGSAnimInstance(UGSAnimInstance&&); \
	NO_API UGSAnimInstance(const UGSAnimInstance&); \
public:


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGSAnimInstance(UGSAnimInstance&&); \
	NO_API UGSAnimInstance(const UGSAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGSAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGSAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGSAnimInstance)


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurrentPawnSpeed() { return STRUCT_OFFSET(UGSAnimInstance, CurrentPawnSpeed); } \
	FORCEINLINE static uint32 __PPO__IsInAir() { return STRUCT_OFFSET(UGSAnimInstance, IsInAir); } \
	FORCEINLINE static uint32 __PPO__IsDead() { return STRUCT_OFFSET(UGSAnimInstance, IsDead); } \
	FORCEINLINE static uint32 __PPO__AttackMontage() { return STRUCT_OFFSET(UGSAnimInstance, AttackMontage); } \
	FORCEINLINE static uint32 __PPO__DodgeMontage() { return STRUCT_OFFSET(UGSAnimInstance, DodgeMontage); }


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_16_PROLOG
#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_RPC_WRAPPERS \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_INCLASS \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_SH_Public_GSAnimInstance_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_SH_Public_GSAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
