// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Animation/AnimInstance.h"
#include "GSAnimInstance.generated.h"

// 멀티캐스트 델리게이트 선언 반환값과 인자 값이 없는 함수 유형. 여러개 의 함수가 등록될수 있음.
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

	void PlayDodgeMontage();

	// 몽타주에서 다음 공격 섹션으로 넘어가는 함수
	void JumpToAttackMontageSection(int32 NewSection);

	// 점프 확인
	bool IsJump();

public:
	// 멀티캐스트 델리게이트 선언. 반환값과 인자 값이 없는 함수 유형. 여러개 의 함수가 등록될수 있음.
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;

	// 사망변수를 true로 바꿈.
	void SetDeadAnim() { IsDead = true; }

private:
	// 노티파이 함수
	UFUNCTION()
		void AnimNotify_AttackHitCheck();
	// 실제 다음 콤보로 넘어가는지 체크하는 함수
	UFUNCTION()
		void AnimNotify_NextAttackCheck();
	// 이 노티파이가 불려진 이후에 들어온 공격만 콤보로 받아들임
	UFUNCTION()
		void AnimNotify_IsInputCombo();

	// 현재 몽타주 섹션의 이름을 출력하기 위한 함수
	FName GetAttackMontageSectionName(int32 Section);


private:
	// 현재 캐릭터 속도 프로퍼티(멤버변수) (사용안하는중)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	// 현재 공중에 떠있는지 확인하는 불값 변수 (사용 안하는중)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;

	// 자신이 사망상태인지 확인하는 변수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsDead;

	// 몽타주 애셋 정보
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;
	// 몽타주 애셋 정보
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* DodgeMontage;


public:
	// 콤보 입력 들어왔는지 확인함
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsInputCombo;

	UPROPERTY(VisibleAnywhere)
	class ALostDarkCharacter* LDCharacter;

};
