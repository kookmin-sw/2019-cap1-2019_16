// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_TurnToTarget.h"
///
#include "LDAIController.h"
#include "LostDarkCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

// Constructor
UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

// Task Node가 실행될때 호출되는 함수
EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	// AI가 조종하는 폰의 데이터를 가져옴
	auto AICharacter = Cast<ALostDarkCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (AICharacter == nullptr) return EBTNodeResult::Failed;

	// 블랙보드에 있는 타깃 정보를 가져옴
	auto Target = Cast<ALostDarkCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ALDAIController::TargetKey));
	if (Target == nullptr) return EBTNodeResult::Failed;

	// 타깃 위치에서 현재 AI위치를 뺌. 방향벡터를 구하는것.
	FVector LookVector = Target->GetActorLocation() - AICharacter->GetActorLocation();
	// Z축은 0로. 캐릭터간의 높이가 다를수 있어서
	LookVector.Z = 0.0f;
	// 방향 벡터를 통해서 회전값 구함.
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	// AI를 회전시킴. RInterpTo(현재 회전값, 목표 회전값, DeltaTime, 보간 속도)
	AICharacter->SetActorRotation(FMath::RInterpTo(AICharacter->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));
	return EBTNodeResult::Succeeded;
}