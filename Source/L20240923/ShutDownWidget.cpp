// Fill out your copyright notice in the Description page of Project Settings.


#include "ShutDownWidget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>
#include "Kismet/KismetSystemLibrary.h"

void UShutDownWidget::NativeConstruct()
{
	Button_yes->OnClicked.AddDynamic(this, &UShutDownWidget::OnClickedYes);
	Button_no->OnClicked.AddDynamic(this, &UShutDownWidget::OnClickedNo);
}

void UShutDownWidget::OnClickedYes()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}

void UShutDownWidget::OnClickedNo()
{
	SetVisibility(ESlateVisibility::Hidden);
}
