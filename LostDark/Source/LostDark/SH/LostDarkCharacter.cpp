// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDarkCharacter.h"
#include "LostDarkPlayerController.h"
#include "GSAnimInstance.h"

ALostDarkCharacter::ALostDarkCharacter()
{
	// tick 함수 활성화
	PrimaryActorTick.bCanEverTick = true;

	// Boom(=SpingArm) 초기화 (기본세팅)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// Camera 초기화 (기본세팅)
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	// Boom 캡슐에 붙이기(상속)
	CameraBoom->SetupAttachment(GetCapsuleComponent());
	// Camera를 Boom에 붙이기(상속)
	FollowCamera->SetupAttachment(CameraBoom);

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
}


void ALostDarkCharacter::BeginPlay()
{
	Super::BeginPlay();
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
	// GS 애님인스턴스 정보 가져오기
	GSAnim = Cast<UGSAnimInstance>(GetMesh()->GetAnimInstance());
	// GS 애님인스턴스를 가져오지 못했다면 예외처리후 함수반환
	ABCHECK(nullptr != GSAnim);
	// 몽타주 재생이 끝나면, 자동으로 OnAttackMontageEnded 라는 함수를 호출하는것임. AnimInstance->OnMontageEnded는 이미 제공함.
	GSAnim->OnMontageEnded.AddDynamic(this, &ALostDarkCharacter::OnAttackMontageEnded);
	UE_LOG(LogTemp, Warning, TEXT("PostInitializeComponents, AddDynamic"));

	// 노티파이 신호가 들어오면 일로 들어옴. void를 반환
	GSAnim->OnNextAttackCheck.AddLambda([this]() -> void {
		// OnNextAttackCheck 브로드캐스트가 발동됨을 Log로 찍음.
		UE_LOG(LogTemp, Warning, TEXT("OnNextAttackCheck Lambda Called"));
		//ABLOG(Warning, TEXT("OnNextAttackCheck"));
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
		// 공격중인데, 다음 콤보로 갈수 있다면,
		if (CanNextCombo)
		{
			// 콤보를 넣었다는 주문을 넣어줌.
			IsComboInputOn = true;
			//UE_LOG(LogTemp, Warning, TEXT("Can NextCombo : %d"),CurrentCombo);
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