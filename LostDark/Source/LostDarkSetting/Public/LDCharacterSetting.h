// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LDCharacterSetting.generated.h"

/**
 * 앞으로 사용할 캐릭터 애셋의 목록을 보관하는 클래스
 */
UCLASS(config=LostDark)
class LOSTDARKSETTING_API ULDCharacterSetting : public UObject
{
	GENERATED_BODY()
	
public:
	ULDCharacterSetting();

	// 애셋 목록을 보관.
	UPROPERTY(config)
		TArray<FSoftObjectPath> CharacterAssets;
};
