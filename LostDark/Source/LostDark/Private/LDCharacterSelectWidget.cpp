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

void ULDCharacterSelectWidget::NextCharacter(bool bForward)
{
	bForward ? CurrentIndex++ : CurrentIndex--;

	// Queue 구조. 마지막 -> 처음, 처음 이전 -> 마지막
	if (CurrentIndex == -1) CurrentIndex = MaxIndex - 1;
	if (CurrentIndex == MaxIndex) CurrentIndex = 0;

	auto CharacterSetting = GetDefault<ULDCharacterSetting>();
	// 초기화 안한 변수는 0이므로 최초 애셋 정보 가져옴.
	auto AssetRef = CharacterSetting->CharacterAssets[CurrentIndex];

	// 현재 월드의 게임인스턴스 정보를 가져옴 (게임 매니저)
	auto LDGameInstance = GetWorld()->GetGameInstance<ULDGameInstance>();
	ABCHECK(nullptr != LDGameInstance);
	ABCHECK(TargetComponent.IsValid());

	// 애셋 목록의 첫번째 애셋을 로드함. 스켈레탈 메시 정보 가져오기
	USkeletalMesh* Asset = LDGameInstance->StreamableManager.LoadSynchronous<USkeletalMesh>(AssetRef);
	if (nullptr != Asset)
	{
		TargetComponent->SetSkeletalMesh(Asset);
	}

}

// Add to viewport or root 할때 호출되는 함수. 뷰포트에 추가할때 실행됨.
void ULDCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CurrentIndex = 0;
	auto CharacterSetting = GetDefault<ULDCharacterSetting>();
	// 애셋 개수 가져옴
	MaxIndex = CharacterSetting->CharacterAssets.Num();

	// 월드에 있는 모든 스켈레탈 메시를 가진 액터를 가져옴. 그게 Null이 될때까지
	for (TActorIterator<ASkeletalMeshActor> It(GetWorld()); It; ++It)
	{
		TargetComponent = It->GetSkeletalMeshComponent();
		break;
	}

	/* 버튼들 바인딩 시킨후, 다이나믹 델리게이트 선언 */
	PrevButton = Cast<UButton>(GetWidgetFromName(TEXT("btnPrev")));
	ABCHECK(PrevButton != nullptr);

	NextButton = Cast<UButton>(GetWidgetFromName(TEXT("btnNext")));
	ABCHECK(NextButton != nullptr);

	TextBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("edtPlayerName")));
	ABCHECK(TextBox != nullptr);

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
void ULDCharacterSelectWidget::OnConfirmClicked()
{
	// 텍스트박스에 있는 문자열 가져오기
	FString CharacterName = TextBox->GetText().ToString();
	// 이름이 없거나, 10글자 이상이면 아무일도 없음.
	if (CharacterName.Len() <= 0 || CharacterName.Len() > 10) return;

	// 새로운 세이브 데이터 변수 만듦.
	ULDSaveGame* NewPlayerData = NewObject<ULDSaveGame>();
	NewPlayerData->PlayerName = CharacterName;
	// 최초 정보 기록
	NewPlayerData->Level = 5;
	NewPlayerData->Exp = 50;
	NewPlayerData->HighScore = 0;
	NewPlayerData->CharacterIndex = CurrentIndex;

	// 플레이어 스테이트 변수 선언
	auto LDPlayerState = GetDefault<ALDPlayerState>();
	// 게임 세이브 저장하고, 성공하면
	if (UGameplayStatics::SaveGameToSlot(NewPlayerData, LDPlayerState->SaveSlotName, 0))
	{
		// 새로운 레벨을 연다. 2번째 인자에는 맵 애셋 이름을 넣어줘야한다.
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("SH_DefaultLevel"));
	}
	else
	{
		ABLOG(Error, TEXT("SaveGame Error!"));
	}
}