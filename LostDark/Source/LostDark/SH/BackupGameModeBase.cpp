// Fill out your copyright notice in the Description page of Project Settings.

#include "BackupGameModeBase.h"
#include "BackupCharacter.h"
#include "UObject/ConstructorHelpers.h"

// GameMode는 접두사 A
ABackupGameModeBase::ABackupGameModeBase()
{
	
	// set default pawn class to our Blueprinted character(3인칭 마네킹). Auto Possesss Player 0번이 우선순위가 더 높다.
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class; // 클래스 정보를 넘겨줘야함.
	//}

	// 외부 블루프린트 클래스를 폰으로 사용할때, 경로_C 정보를 넘겨줌.
	static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT
	("/Game/ParagonGreystone/Characters/Heroes/Greystone/GreystonePlayerCharacter.GreystonePlayerCharacter_C"));

	if (BP_PAWN_C.Class != NULL)
	{
		DefaultPawnClass = BP_PAWN_C.Class; // 클래스 정보를 넘겨줘야함.
	}
}
