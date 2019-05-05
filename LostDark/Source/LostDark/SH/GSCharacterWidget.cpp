// Fill out your copyright notice in the Description page of Project Settings.

#include "GSCharacterWidget.h"
#include "GSCharacterStatComponent.h"

// 캐릭터의 PostInitializeComponents 함수에서 캐릭터 컴포넌트와 UI 위젯을 연결할때 사용할 함수.
void UGSCharacterWidget::BindCharacterStat(UGSCharacterStatComponent* NewCharacterStat)
{
	ABLOG(Warning, TEXT("OnHPChanged@@@@@@@@@@@@@@@@@@@@@"));
	// 캐릭터 스탯 정보가 제대로 들어오지 않으면 예외처리
	ABCHECK(nullptr != NewCharacterStat);

	// 넘어온 데이터를 우리가 미리 선언한 변수에 넣음.
	CurrentCharacterStat = NewCharacterStat;
	// HP가 변했을때, 이쪽에서 불리어짐. (UGSCharacterStatComponent::SetHP(float NewHP) 사용할때 브로드캐스트 발동)
	NewCharacterStat->OnHPChanged.AddLambda([this]()->void {
		// 캐릭터 스텟 정보가 유효하다면,
		if (CurrentCharacterStat.IsValid())
		{
			// 로그 찍어보기.
			ABLOG(Warning, TEXT("HPRatio : %f"), CurrentCharacterStat->GetHPRatio());
		}
	});
}