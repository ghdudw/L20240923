// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SMyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class L20240923_API USMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnClickedOff();

	UFUNCTION()
	void OnClickedOption();

	void UpdateDateTime();


	UPROPERTY(meta = (BindWidget))
	class UButton* home;

	UPROPERTY(meta = (BindWidget))
	class UWidget* BP_ShutDownWidget;

	UPROPERTY(meta = (BindWidget))
	class UWidget* BP_optionwidget;

	UPROPERTY(meta = (BindWidget))
	class UButton* Off;

	UPROPERTY(meta = (BindWidget))
	class UButton* option;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_Timer;

	UFUNCTION(BlueprintCallable, Category = "DateTime")
	FText GetCurrentDateTime() const;

private:
	FTimerHandle TimerHandle;
};