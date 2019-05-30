// Fill out your copyright notice in the Description page of Project Settings.

#include "LDCharacterSelectWidget.h"
//
#include "LDCharacterSetting.h"
#include "LDGameInstance.h"
#include "EngineUtils.h" // TActorIterator
#include "Animation/SkeletalMeshActor.h" //ASkeletalMeshActor
#include "Components/Button.h"// Button.OnClicked.AddDynamic()
#include "Components/EditableTextBox.h" // TextBox->GetText().ToString()
#include "LDSaveGame.h"
#include "LDPlayerState.h"

// Add to viewport or root 할때 호출되는 함수. 뷰포트에 추가할때 실행됨. => 최초 UI 생성하고 실행
void ULDCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CurrentIndex = 0;
	// 애셋 세팅 정보를 가져옴.
	auto CharacterSetting = GetDefault<ULDCharacterSetting>();
	// 애셋 개수 가져옴 (파일정보 읽어옴)
	MaxIndex = CharacterSetting->CharacterAssets.Num();

	// 월드에 있는 모든 스켈레탈 메시는 TActorIterator로 가져올수 있음. 즉, 레벨에 배치된 스켈레탈 매쉬를 사용하는 유일한 액터를 찾는것.
	for (TActorIterator<ASkeletalMeshActor> It(GetWorld()); It; ++It)
	{
		TargetComponent = It->GetSkeletalMeshComponent();
		break;
	}


	/* 각 버튼들 바인딩, 다이나믹 델리게이트 선언 */

	// Button
	PrevButton = Cast<UButton>(GetWidgetFromName(TEXT("btnPrev")));
	ABCHECK(PrevButton != nullptr);
	// Button
	NextButton = Cast<UButton>(GetWidgetFromName(TEXT("btnNext")));
	ABCHECK(NextButton != nullptr);
	// Text Box
	TextBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("edtPlayerName")));
	ABCHECK(TextBox != nullptr);
	// Button
	ConfirmButton = Cast<UButton>(GetWidgetFromName(TEXT("btnConfirm")));
	ABCHECK(ConfirmButton != nullptr);

	PrevButton->OnClicked.AddDynamic(this, &ULDCharacterSelectWidget::OnPrevClicked);
	NextButton->OnClicked.AddDynamic(this, &ULDCharacterSelectWidget::OnNextClicked);
	ConfirmButton->OnClicked.AddDynamic(this, &ULDCharacterSelectWidget::OnConfirmClicked);
}

void ULDCharacterSelectWidget::OnPrevClicked()
{
	NextCharacter(false);
}

void ULDCharacterSelectWidget::OnNextClicked()
{
	NextCharacter(true);
}

// 캐릭터명 적는 버튼 클릭했을때
void ULDCharacterSelectWidget::NextCharacter(bool bForward)
{
	bForward ? CurrentIndex++ : CurrentIndex--;

	// Queue 구조. 마지막 -> 처음, 처음 이전 -> 마지막
	if (CurrentIndex == -1) CurrentIndex = MaxIndex - 1;
	if (CurrentIndex == MaxIndex) CurrentIndex = 0;

	// 애셋 세팅 정보를 가져옴.
	auto CharacterSetting = GetDefault<ULDCharacterSetting>();
	// 최초는 0번째 메시 경로정보 가져옴
	auto AssetRef = CharacterSetting->CharacterAssets[CurrentIndex];

	// 현재 월드의 게임인스턴스 정보를 가져옴 (게임 매니저)
	auto LDGameInstance = GetWorld()->GetGameInstance<ULDGameInstance>();
	ABCHECK(nullptr != LDGameInstance);
	ABCHECK(TargetComponent.IsValid());

	// 세팅에 저장된 애셋 경로로 메시를 새롭게 로드함. 스켈레탈 메시 정보 가져오기
	USkeletalMesh* Asset = LDGameInstance->StreamableManager.LoadSynchronous<USkeletalMesh>(AssetRef);
	if (nullptr != Asset)
	{
		// 화면에 있는 액터의 매쉬를 교체(스켈레탈을 공유하기 때문에 가능함)
		TargetComponent->SetSkeletalMesh(Asset);
	}

}

void ULDCharacterSelectWidget::OnConfirmClicked()
{
	// 텍스트박스에 있는 문자열 가져오기
	FString CharacterName = TextBox->GetText().ToString();
	// 이름이 없거나, 10글자 이상이면 아무일도 없음.
	if (CharacterName.Len() <= 0 || CharacterName.Len() > 10) return;

	/* 세이브 기능 */
	// 새로운 세이브 데이터 변수 만듦.
	ULDSaveGame* NewPlayerData = NewObject<ULDSaveGame>();
	NewPlayerData->PlayerName = CharacterName;
	NewPlayerData->Level = 3;
	NewPlayerData->Exp = 0;
	NewPlayerData->HighScore = 0; // 현재까지 최대 클리어한 횟수(죽인 횟수)
	NewPlayerData->CharacterIndex = CurrentIndex; // 애셋 경로의 인덱스를 저장

	// 플레이어 스테이트 변수 선언
	auto LDPlayerState = GetDefault<ALDPlayerState>();
	// 게임 세이브 저장하고, 성공하면 // (데이터정보, 슬롯이름, 슬롯인덱스)
	if (UGameplayStatics::SaveGameToSlot(NewPlayerData, LDPlayerState->SaveSlotName, 2))
	{
		// 새로운 레벨을 연다. 2번째 인자에는 맵 애셋 이름을 넣어줘야한다.
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("Elemental"));
	}
	else
	{
		ABLOG(Error, TEXT("SaveGame Error!"));
	}
}