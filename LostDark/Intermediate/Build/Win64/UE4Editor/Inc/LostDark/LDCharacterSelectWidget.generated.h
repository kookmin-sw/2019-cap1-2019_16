// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LOSTDARK_LDCharacterSelectWidget_generated_h
#error "LDCharacterSelectWidget.generated.h already included, missing '#pragma once' in LDCharacterSelectWidget.h"
#endif
#define LOSTDARK_LDCharacterSelectWidget_generated_h

#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnConfirmClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnConfirmClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnNextClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnNextClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnPrevClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnPrevClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNextCharacter) \
	{ \
		P_GET_UBOOL(Z_Param_bForward); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->NextCharacter(Z_Param_bForward); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnConfirmClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnConfirmClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnNextClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnNextClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnPrevClicked) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnPrevClicked(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNextCharacter) \
	{ \
		P_GET_UBOOL(Z_Param_bForward); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->NextCharacter(Z_Param_bForward); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULDCharacterSelectWidget(); \
	friend struct Z_Construct_UClass_ULDCharacterSelectWidget_Statics; \
public: \
	DECLARE_CLASS(ULDCharacterSelectWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ULDCharacterSelectWidget)


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_INCLASS \
private: \
	static void StaticRegisterNativesULDCharacterSelectWidget(); \
	friend struct Z_Construct_UClass_ULDCharacterSelectWidget_Statics; \
public: \
	DECLARE_CLASS(ULDCharacterSelectWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ULDCharacterSelectWidget)


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULDCharacterSelectWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULDCharacterSelectWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULDCharacterSelectWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULDCharacterSelectWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULDCharacterSelectWidget(ULDCharacterSelectWidget&&); \
	NO_API ULDCharacterSelectWidget(const ULDCharacterSelectWidget&); \
public:


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULDCharacterSelectWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULDCharacterSelectWidget(ULDCharacterSelectWidget&&); \
	NO_API ULDCharacterSelectWidget(const ULDCharacterSelectWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULDCharacterSelectWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULDCharacterSelectWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULDCharacterSelectWidget)


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurrentIndex() { return STRUCT_OFFSET(ULDCharacterSelectWidget, CurrentIndex); } \
	FORCEINLINE static uint32 __PPO__MaxIndex() { return STRUCT_OFFSET(ULDCharacterSelectWidget, MaxIndex); } \
	FORCEINLINE static uint32 __PPO__PrevButton() { return STRUCT_OFFSET(ULDCharacterSelectWidget, PrevButton); } \
	FORCEINLINE static uint32 __PPO__NextButton() { return STRUCT_OFFSET(ULDCharacterSelectWidget, NextButton); } \
	FORCEINLINE static uint32 __PPO__TextBox() { return STRUCT_OFFSET(ULDCharacterSelectWidget, TextBox); } \
	FORCEINLINE static uint32 __PPO__ConfirmButton() { return STRUCT_OFFSET(ULDCharacterSelectWidget, ConfirmButton); }


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_14_PROLOG
#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_RPC_WRAPPERS \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_INCLASS \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_Public_LDCharacterSelectWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
