// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Blueprint/UserWidget.h"
#include "GSCharacterWidget.generated.h"

/**
 *  UserWidget 클래스는 Anim Instance와 마찬가지로, UI쪽에서 로직을 구현하는 클래스이다. 언리얼에서 미리 제공해줌.
 *	UI쪽 데이터를 관리하고 상호작용하는건 전부 여기서 이뤄지는것임.
 *	여기서는 캐릭터 스탯 정보가 저장되어 있는 GSCharacterStatComponent (Actor Component)와 연동해,
 *	캐릭터의 스탯이 변화할 때마다 Progress Bar의 내용을 업데이트할 예정. (스탯쪽에 델리게이트를 선언해서, 등록함.)
 */
UCLASS()
class LOSTDARK_API UGSCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Progress Bar를 실질적으로 업데이트할 함수.
	void BindCharacterStat(class UGSCharacterStatComponent* NewCharacterStat);

protected:
	// UI시스템이 준비되면 자동호출됨. 참고로 UI 생성은 플레이어컨트롤러의 BeginPlay()에서 이뤄짐. Postinitialize가 먼저 처리되는거 주의
	virtual void NativeConstruct() override; /// 위젯내용을 여기서 업데이트할 예정.
	// 위젯 업데이트
	void UpdateHPWidget();

private:
	// 약 포인터로 선언된 우리 캐릭터의 스탯정보 컴포넌트(Actor Component) 단, 약포인터 변수를 사용할때는 반드시 IsValid로 유효한지 확인해줘야한다.
	TWeakObjectPtr<class UGSCharacterStatComponent> CurrentCharacterStat;

	UPROPERTY()
		// Progress Bar UI 포인터 변수
		class UProgressBar* HPProgressBar;
};
