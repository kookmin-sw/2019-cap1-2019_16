// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LostDarkCharacter.h"
//#include "LostDarkPlayerController.h"
#include "GSAnimInstance.h"
#include "GSWeapon.h"
// ���� ����
#include "GSCharacterStatComponent.h"
#include "DrawDebugHelpers.h"
// UI ���� ����ϱ� ���� �ݵ�� �ʿ��� UMG �𸮾� ���� ���
#include "Components/WidgetComponent.h"
// �츮�� ���� ������ ������ �� Ŭ����
#include "GSCharacterWidget.h"
// AI ��Ʈ�ѷ��� ����
#include "LDAIController.h"
// �ٸ� ��� ���
#include "LDCharacterSetting.h"
// ���� �ν��Ͻ� ���
#include "LDGameInstance.h"
// ĳ���� ��Ʈ�ѷ� ���
#include "LostDarkPlayerController.h"
// ĳ���� ������Ʈ ����
#include "LDPlayerState.h"
#include "LDHUDWidget.h"
#include "LDGameState.h"
#include "LostDarkGameMode.h"

/// ������ Sets Default values
ALostDarkCharacter::ALostDarkCharacter()
{
	// tick �Լ� Ȱ��ȭ
	PrimaryActorTick.bCanEverTick = true;

	// Boom(=SpingArm) �ʱ�ȭ (�⺻����) ������Ʈ ����
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// Camera �ʱ�ȭ (�⺻����) ������Ʈ ����
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// ĳ���� ���ݿ� ���� ������Ʈ ����
	CharacterStat = CreateDefaultSubobject<UGSCharacterStatComponent>(TEXT("CHARACTERSTAT"));
	// UI ���� ������Ʈ ����
	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));


	// Boom ĸ���� ���̱�(���)
	CameraBoom->SetupAttachment(GetCapsuleComponent());
	// Camera�� Boom�� ���̱�(���)
	FollowCamera->SetupAttachment(CameraBoom);
	// �޽ÿ� ���� ������Ʈ�� �����Ѵ�.
	HPBarWidget->SetupAttachment(GetMesh());

	// ���� ���ͺ�� �ʱ�ȭ (ī�޶�, SpringArm ����)
	SetControlMode(EControlMode::BackView);

	// �ܺ� �޽� �ʱ� ��ġ��, ���� �𸮾� ��ǥ�迡 �°� �缳�� (���� 88��ŭ ������, ȸ�� ������ 90�� ȸ��)
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	// �ܺ� �޽� ������ ������ ��������. �ؿܺθ޽ô� ������Ʈ�̴� => FObjectFinder
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Greystone(TEXT(
		"/Game/ParagonGreystone/Characters/Heroes/Greystone/Meshes/Greystone.Greystone"));

	// �޽ð� ��ȿ�ϴٸ�,
	if (Greystone.Succeeded())
	{
		// ���� ĳ���Ϳ� �޽� �ʱ�ȭ(����). �޽ô� ������Ʈ�̹Ƿ� Object�� ������ �ѱ�.
		GetMesh()->SetSkeletalMesh(Greystone.Object);
	}

	// �ִϸ��̼��� �ִϸ��̼� �������Ʈ�� ó���ϱ� ���� �ִϸ��̼� ��� �ɼ� �缳��. �ؾִϸ��̼��� Mesh�� ���� �����ϱ� ������ GetMesh()���� ������.
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	// �ִϸ��̼� �ν��Ͻ� ������ ������ ��������. �ؾִϸ��̼� �ν��Ͻ��� Ŭ�����̴� => FClassFinder, �������� _C�� ���������.
	static ConstructorHelpers::FClassFinder<UAnimInstance> Greyston_Anim(TEXT(
		"/Game/SH/Animations/GS_AnimBlueprint.GS_AnimBlueprint_C"));

	// �ִ��ν��Ͻ��� ��ȿ�ϴٸ�,
	if (Greyston_Anim.Succeeded())
	{
		// ���� ĳ������ �ִ��ν��Ͻ��� �ܺ� �ִ��ν��Ͻ��� �ʱ�ȭ(����)
		GetMesh()->SetAnimInstanceClass(Greyston_Anim.Class);
	}

	// ���� ���濡�� ī�޶� ����� ����Ǵ� �ӵ� ����
	BoomLengthSpeed = 3.0f;
	BoomRotationSpeed = 10.0f;

	// �����ӵ� ����. Z�� �ӵ� ����. 
	GetCharacterMovement()->JumpZVelocity = 450.0f;

	// �ʱ� ���ݻ��´� false
	IsAttacking = false;

	// �ִ� �޺� ī��Ʈ ��
	MaxCombo = 3;
	// �����Ҷ� ���� ȣ���ϰ� ������.
	AttackEndComboState();

	// ĸ��������Ʈ�� �츮�� ���� �ݸ���ä�� ����. GSCharacter��� �ݸ���ä����
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("GSCharacter"));

	// ����� ĸ�� ���� 200cm
	AttackRange = 200.0f;
	// ����� ĸ�� ������ 50cm
	AttackRadius = 50.0f;

	// �⺻ ���ݹ���
	AttackRange = 140.0f;

	///* ������ ���� �ּ� ĳ���� �޽ÿ� ����  */
	//FName WeaponSocket(TEXT("sword_bottom")); //�̸��� ���� bone�� �̸��� ��ġ�ؾ���.
	//// �ش� �޽ÿ� ������ �����Ѵٸ�
	//if (GetMesh()->DoesSocketExist(WeaponSocket))
	//{
	//	// ���̷�Ż �޽� ������Ʈ�� �����ϰ�
	//	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	//	// �ּ� ������ ������ �ް�
	//	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT(
	//		"/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight"));
	//	// �ּ� ������ ������ �޾ƿԴٸ�
	//	if (SK_WEAPON.Succeeded())
	//	{
	//		// ���̷�Ż �޽� ������Ʈ�� �ش� �ּ� ������ �Ѱ��� (���� ����)
	//		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	//	}
	//	// ���θ��� ������Ʈ�� �ڽ��� �޽ÿ� ������ ��ġ�� ��ӽ�Ŵ. ���� ��ġ�� �������� Ʈ�������� �ڵ����� ������. (��ġ����)
	//	Weapon->SetupAttachment(GetMesh(), WeaponSocket);
	//}

	/* HPBarWidget�� ���� ���� */
	// ���� ��ġ Z������ 180cm
	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 202.0f));
	// UI ������ �׻� �÷��̾ ���� ������ Screen ���� ����.
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	// �ܺ� �ּ� ���� ������. ������ Class�����̹Ƿ� �ݵ�� _C�� �ٿ��ش�. (�ڽǼ�����)
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/SH/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded())
	{
		// �ܺ� ���� Ŭ���� ������ ��� (�츮�� ���� ���� ���) => ������ ȭ�鿡 �׸��� �Լ��̱⵵ ��.
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		// ������ ũ�⸦ �������ִ� �Լ�. (����=150cm , ����=50cm)
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}

	// Pawn.h�� �̸� �����Ǵ� �������. AI Ŭ���� �Ӽ��� ����ϴ� �����ε�, �츮�� ���� AIController�� �����.
	AIControllerClass = ALDAIController::StaticClass();
	// �ڵ� AI ���踦 �޴´�. ������ ������ ��ġ�ϰų� �����Ҷ�. �̰Ϳ� �ش��ϴ� ��� ĳ����(LostDarkCharacter�� ���� ĳ����)
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;


	//// Config ���Ͽ� �ִ� ������ LDCharacterSetting ������ �����´�.
	//auto DefaultSetting = GetDefault<ULDCharacterSetting>();

	//// ������ 0���� ũ�ٸ�
	//if (DefaultSetting->CharacterAssets.Num() > 0)
	//{
	//	// �ϳ��� �о���δ�.
	//	for (auto CharacterAsset : DefaultSetting->CharacterAssets)
	//	{
	//		// �̰Ŵ� ���� ���� ���������� �ΰ� �ߴ°���. �� ���Ŀ� �� ���ӿ����� ���̻� ������ ����.
	//		ABLOG(Warning, TEXT("Character Asset : %s"), *CharacterAsset.ToString());
	//	}
	//}

	//
	AssetIndex = 4;
	// ���� ����
	SetActorHiddenInGame(true);
	// ����
	HPBarWidget->SetHiddenInGame(true);
	// ������ �ȹ��� Actor�� �̹� �����������.
	bCanBeDamaged = false;

	// DeadTimer
	DeadTimer = 5.0f;
}

void ALostDarkCharacter::BeginPlay()
{
	Super::BeginPlay();
	/// ĳ���Ͱ� �������ڸ��� �տ� ���⸦ ������ �Ǵ� �Լ�
	//FName WeaponSocket(TEXT("sword_bottom")); //�̸��� ���� bone�� �̸��� ��ġ�ؾ���.
	//// ���� ���͸� ���忡 ������Ŵ.
	//auto CurrentWeapon = GetWorld()->SpawnActor<AGSWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);
	//// ���� ���Ͱ� �����ƴٸ�
	//if (nullptr != CurrentWeapon)
	//{
	//	// ������ ������͸� �ڽ��� �޽ÿ� FAttachmentTransformRules::SnapToTargetNotIncludingScale??? �� �ϰ�, WeaponSocket�� ��ġ�� bone�� �����Ѵ�.
	//	/// ���� �����ϴ� �����̶�� �� �� ����.
	//	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
	//}

	// �÷��̾� ��Ʈ�ѷ���� true
	bIsPlayer = IsPlayerControlled();

	if (bIsPlayer)
	{
		LDPlayerController = Cast<ALostDarkPlayerController>(GetController());
		ABCHECK(nullptr != LDPlayerController);
	}
	else
	{
		LDAIController = Cast<ALDAIController>(GetController());
		ABCHECK(nullptr != LDAIController);
	}

	// Config ���Ͽ� �ִ� ������ LDCharacterSetting ������ �����´�.
	auto DefaultSetting = GetDefault<ULDCharacterSetting>();

	// �÷��̾� ��Ʈ�ѷ����
	if (bIsPlayer)
	{
		// �÷��̾� ������Ʈ�� ������
		auto LDPlayerState = Cast<ALDPlayerState>(GetPlayerState());
		ABCHECK(nullptr != LDPlayerState);
		AssetIndex = LDPlayerState->GetCharacterIndex();
	}
	else
	{
		// ĳ���� �ּ� ������ �����ͼ�, ��������. �ּҴ� 0, �ִ�� ����-1 ����
		AssetIndex = FMath::RandRange(0, DefaultSetting->CharacterAssets.Num() - 2);
	}

	// �ּ� ������ ������
	CharacterAssetToLoad = DefaultSetting->CharacterAssets[AssetIndex];
	// ��GetGameInstance : ���� ��ϵ� �����ν��Ͻ� ������ ������.
	auto LDGameInstance = Cast<ULDGameInstance>(GetGameInstance());
	ABCHECK(nullptr != LDGameInstance);
	// ���� �ν��Ͻ��� �ִ� StreamableManager�� �̿��ؼ� �񵿱��û �Լ��� ��û.
	AssetStreamingHandle = LDGameInstance->StreamableManager.RequestAsyncLoad(
		CharacterAssetToLoad, FStreamableDelegate::CreateUObject(this, &ALostDarkCharacter::OnAssetLoadCompleted));
	/// CreateUObject : �Ｎ���� ��������Ʈ�� �����ؼ� ������Ŵ.
	// �ε����� ������Ʈ ����
	SetCharacterState(ECharacterState::LOADING);


	/* �ڡڡ� Changed in 4.21. copied from PostInitializeComponents() �Ф�  */
	// ������ ������ �θ� UserWidget ������ �Ѱ���. 
	auto CharacterWidget = Cast<UGSCharacterWidget>(HPBarWidget->GetUserWidgetObject());
	/// ���� �ӽ÷� �߰��Ѱ�. ���⼭ ������. (�̰� ����� �޾ƿ��� ���ϰ� ����)
	ABCHECK(nullptr != CharacterWidget);

	if (nullptr != CharacterWidget)
	{
		// ĳ������ PostInitializeComponents �Լ����� ĳ���� ������Ʈ�� UI ������ �����ϴ� �Լ�.
		CharacterWidget->BindCharacterStat(CharacterStat);
	}
}

void ALostDarkCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ������ ����
	/*if (IsDodge)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), GetActorForwardVector()*DodgeSpeed, DeltaTime, 2));
	}*/

	// ���� �����Ҷ� ī�޶� �ڸ���� �Լ�. InterpTo�� �̿� (������ : Interpolation)
	CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength, BoomLengthTo, DeltaTime, BoomLengthSpeed);

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		// ī�޶� �̵�
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
		// SizeSquard() ���߿� ã�ƺ���
		if (DirectionToMove.SizeSquared() > 0.0f)
		{
			// ĳ���� ��Ʈ�ѷ��� ȸ���� ����. X�� ������ ȸ������� ���ϰ�, �װͿ� ��ġ�ϴ� FRotator(Rotator)���� ����.
			GetController()->SetControlRotation(FRotationMatrix::MakeFromX(DirectionToMove).Rotator());
			AddMovementInput(DirectionToMove);
		}
		break;
	default:
		break;
	}
}

// ��� ������Ʈ�� �ʱ�ȭ�Ǹ� �Ҹ������� �Լ�. ������ BeginPlay�Լ��ε�. ���̰� �ִµ� ����.
void ALostDarkCharacter::PostInitializeComponents()
{
	// �θ�� ȣ��
	Super::PostInitializeComponents();
	/* UE_LOG(LogTemp, Warning, TEXT("PostInitializeComponents Start !!! to LostDarkCharacter.cpp")); */
	// GS �ִ��ν��Ͻ� ���� ��������
	GSAnim = Cast<UGSAnimInstance>(GetMesh()->GetAnimInstance());
	// GS �ִ��ν��Ͻ��� �������� ���ߴٸ� ����ó���� �Լ���ȯ
	ABCHECK(nullptr != GSAnim);
	// ��Ÿ�� ����� ������, �ڵ����� OnAttackMontageEnded ��� �Լ��� ȣ���ϴ°���. AnimInstance->OnMontageEnded�� �̹� ������.
	GSAnim->OnMontageEnded.AddDynamic(this, &ALostDarkCharacter::OnAttackMontageEnded);

	GSAnim->OnMontageEnded.AddDynamic(this, &ALostDarkCharacter::OnDodgeMontageEnded);

	// ��Ƽ���� ��ȣ�� ������ �Ϸ� ����. void�� ��ȯ
	GSAnim->OnNextAttackCheck.AddLambda([this]() -> void {
		// OnNextAttackCheck ��ε�ĳ��Ʈ�� �ߵ����� Log�� ����.
		//UE_LOG(LogTemp, Warning, TEXT("OnNextAttackCheck Lambda Called"));
		ABLOG(Warning, TEXT("OnNextAttackCheck"));
		// ���� �޺��� ������ �ϰ�
		CanNextCombo = false;
		// �޺� �Է��� ���Դٸ� // NextAttackCheck ��Ƽ���� ��ε�ĳ��Ʈ �������� ������ 2���̻� ���ȴٸ�
		if (IsComboInputOn)
		{
			// �޺� ���� �Լ� ȣ�� (�޺� ī��Ʈ ����)
			AttackStartComboState();
			// ���� ���� �޺��� �ҷ���
			GSAnim->JumpToAttackMontageSection(CurrentCombo);
			UE_LOG(LogTemp, Warning, TEXT("Called JumpTo Function, Combo : %d"), CurrentCombo);
		}
	});
	// OnAttackHitCheck ��Ƽ���̿��� ��ε�ĳ��Ʈ�� ������, 2��° ���ڿ� �ش��ϴ� �Լ��� ȣ����(=AttackCheck)
	GSAnim->OnAttackHitCheck.AddUObject(this, &ALostDarkCharacter::AttackCheck);

	// GSCharacterStatComponent�� OnHPIsZero ��������Ʈ�� ��ε�ĳ��Ʈ �ϸ� ȣ��Ǵ� �����Լ�. HP�� 0���Ϸ� �������� ȣ����.
	CharacterStat->OnHPIsZero.AddLambda([this]()->void {
		ABLOG(Warning, TEXT("@@ HP Is Zero"));
		// �״� �ִϸ��̼� �۵�
		GSAnim->SetDeadAnim();
		// ���� ������ �ݸ����� ��.
		SetActorEnableCollision(false);
	});

	//// ������ ������ �θ� UserWidget ������ �Ѱ���. /// ���⼭ �ڲ� nulló����. => 4.20 �������� �ٲ� ������ Beginplay���� ȣ���ؾ߸���.
	//auto CharacterWidget = Cast<UGSCharacterWidget>(HPBarWidget->GetUserWidgetObject());
	///// ���� �ӽ÷� �߰��Ѱ�. ���⼭ ������. (�̰� ����� �޾ƿ��� ���ϰ� ����)
	//ABCHECK(nullptr != CharacterWidget);

	//if (nullptr != CharacterWidget)
	//{
	//	ABLOG(Warning, TEXT("Success!!!!!!!!!!!!!!!!!! :("));
	//	// ĳ������ PostInitializeComponents �Լ����� ĳ���� ������Ʈ�� UI ������ �����ϴ� �Լ�.
	//	CharacterWidget->BindCharacterStat(CharacterStat);
	//}
}

// ������ �޴� ������ �����ϴ� �Լ�. AActor�� �ִ� ������ �߰� ������.
float ALostDarkCharacter::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	// �θ������ ���� ������ �����ӿ�ũ�� ������ ������� ����. (������� ���������� ���� ������ ũ��)
	float FinalDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	// �������� �޾Ƽ� ������ �����ӿ�ũ�� �ߵ��� ���� �̸���, ��������� ���� �� ������ ũ�⸦ LOG�� �����.
	ABLOG(Warning, TEXT("Actor : %s took Damage : %f"), *GetName(), FinalDamage);

	/*
	// ���� �������� 0���� ũ�ٸ�
	if (FinalDamage > 0.0f)
	{
		// ���� �ڽ��� ���¸� Dead�� �ٲ۴�.
		GSAnim->SetDeadAnim();
		// ���� �ڽ��� ���� �ݸ����� ����.
		SetActorEnableCollision(false);
	}
	*/

	// ĳ���ͽ��� (���� ������Ʈ)�� �ִ� SetDamage�� ȣ����. ������ ���� �����͸� �������� �Ѱ���. ����� �ű⼭ ��ȣ�ۿ� ������ �ݴ�� ��ȯ��.
	// ������ ������ ���� ĳ���� ���ݿ� ����
	CharacterStat->SetDamage(FinalDamage);

	// ���� ���°� DEAD���
	if (CurrentState == ECharacterState::DEAD)
	{
		// �����ڰ� �÷��̾���
		if (EventInstigator->IsPlayerController())
		{
			ABLOG(Warning, TEXT("Actor : %s"), *EventInstigator->GetName());
			//�÷��̾� ������ ��������
			auto LDPlayerController = Cast<ALostDarkPlayerController>(EventInstigator);
			ABCHECK(nullptr != LDPlayerController, 0.0f);
			// Kill �Լ� ȣ��
			LDPlayerController->AIKill(this);
		}
	}
	// ���������� ���� �������� ��ȯ�Ѵ�
	return FinalDamage;
}

// ���� �����ϴ� ���� ȣ��Ǵ� �Լ�. ���� �������� ȣ��ɵ�?
void ALostDarkCharacter::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);
	// �÷��̾� ��Ʈ�ѷ��� �ִٸ�
	if (IsPlayerControlled())
	{
		// ��� (�÷��̾� ����)
		SetControlMode(EControlMode::BackView);
		// �ȴ� �ӵ� ����
		GetCharacterMovement()->MaxWalkSpeed = 800.0f;
	}
	// �÷��̾ �ƴ� AI���
	else
	{
		// NPC �������� ����
		SetControlMode(EControlMode::NPC);
		// �ִ� �̵��ӵ� ����
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	}

}

// ���� ���⸦ �����ϰ� �ִ��� Ȯ���ϴ� �Լ�
bool ALostDarkCharacter::CanSetWeapon()
{
	// ������ true, ���Ⱑ �ִٸ� false
	//return (nullptr == CurrentWeapon);

	//�׻� ��ü�Ҽ� ����
	return true;
}

// ���� �����Լ�
void ALostDarkCharacter::SetWeapon(AGSWeapon * NewWeapon)
{
	/*
	// (���� ������ �ְ�, ���ÿ� ���� ���Ⱑ ���ٸ�) ���. �ƴϸ� ��� �α׷� ��� return.
	ABCHECK(nullptr != NewWeapon && nullptr == CurrentWeapon);
	// ���̷�Ż �޽��� Bone�� �̸��� ����ȭ��Ŵ. �̸��� ���� bone�� �̸��� ��ġ�ؾ���.
	FName WeaponSocket(TEXT("sword_bottom"));
	// ���� Ŭ������ ���� �ʴٸ�,
	if (nullptr != NewWeapon)
	{
		// NewWeapon ���⿡ �ش��ϴ°� �ڽ��� �޽�(GetMesh)�� FAttachmentTransformRules::SnapToTargetNotIncludingScale??? �� �ϰ�, WeaponSocket�� ��ġ�� bone�� �����Ѵ�.
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
		// ������ �����ڸ� ����
		NewWeapon->SetOwner(this);
		// ���� ���� ���⸦ ���
		CurrentWeapon = NewWeapon;
	}
	*/

	// ���� ���� ���� ȣ������� ����ó��
	ABCHECK(nullptr != NewWeapon);
	// �̹� ���Ⱑ �ִٸ�
	if (nullptr != CurrentWeapon)
	{
		// ??
		CurrentWeapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		// ���� ���� �ı�
		CurrentWeapon->Destroy();
		// ���� ���� ������Ʈ
		CurrentWeapon = nullptr;
	}

	// GreySton�� �����̸��� Ȯ���ϰ� ���� ������.
	FName WeaponSocket(TEXT("sword_bottom"));
	// ���� Ŭ������ ���� �ʴٸ�,
	if (nullptr != NewWeapon)
	{
		// NewWeapon ���⿡ �ش��ϴ°� �ڽ��� �޽�(GetMesh)�� FAttachmentTransformRules::SnapToTargetNotIncludingScale??? �� �ϰ�, WeaponSocket�� ��ġ�� bone�� �����Ѵ�.
		NewWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, WeaponSocket);
		// ������ �����ڸ� ����
		NewWeapon->SetOwner(this);
		// ���� ���� ���⸦ ���
		CurrentWeapon = NewWeapon;
	}
}

// Input ���� (������ Input�� ���� Tick�Լ�)
void ALostDarkCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// BindAction ����. EInputEvent::IE_Pressed, Released �Լ��� �ִ�. ������ ����.
	PlayerInputComponent->BindAction(TEXT("ViewChange"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::ViewChange);

	// Jump ����. Jump�� �⺻������ Character Ŭ������ �̹� ����Ǿ� �־, �θ��� �Լ��� ���ε� ��Ű�� ��.
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::Jump);

	// Attack, Mouse X ���ε��ϱ�.
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::Attack);

	// Dodge, ���� Shift.
	PlayerInputComponent->BindAction(TEXT("Dodge"), EInputEvent::IE_Pressed, this, &ALostDarkCharacter::Dodge);

	/*
		BindAxis(1, 2, 3)
		1 : ������Ʈ ���� Input�� �ִ� BindAxis ���� �̸��� TEXT ���·� �־��ش�.
		2 : ����Ϸ��� Ŭ���� ������ �Ѱ��ش�. �ش� Ŭ�������� ����ϴϱ� this.
		3 : Input�� �������� ȣ���� �Լ��� �ּҸ� �Ѱ��ش�. (�Լ��� �ּҴ� �Լ� �̸�)
		��� : Input�� �ɶ����� 3��° ���ڷ� ���� �Լ��� �ڵ� ȣ����.
	*/
	// Input ������ �ִ� MoveForward ���ε��ϱ�.
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ALostDarkCharacter::MoveForward);
	// Input ������ �ִ� MoveRight ���ε��ϱ�.
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ALostDarkCharacter::MoveRight);

	/// ���� ���ǰͰ� �Ȱ��� ���·� ¥���ϴµ�, ������ �Լ��� �״�� ����غ�.
	// �θ� Pawn Ŭ������ �ִ� AddControllerYawInput �Լ��� ȣ����
	//PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	////// �θ� Pawn Ŭ������ �ִ� AddControllerPitchInput �Լ��� ȣ����
	//PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

}

// ĳ���� ���� ���� ����
void ALostDarkCharacter::SetCharacterState(ECharacterState NewState)
{
	// ���� ���� ������Ʈ�� �����̶�� ����ó��
	ABCHECK(CurrentState != NewState);
	CurrentState = NewState;
	switch (CurrentState)
	{
		/*case ECharacterState::PREINIT:
			break;*/
	case ECharacterState::LOADING:
	{
		// �÷��̾� ��Ʈ�ѷ����
		if (bIsPlayer)
		{
			// Ű�Է��� ���޵�����.
			DisableInput(LDPlayerController);

			// �÷��̾� ��Ʈ�ѷ����� ������ ��� ĳ���� ������ ���ε���Ŵ.
			LDPlayerController->GetHUDWidget()->BindCharacterStat(CharacterStat);

			// �÷��̾� ������Ʈ ������ ������
			auto LDPlayerState = Cast<ALDPlayerState>(GetPlayerState());
			ABCHECK(nullptr != LDPlayerState);
			// ĳ���� ���� ������ ���� ĳ���� ���� ������ �缳��
			CharacterStat->SetNewLevel(LDPlayerState->GetCharacterLevel());
		}
		// AI���
		else
		{
			// ���� ������ ���� ��带 ������
			auto LDGameMode = Cast<ALostDarkGameMode>(GetWorld()->GetAuthGameMode());
			ABCHECK(LDGameMode != nullptr);
			// ������ �̿��ؼ� Ÿ�� ������ ����. ���� ���ھ� * 0.8 ����
			int32 TargetLevel = FMath::CeilToInt(((float)LDGameMode->GetScore()*0.8f));
			// 1���� 20���� ���ӵ����Ϳ� ���� 1���� 20���� �����Ͱ� �� ����
			int32 FinalLevel = FMath::Clamp<int32>(TargetLevel, 1, 20);
			ABLOG(Warning, TEXT("New AI Level : %d"), FinalLevel);
			// ĳ���� ���ݿ��� AI�� ���������� �ٽ� ������
			CharacterStat->SetNewLevel(FinalLevel);
		}
		SetActorHiddenInGame(true);
		HPBarWidget->SetHiddenInGame(true);
		bCanBeDamaged = false;
		break;
	}
	case ECharacterState::READY:
	{
		SetActorHiddenInGame(false);
		HPBarWidget->SetHiddenInGame(false);
		bCanBeDamaged = true;
		// HP�� 0���Ϸ� �������� ������Ʈ ����
		CharacterStat->OnHPIsZero.AddLambda([this]()->void {
			SetCharacterState(ECharacterState::DEAD);
		});
		// ���� ĳ���Ϳ� ����
		auto CharacterWidget = Cast<UGSCharacterWidget>(HPBarWidget->GetUserWidgetObject());
		ABCHECK(nullptr != CharacterWidget);
		CharacterWidget->BindCharacterStat(CharacterStat);

		// �÷��̾���
		if (bIsPlayer)
		{
			SetControlMode(EControlMode::BackView);
			GetCharacterMovement()->MaxWalkSpeed = 600.0f;
			// Ű�Է� �޵��� ��.
			EnableInput(LDPlayerController);
		}
		// AI���
		else
		{
			SetControlMode(EControlMode::NPC);
			GetCharacterMovement()->MaxWalkSpeed = 300.0f;
			LDAIController->RunAI();
		}
		break;
	}

	case ECharacterState::DEAD:
	{
		// �ݸ��� ����
		SetActorEnableCollision(false);
		// �Ⱥ��̰���
		GetMesh()->SetHiddenInGame(false);
		// UI���� �Ⱥ���
		HPBarWidget->SetHiddenInGame(true);
		// �״� �ִϸ��̼�
		GSAnim->SetDeadAnim();
		bCanBeDamaged = false;

		if (bIsPlayer)
		{
			// Ű�Է� ����.
			DisableInput(LDPlayerController);
		}
		else
		{
			// AI �ߴ�
			LDAIController->StopAI();
		}

		// DeadTimer �ð��� �ڵ� ȣ��Ǵ� �Լ�.
		GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda([this]()->void {
			// �÷��̾���
			if (bIsPlayer)
			{
				//// �ٽ� ������
				//LDPlayerController->RestartLevel();
				LDPlayerController->ShowResultUI();
			}
			else
			{
				// AI�� �ı�
				Destroy();
			}
		}), DeadTimer, false);
		break;
	}
	default:
	{
		break;
	}
	}
}

// ĳ���� ���� ���� ��ȯ
ECharacterState ALostDarkCharacter::GetCharacterState() const
{
	// ���� ���� ��ȯ
	return CurrentState;
}

int32 ALostDarkCharacter::GetExp() const
{
	return CharacterStat->GetDropExp();
}

float ALostDarkCharacter::GetFinalAttackRange() const
{
	// ���Ⱑ �ִٸ� ���� ������ ��������, �ƴϸ� �⺻ ������ ���
	return (nullptr != CurrentWeapon) ? CurrentWeapon->GetAttackRange() : AttackRange;
}

float ALostDarkCharacter::GetFinalAttackDamage() const
{
	// ���� ���ݷ���, ���Ⱑ �ִٸ�, �׸��� ���ٸ�
	float AttackDamage = (nullptr != CurrentWeapon) ? (CharacterStat->GetAttack() + CurrentWeapon->GetAttackDamage()) : CharacterStat->GetAttack();
	// ���� ���Ⱑ �ִٸ�, ����ġ ��. ������ 1
	float AttackModifier = (nullptr != CurrentWeapon) ? (CurrentWeapon->GetAttackModifier()) : 1.0f;
	// �������
	return AttackDamage * AttackModifier;
}

// ���콺 ��Ŭ����, Attack ����. ��Ÿ�ָ� ����� ���� �ִϸ��̼��� �����. ���� ���� ������ ���� ������. �̰� ����ϸ� ���ݵ�
void ALostDarkCharacter::Attack()
{
	// ���� ��Ÿ�� ������̶��
	if (IsAttacking)
	{
		// ���� ���� Comboī��Ʈ�� 1~3 ���̰� �ƴ϶�� ��ȯ (����ó��)
		ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 1, MaxCombo));
		// IsInputCombo ��Ƽ���̰� �Ҹ���������
		if (GSAnim->IsInputCombo)
		{
			// �������ε�, ���� �޺��� ���� �ִٸ�,
			if (CanNextCombo)
			{
				// �޺��� �־��ٴ� ��ȣ��.
				IsComboInputOn = true;
				//UE_LOG(LogTemp, Warning, TEXT("Can NextCombo : %d"),CurrentCombo);
			}
		}

	}
	// �������� �ƴ϶��,
	else
	{
		// ���� ���� Combo�� 0�� �ƴϸ� ��ȯ
		ABCHECK(CurrentCombo == 0);
		// �޺� ������Ʈ ȣ��. �޺� ī��Ʈ ���� 1��
		AttackStartComboState();
		// �ִ��ν��Ͻ� ��Ÿ�� �Լ� ȣ��. ���� �ִϸ��̼� ���
		GSAnim->PlayAttackMontage();
		// ���� �������� ���� �޺� ī��Ʈ�� �ѱ�.
		GSAnim->JumpToAttackMontageSection(CurrentCombo);
		// ���� ���� ���� ����
		IsAttacking = true;
	}
	//// �ִ� �ν��Ͻ� ������. Mesh�� �޷��ִ� �ִ��ν��Ͻ��� UGS�� ����ȯ�� ���.
	//auto AnimInstance = Cast<UGSAnimInstance>(GetMesh()->GetAnimInstance());
	//// Ȥ�� �ִ� �ν��Ͻ��� ���� �������� (exception handler)
	//if (nullptr == AnimInstance) return;
	//// �ִ� �ν��Ͻ��� �ִ� ��Ÿ�� �Լ��� �����Ŵ.
	//AnimInstance->PlayAttackMontage();

	//IsAttacking = true;
}

// Dodge
void ALostDarkCharacter::Dodge()
{
	// ���������� �ʰ�, ���������� �������� ����
	if (!IsDodge && !GSAnim->IsJump())
	{
		// dodge ��� ����
		IsDodge = true;
		// ������, ���� ���̸� �������
		if (!IsAttacking && !GSAnim->IsJump())
		{
			// ĳ���� ���� ����.
			GetCharacterMovement()->SetJumpAllowed(false);
			if (bIsPlayer)
			{
				// Ű�Է� ����.
				//DisableInput(LDPlayerController);
			}
			GSAnim->PlayDodgeMontage();
			// �̵�
			// ���� ��ġ = ������ġ + �ڽ��� �չ��� ���� ���� * �̵��Ÿ�
			// ������ġ ~ ������ġ���� ����
			// GetActorLocation
			//DirectionToMove.X = 50.0f;
			//FMath::VInterpTo(GetActorLocation(),GetActorForwardVector()*100.0f,)
			//CameraBoom->TargetArmLength = FMath::FInterpTo(CameraBoom->TargetArmLength, BoomLengthTo, DeltaTime, BoomLengthSpeed);;
		}
	}
}

// ���� ��Ÿ�ְ� ������ ������ �����ϰ�. 
void ALostDarkCharacter::OnDodgeMontageEnded(UAnimMontage * Montage, bool bInterrupted)
{
	// ���� ��밡��.
	GetCharacterMovement()->SetJumpAllowed(true);
	// ���� ��밡��
	IsDodge = false;

	if (bIsPlayer)
	{
		// Ű�Է� ����.
		EnableInput(LDPlayerController);
	}
}

// ��������Ʈ�� ������ �Լ�. ��Ÿ�ְ� ������ ������, �ڵ����� �Ҹ�����.
void ALostDarkCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterruped)
{
	// IsAttacking�� �ƴ϶�� �ٷ� ���� ���� ���� return.
	ABCHECK(IsAttacking);
	// CurrentCombo�� 0���� ũ�� ������ return.
	ABCHECK(CurrentCombo > 0);
	// ������� ��Ÿ�ְ� ������ IsAttacking ������ �ٽ� false�� �ʱ�ȭ.
	IsAttacking = false;
	// ��Ÿ�ְ� ������ ȣ��
	AttackEndComboState();
	// ��Ÿ�� ������ Log ����ֱ�
	UE_LOG(LogTemp, Warning, TEXT("MontageEnded"));

	// AI�� ��� FinishLatentTask �Լ��� ȣ���ϱ� ���� ����.
	OnAttackEnd.Broadcast(); // BTTask_Attack.cpp �� ��������Ʈ ����� �Լ� ����.
}

// ������ �����Ҷ� ���� �Ӽ� �����ϴ� �Լ�. Combo ī��Ʈ�� ������Ŵ
void ALostDarkCharacter::AttackStartComboState()
{
	// ���� �޺��� �Ѿ �� ����.
	CanNextCombo = true;
	// ���� �޺��� ���� ����. (����)
	IsComboInputOn = false;
	// ���� CurrentCombo�� 0~2 ���� �ƴ϶�� ���� ���� ����ϰ� ��ȯ
	ABCHECK(FMath::IsWithinInclusive<int32>(CurrentCombo, 0, MaxCombo - 1));
	/*
		Clamp : �ּ� �ִ밪 ���� �Լ�. (���� �� , �ּ�, �ִ�) �۰ų� �ִ밪���� ũ��, �ش簪�� ������.
		(1,3)�� �ִ���. CurrentCombo�� 3������ ������ �ȵ�. ����� ���ʴ� 0�� ���ͼ� 1�̵�. �׷��� ù��° �޺� �ִϸ��̼� 1�� �����°���
	*/
	/// ���� �޺� ī��Ʈ�� �����ϴ� �ڵ���.
	CurrentCombo = FMath::Clamp<int32>(CurrentCombo + 1, 1, MaxCombo);
}

// ������ ������ �� ����� �Լ�
void ALostDarkCharacter::AttackEndComboState()
{
	// �޺� �Է� ���θ� �ٽ� false�� �ٲ���
	IsComboInputOn = false;
	// ���� �޺��� ���°� ���� (�ִ�)
	CanNextCombo = false;
	// ���� �޺��� �ٽ� 0���� �ʱ�ȭ
	CurrentCombo = 0;
}

// ���� Ŭ���� �浹ó���� �Ǿ����� Ȯ�� // 9�� �浹�̾߱�
void ALostDarkCharacter::AttackCheck()
{
	float FinalAttackRange = GetFinalAttackRange();

	// �浹�� ��ü�� ������ ��� ����ü����
	FHitResult HitResult;
	// Ž�� ����� �ڱ��ڽ��� Ž������ �ʵ��� this�� �־���. ����ü��.
	FCollisionQueryParams Params(NAME_None, false, this);
	// Sweep ������ ��� ����. (������ Ray�߻�)
	bool bResult = GetWorld()->SweepSingleByChannel(
		// �浹�� ��ü�� ��� ����
		HitResult,
		// ���� ��ġ�� ���� ������ ��ġ�� �־���. Vector��
		GetActorLocation(),
		// ���� ��ġ�� ���� ���� �չ������� 2m ��������. Vector��
		GetActorLocation() + GetActorForwardVector() * FinalAttackRange,
		// Ž���� ������ ȸ���� �⺻����
		FQuat::Identity,
		// ���� �浹 ������ ����� Ʈ���̽� ä�� ����
		ECollisionChannel::ECC_GameTraceChannel4,
		// Ž���� ������ ������ ������ ����
		FCollisionShape::MakeSphere(AttackRadius),
		// Ž�� ����� ���� �������� ��Ƶ� ����ü
		Params);

	// ���� ����׸� �׸��� �ִٸ�,
#if ENABLE_DRAW_DEBUG

	// ���� ���̸� ���ͷ� ����ȭ
	FVector TraceVec = GetActorForwardVector() * FinalAttackRange;
	// �߾Ӱ��� ������ġ�� + �չ����� �߰�
	FVector Center = GetActorLocation() + TraceVec * 0.5f;
	// ���ݳ��� = ���ݰ� + ��������. ĸ�����̱� ������ ���� ���� ���̴� ���������� ���������.
	float HalfHeight = FinalAttackRange * 0.5f + AttackRadius;
	// ���ִ� ĸ���� ������ ȸ�����
	FQuat CapsuleRot = FRotationMatrix::MakeFromZ(TraceVec).ToQuat();
	// ����� ĸ���� ����. �浹�ϸ� �ʷϻ�, �ƴϸ� ������
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;
	// ����� ĸ���� �����ð�
	float DebugLifeTime = 5.0f;

	// ����� ĸ��
	DrawDebugCapsule(
		// ���� �׸���
		GetWorld(),
		// �߽ɰ�
		Center,
		// �߽ɱ����� ����
		HalfHeight,
		// ��ü ���� ����
		AttackRadius,
		// ����� ĸ���� ȸ����
		CapsuleRot,
		// ����
		DrawColor,
		// ����
		false,
		// �����ð�
		DebugLifeTime);

#endif
	// ���� �浹�� ��ü�� �ִٸ�,
	if (bResult)
	{
		// �浹�� ������ ��ü�� ��ȿ�� ���̶��
		if (HitResult.Actor.IsValid())
		{
			// �ε��� ��ü�� ������ �̸��� ����Ѵ�.
			ABLOG(Warning, TEXT("Hit Actor Name : %s"), *HitResult.Actor->GetName());
			// �𸮾󿡼� �����ϴ� ������ �����ӿ�ũ ����ü ���� ����. (������ ������ �⺻���ε�)
			FDamageEvent DamageEvent;
			// �浹�� ��ü�� ������ �����ӿ�ũ�� �ߵ���. (������ ������ ����, ������ ����, ���ݸ���� ���� ������(��Ʈ�ѷ�), ������ ������ ���� ����� ����(��))
			HitResult.Actor->TakeDamage(GetFinalAttackDamage(), DamageEvent, GetController(), this);
			/// ĳ���� ���� ���̺� �ִ� ������ �����ؼ� ���ݷ��� �ѱ�GetAttack()
		}
	}
}

// �ּ� �ε��� �Ϸ�Ǹ�
void ALostDarkCharacter::OnAssetLoadCompleted()
{
	// �񵿱� ����
	AssetStreamingHandle->ReleaseHandle();
	// ���� ������, ĳ���� ���� ��ε��
	TSoftObjectPtr<USkeletalMesh> LoadedAssetPath(CharacterAssetToLoad);
	ABCHECK(LoadedAssetPath.IsValid());

	// ���̷�Ż ����
	GetMesh()->SetSkeletalMesh(LoadedAssetPath.Get());
	// ������Ʈ READY�� ����
	SetCharacterState(ECharacterState::READY);
}

// ���� ���� ����
void ALostDarkCharacter::ViewChange()
{
	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		GetController()->SetControlRotation(GetActorRotation());
		// BackView������ QuaterView�� ����
		SetControlMode(EControlMode::QuaterView);
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		GetController()->SetControlRotation(CameraBoom->RelativeRotation);
		// QuaterView������ BackView�� ����
		SetControlMode(EControlMode::BackView);
		break;
	default:
		break;
	}
}

// ���� ��ȯ �Լ�
void ALostDarkCharacter::SetControlMode(EControlMode NewControlMode)
{
	// ���� ���� ���� �缳��.
	CurrentControlMode = NewControlMode;

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		// Boom ���� ����.
		//CameraBoom->TargetArmLength = 450.0f;
		// Boom ȸ������ (0,0,0) = �÷��̾ �ٶ󺸴� X�� ������ (1,0,0)�� �ǹ���.
		//CameraBoom->SetRelativeRotation(FRotator::ZeroRotator);

		// Boom ���� �ʱ�ȭ
		BoomLengthTo = 550.0f;
		/// ������ �߰���
		BoomRotationTo = FRotator::ZeroRotator;

		// SpringArm�� ȸ�������� �÷��̾� ��Ʈ�ѷ� ȸ������ �����. (= ���콺�� ȸ���ϸ� ī�޶� ���� ������ ȸ����)
		CameraBoom->bUsePawnControlRotation = true;
		// �θ� ������Ʈ(�÷��̾�)���� ȸ������(��ġ,��,��) ��ӹ�����
		CameraBoom->bInheritPitch = true;
		CameraBoom->bInheritRoll = true;
		CameraBoom->bInheritYaw = true;
		// ProbeChannel, ProbeSize�� ����Ͽ� �浹üũ, ī�޶� Ŭ������ �Ͼ�°��� �����Ѵ�. (ī�޶�� �÷��̾� ���̿� �ٸ� ��ü�� �����ϸ�, ĳ���ͷ� ������)
		CameraBoom->bDoCollisionTest = true;
		// �¿� ȸ�� ����. true�� ���, Pawn�� Yaw�� �÷��̾� ��Ʈ�ѷ��� Yaw�� ��Ī�ǵ��� ��. (���콺 ȸ��-> �÷��̾� ��Ʈ�ѷ� -> ���� ȸ���� ��������)
		bUseControllerRotationPitch = false; // �߰�
		bUseControllerRotationYaw = false;
		bUseControllerRotationRoll = false; // �߰�
		// ĳ���Ͱ� �����̴� �������� ĳ���͸� �ڵ����� ȸ�������ִ� CharacterMovement �Լ���.
		GetCharacterMovement()->bOrientRotationToMovement = true;
		//
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		// ȸ�� �ӵ� ����. (Y ȸ�� �ӵ�, Z ȸ�� �ӵ�, x ȸ���ӵ�) ������ �𸣰���. => �Լ� ������ �ٸ��Ͱ� �ٸ��� �ؼ� �򰥸�. ����!
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // �� Y���� Yaw���� �𸣰���. FRotator �Լ� �������� ������ �ٸ�.
		break;

	case ALostDarkCharacter::EControlMode::QuaterView:
		// ���� 800
		//CameraBoom->TargetArmLength = 800.0f;
		// �Ʒ��� 45�� ȸ��
		//CameraBoom->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

		// Boom ���� �ʱ�ȭ
		BoomLengthTo = 800.0f;
		// Boom ȸ���� �ʱ�ȭ
		BoomRotationTo = FRotator(-45.0f, 0.0f, 0.0f);
		// SpringArm�� ȸ�������� �÷��̾� ��Ʈ�ѷ� ȸ������ ���
		CameraBoom->bUsePawnControlRotation = false;
		// �θ� ������Ʈ(�÷��̾�)���� ȸ������(��ġ,��,��) ��ӹ�����
		CameraBoom->bInheritPitch = false;
		CameraBoom->bInheritRoll = false;
		CameraBoom->bInheritYaw = false;
		// ProbeChannel, ProbeSize�� ����Ͽ� �浹üũ, ī�޶� Ŭ������ �Ͼ�°��� �������� ����.
		CameraBoom->bDoCollisionTest = false;
		// Pawn�� Yaw�� �÷��̾� ��Ʈ�ѷ��� Yaw�� ��Ī�ǵ��� ��.
		bUseControllerRotationYaw = false;
		// ĳ���Ͱ� �����̴� �������� ĳ���͸� �ڵ����� ȸ�������ִ� �Լ��� ��.
		GetCharacterMovement()->bOrientRotationToMovement = false;
		// ��� �ڿ������� ȸ���ϴ°��� Ŵ.
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		// ȸ�� �ӵ� ����
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

// �յ� �̵� �Լ�
void ALostDarkCharacter::MoveForward(float Value)
{
	// Character Ŭ�������� �����ϴ� �̵� �Լ�. (����, �̵�ũ��)
	//AddMovementInput(GetActorForwardVector(), Value);

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		if (Controller != NULL)
		{
			// ��Ʈ�� ȸ�� �����κ��� ȸ������� �����, ���ϴ� ���� ���� ������ ĳ���Ͱ� �����̴� �������� �̵��ϰ� �Ѵ�.
			const FRotator YawRotation(0, GetControlRotation().Yaw, 0);
			AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value);
		}
		break;
	case ALostDarkCharacter::EControlMode::QuaterView:
		DirectionToMove.X = Value;
		break;
	default:
		break;
	}
}

// �¿� �̵� �Լ�
void ALostDarkCharacter::MoveRight(float Value)
{
	// Character Ŭ�������� �����ϴ� �̵� �Լ�. (����, �̵�ũ��)
	//AddMovementInput(GetActorRightVector(), Value);

	switch (CurrentControlMode)
	{
	case ALostDarkCharacter::EControlMode::BackView:
		// ��Ʈ�� ȸ�� �����κ��� ȸ������� ���� ������ ���ϰ�, ���ϴ� ���� ���� ������ ĳ���Ͱ� �����̴� �������� �̵��ϰ� �Ѵ�.
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