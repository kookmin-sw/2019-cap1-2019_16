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

	// 시점 전환 함수
	void SetControlMode(int32 ControlMode);

private:
	// Called for forwards/backward input
	void MoveForward(float Value);
	// Called for side to side input
	void MoveRight(float Value);

	// 아래 함수는 Pawn에서 기본적으로 제공하는 함수가 있어서 그걸 이용하면됨.
	//void LookUp(float Value);
	//void Turn(float Value);

// 마네킹에 있는거 놔둔 함수. 쓸모있을지도?
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};

