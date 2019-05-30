// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Attack.h"
#include "LDAIController.h"
#include "LostDarkCharacter.h"

// Constructor
UBTTask_Attack::UBTTask_Attack()
{
	// 틱 태스크 활성화
	bNotifyTick = true;
	// 공격중이지 않음.
	IsAttacking = false;
}

// 태스크 실행할때 멤버함수 자동호출. AI가 1번 공격할때마다 이 전체 로직이 한번 불리어진다 생각하면 됨.
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//부모에게 넘겨줌
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	
	// 현재 조종중인 캐릭터 정보를 가져옴
	auto GSCharacter = Cast<ALostDarkCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (GSCharacter == nullptr) return EBTNodeResult::Failed;

	// 이거때문에 Attack함수가 public이 되야했음.
	GSCharacter->Attack();
	// 공격 애니메이션 변수 true;
	IsAttacking = true;
	// 캐릭터 몽타주 끝나면 자동 호출되는 멀티 델리게이트 람다 함수
	GSCharacter->OnAttackEnd.AddLambda([this]()->void {
		IsAttacking = false;
	});

	// 현재 진행중 (무한 대기) -> TickTask 함수만 계속 불리어짐
	return EBTNodeResult::InProgress;
}

// TickTask : 태스크에서의 Tick함수.
void UBTTask_Attack::TickTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	// 공격중이 아니라면
	if (!IsAttacking)
	{
		// 해당 Task Node가 종료됐음을 알려주는 함수. 이걸로 완전히 종료됨
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
