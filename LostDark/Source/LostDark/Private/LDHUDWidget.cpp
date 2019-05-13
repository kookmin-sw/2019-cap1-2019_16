// Fill out your copyright notice in the Description page of Project Settings.

#include "LDHUDWidget.h"
// 추가한 헤더
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "GSCharacterStatComponent.h"
#include "LDPlayerState.h"

// 캐릭터 스텟과 HUD 연동
void ULDHUDWidget::BindCharacterStat(class UGSCharacterStatComponent* CharacterStat)
{
	ABCHECK(nullptr != CharacterStat);
	CurrentCharacterStat = CharacterStat;
	// 캐릭터 스텟의 OnHPChanged가 발생하면 아래 함수를 실행
	CharacterStat->OnHPChanged.AddUObject(this, &ULDHUDWidget::UpdateCharacterStat);
}

// 캐릭터 스테이트와 HUD 연동
void ULDHUDWidget::BindPlayerState(ALDPlayerState * PlayerState)
{
	ABCHECK(nullptr != PlayerState);
	CurrentPlayerState = PlayerState;
	// 캐릭터 스테이트가 바뀌면 아래 함수를 실행
	PlayerState->OnPlayerStateChanged.AddUObject(this, &ULDHUDWidget::UpdatePlayerState);
}

void ULDHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// 위젯에 만든 변수명과 동일한 컴포넌트들을 가져오는것.
	HPBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("pbHP")));
	ABCHECK(nullptr != HPBar);

	ExpBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("pbExp")));
	ABCHECK(nullptr != ExpBar);

	PlayerName = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtPlayerName")));
	ABCHECK(nullptr != PlayerName);

	PlayerLevel = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtLevel")));
	ABCHECK(nullptr != PlayerLevel);

	CurrentScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtCurrentScore")));
	ABCHECK(nullptr != CurrentScore);

	HighScore = Cast<UTextBlock>(GetWidgetFromName(TEXT("txtHighScore")));
	ABCHECK(nullptr != HighScore);
}

void ULDHUDWidget::UpdateCharacterStat()
{
	ABCHECK(CurrentCharacterStat.IsValid());
	HPBar->SetPercent(CurrentCharacterStat->GetHPRatio());
}

void ULDHUDWidget::UpdatePlayerState()
{
	ABCHECK(CurrentPlayerState.IsValid());

	// Exp바 설정
	ExpBar->SetPercent(CurrentPlayerState->GetExpRatio());
	PlayerName->SetText(FText::FromString(CurrentPlayerState->GetPlayerName()));
	PlayerLevel->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetCharacterLevel())));
	CurrentScore->SetText(FText::FromString(FString::FromInt(CurrentPlayerState->GetGameScore())));
}
