// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOSTDARK_YJCharacter_generated_h
#error "YJCharacter.generated.h already included, missing '#pragma once' in YJCharacter.h"
#endif
#define LOSTDARK_YJCharacter_generated_h

#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_RPC_WRAPPERS \
	virtual void AddMP_Implementation(); \
	virtual void ReduceMP_Implementation(); \
	virtual void AddHP_Implementation(); \
	virtual void ReduceHP_Implementation(); \
 \
	DECLARE_FUNCTION(execAddMP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddMP_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceMP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReduceMP_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddHP_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReduceHP_Implementation(); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void AddMP_Implementation(); \
	virtual void ReduceMP_Implementation(); \
	virtual void AddHP_Implementation(); \
	virtual void ReduceHP_Implementation(); \
 \
	DECLARE_FUNCTION(execAddMP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddMP_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceMP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReduceMP_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddHP_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReduceHP) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ReduceHP_Implementation(); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_EVENT_PARMS
#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_CALLBACK_WRAPPERS
#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYJCharacter(); \
	friend struct Z_Construct_UClass_AYJCharacter_Statics; \
public: \
	DECLARE_CLASS(AYJCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(AYJCharacter)


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAYJCharacter(); \
	friend struct Z_Construct_UClass_AYJCharacter_Statics; \
public: \
	DECLARE_CLASS(AYJCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(AYJCharacter)


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AYJCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AYJCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYJCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYJCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AYJCharacter(AYJCharacter&&); \
	NO_API AYJCharacter(const AYJCharacter&); \
public:


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AYJCharacter(AYJCharacter&&); \
	NO_API AYJCharacter(const AYJCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYJCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYJCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AYJCharacter)


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_PRIVATE_PROPERTY_OFFSET
#define LostDark_Source_LostDark_YJ_YJCharacter_h_9_PROLOG \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_EVENT_PARMS


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_RPC_WRAPPERS \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_CALLBACK_WRAPPERS \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_INCLASS \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_YJ_YJCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_CALLBACK_WRAPPERS \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_YJ_YJCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_YJ_YJCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
