// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef LOSTDARK_LostDarkCharacter_generated_h
#error "LostDarkCharacter.generated.h already included, missing '#pragma once' in LostDarkCharacter.h"
#endif
#define LOSTDARK_LostDarkCharacter_generated_h

#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnDodgeMontageEnded) \
	{ \
		P_GET_OBJECT(UAnimMontage,Z_Param_Montage); \
		P_GET_UBOOL(Z_Param_bInterrupted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnDodgeMontageEnded(Z_Param_Montage,Z_Param_bInterrupted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnAttackMontageEnded) \
	{ \
		P_GET_OBJECT(UAnimMontage,Z_Param_Montage); \
		P_GET_UBOOL(Z_Param_bInterrupted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnAttackMontageEnded(Z_Param_Montage,Z_Param_bInterrupted); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnDodgeMontageEnded) \
	{ \
		P_GET_OBJECT(UAnimMontage,Z_Param_Montage); \
		P_GET_UBOOL(Z_Param_bInterrupted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnDodgeMontageEnded(Z_Param_Montage,Z_Param_bInterrupted); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnAttackMontageEnded) \
	{ \
		P_GET_OBJECT(UAnimMontage,Z_Param_Montage); \
		P_GET_UBOOL(Z_Param_bInterrupted); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnAttackMontageEnded(Z_Param_Montage,Z_Param_bInterrupted); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_EVENT_PARMS
#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_CALLBACK_WRAPPERS
#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALostDarkCharacter(); \
	friend struct Z_Construct_UClass_ALostDarkCharacter_Statics; \
public: \
	DECLARE_CLASS(ALostDarkCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ALostDarkCharacter)


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesALostDarkCharacter(); \
	friend struct Z_Construct_UClass_ALostDarkCharacter_Statics; \
public: \
	DECLARE_CLASS(ALostDarkCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ALostDarkCharacter)


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALostDarkCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALostDarkCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALostDarkCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALostDarkCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALostDarkCharacter(ALostDarkCharacter&&); \
	NO_API ALostDarkCharacter(const ALostDarkCharacter&); \
public:


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALostDarkCharacter(ALostDarkCharacter&&); \
	NO_API ALostDarkCharacter(const ALostDarkCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALostDarkCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALostDarkCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALostDarkCharacter)


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__IsAttacking() { return STRUCT_OFFSET(ALostDarkCharacter, IsAttacking); } \
	FORCEINLINE static uint32 __PPO__CanNextCombo() { return STRUCT_OFFSET(ALostDarkCharacter, CanNextCombo); } \
	FORCEINLINE static uint32 __PPO__IsComboInputOn() { return STRUCT_OFFSET(ALostDarkCharacter, IsComboInputOn); } \
	FORCEINLINE static uint32 __PPO__CurrentCombo() { return STRUCT_OFFSET(ALostDarkCharacter, CurrentCombo); } \
	FORCEINLINE static uint32 __PPO__MaxCombo() { return STRUCT_OFFSET(ALostDarkCharacter, MaxCombo); } \
	FORCEINLINE static uint32 __PPO__GSAnim() { return STRUCT_OFFSET(ALostDarkCharacter, GSAnim); } \
	FORCEINLINE static uint32 __PPO__AttackRange() { return STRUCT_OFFSET(ALostDarkCharacter, AttackRange); } \
	FORCEINLINE static uint32 __PPO__AttackRadius() { return STRUCT_OFFSET(ALostDarkCharacter, AttackRadius); } \
	FORCEINLINE static uint32 __PPO__CurrentState() { return STRUCT_OFFSET(ALostDarkCharacter, CurrentState); } \
	FORCEINLINE static uint32 __PPO__bIsPlayer() { return STRUCT_OFFSET(ALostDarkCharacter, bIsPlayer); } \
	FORCEINLINE static uint32 __PPO__LDAIController() { return STRUCT_OFFSET(ALostDarkCharacter, LDAIController); } \
	FORCEINLINE static uint32 __PPO__LDPlayerController() { return STRUCT_OFFSET(ALostDarkCharacter, LDPlayerController); } \
	FORCEINLINE static uint32 __PPO__DeadTimer() { return STRUCT_OFFSET(ALostDarkCharacter, DeadTimer); } \
	FORCEINLINE static uint32 __PPO__IsDodge() { return STRUCT_OFFSET(ALostDarkCharacter, IsDodge); } \
	FORCEINLINE static uint32 __PPO__DodgeSpeed() { return STRUCT_OFFSET(ALostDarkCharacter, DodgeSpeed); }


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_18_PROLOG \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_EVENT_PARMS


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_RPC_WRAPPERS \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_CALLBACK_WRAPPERS \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_INCLASS \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_CALLBACK_WRAPPERS \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LostDarkCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_Public_LostDarkCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
