// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "GameFramework/PlayerController.h"
#include "LostDarkPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API ALostDarkPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	// Constructor
	ALostDarkPlayerController();

	//virtual void PostInitializeComponents() override;
	//virtual void Possess(APawn* aPawn) override;

	class ULDHUDWidget* GetHUDWidget() const;

	void AIKill(class ALostDarkCharacter* KiiledAI) const;
	// 게임 스코어를 올릴때
	void AddGameScore() const;

protected:
	virtual void BeginPlay() override;
	//virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class ULDHUDWidget> HUDWidgetClass;

private:
	UPROPERTY()
		class ULDHUDWidget* HUDWidget;
	UPROPERTY()
		class ALDPlayerState* LDPlayerState;
};
