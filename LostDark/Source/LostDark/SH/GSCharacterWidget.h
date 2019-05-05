// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Blueprint/UserWidget.h"
#include "GSCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API UGSCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Progress Bar를 실질적으로 업데이트할 함수.
	void BindCharacterStat(class UGSCharacterStatComponent* NewCharacterStat);

private:
	// 약 포인터로 선언된 우리 캐릭터의 스탯정보 컴포넌트(Actor Component)
	TWeakObjectPtr<class UGSCharacterStatComponent> CurrentCharacterStat;
};
