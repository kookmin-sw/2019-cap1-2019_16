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

// PostInitializeComponent보다 먼저 불리어지는 함수. (※생성자보다는 당연히 느림.)
void UGSCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetNewLevel(Level); // Level 1이 들어감 (생성자에서 초기화)
}


// Called every frame
void UGSCharacterStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// 게임이 최초에 시작됐을때(InitializeComponent) or 새로운 레벨을 설정할때
void UGSCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	// 현재 프로젝트 설정에 넣어진 게임 인스턴스를 변수로 가져와 할당. (스탯정보가 담긴 클래스)
	auto LDGameInstance = Cast<ULDGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	// 혹시 월드에 설정된 게임인스터스가 없다면 (None) 예외처리
	ABCHECK(nullptr != LDGameInstance);

	// NewLevel에 해당하는 테이블 행(Row) 데이터 전부 구조체 변수로 가져옴. (실제 스탯 정보는 구조체에 있음)
	CurrentStatData = LDGameInstance->GetGSCharacterData(NewLevel);
	ABLOG(Warning, TEXT("Game Start! CurrentStatData initialize~~~ by GSCharacterStatComponent.cpp")); ///디버깅용 코드
	if (nullptr != CurrentStatData)
	{
		// 레벨 변경
		Level = NewLevel; /// 최초에는 Level = Level이 됨.
		// 현재 HP를 최대 HP값으로 설정
		SetHP(CurrentStatData->MaxHP);
		// 현재 HP, 다음 레벨에 해당하는 HP로 변경
		// CurrentHP = CurrentStatData->MaxHP;
	}
	// 해당 Level이 없을때, 예를들어 1000 Level 데이터를 참조하려고 할때.
	else
	{
		ABLOG(Error, TEXT("Level (%d) data doesn't exist"), NewLevel);
	}
}

// 데미지 상호작용 및 브로드캐스트(델리게이트) (TakeDamage처리할때 호출함)
void UGSCharacterStatComponent::SetDamage(float NewDamage)
{
	// 현재 캐릭터 데이터 테이블을 가지고 있지 않다면 예외처리
	ABCHECK(nullptr != CurrentStatData);
	// 현재 HP는 데미지 가감에 결과, 최소 0~최대 HP 사이값을 가져야함.
	SetHP(FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP));
	
	//// 현재 HP는 데미지 가감에 결과, 최소 0~최대 HP 사이값을 가져야함.
	//CurrentHP = FMath::Clamp<float>(CurrentHP - NewDamage, 0.0f, CurrentStatData->MaxHP);
	//if (CurrentHP <= 0.0f)
	//{
	//	// HP가 0이하로 떨어지면 브로드캐스트
	//	OnHPIsZero.Broadcast();
	//}
}

// HP를 설정해줌
void UGSCharacterStatComponent::SetHP(float NewHP)
{
	// 현재 HP를 새롭게 설정
	CurrentHP = NewHP;
	// HP가 변한것을 브로드 캐스트
	OnHPChanged.Broadcast(); /// GSCharacterWidget.cpp에 Lambda 함수로 구현되어 있음. /// 처음 브로드 캐스트는 아무 효과없음. 받으려고 등록된 함수가 없기때문.
	// KINAD_SMALL_NUMBER : 무시 가능한 오차를 측정하도록 사용하는 float의 0값에 가까운 숫자.
	if (CurrentHP < KINDA_SMALL_NUMBER)
	{
		// 현재 HP를 0으로 재설정
		CurrentHP = 0.0f;
		// HP가 0이하로 떨어지면 브로드캐스트 (사망상태로)
		OnHPIsZero.Broadcast(); /// LostDarkCharacter에 Lambda 함수로 구현되어있음.
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

// HP비율을 반환해주는 함수
float UGSCharacterStatComponent::GetHPRatio()
{
	// 현재 스탯 테이블 정보가 없다면
	ABCHECK(nullptr != CurrentStatData, 0.0f);

	// 0에 가까운 숫자면 0을 반환하고, 그게 아니면 현재 HP를 전체 HP
	return ((CurrentStatData->MaxHP < KINDA_SMALL_NUMBER) ? 0.0f : (CurrentHP / CurrentStatData->MaxHP));
}