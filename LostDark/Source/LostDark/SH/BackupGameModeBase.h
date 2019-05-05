// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BackupGameModeBase.generated.h"

/*
	minimalapi = 클래스 지정자.
	엔진, 에디터 전용 기능으로 어떻게 작동하는지 제어가능.
	클래스의 형 정보만 다른 모듈이 사용할 수 있도록 노출.
	이 클래스는 형병환이 가능하지만, 그 함수를 호출할 수 없음.
	컴파일 시간이 향상됨.
	http://api.unrealengine.com/KOR/Programming/UnrealArchitecture/Reference/Classes/
*/
UCLASS(minimalapi)
class LOSTDARK_API ABackupGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ABackupGameModeBase();
	
};
