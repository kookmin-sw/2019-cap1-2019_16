// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Blueprint/UserWidget.h"
#include "LDHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API ULDHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindCharacterStat(class UGSCharacterStatComponent* CharacterStat);
	void BindPlayerState(class ALDPlayerState* PlayerState);

protected:
	virtual void NativeConstruct() override;
	void UpdateCharacterStat();
	void UpdatePlayerState();

private:
	TWeakObjectPtr<class UGSCharacterStatComponent> CurrentCharacterStat;
	TWeakObjectPtr<class ALDPlayerState> CurrentPlayerState;

	UPROPERTY()
		class UProgressBar* HPBar;
	UPROPERTY()
		class UProgressBar* ExpBar;
	UPROPERTY()
		class UTextBlock* PlayerName;
	UPROPERTY()
		class UTextBlock* PlayerLevel;
	UPROPERTY()
		class UTextBlock* CurrentScore;
	UPROPERTY()
		class UTextBlock* HighScore;
};
