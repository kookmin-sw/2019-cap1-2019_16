// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LostDark.h"
#include "GameFramework/GameModeBase.h"
#include "LostDarkGameMode.generated.h"

/*
	minimalapi = 클래스 지정자.
	엔진, 에디터 전용 기능으로 어떻게 작동하는지 제어가능.
	클래스의 형 정보만 다른 모듈이 사용할 수 있도록 노출.
	이 클래스는 형병환이 가능하지만, 그 함수를 호출할 수 없음.
	컴파일 시간이 향상됨.
	http://api.unrealengine.com/KOR/Programming/UnrealArchitecture/Reference/Classes/
*/
UCLASS(minimalapi)
class ALostDarkGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//Constructor
	ALostDarkGameMode();

	//
	virtual void PostInitializeComponents() override;
	// 플레이어 컨트롤러가 완료되면 게임 모드에서 자동 호출
	virtual void PostLogin(APlayerController* NewPlayer) override;
	// 점수 획득한 플레이어의 점수를 올려주는 함수
	void AddScore(class ALostDarkPlayerController* ScoredPlayer);
	// 현재 게임 스코어
	int32 GetScore() const;

private:
	// 전체 게임 스테이트 (전체 게임 스코어를 위한)
	UPROPERTY()
		class ALDGameState* LDGameState;
};