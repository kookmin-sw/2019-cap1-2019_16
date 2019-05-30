// Fill out your copyright notice in the Description page of Project Settings.

#include "BTService_Detect.h"
//
#include "LDAIController.h" // UBehaviorTreeComponent & OwnerComp 에서 OwnerComp의 컴포넌트 기능을 사용하려면 필요
#include "LostDarkCharacter.h" // 탐지한 폰이 우리 플레이어인지 추려낼때 필요함 (ALostDarkCharacter* AnyCharacter~~)
#include "BehaviorTree/BlackboardComponent.h" // OwnerComp 컴포넌트 사용하고 싶을때
#include "DrawDebugHelpers.h" // 탐지 디버깅용을 그리고 싶을때

// Constructor
UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	// 주기적으로 불리어지는 TickNode의 시간 변수
	Interval = 1.0f;
}

// 자신이 속한 컴포짓 노드가 활성화될 경우 주기적으로 TickNode 함수를 자동 호출
void UBTService_Detect::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// 현재 조종하는 폰의 정보를 가져옴
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ControllingPawn == nullptr) return; // 조종하는 폰이 없으면 return

	// 폰이 존재하는 월드 정보를 가져옴
	UWorld* World = ControllingPawn->GetWorld();
	// 현재 폰의 위치값을 Center로 받음
	FVector Center = ControllingPawn->GetActorLocation();
	// 탐지 반경 600cm
	float DetectRadius = 600.0f;
	// 만약 월드 정보가 없다면 return
	if (World == nullptr) return;
	// 반경내에 있는 모든 캐릭터 정보를 담을 데이터 자료구조.
	TArray<FOverlapResult> OverlapResults;
	// CollisionQueryParams에 대한 정보 
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	// 반경내 모든 캐릭터를 감지하는 함수. bool값으로 처리함.
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2, // Attack Trace 콜리전 채널임. GSCharacter만 찾도록 되어있는 콜리전 채널이기 때문.
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);


	/* 탐지했을때, 플레이어를 추려내는 로직 */
	if (bResult) // 어떠한 등록한 Pawn이라도 감지했다면,
	{
		// OverlapResults에 담긴 모든 정보들을 하나씩 순차적으로 검사하는데,
		for (auto OverlapResult : OverlapResults)
		{
			// 현재 탐지한 정보를 가진 액터(폰, 캐릭터)를 등록
			ALostDarkCharacter* AnyCharacter = Cast<ALostDarkCharacter>(OverlapResult.GetActor());
			// 만약 그 캐릭터의 컨트롤러가 PlayerController라면 (사용자라면)
			if (AnyCharacter && AnyCharacter->GetController()->IsPlayerController())
			{
				// 블랙보드 TargetKey 값의 대상을 현재 정보를 가진 캐릭터로 지정 (사용자로 타깃 지정)
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(ALDAIController::TargetKey, AnyCharacter);
				// 디버깅용 구 영역을 그림. 찾았으니까 녹색으로
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);
				// 플레이어까지 디버깅용 선도 그림, 맨 마지막은 굵기(Thick)임
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), AnyCharacter->GetActorLocation(), FColor::Blue, false, 0.2f, 0, 5.0f);
				return;
			}
		}
	}
	// 만약 아무것도 발견하지 못했으면
	else
	{
		// 다시 블랙보드의 TargetKey에는 nullptr을 넣어줌. (찾았다가, 플레이어가 영역밖으로 도망갈 경우를 대비)
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(ALDAIController::TargetKey, nullptr);
	}
	// 디버깅용 구
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
}
