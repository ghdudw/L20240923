// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "EngineUtils.h"
#include "GameFramework/GameUserSettings.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (HUDWidgetClass)
	{
		HUDWidget = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidget)
		{
			HUDWidget->AddToViewport();
			SetInputMode(FInputModeUIOnly());
			bShowMouseCursor = true;
		}
	}
}

void AMyPlayerController::SetFullscreenMode()
{
	UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
	if (UserSettings)
	{
		UserSettings->SetScreenResolution(FIntPoint(1920, 1080));
		// 전체화면 모드로 설정
		UserSettings->SetFullscreenMode(EWindowMode::Fullscreen);

		// 설정 적용
		UserSettings->ApplySettings(false);
	}
}
