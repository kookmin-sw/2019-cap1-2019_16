// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YJCharacter.generated.h"

UCLASS()
class LOSTDARK_API AYJCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYJCharacter();

	UFUNCTION(BlueprintPure, Category = Status)
	int32 GetHP() const;

	UFUNCTION(BlueprintPure, Category = Status)
	int32 GetMP() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	int32 HealthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	int32 MentalPoint;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
