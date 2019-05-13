// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "AIController.h"
#include "LDAIController.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API ALDAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	// Constructor(약자 ctor)
	ALDAIController();
	// AI 컨트롤러에 있는 빙의 함수
	virtual void Possess(APawn* InPawn) override;
	//// AI 컨트롤러에 있는 탈출 함수
	//virtual void UnPossess() override;

	// 시작위치와 목적지 위치값을 갖는 블랙보드 Vector유형 데이터 static const이므로 절대 바뀌면 안됨
	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;

	void RunAI();
	void StopAI();
	
private:
	//// 타이머 함수
	//void OnRepeatTimer();
	//// 
	//FTimerHandle RepeatTimerHandle;
	//// 타이머 시간 변수
	//float RepeatInterval;

	// 비헤이비어 트리 애셋 정보
	UPROPERTY()
		class UBehaviorTree* BTAsset;
	// 블랙보드 애셋 정보
	UPROPERTY()
		class UBlackboardData* BBAsset;
};
