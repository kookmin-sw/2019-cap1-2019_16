// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "GameFramework/SaveGame.h"
#include "LDSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API ULDSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	// Constructor
	ULDSaveGame();

	UPROPERTY()
		int32 Level;
	UPROPERTY()
		int32 Exp;
	UPROPERTY()
		FString PlayerName;
	UPROPERTY()
		int32 HighScore;
};
