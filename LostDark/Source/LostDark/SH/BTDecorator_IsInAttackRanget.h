// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsInAttackRanget.generated.h"

/**
 * 목표물인 플레이어가 공격 범위 내에 있는지 판단하는 데코레이터
 */
UCLASS()
class LOSTDARK_API UBTDecorator_IsInAttackRanget : public UBTDecorator
{
	GENERATED_BODY()
public:
	// Constructor
	UBTDecorator_IsInAttackRanget();

protected:
	// 원하는 조건이 달성됐는지 파악할 수 있다. 이 함수는 const 선언돼 데코레이터 클래스의 멤버 변수 값은 변경할 수 없다.
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
