// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindPatrolPos.h"
/// 추가함
#include "LDAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
// 4.20 버전이후 추가해야함
#include "NavigationSystem.h"

// Constructor
UBTTask_FindPatrolPos::UBTTask_FindPatrolPos()
{
	// NodeName : 태스크 이름, 새롭게 지정. 이때 TEXT() 문자열을 사용함.
	NodeName = TEXT("FindPatrolPos");
}

//
EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	// 부모에게 정보를 넘겨서 받기
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// 비헤이비어 트리에서 AI 조종중인 폰의 정보를 가져옴
	auto ControlligPawn = OwnerComp.GetAIOwner()->GetPawn();

	// 조종중인 폰이 없다면
	if (ControlligPawn == nullptr)
		return EBTNodeResult::Failed; //만약 조종중인 폰이 없다면 실패를 전달

	// 내비게이션 변수에 현재 등록된 내비게이션 메시 정보를 가져옴
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControlligPawn->GetWorld());
	
	// 내비게이션 정보가 없다면
	if (NavSystem == nullptr)
		return EBTNodeResult::Failed; // 만약 등록된 내비게이션 정보가 없다면 Failed 전달

	// AI가 생성된 최초 위치를 블랙보드에서 가져와서 변수에 넣어줌
	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(ALDAIController::HomePosKey);
	// 다음 목적지를 기록할 변수 생성
	FNavLocation NextPatrol;

	// 다음 랜덤 내비게이션 정보가 존재한다면, NextPatrol에 값을 넣어준다.
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 500.0f, NextPatrol))
	{
		// 비헤이비어 트리의 블랙보드에서 목적지 PatroPoskey 값에 NextPatrol.Location 등록한다. 
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(ALDAIController::PatrolPosKey, NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
