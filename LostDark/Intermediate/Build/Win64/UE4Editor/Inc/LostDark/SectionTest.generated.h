// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef LOSTDARK_SectionTest_generated_h
#error "SectionTest.generated.h already included, missing '#pragma once' in SectionTest.h"
#endif
#define LOSTDARK_SectionTest_generated_h

#define LostDark_Source_LostDark_Public_SectionTest_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnKeyAIDestroyed) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DestroyedActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnKeyAIDestroyed(Z_Param_DestroyedActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnGateTriggerBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnGateTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_SectionTest_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnKeyAIDestroyed) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DestroyedActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnKeyAIDestroyed(Z_Param_DestroyedActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnGateTriggerBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnGateTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnTriggerBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define LostDark_Source_LostDark_Public_SectionTest_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASectionTest(); \
	friend struct Z_Construct_UClass_ASectionTest_Statics; \
public: \
	DECLARE_CLASS(ASectionTest, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ASectionTest)


#define LostDark_Source_LostDark_Public_SectionTest_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASectionTest(); \
	friend struct Z_Construct_UClass_ASectionTest_Statics; \
public: \
	DECLARE_CLASS(ASectionTest, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/LostDark"), NO_API) \
	DECLARE_SERIALIZER(ASectionTest)


#define LostDark_Source_LostDark_Public_SectionTest_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASectionTest(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASectionTest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASectionTest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASectionTest); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASectionTest(ASectionTest&&); \
	NO_API ASectionTest(const ASectionTest&); \
public:


#define LostDark_Source_LostDark_Public_SectionTest_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASectionTest(ASectionTest&&); \
	NO_API ASectionTest(const ASectionTest&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASectionTest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASectionTest); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASectionTest)


#define LostDark_Source_LostDark_Public_SectionTest_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh() { return STRUCT_OFFSET(ASectionTest, Mesh); } \
	FORCEINLINE static uint32 __PPO__Trigger() { return STRUCT_OFFSET(ASectionTest, Trigger); } \
	FORCEINLINE static uint32 __PPO__GateMeshes() { return STRUCT_OFFSET(ASectionTest, GateMeshes); } \
	FORCEINLINE static uint32 __PPO__GateTriggers() { return STRUCT_OFFSET(ASectionTest, GateTriggers); } \
	FORCEINLINE static uint32 __PPO__bNoBattle() { return STRUCT_OFFSET(ASectionTest, bNoBattle); } \
	FORCEINLINE static uint32 __PPO__NPCSpawnTime() { return STRUCT_OFFSET(ASectionTest, NPCSpawnTime); } \
	FORCEINLINE static uint32 __PPO__ItemBoxSpawnTime() { return STRUCT_OFFSET(ASectionTest, ItemBoxSpawnTime); }


#define LostDark_Source_LostDark_Public_SectionTest_h_9_PROLOG
#define LostDark_Source_LostDark_Public_SectionTest_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_SectionTest_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_SectionTest_h_12_RPC_WRAPPERS \
	LostDark_Source_LostDark_Public_SectionTest_h_12_INCLASS \
	LostDark_Source_LostDark_Public_SectionTest_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LostDark_Source_LostDark_Public_SectionTest_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LostDark_Source_LostDark_Public_SectionTest_h_12_PRIVATE_PROPERTY_OFFSET \
	LostDark_Source_LostDark_Public_SectionTest_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_SectionTest_h_12_INCLASS_NO_PURE_DECLS \
	LostDark_Source_LostDark_Public_SectionTest_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LostDark_Source_LostDark_Public_SectionTest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
