// Fill out your copyright notice in the Description page of Project Settings.

#include "LostDark/SH/Public/SH_ItemBox.h"
#include "LostDark/SH/Public/LostDarkCharacter.h"
#include "LostDark/SH/Public/GSWeapon.h"

// Sets default values
ASH_ItemBox::ASH_ItemBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// 트리거, 박스, 이펙트(파티클) 컴포넌트 생성
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	Box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BOX"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EFFECT"));

	// 루트컴포넌트에 박스 컴포넌트 등록
	RootComponent = Trigger;
	// 루트에 박스, 이펙트 컴포넌트 상속
	Box->SetupAttachment(RootComponent);
	Effect->SetupAttachment(RootComponent);

	// 전체 콜리전 박스 크기의 절반 값을 의미한다. (80 X 82 X 41 이었음) 높이는 좀더 키우려고 저렇게 한거임.
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));

	// Box 애셋 정보 가져오기
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_BOX(TEXT(
		"/Game/InfinityBladeGrassLands/Environments/Breakables/StaticMesh/Box/SM_Env_Breakables_Box1.SM_Env_Breakables_Box1"));
	if (SM_BOX.Succeeded())
	{
		// 박스 컴포넌트에 가져온 애셋 정보를 부착(구현)
		Box->SetStaticMesh(SM_BOX.Object);
	}

	// 외부 파티클 애셋을 가져옴.
	static ConstructorHelpers::FObjectFinder<UParticleSystem> P_CHESTOPEN(TEXT(
		"/Game/InfinityBladeGrassLands/Effects/FX_Treasure/Chest/P_TreasureChest_Open_Mesh.P_TreasureChest_Open_Mesh"));
	if (P_CHESTOPEN.Succeeded())
	{
		// 이펙트 컴포넌트에 애셋을 등록
		Effect->SetTemplate(P_CHESTOPEN.Object);
		// 자동활성화 끔
		Effect->bAutoActivate = false;
	}

	// 박스 스태틱메시의 위치를 조정
	Box->SetRelativeLocation(FVector(0.0f, -3.5f, -30.0f));

	// Collision채널 등록. Object 채널의 이름과 동일해야함.
	Trigger->SetCollisionProfileName(TEXT("ItemBox"));
	// 스태틱메시에 자동으로 붙어있는 콜리전은 꺼준다.
	Box->SetCollisionProfileName(TEXT("NoCollision"));

	// 무기 클래스 정보를 넘겨줌.
	WeaponItemClass = AGSWeapon::StaticClass();
}

// Called when the game starts or when spawned
void ASH_ItemBox::BeginPlay()
{
	Super::BeginPlay();
}

void ASH_ItemBox::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	// Overlap 될때마다 해당하는 함수를 자동 호출하도록 바인딩함.
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ASH_ItemBox::OnCharacterOverlap);
}

// Called every frame
void ASH_ItemBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Overlap 될때마다 자동 호출되는 함수. 델리게이트. 바인딩됨.
void ASH_ItemBox::OnCharacterOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ABLOG_S(Warning);
	// 충돌처리되는 상대측 정보를 등록. 우리 콜리전 채널에는 반드시 플레이어만 들어오니까 이렇게 하나만 간단하게 코딩하면됨.
	auto GSCharacter = Cast<ALostDarkCharacter>(OtherActor);
	// 만약 충돌된 대상이 플레이어가 아니라면 예외처리.
	ABCHECK(nullptr != GSCharacter);

	if (nullptr != GSCharacter && nullptr != WeaponItemClass)
	{
		// 플레이어가 무기를 장착할 수 있다면 (빈손이라면)
		if (GSCharacter->CanSetWeapon())
		{
			// 월드에 무기를 생성시킴. WeaponItemClass에 등록된 정보를 참고해서
			auto NewWeapon = GetWorld()->SpawnActor<AGSWeapon>(WeaponItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
			// 플레이어에 생성시킨 무기를 장착함.
			GSCharacter->SetWeapon(NewWeapon);
			// 미리 등록해놓은 이펙트 활성화
			Effect->Activate(true);
			// 스태틱메시 모두 감추기
			Box->SetHiddenInGame(true, true);
			// 아이템 박스 전체 콜리전 끄기
			SetActorEnableCollision(false);
			// 델리게이트 선언. 파티클이 끝나면 호출되도록 바인딩함
			Effect->OnSystemFinished.AddDynamic(this, &ASH_ItemBox::OnEffectFinished);
		}
		// 플레이어가 이미 무기를 가졌다면,
		else
		{
			// 로그 찍음.
			ABLOG(Warning, TEXT("%s can't equip weapon currently."), *GSCharacter->GetName());
		}
	}
}

void ASH_ItemBox::OnEffectFinished(UParticleSystemComponent * PSystem)
{
	// 자신 삭제 (액터)
	Destroy();
}

