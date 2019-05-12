// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TurnToTarget.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API UBTTask_TurnToTarget : public UBTTaskNode
{
	GENERATED_BODY()
public:
	// Constructor
	UBTTask_TurnToTarget();
	// 태스크를 실행할때 호출되는 함수.
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
