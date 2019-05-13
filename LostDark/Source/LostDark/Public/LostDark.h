// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

/*
	EngineMinimal vs CoreMinimal
	최소한의 선언을 지정하기 위해 CoreMinimal이 선언되는데,
	대부분의 경우 엔진 기능을 사용하기 때문에 EngineMinimal을 지정한다.
*/
#include "EngineMinimal.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	PREINIT,
	LOADING,
	READY,
	DEAD
};

DECLARE_LOG_CATEGORY_EXTERN(LostDark, Log, All);
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(LostDark, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(LostDark, Verbosity, TEXT("%s %s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
// 매크로 안의 조건이 참이 아닌경우 로그가 붉게 띄고 바로 함수 반환함.
#define ABCHECK(Expr, ...) {if(!(Expr)) { ABLOG(Error,TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; } }