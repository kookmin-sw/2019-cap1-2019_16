// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOSTDARK_LDGamePlayWidget_generated_h
#error "LDGamePlayWidget.generated.h already included, missing '#pragma once' in LDGamePlayWidget.h"
#endif
#define LOSTDARK_LDGamePlayWidget_generated_h

#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnRetryGameClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnRetryGameClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnReturnToTitleClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnReturnToTitleClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnResumeClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnResumeClicked(); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRetryGameClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnRetryGameClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnReturnToTitleClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnReturnToTitleClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnResumeClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnResumeClicked(); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULDGamePlayWidget(); \
	friend struct Z_Construct_UClass_ULDGamePlayWidget_Statics; \
public: \
	DECLARE_CLASS(ULDGamePlayWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ULDGamePlayWidget)


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_INCLASS \
private: \
	static void StaticRegisterNativesULDGamePlayWidget(); \
	friend struct Z_Construct_UClass_ULDGamePlayWidget_Statics; \
public: \
	DECLARE_CLASS(ULDGamePlayWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ULDGamePlayWidget)


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULDGamePlayWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULDGamePlayWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULDGamePlayWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULDGamePlayWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULDGamePlayWidget(ULDGamePlayWidget&&); \
	NO_API ULDGamePlayWidget(const ULDGamePlayWidget&); \
public:


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULDGamePlayWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULDGamePlayWidget(ULDGamePlayWidget&&); \
	NO_API ULDGamePlayWidget(const ULDGamePlayWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULDGamePlayWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULDGamePlayWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULDGamePlayWidget)


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ResumeButton() { return STRUCT_OFFSET(ULDGamePlayWidget, ResumeButton); } \
	FORCEINLINE static uint32 __PPO__ReturnToTitleButton() { return STRUCT_OFFSET(ULDGamePlayWidget, ReturnToTitleButton); } \
	FORCEINLINE static uint32 __PPO__RetryGameButton() { return STRUCT_OFFSET(ULDGamePlayWidget, RetryGameButton); }


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_13_PROLOG
#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_RPC_WRAPPERS \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_INCLASS \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LDGamePlayWidget_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_Public_LDGamePlayWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
