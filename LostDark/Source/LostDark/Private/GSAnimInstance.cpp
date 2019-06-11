// Fill out your copyright notice in the Description page of Project Settings.

#include "GSAnimInstance.h"
#include "LostDarkCharacter.h"

// ������
UGSAnimInstance::UGSAnimInstance()
{
	// ���� ĳ������ �ӵ� �ʱ�ȭ
	CurrentPawnSpeed = 0.0f;
	// ���� ���� ���´� false
	IsInAir = false;
	// ���� ������´� false
	IsDead = false;

	// ��Ÿ�� �ּ� ���� ���. ��Ÿ�ִ� Object ������.
	static ConstructorHelpers::FObjectFinder<UAnimMontage> Attack_Montage(TEXT(
		"/Game/SH/Animations/Greystone_Skeleton_Montage1.Greystone_Skeleton_Montage1"));
	// ��Ÿ�� ������ ������ ã������
	if (Attack_Montage.Succeeded())
	{
		// ��Ÿ�� �ּ� ���� ���
		AttackMontage = Attack_Montage.Object;
		UE_LOG(LogTemp, Warning, TEXT("Enroll Attack Montage"));
	}
	// ���� �޺� �Է��� ������ �ʾ���.
	IsInputCombo = false;

	/*static ConstructorHelpers::FObjectFinder<UAnimMontage> Dodge_Montage(TEXT(
		"/Game/SH/Animations/GreystonDodge_Montage.GreystonDodge_Montage"));*/
	static ConstructorHelpers::FObjectFinder<UAnimMontage> Dodge_Montage(TEXT(
		"/Game/SH/Animations/RollForward_Root_Montage.RollForward_Root_Montage"));
	if (Dodge_Montage.Succeeded())
	{
		DodgeMontage = Dodge_Montage.Object;
	}

}

// �Ϲ� Tick�� ������ ��ġ. �ǽð����� �ִϸ��̼� �ý����� ƽ���� ���� ������ ���� �ӷ� ���� ���� (�Ƹ��� ��� ���ϴ����ε�)
void UGSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// AnimInstance�� �ִ� NativeUpdateAnimation�� ������ �Ѱ���.
	Super::NativeUpdateAnimation(DeltaSeconds);

	// APawn ��ü ������, ���� �ش��ϴ� �� �ִ��ν��Ͻ��� �����ϴ� ���� ������ �ѱ�.
	auto Pawn = TryGetPawnOwner();
	// Pawn�� ������ �� ���ٸ� ��ȯ (����ó��)
	if (!::IsValid(Pawn)) return;

	if (!IsDead)
	{
		// ���� �ӵ��� float���� ��ȯ.
		CurrentPawnSpeed = Pawn->GetVelocity().Size();

		// �ӽ� ĳ���� ������ ����� �츮�� �����ϰ� �ִ� ĳ���� Ŭ���� ������ �Ѱ��ְ�
		auto Character = Cast<ACharacter>(Pawn);
		// ĳ���� Ŭ������ ��ȿ�ϴٸ�,
		if (Character)
		{
			// IsFalling �������� Ȯ���Ѵ�.
			IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}

// ���� ���� ���� ��ȯ
bool UGSAnimInstance::IsJump()
{
	return IsInAir;
}

// Dodge ��Ÿ�� ���
void UGSAnimInstance::PlayDodgeMontage()
{
	Montage_Play(DodgeMontage, 1.0f);
}

// ���� ��Ÿ�� ��� �Լ�
void UGSAnimInstance::PlayAttackMontage()
{
	/// ��������Ʈ�� ���� ������ ���۰� ���ᰡ �����Ǳ� ������ IsPlaying���� Ȯ������ �ʾƵ� ��.
	// AttackMontage�� ����ǰ� ���� �ʴٸ�,
	//if (!Montage_IsPlaying(AttackMontage))
	//{
	//	// ��Ÿ�� �����Ŵ (�����ų ��Ÿ�� ����, �ӵ�)
	//	Montage_Play(AttackMontage, 1.0f);
	//}
	// �ڽ��� �׾��ٸ� return.
	ABCHECK(!IsDead);
	// ��ϵ� ��Ÿ�� ���.
	Montage_Play(AttackMontage, 1.0f);
}

// ��Ÿ�ֿ��� ���� ���� �������� �Ѿ�� �Լ�
void UGSAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	// �ڽ��� �׾��ٸ� return
	ABCHECK(!IsDead);
	// ���� ��Ÿ�ְ� ��������� �ʴٸ�, ���� ���� ����ϰ� return. (����ó��)
	ABCHECK(Montage_IsPlaying(AttackMontage));
	// Montage_JumpToSection�� �θ� AnimInstance���� �̸� �������. (���� ���� �ѹ�, ������� ��Ÿ�� ����)
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

// ��Ƽ���� �Լ�.
void UGSAnimInstance::AnimNotify_AttackHitCheck()
{
	//UE_LOG(LogTemp, Warning, TEXT("AttackHitCheck"));
	OnAttackHitCheck.Broadcast();
}

// ���� �޺��� ������ �ߵ�.
void UGSAnimInstance::AnimNotify_NextAttackCheck()
{
	// �ٽ� �޺� �Է°� ����.
	IsInputCombo = false;
	//UE_LOG(LogTemp, Warning, TEXT("NextAttackCheck"));
	// �Ʒ� ��������Ʈ ������ ���ٽ����� ������ ����
	OnNextAttackCheck.Broadcast();

}

// �� �Լ��� �Ҹ������� NextAttackCheck()�� �Ҹ��� ������ ���� ���ݸ� �߰� �޺� �Է����� �޾Ƶ���
void UGSAnimInstance::AnimNotify_IsInputCombo()
{
	// �������� ������ ������ ���� �߰� �޺� ������.
	IsInputCombo = true;
}

void UGSAnimInstance::AnimNotify_SoundPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));
	LDCharacter = Cast<ALostDarkCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (LDCharacter != NULL)
	{
		LDCharacter->AttackSound();
	}
}

// ���� ���� ���� ������ ���
FName UGSAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	// ���� Section�� 1~3 ���� ���ڰ� �ƴ϶��, return
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 3), NAME_None);
	// ���� �޺� ���¸� �˷��ִ� ���� ���ڸ� ���
	///�ڡڡڡڡ� �ſ� �����ؾ��ϴ°�, Attack%d�� ���� ��Ƽ���� �̸��� �����ؾ���. �׷��� �����ϸ� �ȵ�!
	return FName(*FString::Printf(TEXT("Attack%d"),Section));
}
