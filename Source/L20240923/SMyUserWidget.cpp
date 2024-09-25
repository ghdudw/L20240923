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
        // ���� ���ü� ���¸� �����ͼ� ��� (���̸� �����, ����� ���̵���)
        ESlateVisibility CurrentVisibility = BP_ShutDownWidget->GetVisibility();

        if (CurrentVisibility == ESlateVisibility::Visible)
        {
            // ���ü��� ���̴� ���¶�� �����
            BP_ShutDownWidget->SetVisibility(ESlateVisibility::Hidden);
        }
        else
        {
            // ������ ���¶�� ���̰� �ϱ�
            BP_ShutDownWidget->SetVisibility(ESlateVisibility::Visible);
        }

        UE_LOG(LogTemp, Warning, TEXT("Button Clicked, Visibility Toggled"));
    }
}

void USMyUserWidget::OnClickedOption()
{
    if (BP_optionwidget)
    {
        // ���� ���ü� ���¸� �����ͼ� ��� (���̸� �����, ����� ���̵���)
        ESlateVisibility CurrentVisibility = BP_optionwidget->GetVisibility();

        if (CurrentVisibility == ESlateVisibility::Visible)
        {
            // ���ü��� ���̴� ���¶�� �����
            BP_optionwidget->SetVisibility(ESlateVisibility::Hidden);
        }
        else
        {
            // ������ ���¶�� ���̰� �ϱ�
            BP_optionwidget->SetVisibility(ESlateVisibility::Visible);
        }

        UE_LOG(LogTemp, Warning, TEXT("Button Clicked, Visibility Toggled"));
    }
}

void USMyUserWidget::UpdateDateTime()
{
    if (TextBlock_Timer)
    {
        // ���� �ð��� �����ͼ� �ؽ�Ʈ ��Ͽ� ����
        TextBlock_Timer->SetText(GetCurrentDateTime());
    }

}

FText USMyUserWidget::GetCurrentDateTime() const
{
    FDateTime Now = FDateTime::Now();

    // ��¥�� �ð��� ���ڿ��� ��ȯ
    FString DateTimeString = Now.ToString(TEXT("%Y-%m-%d %H:%M:%S"));

    // �ؽ�Ʈ�� ��ȯ �� ��ȯ
    return FText::FromString(DateTimeString);
}
