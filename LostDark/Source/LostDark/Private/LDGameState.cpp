// Fill out your copyright notice in the Description page of Project Settings.

#include "LDGameState.h"

//Constructor
ALDGameState::ALDGameState()
{
	TotalGameScore = 0;
}

int32 ALDGameState::GetTotalGameScore() const
{
	return TotalGameScore;
}

void ALDGameState::AddGameScore()
{
	TotalGameScore++;
}
