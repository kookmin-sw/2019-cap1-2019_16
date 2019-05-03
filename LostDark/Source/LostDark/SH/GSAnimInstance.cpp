// Fill out your copyright notice in the Description page of Project Settings.

#include "GSAnimInstance.h"

// 생성자
UGSAnimInstance::UGSAnimInstance()
{
	// 현재 캐릭터의 속도 초기화
	CurrentPawnSpeed = 0.0f;
	// 최초 점프 상태는 false
	IsInAir2 = false;

	// 몽타주 애셋 정보 등록. 몽타주는 Object 단위다.
	static ConstructorHelpers::FObjectFinder<UAnimMontage> Attack_Montage1(TEXT(
		"/Game/SH/Animations/Greystone_Skeleton_Montage1.Greystone_Skeleton_Montage1"));
	// 무사히 찾았으면
	if (Attack_Montage1.Succeeded())
	{
		// 몽타주 애셋 정보 등록
		AttackMontage = Attack_Montage1.Object;
	}
}

// 일반 Tick과 완전히 일치. 실시간으로 애니메이션 시스템의 틱에서 폰에 접근해 폰의 속력 값을 얻어옴
void UGSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// AnimInstance에 있는 NativeUpdateAnimation에 정보를 넘겨줌.
	Super::NativeUpdateAnimation(DeltaSeconds);

	// APawn 객체 생성후, 현재 해당하는 이 애님인스턴스가 관리하는 폰의 정보를 넘김.
	auto Pawn = TryGetPawnOwner();

	// 애님 인스턴스가 Pawn 정보를 제대로 갖고 왔다면,
	if (::IsValid(Pawn))
	{
		// 현재 속도를 float으로 반환.
		CurrentPawnSpeed = Pawn->GetVelocity().Size();

		// 임시 캐릭터 변수를 만들어 우리가 조종하고 있는 캐릭터 클래스 정보를 넘겨주고
		auto Character = Cast<ACharacter>(Pawn);
		// 캐릭터 클래스가 유효하다면,
		if (Character)
		{
			// IsFalling 상태인지 확인한다.
			IsInAir2 = Character->GetMovementComponent()->IsFalling();
		}
	}
}

// 공격 몽타주 재생 함수
void UGSAnimInstance::PlayAttackMontage()
{
	/// 델리게이트에 의해 공격의 시작과 종료가 감지되기 때문에 IsPlaying으로 확인하지 않아도 됨.
	// AttackMontage가 재생되고 있지 않다면,
	//if (!Montage_IsPlaying(AttackMontage))
	//{
	//	// 몽타주 재생시킴 (재생시킬 몽타주 정보, 속도)
	//	Montage_Play(AttackMontage, 1.0f);
	//}
	
	// 등록된 몽타주 재생.
	Montage_Play(AttackMontage, 1.0f);
}

// 몽타주에서 다음 공격 섹션으로 넘어가는 함수
void UGSAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	// Montage_JumpToSection는 이미 애님인스턴스에서 제공. (현재 섹션 넘버, 몽타주 정보)
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

// 노티파이 함수.
void UGSAnimInstance::AnimNotify_AttackHitCheck()
{
	UE_LOG(LogTemp, Warning, TEXT("AttackHitCheck"));
	OnAttackHitCheck.Broadcast();
}

void UGSAnimInstance::AnimNotify_NextAttackCheck()
{
	UE_LOG(LogTemp, Warning, TEXT("NextAttackCheck"));
	OnNextAttackCheck.Broadcast();
}

FName UGSAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	return FName(*FString::Printf(TEXT("Attack %d\n"),Section));
}
