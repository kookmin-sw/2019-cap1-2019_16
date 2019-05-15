// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "GameFramework/PlayerController.h"
#include "LDUIPlayerController.generated.h"

/*
 *	UI 전용 플레이어 컨트롤러 클래스.
	게임이 시작되면 해당 클래스로부터 UI를 생성하고 이를 Viewport에 띄우고 입력은 UI에만 전달하도록 제작한다.
 */
UCLASS()
class LOSTDARK_API ALDUIPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	// 위젯 클래스정보
	UPROPERTY(EditDefaultsOnly, BlueprintReadwrite, Category = UI)
		TSubclassOf<class UUserWidget> UIWidgetClass;

	// 위젯 인스턴스
	UPROPERTY()
		class UUserWidget* UIWidgetInstance;
	
};
