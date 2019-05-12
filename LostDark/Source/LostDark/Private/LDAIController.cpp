// Fill out your copyright notice in the Description page of Project Settings.

#include "LDAIController.h"
// 4.20 버전 이후로 내비게이션 메시 시스템을 사용하려면 추가해야함!
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h" // SimplerMoveToLocation을 사용하려면 필수
#include "BehaviorTree/BehaviorTree.h" // 비헤이비어 트리
#include "BehaviorTree/BlackboardData.h" // 블랙보드
#include "BehaviorTree/BlackboardComponent.h" // Blackboard 컴포넌트 기능 사용하려면 헤더파일 추가해야함.

// 블랙보드 기반의 이름을 초기화후 const로 고정시킴. 블랙보드 이름과 완전히 일치해야만함. 실수 주의
const FName ALDAIController::HomePosKey(TEXT("HomePos"));
const FName ALDAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName ALDAIController::TargetKey(TEXT("Target"));

ALDAIController::ALDAIController()
{
	//// 타이머 3초
	//RepeatInterval = 3.0f;

	// 외부 블랙보드 애셋 정보 가져옴
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/SH/AI/BB_LDCharacter.BB_LDCharacter"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	// 외부 비헤이비어 트리 애셋 정보 가져옴
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/SH/AI/BT_LDCharacter.BT_LDCharacter"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

// AI가 빙의됐을때 불리는 함수.
void ALDAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	//// AI컨트롤러가 빙의되면 월드에서 타이머 시작해서 TimerHandler에 등록하고, OnRepeaTimer 함수를 호출함. 3초 간격으로
	//GetWorld()->GetTimerManager().SetTimer(RepeatTimerHandle, this, &ALDAIController::OnRepeatTimer, RepeatInterval, true);

	// UseBlackborad() : 블랙보드를 연동(binding)시키는 함수. 성공여부를 bool값으로 반환
	if (UseBlackboard(BBAsset, Blackboard)) 
	{
		/// Blackboard 컴포넌트 기능 사용하려면 헤더파일 추가해야함.
		// 블랙보드에 있는 HomePosKey에 현재 폰의 위치를 초기화 해줌. (HomePosKey = InPawn->GetActorLocation() 이라고 볼수 있음)
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation()); // HomePosKey에 해당하는 이름의 블랙보드 변수에 폰의 위치값을 넣어줌.
		// RunBehaviorTree(비헤이비어 트리 정보) : 비헤이비어 트리 연동(binding)시키는 함수. 성공여부를 bool값으로 반환
		if (!RunBehaviorTree(BTAsset))
		{
			// 로그 띄움
			ABLOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}

//void ALDAIController::UnPossess()
//{
//	Super::UnPossess();
//	// 타이머 초기화
//	GetWorld()->GetTimerManager().ClearTimer(RepeatTimerHandle);
//}

//void ALDAIController::OnRepeatTimer()
//{
//	// 현재 폰의 정보를 가져옴
//	auto CurrentPawn = GetPawn();
//	// AI컨트롤러가 적용된 폰이 없다면 예외처리
//	ABCHECK(CurrentPawn != nullptr);
//	// 내비게이션 타입 변수를 만들어 현재 월드에 설치된 내비게이션을 등록함.
//	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
//	// 혹시 월드에 배치된 내비게이션 시스템이 없으면 예외처리
//	if (NavSystem == nullptr) return;
//
//	// 내비게이션 메시에 있는 구조체 변수
//	FNavLocation NextLocation;
//	
//	// 내비게이션 매시 바운드가 있는 반경에서 현재위치에서 500 반경에서 다음 위치가 존재한다면, 랜덤한 목적지를 NextLoctaion에 등록함.
//	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, NextLocation))
//	{
//		// 랜덤하게 등록된 다음 목적지로 AI를 이동하게함.
//		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, NextLocation.Location);
//		// 해당 위치를 출력
//		ABLOG(Warning, TEXT("Next Location : %s"), *NextLocation.Location.ToString());
//	}
//}