// Fill out your copyright notice in the Description page of Project Settings.

#include "YJCharacter.h"

// Sets default values
AYJCharacter::AYJCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AYJCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AYJCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AYJCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 AYJCharacter::GetHP() const {
	return HealthPoint;
}

int32 AYJCharacter::GetMP() const {
	return HealthPoint;
}
