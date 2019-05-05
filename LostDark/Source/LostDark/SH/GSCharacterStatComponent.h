// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Components/ActorComponent.h"
#include "GSCharacterStatComponent.generated.h"

// 멀리캐스트 델리게이트 선언
DECLARE_MULTICAST_DELEGATE(FOnHPIsZeroDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOSTDARK_API UGSCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGSCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// 미리 만들어진 이니셜라이즈 컴포넌트 오버라이드
	virtual void InitializeComponent() override;

public:	
	// Called every frame (사용안함)
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// 새로운 레벨 설정
	void SetNewLevel(int32 NewLevel);
	// 캐릭터의 TakeDamage 함수에서 이를 호출해서 데미지 상호작용을 처리
	void SetDamage(float NewDamage);
	// 데미지 크기 반환
	float GetAttack();

	// 델리게이트 변수
	FOnHPIsZeroDelegate OnHPIsZero;

private:
	// 캐릭터 데이터 테이블 구조체 참조 변수
	struct FGSCharacterData* CurrentStatData = nullptr;

	// 레벨 변수
	UPROPERTY(EditInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		int32 Level;
	// 현재 HP / Transient는 UPROPERTY 속성을 저장하지 않는다는걸 의미한다. 수시로 변할수 있는 데이터이기에 보관하는것이 의미 없음.
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
		float CurrentHP;

		
};
