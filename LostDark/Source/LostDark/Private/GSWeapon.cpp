// Fill out your copyright notice in the Description page of Project Settings.

#include "GSWeapon.h"

// Sets default values
AGSWeapon::AGSWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// 스켈레탈 메시 컴포넌트 생성
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WEAPON"));
	// 루트 컴포넌트 설정
	RootComponent = Weapon;
	// 무기 애셋 정보를 찾아서 등록
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_WEAPON(TEXT(
		"/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Blade_BlackKnight.SK_Blade_BlackKnight"));
	// 만약 해당 무기 애셋 정보를 잘 가져왔다면
	if (SK_WEAPON.Succeeded())
	{
		// 컴포넌트에 애셋을 구현
		Weapon->SetSkeletalMesh(SK_WEAPON.Object);
	}
	// 스켈레탈 메시 컴포넌트의 충돌 설정을 NoCollision으로 설정
	Weapon->SetCollisionProfileName(TEXT("NoCollision"));
	
	AttackRange = 150.0f;
	// 데미지 최소 -2.5
	AttackDamageMin = -2.5f;
	// 데미지 최대
	AttackDamageMax = 10.0f;
	AttackModifierMin = 0.85f;
	AttackModifierMax = 1.25f;
}

float AGSWeapon::GetAttackRange() const
{
	return AttackRange;
}

float AGSWeapon::GetAttackDamage() const
{
	return AttackDamage;
}

float AGSWeapon::GetAttackModifier() const
{
	return AttackModifier;
}

// Called when the game starts or when spawned
void AGSWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	// 무기 최초 생성시 공격 데미지 랜덤
	AttackDamage = FMath::RandRange(AttackDamageMin, AttackDamageMax);
	// 무기 최초 생성시 공격력 보정치 랜덤
	AttackModifier = FMath::RandRange(AttackModifierMin, AttackModifierMax);
	ABLOG(Warning, TEXT("Weapon Damage : %f, Modifier : %f"), AttackDamage, AttackModifier);
}

// Called every frame
void AGSWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

