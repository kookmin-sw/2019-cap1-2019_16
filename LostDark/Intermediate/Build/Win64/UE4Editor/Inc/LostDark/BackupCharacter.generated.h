// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOSTDARK_BackupCharacter_generated_h
#error "BackupCharacter.generated.h already included, missing '#pragma once' in BackupCharacter.h"
#endif
#define LOSTDARK_BackupCharacter_generated_h

#define LostDark_Source_LostDark_BackupCharacter_h_12_RPC_WRAPPERS
#define LostDark_Source_LostDark_BackupCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define LostDark_Source_LostDark_BackupCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABackupCharacter(); \
	friend struct Z_Construct_UClass_ABackupCharacter_Statics; \
public: \
	DECLARE_CLASS(ABackupCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ABackupCharacter)


#define LostDark_Source_LostDark_BackupCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesABackupCharacter(); \
	friend struct Z_Construct_UClass_ABackupCharacter_Statics; \
public: \
	DECLARE_CLASS(ABackupCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ABackupCharacter)


#define LostDark_Source_LostDark_BackupCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABackupCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABackupCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABackupCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABackupCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABackupCharacter(ABackupCharacter&&); \
	NO_API ABackupCharacter(const ABackupCharacter&); \
public:


#define LostDark_Source_LostDark_BackupCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABackupCharacter(ABackupCharacter&&); \
	NO_API ABackupCharacter(const ABackupCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABackupCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABackupCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABackupCharacter)


#define LostDark_Source_LostDark_BackupCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ABackupCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ABackupCharacter, FollowCamera); }


#define LostDark_Source_LostDark_BackupCharacter_h_9_PROLOG
#define LostDark_Source_LostDark_BackupCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_BackupCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_BackupCharacter_h_12_RPC_WRAPPERS \
	LostDark_Source_LostDark_BackupCharacter_h_12_INCLASS \
	LostDark_Source_LostDark_BackupCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_BackupCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_BackupCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_BackupCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_BackupCharacter_h_12_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_BackupCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_BackupCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
