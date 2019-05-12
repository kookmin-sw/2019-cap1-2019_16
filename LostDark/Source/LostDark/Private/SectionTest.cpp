// Fill out your copyright notice in the Description page of Project Settings.

#include "SectionTest.h"
// NPC 생성을 위해 필요
#include "LostDarkCharacter.h"
// 아이템 생성을 위해 필요
#include "SH_ItemBox.h"

// Sets default values
ASectionTest::ASectionTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Mesh;

	FString AssetPath = TEXT("/Game/DefaultLevel/SM_SQUARE.SM_SQUARE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_SQUARE(*AssetPath);
	if (SM_SQUARE.Succeeded())
	{
		Mesh->SetStaticMesh(SM_SQUARE.Object);
	}
	else
	{
		ABLOG(Error, TEXT("Failed to load staticmesh asset. : %s"), *AssetPath);
	}
	// 트리거 컴포넌트 생성
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));
	// 기본 박스 오브젝트 해당 크기로 생성 (사이즈)
	Trigger->SetBoxExtent(FVector(775.0f, 775.0f, 300.0f));
	Trigger->SetupAttachment(RootComponent);
	Trigger->SetRelativeLocation(FVector(0.0f, 0.0f, 250.0f));
	// 콜리전 Preset과 이름이 같아야함. 그래야 적용됨
	Trigger->SetCollisionProfileName(TEXT("LDTrigger"));

	// 중앙 박스 트리거 델리게이트 함수 바인딩
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ASectionTest::OnTriggerBeginOverlap);

	/* Gate 애셋 */

	FString GateAssetPath = TEXT("/Game/DefaultLevel/SM_GATE.SM_GATE");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_GATE(*GateAssetPath);
	if (!SM_GATE.Succeeded())
	{
		ABLOG(Error, TEXT("Failed to load staticmesh asset. :%s"), *GateAssetPath);
	}

	static FName GateSockets[] = { {TEXT("+XGate")},{TEXT("-XGate")},{TEXT("+YGate")},{TEXT("-YGate")} };

	for (FName GateSocket : GateSockets)
	{
		ABCHECK(Mesh->DoesSocketExist(GateSocket));
		// 새로운 스태틱메시 컴포넌트 추가
		UStaticMeshComponent* NewGate = CreateDefaultSubobject<UStaticMeshComponent>(*GateSocket.ToString());
		ABLOG(Error, TEXT("Success GateMeshs :%s"), *GateSocket.ToString());
		// 새로운 게이트에 메시 추가
		NewGate->SetStaticMesh(SM_GATE.Object);
		// 소켓명도 넣어줌.
		NewGate->SetupAttachment(RootComponent, GateSocket);
		// 게이트 메시 위치 조절
		NewGate->SetRelativeLocation(FVector(0.0f, -80.5f, 0.0f));
		// TArray에 메시 컴포넌트 정보 넣어줌.
		GateMeshes.Add(NewGate);
		//ABLOG(Error, TEXT("Success GateMeshs :%s"), *GateAssetPath);

		// 문 트리거 컴포넌트 생성
		UBoxComponent* NewGateTrigger = CreateDefaultSubobject<UBoxComponent>(*GateSocket.ToString().Append(TEXT("Trigger")));
		NewGateTrigger->SetBoxExtent(FVector(100.0f, 100.0f, 300.0f));
		NewGateTrigger->SetupAttachment(RootComponent, GateSocket);
		NewGateTrigger->SetRelativeLocation(FVector(70.0f, 0.0f, 250.0f));
		// 콜리전 Preset 적용
		NewGateTrigger->SetCollisionProfileName(TEXT("LDTrigger"));
		// TArray에 저장
		GateTriggers.Add(NewGateTrigger);

		// 문 박스 트리거 델리게이트 함수 바인딩
		NewGateTrigger->OnComponentBeginOverlap.AddDynamic(this, &ASectionTest::OnGateTriggerBeginOverlap);
		// 각 문 박스 트리거에 태그 지정
		NewGateTrigger->ComponentTags.Add(GateSocket);
	}

	// 기본적으로 false
	bNoBattle = false;

	// 초기값 설정
	NPCSpawnTime = 2.0f;
	ItemBoxSpawnTime = 5.0f;
}
// 에디터에서 액터의 속성이나 트랜스폼 정보가 변경될때 자동 호출되는 함수
void ASectionTest::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

// Called when the game starts or when spawned
void ASectionTest::BeginPlay()
{
	Super::BeginPlay();
	// 최초 시작시 bNoBattle 값에 따라 설정
	SetState(bNoBattle ? ESectionState::COMPLETE : ESectionState::READY);
}

void ASectionTest::SetState(ESectionState NewState)
{
	switch (NewState)
	{
	case ASectionTest::ESectionState::READY:
		// 중앙 트리거 콜리전 설정
		Trigger->SetCollisionProfileName(TEXT("LDTrigger"));
		// 문 트리거 콜리전 재설정
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}
		// 처음에는 문이 다 열려있음.
		OperateGates(true);
		break;
	case ASectionTest::ESectionState::BATTLE:
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			GateTrigger->SetCollisionProfileName(TEXT("NoCollision"));
		}
		OperateGates(false);

		// AI 타이머 설정과 델리게이터 바인딩
		GetWorld()->GetTimerManager().SetTimer(SpawnNPCTimerHandle, FTimerDelegate::CreateUObject(this, &ASectionTest::OnNPCSpawn), NPCSpawnTime, false);
		// 아이템 스폰 타이머 설정과 델리게이터를 람다로 바인딩
		GetWorld()->GetTimerManager().SetTimer(SpawnItemBoxTimerHandle, FTimerDelegate::CreateLambda([this]()->void {
			// 높이가 없는 반경 600cm안의 랜덤한 x,y값
			FVector2D RandXY = FMath::RandPointInCircle(600.0f);
			// 배경 액터의 중심위치 + 높이 30
			GetWorld()->SpawnActor<ASH_ItemBox>(GetActorLocation() + FVector(RandXY, 30.0f), FRotator::ZeroRotator);
		}), ItemBoxSpawnTime, false);

		break;
	case ASectionTest::ESectionState::COMPLETE:
		Trigger->SetCollisionProfileName(TEXT("NoCollision"));
		for (UBoxComponent* GateTrigger : GateTriggers)
		{
			GateTrigger->SetCollisionProfileName(TEXT("LDTrigger"));
		}
		OperateGates(true);
		break;
	default:
		break;
	}
	// 현재상태 변경
	CurrentState = NewState;
}
// 문 열리는 함수
void ASectionTest::OperateGates(bool bOpen)
{
	for (UStaticMeshComponent* Gate : GateMeshes)
	{
		Gate->SetRelativeRotation(bOpen ? FRotator(0.0f, -90.0f, 0.0f) : FRotator::ZeroRotator);
	}
}

// 중앙 박스 트리거의 델리게이트
void ASectionTest::OnTriggerBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// 현재 레디 스테이트면
	if (CurrentState == ESectionState::READY)
	{
		// 배틀 스테이트로 전환
		SetState(ESectionState::BATTLE);
	}
}

// 문 박스 트리거의 델리게이트
void ASectionTest::OnGateTriggerBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	// 해당 트리거의 태그가 1개가 아니면 예외처리.
	ABCHECK(OverlappedComponent->ComponentTags.Num() == 1);
	// 들어온 문의 태그 이름을 받음
	FName ComponentTag = OverlappedComponent->ComponentTags[0];
	// 소켓 이름을 받아옴. 왼쪽에서 2번째 이름까지 이름을 가져옴.
	FName SocketName = FName(*ComponentTag.ToString().Left(2));
	ABLOG(Warning, TEXT("Success GateMeshs :%s"), *SocketName.ToString());
	// 예외처리
	if (!Mesh->DoesSocketExist(SocketName))
		return;

	// 다음에 생성할 맵의 위치값을 받아옴.
	FVector NewLocation = Mesh->GetSocketLocation(SocketName);

	// 
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, this);
	FCollisionObjectQueryParams ObjectQueryParam(FCollisionObjectQueryParams::InitType::AllObjects);

	// 문쪽으로 레이트레이스
	bool bResult = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		NewLocation,
		FQuat::Identity,
		ObjectQueryParam,
		FCollisionShape::MakeSphere(775.0f),
		CollisionQueryParam
	);

	// 정보가 없다면 새로 만들어라. GetWorld()->SpawnActor<>();
	if (!bResult)
	{
		auto NewSection = GetWorld()->SpawnActor<ASectionTest>(NewLocation, FRotator::ZeroRotator);
	}
	// 정보가 있다면 이미 만들어진곳
	else
	{
		ABLOG(Warning, TEXT("New section area is not empty."));
	}
}

void ASectionTest::OnNPCSpawn()
{
	// 맵 중앙 + 높이 88에 생성. 캐릭터 높이가 176를 감안한듯?
	GetWorld()->SpawnActor<ALostDarkCharacter>(GetActorLocation() + FVector::UpVector*88.0f, FRotator::ZeroRotator);
}

// Called every frame
void ASectionTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}