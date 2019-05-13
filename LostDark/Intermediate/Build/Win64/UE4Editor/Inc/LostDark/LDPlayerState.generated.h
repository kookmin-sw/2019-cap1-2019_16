// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOSTDARK_LDPlayerState_generated_h
#error "LDPlayerState.generated.h already included, missing '#pragma once' in LDPlayerState.h"
#endif
#define LOSTDARK_LDPlayerState_generated_h

#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_RPC_WRAPPERS
#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALDPlayerState(); \
	friend struct Z_Construct_UClass_ALDPlayerState_Statics; \
public: \
	DECLARE_CLASS(ALDPlayerState, APlayerState, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ALDPlayerState)


#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_INCLASS \
private: \
	static void StaticRegisterNativesALDPlayerState(); \
	friend struct Z_Construct_UClass_ALDPlayerState_Statics; \
public: \
	DECLARE_CLASS(ALDPlayerState, APlayerState, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ALDPlayerState)


#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALDPlayerState(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALDPlayerState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALDPlayerState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALDPlayerState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALDPlayerState(ALDPlayerState&&); \
	NO_API ALDPlayerState(const ALDPlayerState&); \
public:


#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALDPlayerState(ALDPlayerState&&); \
	NO_API ALDPlayerState(const ALDPlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALDPlayerState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALDPlayerState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALDPlayerState)


#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__GameScore() { return STRUCT_OFFSET(ALDPlayerState, GameScore); } \
	FORCEINLINE static uint32 __PPO__CharacterLevel() { return STRUCT_OFFSET(ALDPlayerState, CharacterLevel); } \
	FORCEINLINE static uint32 __PPO__Exp() { return STRUCT_OFFSET(ALDPlayerState, Exp); }


#define LostDark_Source_LostDark_Public_LDPlayerState_h_15_PROLOG
#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_RPC_WRAPPERS \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_INCLASS \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_Public_LDPlayerState_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LDPlayerState_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_Public_LDPlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
