// Fill out your copyright notice in the Description page of Project Settings.

#include "LDGamePlayWidget.h"
//
#include "Components/Button.h"
#include "LostDarkPlayerController.h"

// 해당 위젯을 Add to Viewport 했을때 호출됨
void ULDGamePlayWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 재시작
	ResumeButton = Cast<UButton>(GetWidgetFromName(TEXT("btnResume")));
	if (ResumeButton != nullptr)
	{
		ResumeButton->OnClicked.AddDynamic(this, &ULDGamePlayWidget::OnResumeClicked);
	}

	// 타이틀 화면으로
	ReturnToTitleButton = Cast<UButton>(GetWidgetFromName(TEXT("btnReturnToTitle")));
	if (ReturnToTitleButton != nullptr)
	{
		ReturnToTitleButton->OnClicked.AddDynamic(this, &ULDGamePlayWidget::OnReturnToTitleClicked);
	}

	// 재도전
	RetryGameButton = Cast<UButton>(GetWidgetFromName(TEXT("btnRetryGame")));
	if (RetryGameButton != nullptr)
	{
		RetryGameButton->OnClicked.AddDynamic(this, &ULDGamePlayWidget::OnRetryGameClicked);
	}
}

// 재시작
void ULDGamePlayWidget::OnResumeClicked()
{
	// 현재 월드에서 자신이 관리하는 플레이어 컨트롤러의 정보를 가져온다.
	auto LDPlayerController = Cast<ALostDarkPlayerController>(GetOwningPlayer());
	ABCHECK(LDPlayerController != nullptr);

	// 뷰포트에 띄워진 자신(플레이어 컨트롤러)을 제거할 수 있다.
	RemoveFromParent();
	LDPlayerController->ChangeInputMode(true);
	LDPlayerController->SetPause(false);
}

// 타이틀로 돌아가기
void ULDGamePlayWidget::OnReturnToTitleClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Title"));
}

// 다시도전
void ULDGamePlayWidget::OnRetryGameClicked()
{
	// 현재 월드에서 플레이어 컨트롤러 정보를 가져옴
	auto LDPlayerController = Cast<ALostDarkPlayerController>(GetOwningPlayer());
	ABCHECK(LDPlayerController != nullptr);
	// 해당하는 플레이어 컨트롤러 정보를 가지고 다시 재시작
	LDPlayerController->RestartLevel();
}
