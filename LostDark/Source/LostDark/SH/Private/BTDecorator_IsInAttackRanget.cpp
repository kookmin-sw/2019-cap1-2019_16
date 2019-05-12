// Fill out your copyright notice in the Description page of Project Settings.

#include "LostDark/SH/Public/BTDecorator_IsInAttackRanget.h"
//
#include "LostDark/SH/Public/LDAIController.h"
#include "LostDark/SH/Public/LostDarkCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


// Constructor
UBTDecorator_IsInAttackRanget::UBTDecorator_IsInAttackRanget()
{
	NodeName = TEXT("CanAttack");
}

// 해당하는 Composites이 실행될때 자동으로 불리어지는 함수. 조건 확인
bool UBTDecorator_IsInAttackRanget::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	// AI가 조종중인 폰의 정보를 가져옴
	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ControllingPawn == nullptr) return false;
	
	// 현재 블랙보드에 들어가 있는 Target 값을 가져옴
	auto Target = Cast<ALostDarkCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ALDAIController::TargetKey));
	if (Target == nullptr) return false;
	
	// AI에서 타깃까지 거리가 200cm 이내라면 true를 넘겨준다.
	bResult = (Target->GetDistanceTo(ControllingPawn) <= 200.0f);

	return bResult;
}