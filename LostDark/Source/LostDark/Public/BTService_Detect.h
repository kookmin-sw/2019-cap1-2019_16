// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "BehaviorTree/BTService.h"
#include "BTService_Detect.generated.h"

/**
 * 정찰 중 플레이어가 일정 반경 내에 있으면 감지해 추격하는 기능을 하는 서비스노드.
 */
UCLASS()
class LOSTDARK_API UBTService_Detect : public UBTService
{
	GENERATED_BODY()
	
public:
	// Constructor
	UBTService_Detect();

protected:
	// 자신이 속한 컴포짓 노드가 활성화될 경우 주기적으로 TickNode 함수를 자동 호출
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
