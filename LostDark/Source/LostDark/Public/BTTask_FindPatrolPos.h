// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPatrolPos.generated.h"

/**
 *  AI가 이동할 목적지 PatrolPos 데이터
 */
UCLASS()
class LOSTDARK_API UBTTask_FindPatrolPos : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	// Constructor
	UBTTask_FindPatrolPos();

	// ExecuteTask : 비헤이비어 트리에서 태스크를 실행할때 사용하는 함수 반드시 몇가지 형태의 결과값을 반환해야한다.
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; // OwnerComp : 비헤이비어 트리
};
