// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "GameFramework/Actor.h"
#include "SectionTest.generated.h"

UCLASS()
class LOSTDARK_API ASectionTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASectionTest();
	// 에디터에서 액터의 속성이나 트랜스폼 정보가 변경될때 자동 호출되는 함수
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	enum class ESectionState : uint8
	{
		READY=0,
		BATTLE,
		COMPLETE
	};

	// 스테이트 설정
	void SetState(ESectionState NewState);
	// 최초 상태는 Ready
	ESectionState CurrentState = ESectionState::READY;
	// 문 열리는 함수
	void OperateGates(bool bOpen = true);

	// 중앙 박스 트리거의 델리게이트
	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent*OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	// 문 박스 트리거의 델리게이트
	UFUNCTION()
		void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	// NPC 스폰함수
	void OnNPCSpawn();

	// 마지막에 죽인 액터가 누구인지
	UFUNCTION()
		void OnKeyAIDestroyed(AActor* DestroyedActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 배경 메시
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* Mesh;
	// 입장 트리거
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UBoxComponent* Trigger;

	// 문 메시
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		TArray<UStaticMeshComponent*> GateMeshes;
	// 문 트리거
	UPROPERTY(VisibleAnywhere, Category = Trigger, Meta = (AllowPrivateAccess = true))
		TArray<UBoxComponent*> GateTriggers;

	// Battle 섹션인지 구별 변수
	UPROPERTY(EditAnywhere, Category = State, Meta = (AllowPrivateAccess = true))
		bool bNoBattle;
	
	// NPC 스폰 타임
	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
		float NPCSpawnTime;
	// 아이템 스폰 타임
	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
		float ItemBoxSpawnTime;

	FTimerHandle SpawnNPCTimerHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};
};
