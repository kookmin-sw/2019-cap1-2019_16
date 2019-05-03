// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Animation/AnimInstance.h"
#include "GSAnimInstance.generated.h"

// 멀티캐스트 델리게이트 선언
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

/**
 * GS = GreyStone
 */
UCLASS()
class LOSTDARK_API UGSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// 생성자
	UGSAnimInstance();

	// AnimInstance 클래스가 갖고있는 함수. 애니메이션을 제대로 재생하기 위해 필수.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// 공격 몽타주 플레이 함수
	void PlayAttackMontage();

	// 몽타주에서 다음 공격 섹션으로 넘어가는 함수
	void JumpToAttackMontageSection(int32 NewSection);

public:
	// 멀티캐스트 델리게이트 선언
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;

private:
	// 노티파이 함수
	UFUNCTION()
		void AnimNotify_AttackHitCheck();

	UFUNCTION()
		void AnimNotify_NextAttackCheck();

	FName GetAttackMontageSectionName(int32 Section);

private:
	// 현재 캐릭터 속도 프로퍼티(멤버변수) (사용안하는중)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	// 현재 공중에 떠있는지 확인하는 불값 변수 (사용 안하는중)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir2;
	
	// 몽타주 애셋 정보
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;

};
