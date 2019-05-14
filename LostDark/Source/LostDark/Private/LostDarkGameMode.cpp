// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDarkGameMode.h"
#include "LostDarkCharacter.h"
#include "LostDarkPlayerController.h"
#include "LDPlayerState.h"
#include "LDGameState.h"

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
	// 플레이어 스테이트 정보 등록. 플레이어 컨트롤러가 초기화될때 해당 클래스의 인스턴스가 생성되면서 그 포인턱밧을 PlayerState속성에 저장함.
	PlayerStateClass = ALDPlayerState::StaticClass();
	// 게임 스테이트 정보 등록.
	GameStateClass = ALDGameState::StaticClass();
}

void ALostDarkGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	LDGameState = Cast<ALDGameState>(GameState);
}

// 플레이어 컨트롤러가 완료되면 게임 모드에서 자동 호출
void ALostDarkGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// 플레이어 컨트롤러에 해당하는 플레이어 스테이트 정보 가져옴
	auto LDPlayerState = Cast<ALDPlayerState>(NewPlayer->PlayerState);
	ABCHECK(nullptr != LDPlayerState);
	// 최초 데이터 등록
	LDPlayerState->InitPlayerData();
}

void ALostDarkGameMode::AddScore(ALostDarkPlayerController * ScoredPlayer)
{
	// 참여중인 플레이어 캐릭터 컨트롤러를 전부 받아옴
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		const auto LDPlayerController = Cast<ALostDarkPlayerController>(It->Get());
		// 스코어 획득한 플레이어를 찾으면
		if ((nullptr != LDPlayerController) && (ScoredPlayer == LDPlayerController))
		{
			LDPlayerController->AddGameScore();
			break;
		}
	}
	// 전체 게임 스테이트도 올려줌
	LDGameState->AddGameScore();
}

int32 ALostDarkGameMode::GetScore() const
{
	return LDGameState->GetTotalGameScore();
}
