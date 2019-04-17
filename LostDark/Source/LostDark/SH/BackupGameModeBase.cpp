// Fill out your copyright notice in the Description page of Project Settings.

#include "BackupGameModeBase.h"
#include "BackupCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABackupGameModeBase::ABackupGameModeBase()
{
	// set default pawn class to our Blueprinted character(3인칭 마네킹). Auto Possesss Player 0번이 우선순위가 더 높다.
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class; // 클래스 정보를 넘겨줘야함.
	}
}
