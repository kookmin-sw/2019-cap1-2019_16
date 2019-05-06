// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDarkCharacter.h"
//#include "LostDarkPlayerController.h"
#include "GSAnimInstance.h"
#include "GSWeapon.h"
// 스텟 정보
#include "GSCharacterStatComponent.h"
#include "DrawDebugHelpers.h"
// UI 위젯 사용하기 위해 반드시 필요한 UMG 언리얼 엔진 헤더
#include "Components/WidgetComponent.h"
// 우리가 만든 위젯의 로직이 들어간 클래스
#include "GSCharacterWidget.h"
// AI 컨트롤러를 위한
#include "LDAIController.h"


/// 생성자 Sets Default values
ALostDarkCharacter::ALostDarkCharacter()
{
	// tick 함수 활성화
	PrimaryActorTick.bCanEverTick = true;

	// Boom(=SpingArm) 초기화 (기본세팅) 컴포넌트 생성
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// Camera 초기화 (기본세팅) 컴포넌트 생성
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// 캐릭터 스텟에 관한 컴포넌트 생성
	CharacterStat = CreateDefaultSubobject<UGSCharacterStatComponent>(TEXT("CHARACTERSTAT"));
	// UI 위젯 컴포넌트 생성
	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));


	// Boom 캡슐에 붙이기(상속)
	CameraBoom->SetupAttachment(GetCapsuleComponent());
	// Camera를 Boom에 붙이기(상속)
	FollowCamera->SetupAttachment(CameraBoom);
	// 메시에 위젯 컴포넌트를 부착한다.
	HPBarWidget->SetupAttachment(GetMesh());

	// 시점 쿼터뷰로 초기화 (카메라, SpringArm 설정)
	SetControlMode(EControlMode::BackView);

	// 외부 메시 초기 위치값, 방향 언리얼 좌표계에 맞게 재설정 (높이 88만큼 내리고, 회전 앞으로 90도 회전)
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	// 외부 메시 정보를 변수로 가져오기. ※외부메시는 오브젝트이다 => FObjectFinder
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Greystone(TEXT(
		"/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));

	// 메시가 유효하다면,
	if (Greystone.Succeeded())
	{
		// 현재 캐릭터에 메시 초기화(설정). 메시는 오브젝트이므로 Object를 정보를 넘김.
		GetMesh()->SetSkeletalMesh(Greystone.Object);
	}

	// 애니메이션을 애니메이션 블루프린트로 처리하기 위해 애니메이션 모드 옵션 재설정. ※애니메이션은 Mesh가 최종 관리하기 때문에 GetMesh()에서 설정함.
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// 애니메이션 인스턴스 정보를 변수로 가져오기. ※애니메이션 인스턴스는 클래스이다 => FClassFinder, 마지막에 _C를 적어줘야함.
	static ConstructorHelpers::FClassFinder<UAnimInstance> Greyston_Anim(TEXT(
		"/Game/SH/Animations/GS_AnimBlueprint.GS_AnimBlueprint_C"));

	// 애님인스턴스가 유효하다면,
	if (Greyston_Anim.Succeeded())
	{
		// 현재 캐릭터의 애님인스턴스를 외부 애님인스턴스로 초기화(설정)
		GetMesh()->SetAnimInstanceClass(Greyston_Anim.Class);
	}

	// 시점 변경에서 카메라 막대로 변경되는 속도 조절
	BoomLengthSpeed = 3.0f;
	BoomRotationSpeed = 10.0f;

	// 점프속도 변경. Z축 속도 변경. 
	GetCharacterMovement()->JumpZVelocity = 450.0f;

	// 초기 공격상태는 false
	IsAttacking = false;

	// 최대 콤보 카운트 수
	MaxCombo = 3;
	// 시작할때 먼저 호출하고 시작함.
	AttackEndComboState();

	// 캡슐컴포넌트에 우리가 만든 콜리전채널 설정. GSCharacter라는 콜리전채널임
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("GSCharacter"));

	// 디버깅 캡슐 길이 200cm
	AttackRange = 200.0f;
	// 디버깅 캡슐 반지름 50cm
	AttackRadius = 50.0f;

	///* 부착할 무기 애셋 캐릭터 메시에 부착  */
	//FName WeaponSocket(TEXT("sword_bottom")); //이름은 실제 bone의 이름과 일치해야함.
	//// 해당 메시에 소켓이 존재한다면
	//if (GetMesh()->DoesSocketExist(WeaponSocket))
	//{
	//	// 스켈레탈 메시 컴포넌트를 생성하고
	//	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	//	// 애셋 정보를 변수로 받고
	//	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT(
	//		"/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight"));
	//	// 애셋 정보를 무사히 받아왔다면
	//	if (SK_WEAPON.Succeeded())
	//	{
	//		// 스켈레탈 메시 컴포넌트에 해당 애셋 정보를 넘겨줌 (실제 부착)
	//		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	//	}
	//	// 새로만든 컴포넌트를 자신의 메시에 적절한 위치에 상속시킴. 소켓 위치를 기준으로 트랜스폼이 자동으로 설정됨. (위치조절)
	//	Weapon->SetupAttachment(GetMesh(), WeaponSocket);
	//}
	
	/* HPBarWidget에 대한 내용 */
	// 위젯 위치 Z축으로 180cm
	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 202.0f));
	// UI 위젯은 항상 플레이어를 향해 보도록 Screen 모드로 지정.
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	// 외부 애셋 정보 가져옴. 위젯은 Class단위이므로 반드시 _C를 붙여준다. (★실수주의)
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/SH/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded())
	{
		// 외부 위젯 클래스 정보를 등록 (우리가 만든 위젯 등록) => 실제로 화면에 그리는 함수이기도 함.
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		// 위젯의 크기를 조절해주는 함수. (가로=150cm , 세로=50cm)
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}

	// Pawn.h에 미리 제공되는 멤버변수. AI 클래스 속성을 등록하는 변수인데, 우리가 만든 AIController를 등록함.
	AIControllerClass = ALDAIController::StaticClass();
	// 자동 AI 지배를 받는다. 조건은 레벨에 설치하거나 스폰할때. 이것에 해당하는 모든 캐릭터(LostDarkCharacter로 만든 캐릭터)
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}


void ALostDarkCharacter::BeginPlay()
{
	Super::BeginPlay();
	/// 캐릭터가 생성되자마자 손에 무기를 가지게 되는 함수
	//FName WeaponSocket(TEXT("sword_bottom")); //이름은 실제 bone의 이름과 일치해야함.
	//// 무기 액터를 월드에 생성시킴.
	//auto CurrentWeapon = GetWorld()->SpawnActor<AGSWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
	//// 무기 액터가 생성됐다면
	//if (nullptr != CurrentWeapon)
	//{
	//	// 생성된 무기액터를 자신의 메시에 FAttachmentTransformRules::SnapToTargetNotIncludingScale??? 로 하게, WeaponSocket에 위치한 bone에 부착한다.
	//	/// 실제 부착하는 내용이라고 볼 수 있음.
	//	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
	//}



	/* ★★★ Changed in 4.21. copied from PostInitializeComponents() ㅠㅠ  */

	// 위젯에 설정된 부모 UserWidget 정보를 넘겨줌. /// 여기서 자꾸 null처리됨.
	auto CharacterWidget = Cast<UGSCharacterWidget>(HPBarWidget->GetUserWidgetObject());
	/// 내가 임시로 추가한것. 여기서 에러뜸. (이걸 제대로 받아오지 못하고 있음)
	ABCHECK(nullptr != CharacterWidget);

	if (nullptr != CharacterWidget)
	{
		// 캐릭터의 PostInitializeComponents 함수에서 캐릭터 컴포넌트와 UI 위젯을 연결하는 함수.
		CharacterWidget->BindCharacterStat(CharacterStat);
	}
}

void ALostDarkCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 최초 시작할때 카메라가 자리잡는 함수. InterpTo를 이용 (보간법 : Interpolation)
	CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength, BoomLengthTo, DeltaTime, BoomLengthSpeed);

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		// 카메라 이동
		CameraBoom->RelativeRotation = FMath::RInterpTo(CameraBoom->RelativeRotation, BoomRotationTo, DeltaTime, BoomRotationSpeed);
		break;
	default:
		break;
	}

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		// SizeSquard() 나중에 찾아보기
		if (DirectionToMove.SizeSquared() > 0.0f)
		{
			// 캐릭터 컨트롤러의 회전값 설정. X축 방향의 회전행렬을 구하고, 그것에 일치하는 FRotator(Rotator)값을 얻어옴.
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
		}
		break;
	default:
		break;
	}
}

// 모든 컴포넌트가 초기화되면 불리어지는 함수. 일종의 BeginPlay함수인듯. 차이가 있는데 생략.
void ALostDarkCharacter::PostInitializeComponents()
{
	// 부모것 호출
	Super::PostInitializeComponents();
	/*UE_LOG(LogTemp, Warning, TEXT("PostInitializeComponents Start !!! to LostDarkCharacter.cpp"));*/
	// GS 애님인스턴스 정보 가져오기
	GSAnim = Cast<UGSAnimInstance>(GetMesh()->GetAnimInstance());
	// GS 애님인스턴스를 가져오지 못했다면 예외처리후 함수반환
	ABCHECK(nullptr != GSAnim);
	// 몽타주 재생이 끝나면, 자동으로 OnAttackMontageEnded 라는 함수를 호출하는것임. AnimInstance->OnMontageEnded는 이미 제공함.
	GSAnim->OnMontageEnded.AddDynamic(this, &ALostDarkCharacter::OnAttackMontageEnded);

	// 노티파이 신호가 들어오면 일로 들어옴. void를 반환
	GSAnim->OnNextAttackCheck.AddLambda([this]() -> void {
		// OnNextAttackCheck 브로드캐스트가 발동됨을 Log로 찍음.
		//UE_LOG(LogTemp, Warning, TEXT("OnNextAttackCheck Lambda Called"));
		ABLOG(Warning, TEXT("OnNextAttackCheck"));
		// 다음 콤보로 못가게 하고
		CanNextCombo = false;
		// 콤보 입력이 들어왔다면 // NextAttackCheck 노티파이 브로드캐스트 이전까지 공격이 2번이상 눌렸다면
		if (IsComboInputOn)
		{
			// 콤보 시작 함수 호출 (콤보 카운트 증가)
			AttackStartComboState();
			// 다음 섹션 콤보를 불러옴
			GSAnim->JumpToAttackMontageSection(CurrentCombo);
			UE_LOG(LogTemp, Warning, TEXT("Called JumpTo Function, Combo : %d"),CurrentCombo);
		}
	});
	// OnAttackHitCheck 노티파이에서 브로드캐스트가 들어오면, 2번째 인자에 해당하는 함수를 호출함(=AttackCheck)
	GSAnim->OnAttackHitCheck.AddUObject(this, &ALostDarkCharacter::AttackCheck);

	// GSCharacterStatComponent의 OnHPIsZero 델리게이트가 브로드캐스트 하면 호출되는 람다함수. HP가 0이하로 떨어지면 호출함.
	CharacterStat->OnHPIsZero.AddLambda([this]()->void {
		ABLOG(Warning, TEXT("@@ HP Is Zero"));
		// 죽는 애니메이션 작동
		GSAnim->SetDeadAnim();
		// 현재 액터의 콜리전을 끔.
		SetActorEnableCollision(false);
	});

	//// 위젯에 설정된 부모 UserWidget 정보를 넘겨줌. /// 여기서 자꾸 null처리됨.
	//auto CharacterWidget = Cast<UGSCharacterWidget>(HPBarWidget->GetUserWidgetObject());
	///// 내가 임시로 추가한것. 여기서 에러뜸. (이걸 제대로 받아오지 못하고 있음)
	//ABCHECK(nullptr != CharacterWidget);

	//if (nullptr != CharacterWidget)
	//{
	//	ABLOG(Warning, TEXT("Success!!!!!!!!!!!!!!!!!! :("));
	//	// 캐릭터의 PostInitializeComponents 함수에서 캐릭터 컴포넌트와 UI 위젯을 연결하는 함수.
	//	CharacterWidget->BindCharacterStat(CharacterStat);
	//}
}

// 데미지 받는 로직을 구현하는 함수. AActor에 있는 로직을 추가 구현함.
float ALostDarkCharacter::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	// 부모로직에 받은 데미지 프레임워크를 던져서 결과값을 받음. (결과값은 최종적으로 받은 데미지 크기)
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	// 데미지를 받아서 데미지 프레임워크가 발동한 폰의 이름과, 결과적으로 받은 총 데미지 크기를 LOG로 출력함.
	ABLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);

	/*
	// 들어온 데미지가 0보다 크다면
	if (FinalDamage > 0.0f)
	{
		// 현재 자신의 상태를 Dead로 바꾼다.
		GSAnim->SetDeadAnim();
		// 현재 자신의 액터 콜리전을 끈다.
		SetActorEnableCollision(false);
	}
	*/
	
	// 캐릭터스텟 (액터 컴포넌트)에 있는 SetDamage를 호출함. 데미지 받은 데이터를 그쪽으로 넘겨줌. 참고로 거기서 상호작용 끝내고 반대로 반환함.
	CharacterStat->SetDamage(FinalDamage);

	// 최종적으로 받은 데미지를 반환한다
	return FinalDamage;
}

void ALostDarkCharacter::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);
	// 플레이어 컨트롤러가 있다면
	if (IsPlayerControlled())
	{
		// 백뷰 (플레이어 시작)
		SetControlMode(EControlMode::BackView);
		// 걷는 속도 조절
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}
	// 플레이어가 아닌 AI라면
	else
	{
		// NPC 설정으로 변경
		SetControlMode(EControlMode::NPC);
		// 최대 이동속도 조절
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	}

}

// 현재 무기를 장착하고 있는지 확인하는 함수
bool ALostDarkCharacter::CanSetWeapon()
{
	// 없으면 true, 무기가 있다면 false
	return (nullptr==CurrentWeapon);
}

// 무기 장착함수
void ALostDarkCharacter::SetWeapon(AGSWeapon * NewWeapon)
{
	// (무기 정보가 있고, 동시에 현재 무기가 없다면) 통과. 아니면 경고 로그로 찍고 return.
	ABCHECK(nullptr != NewWeapon && nullptr == CurrentWeapon);
	// 스켈레탈 메시의 Bone의 이름을 변수화시킴. 이름은 실제 bone의 이름과 일치해야함.
	FName WeaponSocket(TEXT("sword_bottom"));
	// 무기 클래스가 없지 않다면,
	if (nullptr != NewWeapon)
	{
		// NewWeapon 무기에 해당하는걸 자신의 메시(GetMesh)에 FAttachmentTransformRules::SnapToTargetNotIncludingScale??? 로 하게, WeaponSocket에 위치한 bone에 부착한다.
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
		// 무기의 소유자를 변경
		NewWeapon->SetOwner(this);
		// 현재 장착 무기를 등록
		CurrentWeapon = NewWeapon;
	}
}

// Input 설정 (일종의 Input을 위한 Tick함수)
void ALostDarkCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// BindAction 설정. EInputEvent::IE_Pressed, Released 함수가 있다. 누르고 뗄때.
	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::ViewChange);

	// Jump 설정. Jump는 기본적으로 Character 클래스에 이미 설계되어 있어서, 부모의 함수로 바인딩 시키면 됨.
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::Jump);

	// Attack, Mouse X 바인딩하기.
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::Attack);

	/*
		BindAxis(1, 2, 3)
		1 : 프로젝트 세팅 Input에 있는 BindAxis 변수 이름을 TEXT 형태로 넣어준다.
		2 : 사용하려는 클래스 정보를 넘겨준다. 해당 클래스에서 사용하니까 this.
		3 : Input이 들어갈때마다 호출할 함수의 주소를 넘겨준다. (함수의 주소는 함수 이름)
		결과 : Input이 될때마다 3번째 인자로 들어가는 함수를 자동 호출함.
	*/
	// Input 설정에 있는 MoveForward 바인딩하기.
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ALostDarkCharacter::MoveForward);
	// Input 설정에 있는 MoveRight 바인딩하기.
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ALostDarkCharacter::MoveRight);

	/// 원래 위의것과 똑같은 형태로 짜야하는데, 기존의 함수를 그대로 사용해봄.
	// 부모 Pawn 클래스에 있는 AddControllerYawInput 함수를 호출함
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	// 부모 Pawn 클래스에 있는 AddControllerPitchInput 함수를 호출함
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

}

// 마우스 좌클릭, Attack 구현. 몽타주를 사용해 공격 애니메이션을 재생함.
void ALostDarkCharacter::Attack()
{
	// 현재 몽타주 재생중이라면
	if (IsAttacking)
	{
		// 만약 현재 Combo카운트가 1~3 사이가 아니라면 반환 (예외처리)
		ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));
		// IsInputCombo 노티파이가 불리어졌는지
		if (GSAnim->IsInputCombo)
		{
			// 공격중인데, 다음 콤보로 갈수 있다면,
			if (CanNextCombo)
			{
				// 콤보를 넣었다는 신호임.
				IsComboInputOn = true;
				//UE_LOG(LogTemp, Warning, TEXT("Can NextCombo : %d"),CurrentCombo);
			}
		}

	}
	// 공격중이 아니라면,
	else
	{
		// 만약 현재 Combo가 0이 아니면 반환
		ABCHECK(CurrentCombo == 0);
		// 콤보 스테이트 호출. 콤보 카운트 증가 1로
		AttackStartComboState();
		// 애님인스턴스 몽타주 함수 호출. 최초 애니메이션 재생
		GSAnim->PlayAttackMontage();
		// 다음 섹션으로 현재 콤보 카운트를 넘김.
		GSAnim->JumpToAttackMontageSection(CurrentCombo);
		// 공격 상태 변수 설정
		IsAttacking = true;
	}
	//// 애님 인스턴스 가져옴. Mesh에 달려있는 애님인스턴스를 UGS로 형변환후 등록.
	//auto AnimInstance = Cast<UGSAnimInstance>(GetMesh()->GetAnimInstance());
	//// 혹시 애님 인스턴스로 받지 못했을때 (exception handler)
	//if (nullptr == AnimInstance) return;
	//// 애님 인스턴스에 있는 몽타주 함수를 재생시킴.
	//AnimInstance->PlayAttackMontage();

	//IsAttacking = true;
}

// 델리게이트로 지정된 함수. 몽타주가 완전히 끝나면, 자동으로 불리어짐.
void ALostDarkCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterruped)
{
	// IsAttacking이 아니라면 바로 붉은 에러 띄우고 return.
	ABCHECK(IsAttacking);
	// CurrentCombo가 0보다 크지 않으면 return.
	ABCHECK(CurrentCombo > 0);
	// 재생중인 몽타주가 끝나면 IsAttacking 변수를 다시 false로 초기화.
	IsAttacking = false;
	// 몽타주가 끝나면 호출
	AttackEndComboState();
	// 몽타주 끝난거 Log 찍어주기
	UE_LOG(LogTemp, Warning, TEXT("MontageEnded"));

	// AI의 경우 FinishLatentTask 함수를 호출하기 위해 만듦.
	OnAttackEnd.Broadcast();
}

// 공격이 시작할때 관련 속성 지정하는 함수. Combo 카운트를 증가시킴
void ALostDarkCharacter::AttackStartComboState()
{
	// 다음 콤보로 넘어갈 수 있음.
	CanNextCombo = true;
	// 아직 콤보는 들어가지 않음. (최초)
	IsComboInputOn = false;
	// 만약 CurrentCombo가 0~2 값이 아니라면 빨간 오류 출력하고 반환
	ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	/*
		Clamp : 최소 최대값 제한 함수. (현재 값 , 최소, 최대) 작거나 최대값보다 크면, 해당값을 리턴함.
		(1,3)이 최대임. CurrentCombo는 3에서는 증가가 안됨. 참고로 최초는 0이 들어와서 1이됨. 그래서 첫번째 콤보 애니메이션 1이 찍히는것임
	*/
	/// 실제 콤보 카운트가 증가하는 코드임.
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

// 공격이 종료할 때 사용할 함수
void ALostDarkCharacter::AttackEndComboState()
{
	// 콤보 입력 여부를 다시 false로 바꿔줌
	IsComboInputOn = false;
	// 다음 콤보로 가는걸 막음 (최대)
	CanNextCombo = false;
	// 현재 콤보를 다시 0으로 초기화
	CurrentCombo = 0;
}

void ALostDarkCharacter::AttackCheck()
{
	// 충돌된 물체의 정보를 담는 구조체변수
	FHitResult HitResult;
	// 탐색 방법은 자기자신은 탐지되지 않도록 this를 넣어줌. 구조체임.
	FCollisionQueryParams Params(NAME_None, false, this);
	// Sweep 실행. (일종의 Ray발사)
	bool bResult = GetWorld()->SweepSingleByChannel(
		// 충돌된 물체를 담는 변수
		HitResult,
		// 시작 위치로 현재 액터의 위치를 넣어줌. Vector값
		GetActorLocation(),
		// 끝낼 위치로 현재 액터 앞방향으로 2m 떨어진곳. Vector값
		GetActorLocation() + GetActorForwardVector()*AttackRange,
		// 탐색할 도형의 회전값 기본으로
		FQuat::Identity,
		// 물리 충돌 감지에 사용할 트레이스 채널 정보
		ECollisionChannel::ECC_GameTraceChannel2,
		// 탐색할 도형의 종류와 반지름 길이
		FCollisionShape::MakeSphere(AttackRadius),
		// 탐색 방법에 대한 설정값을 모아둔 구조체
		Params);

	// 만약 디버그를 그릴수 있다면,
#if ENABLE_DRAW_DEBUG

	// 공격 길이를 벡터로 변수화
	FVector TraceVec = GetActorForwardVector()*AttackRange;
	// 중앙값은 현재위치값 + 앞방향의 중간
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	// 절반높이 = 절반값 + 반지름값. 캡슐형이기 때문에 실제 절반 높이는 반지름값을 더해줘야함.
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	// 서있는 캡슐을 눕히는 회전행렬
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	// 디버깅 캡슐의 색깔. 충돌하면 초록색, 아니면 빨간색
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	// 디버깅 캡슐의 생존시간
	float DebugLifeTime = 5.0f;

	// 디버그 캡슐
	DrawDebugCapsule(
		// 세상에 그리고
		GetWorld(),
		// 중심값
		Center,
		// 중심까지의 길이
		HalfHeight,
		// 전체 판정 길이
		AttackRadius,
		// 디버그 캡슐의 회전량
		CapsuleRot,
		// 색깔
		DrawColor,
		// 무시
		false,
		// 생존시간
		DebugLifeTime);

#endif

	// 만약 충돌된 물체가 있다면,
	if (bResult)
	{
		// 충돌된 액터의 물체가 유효한 것이라면
		if (HitResult.Actor.IsValid())
		{
			// 부딪힌 물체의 액터의 이름을 출력한다.
			ABLOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.Actor->GetName());
			// 언리얼에서 제공하는 데미지 프레임워크 구조체 변수 선언. (데미지 종류중 기본값인듯)
			FDamageEvent DamageEvent;
			// 충돌한 물체에 데미지 프레임워크를 발동함. (전달할 데미지 세기, 데미지 종류, 공격명령을 내린 가해자(컨트롤러), 제미지 전달을 위해 사용한 도구(폰))
			HitResult.Actor->TakeDamage(CharacterStat->GetAttack(), DamageEvent, GetController(), this);
			/// 캐릭터 스텟 테이블에 있는 변수를 참조해서 공격력을 넘김GetAttack()
		}
	}
}

// 시점 변수 변경
void ALostDarkCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		GetController()->SetControlRotation(GetActorRotation());
		// BackView였으면 QuaterView로 변경
		SetControlMode(EControlMode::QuaterView);
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		GetController()->SetControlRotation(CameraBoom->RelativeRotation);
		// QuaterView였으면 BackView로 변경
		SetControlMode(EControlMode::BackView);
		break;
	default:
		break;
	}
}

// 시점 전환 함수
void ALostDarkCharacter::SetControlMode(EControlMode NewControlMode)
{
	// 현재 시점 변수 재설정.
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		// Boom 길이 설정.
		//CameraBoom->TargetArmLength = 450.0f;
		// Boom 회전값은 (0,0,0) = 플레이어가 바라보는 X축 방향의 (1,0,0)을 의미함.
		//CameraBoom->SetRelativeRotation(FRotator::ZeroRotator);

		// Boom 길이 초기화
		BoomLengthTo = 450.0f;
		/// 없던거 추가함
		BoomRotationTo = FRotator::ZeroRotator;

		// SpringArm의 회전값으로 플레이어 컨트롤러 회전값을 사용함. (= 마우스가 회전하면 카메라도 같은 값으로 회전함)
		CameraBoom->bUsePawnControlRotation = true;
		// 부모 컴포넌트(플레이어)에서 회전값을(피치,롤,요) 상속받을지
		CameraBoom->bInheritPitch = true;
		CameraBoom->bInheritRoll = true;
		CameraBoom->bInheritYaw = true;
		// ProbeChannel, ProbeSize를 사용하여 충돌체크, 카메라 클리핑이 일어나는것을 방지한다. (카메라와 플레이어 사이에 다른 물체가 간섭하면, 캐릭터로 줌인함)
		CameraBoom->bDoCollisionTest = true;
		// 좌우 회전 막음. true인 경우, Pawn의 Yaw가 플레이어 컨트롤러의 Yaw에 매칭되도록 함. (마우스 회전-> 플레이어 컨트롤러 -> 폰의 회전값 변경했음)
		bUseControllerRotationYaw = false;
		// 캐릭터가 움직이는 방향으로 캐릭터를 자동으로 회전시켜주는 CharacterMovement 함수임.
		GetCharacterMovement()->bOrientRotationToMovement = true;
		//
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		// 회전 속도 조절. (Y 회전 속도, Z 회전 속도, x 회전속도) 이유는 모르겟음. => 함수 구현을 다른것과 다르게 해서 헷갈림. 주의!
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // 왜 Y값이 Yaw인지 모르겠음. FRotator 함수 구현에서 순서가 다름.
		break;

	case ALostDarkCharacter::EControlMode::QuaterView:
		// 길이 800
		//CameraBoom->TargetArmLength = 800.0f;
		// 아래로 45도 회전
		//CameraBoom->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

		// Boom 길이 초기화
		BoomLengthTo = 800.0f;
		// Boom 회전값 초기화
		BoomRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
		// SpringArm의 회전값으로 플레이어 컨트롤러 회전값을 사용
		CameraBoom->bUsePawnControlRotation = false;
		// 부모 컴포넌트(플레이어)에서 회전값을(피치,롤,요) 상속받을지
		CameraBoom->bInheritPitch = false;
		CameraBoom->bInheritRoll = false;
		CameraBoom->bInheritYaw = false;
		// ProbeChannel, ProbeSize를 사용하여 충돌체크, 카메라 클리핑이 일어나는것을 방지하지 않음.
		CameraBoom->bDoCollisionTest = false;
		// Pawn의 Yaw가 플레이어 컨트롤러의 Yaw에 매칭되도록 함.
		bUseControllerRotationYaw = false;
		// 캐릭터가 움직이는 방향으로 캐릭터를 자동으로 회전시켜주는 함수를 끔.
		GetCharacterMovement()->bOrientRotationToMovement = false;
		// 대신 자연스럽게 회전하는것을 킴.
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		// 회전 속도 조절
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
		break;

	case EControlMode::NPC:
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 480.0f, 0.0f);
		break;
	default:
		break;
	}
}

// 앞뒤 이동 함수
void ALostDarkCharacter::MoveForward(float Value)
{
	// Character 클래스에서 제공하는 이동 함수. (방향, 이동크기)
	//AddMovementInput(GetActorForwardVector(), Value);

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		// 컨트롤 회전 값으로부터 회전행렬을 만들고, 원하는 방향 축을 대입해 캐릭터가 움직이는 방향으로 이동하게 한다.
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), Value);
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		DirectionToMove.X = Value;
		break;
	default:
		break;
	}
}

// 좌우 이동 함수
void ALostDarkCharacter::MoveRight(float Value)
{
	// Character 클래스에서 제공하는 이동 함수. (방향, 이동크기)
	//AddMovementInput(GetActorRightVector(), Value);

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		// 컨트롤 회전 값으로부터 회전행렬을 만들고, 원하는 방향 축을 대입해 캐릭터가 움직이는 방향으로 이동하게 한다.
		AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), Value);
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		DirectionToMove.Y = Value;
		break;
	default:
		break;
	}
}

//void ALostDarkCharacter::LookUp(float Value)
//{
//	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), Value);
//}
//
//void ALostDarkCharacter::Turn(float Value)
//{
//	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), Value);
//}