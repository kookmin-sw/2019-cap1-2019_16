// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
// 엑셀 데이터 사용하려면
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "LDGameInstance.generated.h"

// 구조체 선언해준다.
USTRUCT(BlueprintType)
// FTableRowBase 구조체를 상속받아야한다.
struct FGSCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// 테이블의 첫번째 위치한 열 데이터는(Name) 언리얼에서 자동으로 키 값으로 사용하기 때문에 선언에서 제외해야함. (규칙)
	FGSCharacterData() : Level(1), MaxHP(100.0f), Attack(10.0f), DropExp(10), NextExp(30) {}

	// 현재 레벨
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Level;
	// 최대 에너지
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MaxHP;
	// 공격력
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Attack;
	// 떨어지는 경험치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 DropExp;
	// 다음 경험치
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 NextExp;
};


/**
 *
 */
UCLASS()
class LOSTDARK_API ULDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	ULDGameInstance();

	virtual void Init() override;
	// 캐릭터 데이터 테이블에서 정보를 가져오는 함수. 해당 테이블 행의 정보를 가져옴. Level에 따른 모든 정보 접근 가능
	FGSCharacterData* GetGSCharacterData(int32 Level);

private:
	// 데이터 테이블 등록하기 위한 변수. 실제 관리는 이 변수로 함.
	UPROPERTY()
		class UDataTable* GSCharacterTable;

};
