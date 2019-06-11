// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Animation/AnimInstance.h"
#include "GSAnimInstance.generated.h"

// ��Ƽĳ��Ʈ ��������Ʈ ���� ��ȯ���� ���� ���� ���� �Լ� ����. ������ �� �Լ��� ��ϵɼ� ����.
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
	// ������
	UGSAnimInstance();

	// AnimInstance Ŭ������ �����ִ� �Լ�. �ִϸ��̼��� ����� ����ϱ� ���� �ʼ�.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// ���� ��Ÿ�� �÷��� �Լ�
	void PlayAttackMontage();

	void PlayDodgeMontage();

	// ��Ÿ�ֿ��� ���� ���� �������� �Ѿ�� �Լ�
	void JumpToAttackMontageSection(int32 NewSection);

	// ���� Ȯ��
	bool IsJump();

public:
	// ��Ƽĳ��Ʈ ��������Ʈ ����. ��ȯ���� ���� ���� ���� �Լ� ����. ������ �� �Լ��� ��ϵɼ� ����.
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnAttackHitCheckDelegate OnAttackHitCheck;

	// ��������� true�� �ٲ�.
	void SetDeadAnim() { IsDead = true; }

private:
	// ��Ƽ���� �Լ�
	UFUNCTION()
		void AnimNotify_AttackHitCheck();
	// ���� ���� �޺��� �Ѿ���� üũ�ϴ� �Լ�
	UFUNCTION()
		void AnimNotify_NextAttackCheck();
	// �� ��Ƽ���̰� �ҷ��� ���Ŀ� ���� ���ݸ� �޺��� �޾Ƶ���
	UFUNCTION()
		void AnimNotify_IsInputCombo();
	UFUNCTION()
		void AnimNotify_SoundPlay();

	// ���� ��Ÿ�� ������ �̸��� ����ϱ� ���� �Լ�
	FName GetAttackMontageSectionName(int32 Section);


private:
	// ���� ĳ���� �ӵ� ������Ƽ(�������) (�����ϴ���)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	// ���� ���߿� ���ִ��� Ȯ���ϴ� �Ұ� ���� (��� ���ϴ���)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;

	// �ڽ��� ����������� Ȯ���ϴ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsDead;

	// ��Ÿ�� �ּ� ����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;
	// ��Ÿ�� �ּ� ����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* DodgeMontage;


public:
	// �޺� �Է� ���Դ��� Ȯ����
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		bool IsInputCombo;

	UPROPERTY(VisibleAnywhere)
	class ALostDarkCharacter* LDCharacter;

};
