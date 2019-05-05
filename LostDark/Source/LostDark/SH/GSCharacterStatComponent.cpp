// Fill out your copyright notice in the Description page of Project Settings.

#include "GSCharacterStatComponent.h"
// 게임 인스턴스 헤더 추가
#include "LDGameInstance.h"

// Sets default values for this component's properties
UGSCharacterStatComponent::UGSCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// InitializeComponent 사용함.
	bWantsInitializeComponent = true;

	// 최초 레벨 1로
	Level = 1;
	// ...
}


// Called when the game starts
void UGSCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UGSCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetNewLevel(Level); // Level 1이 들어감.
}


// Called every frame
void UGSCharacterStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGSCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	// 현재 프로젝트 설정에 넣어진 게임 인스턴스를 변수로 초기화.
	auto LDGameInstance = Cast<ULDGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	// 혹시 설정된 게임인스터스가 없다면 (None) 예외처리
	ABCHECK(nullptr != LDGameInstance);
	// Level에 해당하는 테이블 데이터 전부 구조체 변수로 가져옴.
	CurrentStatData = LDGameInstance->GetGSCharacterData(NewLevel);
	if (nullptr != CurrentStatData)
	{
		// 레벨 변경
		Level = NewLevel;
		// 현재 HP, 다음 레벨에 해당하는 HP로 변경
		CurrentHP = CurrentStatData->MaxHP;
	}
	// 해당 Level이 없을때, 예를들어 1000 Level 데이터를 참조하려고 할때.
	else
	{
		//ABLOG(Error, TEXT(("Level (%d) data doesn't exist"), NewLevel);
	}
}

// 데미지 상호작용 및 브로드캐스트(델리게이트)
void UGSCharacterStatComponent::SetDamage(float NewDamage)
{
	// 현재 캐릭터 데이터 테이블을 가지고 있지 않다면 예외처리
	ABCHECK(nullptr != CurrentStatData);
	// 현재 HP는 데미지 가감에 결과, 최소 0~최대 HP 사이값을 가져야함.
	CurrentHP = FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP);
	if (CurrentHP <= 0.0f)
	{
		// HP가 0이하로 떨어지면 브로드캐스트
		OnHPIsZero.Broadcast();
	}
}

// 공격력 반환 함수
float UGSCharacterStatComponent::GetAttack()
{
	// 참조하고 있는 스탯 데이터 테이블 정보가 없다면 예외처리
	ABCHECK(CurrentStatData != nullptr, 0.0f);
	// 스탯 데이터 테이블 정보에 있는 Attack값을 반환
	return CurrentStatData->Attack;
}
