// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Animation/AnimInstance.h"
#include "GSAnimInstance.generated.h"

/**
 * GS = GreyStone
 */
UCLASS()
class LOSTDARK_API UGSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// 생성자
	UGSAnimInstance();

private:
	// 현재 캐릭터 속도 프로퍼티(멤버변수)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

};
