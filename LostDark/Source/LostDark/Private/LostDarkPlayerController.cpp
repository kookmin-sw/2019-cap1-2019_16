// Fill out your copyright notice in the Description page of Project Settings.

#include "LostDarkPlayerController.h"
// HUD 위젯
#include "LDHUDWidget.h"
#include "LDPlayerState.h"
#include "LostDarkCharacter.h"

// Constructor
ALostDarkPlayerController::ALostDarkPlayerController()
{
	//// 마우스 커서 보이기 (Whether the mouse cursor should be displayed.)
	//this->bShowMouseCursor = true;
	//// 마우스 클릭 이벤트 활성화 (Whether actor/component click events should be generated.)
	//this->bEnableClickEvents = true;
	//// 마우스 over 이벤트 = 커서가 닿으면 발생하는 이벤트 활성화 (Whether actor/component mouse over events should be generated.)
	//this->bEnableMouseOverEvents = true;

	// 애셋 Class정보면, _C 붙여주자 ㅜㅜ
	static ConstructorHelpers::FClassFinder<ULDHUDWidget> UI_HUD_C(TEXT("/Game/SH/UI/UI_HUD.UI_HUD_C"));
	
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}
}

void ALostDarkPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// 게임 시작시 자동으로 화면 한번 클릭한것처럼 시작됨
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);

	// 위젯 애셋정보를 통해, 이 캐릭터컨트롤러에 위젯을 생성한다. (플레이어 화면)
	HUDWidget = CreateWidget<ULDHUDWidget>(this, HUDWidgetClass);
	// 화면에 출력
	HUDWidget->AddToViewport();

	// 플레이어 스테이트를 받아서 HUD위젯에 바인드
	LDPlayerState = Cast<ALDPlayerState>(PlayerState);
	ABCHECK(nullptr != LDPlayerState);
	HUDWidget->BindPlayerState(LDPlayerState);
	LDPlayerState->OnPlayerStateChanged.Broadcast();
}

// 위젯 정보 반환
ULDHUDWidget * ALostDarkPlayerController::GetHUDWidget() const
{
	return HUDWidget;
}

// 경험치 획득
void ALostDarkPlayerController::AIKill(ALostDarkCharacter * KiiledAI) const
{
	LDPlayerState->AddExp(KiiledAI->GetExp());
}

void ALostDarkPlayerController::AddGameScore() const
{
	LDPlayerState->AddGameScore();
}
