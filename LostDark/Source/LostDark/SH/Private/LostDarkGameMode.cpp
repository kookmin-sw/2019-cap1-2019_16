// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDark/SH/Public/LostDarkGameMode.h"
#include "LostDark/SH/Public/LostDarkCharacter.h"
#include "LostDark/SH/Public/LostDarkPlayerController.h"

// GameMode는 접두사 A
ALostDarkGameMode::ALostDarkGameMode()
{
	// set default pawn class to our Blueprinted character(3인칭 마네킹). Auto Possesss Player 0번이 우선순위가 더 높다.
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	/*
		Greystone 만들어진 블루프린트 클래스 사용할때.
		외부 블루프린트 클래스를 폰으로 사용할때, 경로_C 정보를 넘겨줌.
	*/
	//static ConstructorHelpers::FClassFinder<APawn> BP_PAWN_C(TEXT
	//("/Game/ParagonGreystone/Characters/Heroes/Greystone/GreystonePlayerCharacter.GreystonePlayerCharacter_C"));

	//if (BP_PAWN_C.Class != NULL)
	//{
	//	DefaultPawnClass = BP_PAWN_C.Class; // 클래스 정보를 넘겨줘야함.
	//}

	// GameMode에서 디폴트 폰 클래스 설정 = LostDarkCharacter C++ 클래스로 선언
	DefaultPawnClass = ALostDarkCharacter::StaticClass();
	// GameMode에서 플레이어 컨트롤러 클래스 설정
	PlayerControllerClass = ALostDarkPlayerController::StaticClass();

}
