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
	// Input모드를 변경
	void ChangeInputMode(bool bGameMode = true);
	
	// 결과 UI
	void ShowResultUI();

protected:
	virtual void BeginPlay() override;
	// 플레이어 컨트롤러에 있는 함수. 
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class ULDHUDWidget> HUDWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class ULDGamePlayWidget> MenuWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class ULDGamePlayResultWidget> ResultWidgetClass;

private:
	// 게임중지 함수
	void OnGamePause();

	UPROPERTY()
		class ULDHUDWidget* HUDWidget;
	UPROPERTY()
		class ALDPlayerState* LDPlayerState;

	UPROPERTY()
		class ULDGamePlayWidget* MenuWidget;
	UPROPERTY()
		class ULDGamePlayResultWidget* ResultWidget;

	// 게임에만 클릭이 전달
	FInputModeGameOnly GameInputMode;
	// UI에만 클릭이 전달
	FInputModeUIOnly UIInputMode;
};
