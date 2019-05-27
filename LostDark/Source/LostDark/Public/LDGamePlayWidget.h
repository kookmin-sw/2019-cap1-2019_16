// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Blueprint/UserWidget.h"
#include "LDGamePlayWidget.generated.h"

/**
 *	UI_Menu 애셋이 사용할 클래스
	UI_Result 애셋이 사용할 클래스
 */
UCLASS()
class LOSTDARK_API ULDGamePlayWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	// 이 위젯을 뷰포트에 추가했을때 불리어지는 함수
	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnResumeClicked();
	UFUNCTION()
		void OnReturnToTitleClicked();
	UFUNCTION()
		void OnRetryGameClicked();
protected:
	// 둘다 공용
	UPROPERTY()
		class UButton* ResumeButton;
	// 둘다 공용
	UPROPERTY()
		class UButton* ReturnToTitleButton;
	// Result UI에서 사용
	UPROPERTY()
		class UButton* RetryGameButton;
};
