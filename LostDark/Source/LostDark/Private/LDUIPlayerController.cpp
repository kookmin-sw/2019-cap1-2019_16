// Fill out your copyright notice in the Description page of Project Settings.

#include "LDUIPlayerController.h"
// 추가
#include "Blueprint/UserWidget.h" // 위젯


void ALDUIPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// UIWidgetClass이 없으면 예외처리
	ABCHECK(nullptr != UIWidgetClass);
	
	// 위젯 인스턴스를 만듦
	UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
	ABCHECK(nullptr != UIWidgetInstance);

	UIWidgetInstance->AddToViewport();

	// UI에만 입력이 전달되는 변수
	FInputModeUIOnly Mode;
	Mode.SetWidgetToFocus(UIWidgetInstance->GetCachedWidget());
	// 
	SetInputMode(Mode);
	// 마우스 커서 보이기
	bShowMouseCursor = true;
}