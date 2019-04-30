// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LostDark.h"
#include "GameFramework/Character.h"
#include "LostDarkCharacter.generated.h"

/*
	클래스 지정자 : Config = ConfigName
	이 클래스는 환경설정(.ini)파일에 데이터를 저장할 수 있음을 나타낸다.
	이 지정자는 그 프로퍼티를 해당 이름의 환경설정 파일에 저장하도록 한다.
	모든 자식 클래스에 전파되며, 자식 클래스에서 환경설정 파일을 바꿀 수 있다.
*/
UCLASS(config=Game)
class ALostDarkCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	ALostDarkCharacter();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	// 시점 전환 열거형
	enum class EControlMode
	{
		BackView, //백뷰
		QuaterView //쿼터뷰
	};

	// 시점 전환 함수
	void SetControlMode(EControlMode NewControlMode);
	// 현재 시점 변수
	EControlMode CurrentControlMode = EControlMode::BackView;
	// 쿼터뷰에서 앞방향(X방향)을 나타내는 멤버변수
	FVector DirectionToMove = FVector::ZeroVector;

	// Boom 길이
	float BoomLengthTo = 0.0f;
	// Boom 회전값
	FRotator BoomRotationTo = FRotator::ZeroRotator;
	// 시점 변경시 해당 Boom으로 늘어나거나 줄어드는 속도
	float BoomLengthSpeed = 0.0f;
	// 시점 변경시 해당 Boom으로 회전하는 속도
	float BoomRotationSpeed = 0.0f;

private:
	// Called for forwards/backward input
	void MoveForward(float Value);
	// Called for side to side input
	void MoveRight(float Value);

	// 아래 함수는 Pawn에서 기본적으로 제공하는 함수가 있어서 그걸 이용하면됨.
	//void LookUp(float Value);
	//void Turn(float Value);

	// 시점 변수 설정하는 함수
	void ViewChange();

// 마네킹에 있는거 놔둔 함수. 쓸모있을지도?
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};

