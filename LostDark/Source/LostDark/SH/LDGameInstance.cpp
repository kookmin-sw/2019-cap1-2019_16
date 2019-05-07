// Fill out your copyright notice in the Description page of Project Settings.

#include "LDGameInstance.h"

ULDGameInstance::ULDGameInstance()
{
	// 데이터 테이블 레퍼런스를 변수에 넣어줌. 일종의 string 변수 만든거임
	FString CharacterDataPath = TEXT("/Game/SH/GameData/LostDarkCharacterData.LostDarkCharacterData");
	// 가져온 정보로 사용할 변수를 실제로 만듦
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_GSCHARACTER(*CharacterDataPath);
	// 데이터 테이블 정보를 잘 가져오지 못했으면 예외처리
	ABCHECK(DT_GSCHARACTER.Succeeded());
	// 전방선언한 테이블 정보 초기화. 이제부터 GSCharacterTable로 계산한다는 의미.
	GSCharacterTable = DT_GSCHARACTER.Object;
	// 왜 안되는지 모르겠음. RowMap에 접근할수가 없음. 분명 존재하는데. Protected라서 그런듯?
	//ABCHECK(GSCharacterTable->RowMap.Num()>0);
}

void ULDGameInstance::Init()
{
	Super::Init();
	// Level 20번째 행의 DropExp의 정보.
	//ABLOG(Warning,TEXT("DropExp of Level 20 GSCharacter : %d"), GetGSCharacterData(20)->DropExp);
}

// 실제 스탯 데이터가 저장된 구조체를 반환해주는 함수.
FGSCharacterData * ULDGameInstance::GetGSCharacterData(int32 Level)
{
	// 실제로 테이블에서 찾는 함수
	return GSCharacterTable->FindRow<FGSCharacterData>(*FString::FromInt(Level), TEXT(""));
}
