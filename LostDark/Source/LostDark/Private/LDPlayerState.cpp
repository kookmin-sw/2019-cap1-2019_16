// Fill out your copyright notice in the Description page of Project Settings.

#include "LDPlayerState.h"
// 추가
#include "LDGameInstance.h"

// Constructor
ALDPlayerState::ALDPlayerState()
{
	CharacterLevel = 1;
	GameScore = 0;
	Exp = 0;
}

int32 ALDPlayerState::GetGameScore() const
{
	return GameScore;
}

int32 ALDPlayerState::GetCharacterLevel() const
{
	return CharacterLevel;
}

void ALDPlayerState::InitPlayerData()
{
	// 캐릭터 닉네임 설정.
	SetPlayerName(TEXT("Destiny"));
	SetCharacterLevel(5);
	GameScore = 0;
	Exp = 0;
}

float ALDPlayerState::GetExpRatio() const
{
	// 스텟 정보의 NextExp가 0보다 작다면
	if (CurrentStateData->NextExp <= KINDA_SMALL_NUMBER)
		return 0.0f;
	// 경험치 바 비율(%) 계산. 현재 습득 경험치 / 전체 경험치 
	float Result = (float)Exp / (float)CurrentStateData->NextExp;
	// 비율, 현재, 전체
	ABLOG(Warning, TEXT("Ratio : %f, Current : %d, Next : %d"), Result, Exp, CurrentStateData->NextExp);
	return Result;
}

bool ALDPlayerState::AddExp(int32 IncomeExp)
{
	// 다음 경험치가 없다면  (최대 레벨)
	if(CurrentStateData->NextExp==-1)
		return false;

	bool DidLevelup = false;
	Exp = Exp + IncomeExp;
	// 경험치가 최대 경험치를 넘어갔다면
	if (Exp >= CurrentStateData->NextExp)
	{
		// 모든 경험치 초기화
		Exp -= CurrentStateData->NextExp;
		// 레벨업 1
		SetCharacterLevel(CharacterLevel + 1);
		DidLevelup = true;
	}

	// 스테이트 변경
	OnPlayerStateChanged.Broadcast();
	return DidLevelup;
}

void ALDPlayerState::AddGameScore()
{
	GameScore++;
	OnPlayerStateChanged.Broadcast();
}


void ALDPlayerState::SetCharacterLevel(int32 NewCharacterLevel)
{
	auto LDGameInstance = Cast<ULDGameInstance>(GetGameInstance());
	ABCHECK(nullptr != LDGameInstance);

	// 현재 게임 데이터를 게임인스턴스에서 가져옴
	CurrentStateData = LDGameInstance->GetGSCharacterData(NewCharacterLevel);
	ABCHECK(nullptr != CurrentStateData);

	CharacterLevel = NewCharacterLevel;
}