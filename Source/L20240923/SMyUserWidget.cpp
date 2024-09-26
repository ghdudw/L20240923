// Fill out your copyright notice in the Description page of Project Settings.


#include "SMyUserWidget.h"
#include "Components/Button.h"
#include "Components/Widget.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetTextLibrary.h"
#include "TimerManager.h"
#include "Misc/DateTime.h"


void USMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

    BP_ShutDownWidget->SetVisibility(ESlateVisibility::Hidden);
    BP_optionwidget->SetVisibility(ESlateVisibility::Hidden);


	Off->OnClicked.AddDynamic(this, &USMyUserWidget::OnClickedOff);
    option->OnClicked.AddDynamic(this, &USMyUserWidget::OnClickedOption);
    //home->OnClicked.AddDynamic(this, &USMyUserWidget::OnResetButtonClicked);

    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &USMyUserWidget::UpdateDateTime, 1.0f, true);

    UpdateDateTime();
}

void USMyUserWidget::OnClickedOff()
{
    if (BP_ShutDownWidget)
    {
        // 현재 가시성 상태를 가져와서 토글 (보이면 숨기고, 숨기면 보이도록)
        ESlateVisibility CurrentVisibility = BP_ShutDownWidget->GetVisibility();

        if (CurrentVisibility == ESlateVisibility::Visible)
        {
            // 가시성이 보이는 상태라면 숨기기
            BP_ShutDownWidget->SetVisibility(ESlateVisibility::Hidden);
        }
        else
        {
            // 숨겨진 상태라면 보이게 하기
            BP_ShutDownWidget->SetVisibility(ESlateVisibility::Visible);
        }

        UE_LOG(LogTemp, Warning, TEXT("Button Clicked, Visibility Toggled"));
    }
}

void USMyUserWidget::OnClickedOption()
{
    if (BP_optionwidget)
    {
        // 현재 가시성 상태를 가져와서 토글 (보이면 숨기고, 숨기면 보이도록)
        ESlateVisibility CurrentVisibility = BP_optionwidget->GetVisibility();

        if (CurrentVisibility == ESlateVisibility::Visible)
        {
            // 가시성이 보이는 상태라면 숨기기
            BP_optionwidget->SetVisibility(ESlateVisibility::Hidden);
        }
        else
        {
            // 숨겨진 상태라면 보이게 하기
            BP_optionwidget->SetVisibility(ESlateVisibility::Visible);
        }

        UE_LOG(LogTemp, Warning, TEXT("Button Clicked, Visibility Toggled"));
    }
}

void USMyUserWidget::UpdateDateTime()
{
    if (TextBlock_Timer)
    {
        // 현재 시간을 가져와서 텍스트 블록에 설정
        TextBlock_Timer->SetText(GetCurrentDateTime());
    }

}

FText USMyUserWidget::GetInformation() const
{
    return FText::FromString(MyLevelStruct.MyLevelStruct.DataType);
}

FText USMyUserWidget::GetCurrentDateTime() const
{
    FDateTime Now = FDateTime::Now();

    // 날짜와 시간을 문자열로 변환
    FString DateTimeString = Now.ToString(TEXT("%Y-%m-%d %H:%M:%S"));

    // 텍스트로 변환 후 반환
    return FText::FromString(DateTimeString);
}
