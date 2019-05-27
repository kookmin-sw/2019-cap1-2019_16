// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "GameFramework/Actor.h"
#include "GSWeapon.generated.h"

UCLASS()
class LOSTDARK_API AGSWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGSWeapon();

	// 공격 범위
	float GetAttackRange() const;
	// 무기 공격 데미지
	float GetAttackDamage() const;
	//
	float GetAttackModifier() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// 공격 범위 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
		float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
		float AttackDamageMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
		float AttackDamageMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
		float AttackModifierMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack)
		float AttackModifierMax;

	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
		float AttackDamage;
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
		float AttackModifier;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// 무기 애셋 스켈레탈 변수
	UPROPERTY(VisibleAnywhere, Category = Weapon)
		USkeletalMeshComponent* Weapon;
};
