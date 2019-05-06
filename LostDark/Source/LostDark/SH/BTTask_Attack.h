// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack.generated.h"

/**
 * 
 */
UCLASS()
class LOSTDARK_API UBTTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	// Constructor
	UBTTask_Attack();
	
	// 태스크 실행할때 멤버함수 자동호출 
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	// TickTask : 태스크에서의 Tick함수.
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	// 애니메이션 공격 상태 변수
	bool IsAttacking = false;
};
