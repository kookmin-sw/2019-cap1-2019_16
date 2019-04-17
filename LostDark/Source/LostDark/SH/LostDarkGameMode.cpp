// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDarkGameMode.h"
#include "LostDarkCharacter.h"
//#include "UObject/ConstructorHelpers.h" //기존 코드

// GameMode는 접두사 A
ALostDarkGameMode::ALostDarkGameMode()
{
	// set default pawn class to our Blueprinted character(3인칭 마네킹). Auto Possesss Player 0번이 우선순위가 더 높다.
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	// 외부 블루프린트 클래스를 폰으로 사용할때, 경로_C 정보를 넘겨줌.
	static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT
	("/Game/ParagonGreystone/Characters/Heroes/Greystone/GreystonePlayerCharacter.GreystonePlayerCharacter_C"));

	if (BP_PAWN_C.Class != NULL)
	{
		DefaultPawnClass = BP_PAWN_C.Class; // 클래스 정보를 넘겨줘야함.
	}
}
