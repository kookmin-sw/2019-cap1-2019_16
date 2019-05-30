// Fill out your copyright notice in the Description page of Project Settings.

#include "LostDarkPlayerController.h"
// HUD 위젯
#include "LDHUDWidget.h"
#include "LDPlayerState.h"
#include "LostDarkCharacter.h"
#include "LDGamePlayWidget.h"
#include "LDGamePlayResultWidget.h"
#include "LDGameState.h"

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

	static ConstructorHelpers::FClassFinder<ULDGamePlayWidget> UI_MENU_C(TEXT("/Game/SH/UI/UI_Menu.UI_Menu_C"));
	if (UI_MENU_C.Succeeded())
	{
		MenuWidgetClass = UI_MENU_C.Class;
	}

	static ConstructorHelpers::FClassFinder<ULDGamePlayResultWidget> UI_RESULT_C(TEXT("/Game/SH/UI/UI_Result.UI_Result_C"));
	if (UI_RESULT_C.Succeeded())
	{
		ResultWidgetClass = UI_RESULT_C.Class;
	}
}

void ALostDarkPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ChangeInputMode(true);
	//// 게임 시작시 자동으로 화면 한번 클릭한것처럼 시작됨
	//FInputModeGameOnly InputMode;
	//SetInputMode(InputMode);

	if (HUDWidget == nullptr)
	{
		// 위젯 애셋정보를 통해, 이 캐릭터컨트롤러에 위젯을 생성한다. (플레이어 화면)
		HUDWidget = CreateWidget<ULDHUDWidget>(this, HUDWidgetClass);
		ABCHECK(HUDWidget != nullptr);
		// 화면에 출력
		HUDWidget->AddToViewport(1);
	}

	// 결과 위젯 만들어놓기
	ResultWidget = CreateWidget<ULDGamePlayResultWidget>(this, ResultWidgetClass);
	ABCHECK(ResultWidget != nullptr);

	// 플레이어 스테이트를 받아서 HUD위젯에 바인드
	LDPlayerState = Cast<ALDPlayerState>(PlayerState);
	ABCHECK(nullptr != LDPlayerState);
	HUDWidget->BindPlayerState(LDPlayerState);
	LDPlayerState->OnPlayerStateChanged.Broadcast();
}

// 바인딩
void ALostDarkPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction(TEXT("GamePause"), EInputEvent::IE_Pressed, this, &ALostDarkPlayerController::OnGamePause);
}

void ALostDarkPlayerController::OnGamePause()
{
	// 메뉴 위젯 생성
	MenuWidget = CreateWidget<ULDGamePlayWidget>(this, MenuWidgetClass);
	ABCHECK(MenuWidget != nullptr);
	MenuWidget->AddToViewport(3);

	// 일시중지
	SetPause(true);
	// UI만 입력
	ChangeInputMode(false);
}

// 위젯 정보 반환
ULDHUDWidget * ALostDarkPlayerController::GetHUDWidget() const
{
	return HUDWidget;
}

// 외부 블루프린트 Enemy에서 죽었을때 경험치를 받아오는 함수. UFUNCTION
void ALostDarkPlayerController::AddScore(int32 Score) const
{
	ABLOG(Warning, TEXT("New AI Level : %d"), Score);
	LDPlayerState->AddExp(Score);
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

void ALostDarkPlayerController::ChangeInputMode(bool bGameMode)
{
	// true면 게임화면만
	if (bGameMode)
	{
		//SetInputMode(GameInputMode);
		bShowMouseCursor = true;
	}
	// false면 UI에만
	else
	{
		SetInputMode(UIInputMode);
		bShowMouseCursor = true;
	}
}

void ALostDarkPlayerController::ShowResultUI()
{
	// 현재 월드에서 게임스테이트를 가져옴
	auto LDGameState = Cast<ALDGameState>(UGameplayStatics::GetGameState(this));
	ABCHECK(LDGameState != nullptr);
	// 해당 게임스테이트 정보를 바인딩시킴
	ResultWidget->BindGameState(LDGameState);
	
	// 뷰 포트에 추가
	ResultWidget->AddToViewport();
	ChangeInputMode(false);
}