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
	// 몽타주 에셋을 무사히 찾았으면
	if (Attack_Montage1.Succeeded())
	{
		// 몽타주 애셋 정보 등록
		AttackMontage = Attack_Montage1.Object;
		UE_LOG(LogTemp, Warning, TEXT("Enroll Attack Montage"));
	}
	// 최초 콤보 입력이 들어오지 않았음.
	IsInputCombo = false;
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
	// ABCHECK(!IsDead);
	// 등록된 몽타주 재생.
	Montage_Play(AttackMontage, 1.0f);
}

// 몽타주에서 다음 공격 섹션으로 넘어가는 함수
void UGSAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	// 만약 몽타주가 재생중이지 않다면, 빨간 에러 출력하고 return. (예외처리)
	ABCHECK(Montage_IsPlaying(AttackMontage));
	// Montage_JumpToSection는 부모 AnimInstance에서 미리 기능제공. (현재 섹션 넘버, 재생중인 몽타주 정보)
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

// 노티파이 함수.
void UGSAnimInstance::AnimNotify_AttackHitCheck()
{
	//UE_LOG(LogTemp, Warning, TEXT("AttackHitCheck"));
	OnAttackHitCheck.Broadcast();
}

// 다음 콤보가 있으면 발동.
void UGSAnimInstance::AnimNotify_NextAttackCheck()
{
	// 다시 콤보 입력값 없앰.
	IsInputCombo = false;
	//UE_LOG(LogTemp, Warning, TEXT("NextAttackCheck"));
	// 아래 델리게이트 로직은 람다식으로 구현할 예정
	OnNextAttackCheck.Broadcast();

}

// 이 함수가 불리어지고 NextAttackCheck()가 불리기 전까지 들어온 공격만 추가 콤보 입력으로 받아들임
void UGSAnimInstance::AnimNotify_IsInputCombo()
{
	// 이제부터 들어오는 공격은 전부 추가 콤보 공격임.
	IsInputCombo = true;
}

// 다음 공격 섹션 정보를 출력
FName UGSAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	// 만약 Section이 1~3 까지 숫자가 아니라면, return
	ABCHECK(FMath::IsWithinInclusive<int32>(Section, 1, 3), NAME_None);
	// 현재 콤보 상태를 알려주는 섹션 숫자를 출력
	///★★★★★ 매우 주의해야하는건, Attack%d는 다음 노티파이 이름과 동일해야함. 그래서 띄어쓰기하면 안됨!
	return FName(*FString::Printf(TEXT("Attack%d"),Section));
}
