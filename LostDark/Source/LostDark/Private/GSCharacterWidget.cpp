// Fill out your copyright notice in the Description page of Project Settings.

#include "GSCharacterWidget.h"
// 스텟 컴포넌트와 연결하기 위해 헤더 추가
#include "GSCharacterStatComponent.h"
// ProgressBar 포인터를 위한 헤더
#include "Components/ProgressBar.h"

// 캐릭터의 PostInitializeComponents 함수에서 캐릭터 컴포넌트와 UI 위젯을 연결할때 사용할 함수.
void UGSCharacterWidget::BindCharacterStat(UGSCharacterStatComponent* NewCharacterStat)
{
	// 캐릭터 스탯 정보가 제대로 들어오지 않으면 예외처리
	ABCHECK(nullptr != NewCharacterStat);

	// 넘어온 데이터를 약 포인터로 만든 멤버 변수에 넣음.
	CurrentCharacterStat = NewCharacterStat;
	// HP가 변했을때, 이쪽에서 불리어짐. (UGSCharacterStatComponent::SetHP(float NewHP) 사용할때 브로드캐스트 발동)
	//NewCharacterStat->OnHPChanged.AddLambda([this]()->void {
	//	// 약 포인터를 사용했기 때문에, 반드시 IsValid로 유효한지 체크. (캐릭터 스탯정보)
	//	if (CurrentCharacterStat.IsValid())
	//	{
	//		// 로그 찍어보기.
	//		ABLOG(Warning, TEXT("HPRatio : %f"), CurrentCharacterStat->GetHPRatio());
	//		ABLOG(Warning, TEXT("GOOOOOOOOOOOOOOOOOOOOOOOOOD"));
	//	}
	//});
	
	// 델리게이트 함수 등록
	NewCharacterStat->OnHPChanged.AddUObject(this, &UGSCharacterWidget::UpdateHPWidget);
}

// UI 시스템이 완료되면 자동호출 /// 최초의 UI 초기화 (BeginPlay에서 실행됨. 느림)
void UGSCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// 위젯의 실제 파일 이름으로 애셋 정보를 넘김
	HPProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBar")));
	// 위젯 정보가 들어오지 않는다면(ex파일 이름이 다를경우)
	ABCHECK(nullptr != HPProgressBar);
	// 업데이트 위젯함수 호출
	UpdateHPWidget();
}

// 실제 위젯의 내용을 업데이트하는 함수
void UGSCharacterWidget::UpdateHPWidget()
{
	// 약포인터로 선언된 스탯정보가 아직 유효한지
	if (CurrentCharacterStat.IsValid())
	{
		if (nullptr != HPProgressBar)
		{
			// 현재 HP의 비율을 HPProgressBar에 업데이트 (SetPercent함수로)
			HPProgressBar->SetPercent(CurrentCharacterStat->GetHPRatio());
		}
	}
}
