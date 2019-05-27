// Fill out your copyright notice in the Description page of Project Settings.

#include "LDGamePlayResultWidget.h"
//
#include "Components/TextBlock.h"
#include "LDGameState.h"

void ULDGamePlayResultWidget::BindGameState(ALDGameState* GameState)
{
	ABCHECK(GameState != nullptr);
	// 게임스테이트 정보를 등록
	CurrentGameState = GameState;
}

// 해당 위젯이 추가됐을때 불리어지는 함수(Add to Viewport)
void ULDGamePlayResultWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 게임스테이트 정보가 미리 바인딩 됐는지 체크
	ABCHECK(CurrentGameState.IsValid());

	auto Result = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtResult")));
	ABCHECK(Result != nullptr);
	Result->SetText(FText::FromString(CurrentGameState->IsGameCleared() ? TEXT("Mission Complete") : TEXT("Mission Failed")));

	auto TotalScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtTotalScore")));
	ABCHECK(TotalScore != nullptr);
	TotalScore->SetText(FText::FromString(FString::FromInt(CurrentGameState->GetTotalGameScore())));
}