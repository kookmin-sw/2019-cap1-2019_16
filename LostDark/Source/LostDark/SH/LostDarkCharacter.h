// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LostDark.h"
#include "GameFramework/Character.h"
#include "LostDarkCharacter.generated.h"

// AI가 공격이 끝났을때 발동할 델리게이트 선언. BTTask_Attack 클래스에 델리게이트 등록하는 함수 있음.
DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

/*
	클래스 지정자 : Config = ConfigName
	이 클래스는 환경설정(.ini)파일에 데이터를 저장할 수 있음을 나타낸다.
	이 지정자는 그 프로퍼티를 해당 이름의 환경설정 파일에 저장하도록 한다.
	모든 자식 클래스에 전파되며, 자식 클래스에서 환경설정 파일을 바꿀 수 있다.
*/
UCLASS(config=Game)
class ALostDarkCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	ALostDarkCharacter();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// 부착할 무기 애셋 변수
	UPROPERTY(VisibleAnywhere, Category = Weapon)
		USkeletalMeshComponent* Weapon;

	// UI 위젯 전방선언. 액터에 UI 위젯을 부착할 수 있는 UWidgetComponent 클래스임.
	UPROPERTY(VisibleAnywhere, Category = UI)
		// 외부 위젯 블루프린트 클래스 정보를 담는 변수
		class UWidgetComponent* HPBarWidget;

	// Attack 기능을 담당하는 함수. AI컨트롤러에게 명령을 내릴수 있도록 public으로 변경함
	void Attack();
	// 델리게이트 변수 선언
	FOnAttackEndDelegate OnAttackEnd;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	// 시점 전환 열거형
	enum class EControlMode
	{
		BackView, //백뷰
		QuaterView, //쿼터뷰
		NPC
	};

	// 시점 전환 함수
	void SetControlMode(EControlMode NewControlMode);
	// 현재 시점 변수
	EControlMode CurrentControlMode = EControlMode::BackView;
	// 쿼터뷰에서 앞방향(X방향)을 나타내는 멤버변수
	FVector DirectionToMove = FVector::ZeroVector;

	// Boom 길이
	float BoomLengthTo = 0.0f;
	// Boom 회전값
	FRotator BoomRotationTo = FRotator::ZeroRotator;
	// 시점 변경시 해당 Boom으로 늘어나거나 줄어드는 속도
	float BoomLengthSpeed = 0.0f;
	// 시점 변경시 해당 Boom으로 회전하는 속도
	float BoomRotationSpeed = 0.0f;

private:
	// Called for forwards/backward input
	void MoveForward(float Value);
	// Called for side to side input
	void MoveRight(float Value);

	// 아래 함수는 Pawn에서 기본적으로 제공하는 함수가 있어서 그걸 이용하면됨.
	// void LookUp(float Value);
	// void Turn(float Value);

	// 시점 변수 설정하는 함수
	void ViewChange();

	//// Attack 기능 함수
	//void Attack();

	// BP와 관련된 C++함수는 반드시 UFUNCTION 매크로를 사용해야한다. 다이나믹 델리게이트.
	UFUNCTION()
		// 몽타주 관련 델리게이트 함수. UAnimMontage을 적어야함!
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	// 공격이 시작할때 관련 속성 지정하는 함수
	void AttackStartComboState();
	// 공격이 종료할 때 사용할 함수
	void AttackEndComboState();
	// 공격 물리판정 함수
	void AttackCheck();

private:
	//인스턴스 속성을 보여주는 에디터 뷰포트에서만 보여지는 VisibleInstanceOnly.
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 현재 공격중인지 확인하는 변수. 
		bool IsAttacking;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 다음 콤보로 이동 가능 여부
		bool CanNextCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 콤보 입력여부
		bool IsComboInputOn;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 현재 실행중인 콤보 카운트
		int32 CurrentCombo;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 콤보 카운트 최대치
		int32 MaxCombo;

	// 자주사용할 애님 인스턴스 클래스를 포인터로 아예 가져오자. (전방선언)
	UPROPERTY()
		class UGSAnimInstance* GSAnim;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 공격 길이 변수
		float AttackRange;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		// 공격 반경 (반지름)
		float AttackRadius;

// 마네킹에 있는거 놔둔 함수. 쓸모있을지도?
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// 몽타주 재생을 위한 델리게이트 함수 선언 (모든 컴포넌트가 초기화 됐을때 불리어짐). OnMontageEnded 델리게이트에 바인딩한다.
	virtual void PostInitializeComponents() override;
	
	
	// AActor에 있는 TakeDamage함수를 추가 구현한다. 가상함수. 받는부분에 대한 로직을 여기서 구현함.
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	// 게임 시작후 최초 빙의했을때 자동 호출하는 함수
	virtual void PossessedBy(AController* NewController) override;


	// 무기 장착여부 조사
	bool CanSetWeapon();
	// 무기를 장착하는 함수
	void SetWeapon(class AGSWeapon* NewWeapon);
	// 무기 클래스에 대한 전방선언
	UPROPERTY(VisibleAnywhere, Category = Weapon)
		class AGSWeapon* CurrentWeapon;

	// 캐릭터 스텟 컴포넌트 전방선언
	UPROPERTY(VisibleAnywhere, Category = Stat)
		class UGSCharacterStatComponent* CharacterStat;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};