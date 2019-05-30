// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Attack.generated.h"

/**
 *  실제로 플레이어를 공격할 Task Node
 공격 Task Node는 공격 애니메이션이 끝날 때까지 대기해야 하는 지연 태스크이므로,
 ExcuteTask의 결과 값을 InProgress로 반환하고 공격이 끝났을때 태스크가 끝났다고 알려줘야 한다.
 */
UCLASS()
class LOSTDARK_API UBTTask_Attack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	// Constructor
	UBTTask_Attack();
	
	// Task 노드가 실행할때 매번 자동호출 
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	// TickTask : 태스크에서의 Tick함수.
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	// 애니메이션 공격 상태 변수
	bool IsAttacking = false;
};
