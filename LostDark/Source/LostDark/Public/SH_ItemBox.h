// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "GameFramework/Actor.h"
#include "SH_ItemBox.generated.h"

UCLASS()
class LOSTDARK_API ASH_ItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASH_ItemBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// PostinitializeComponents
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 박스 콜리전 컴포넌트(트리거)
	UPROPERTY(VisibleAnywhere, Category = Box)
		UBoxComponent* Trigger;

	// 박스 스태틱메시
	UPROPERTY(VisibleAnywhere, Category = Box)
		UStaticMeshComponent* Box;

	// 파티클시스템 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = Effect)
		UParticleSystemComponent* Effect;

	// 클래스 정보를 저장할 변수를 아이템 상자와 상속받은 클래스들로 목록을 한정시킴. (TSubclassof)
	UPROPERTY(EditInstanceOnly, Category = Box)
		TSubclassOf<class AGSWeapon> WeaponItemClass;

private:
	// Overlap 이벤트 발생할때 호출할 멤버 함수. 바인딩할 예정. 인자 형식은 아래와 반드시 같아야만함.
	UFUNCTION()
		void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// 파티클 시스템의 OnSystemFinished 델리게이트를 바인딩할 대상 멤버 함수.
	UFUNCTION()
		void OnEffectFinished(class UParticleSystemComponent* PSystem);
};
