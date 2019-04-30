// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDarkCharacter.h"
#include "LostDarkPlayerController.h"

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
	SetControlMode(EControlMode::QuaterView);

	// 외부 메시 초기 위치값, 방향 언리얼 좌표계에 맞게 재설정 (높이 88만큼 내리고, 회전 앞으로 90도 회전)
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));


	/*
		<스켈레탈 메시 적용>
	*/
	// 외부 메시 정보를 변수로 가져오기. ※외부메시는 오브젝트이다 => FObjectFinder
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Greystone(TEXT(
		"/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));

	// 메시가 유효하다면,
	if (Greystone.Succeeded())
	{
		// 현재 캐릭터에 메시 초기화(설정). 메시는 오브젝트이므로 Object를 정보를 넘김.
		GetMesh()->SetSkeletalMesh(Greystone.Object);
	}

	/*
		<애니메이션 블루프린트 적용>
	*/
	// 애니메이션을 애니메이션 블루프린트로 처리하기 위해 애니메이션 모드 옵션 재설정. ※애니메이션은 Mesh가 최종 관리하기 때문에 GetMesh()에서 설정함.
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// 애니메이션 인스턴스 정보를 변수로 가져오기. ※애니메이션 인스턴스는 클래스이다 => FClassFinder, 마지막에 _C를 적어줘야함.
	static ConstructorHelpers::FClassFinder<UAnimInstance> Greyston_Anim(TEXT(
		"/Game/ParagonGreystone/Characters/Heroes/Greystone/Greystone_AnimBlueprint.Greystone_AnimBlueprint_C"));

	// 애님인스턴스가 유효하다면,
	if (Greyston_Anim.Succeeded())
	{
		// 현재 캐릭터의 애님인스턴스를 외부 애님인스턴스로 초기화(설정)
		GetMesh()->SetAnimInstanceClass(Greyston_Anim.Class);
	}

	BoomLengthSpeed = 3.0f;
	BoomRotationSpeed = 10.0f;

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
		// SizeSquard() ??
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

// Input 설정 (일종의 Input을 위한 Tick함수)
void ALostDarkCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// BindAction 설정. EInputEvent::IE_Pressed, Released 함수가 있다. 누르고 뗄때.
	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::ViewChange);

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