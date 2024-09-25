// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShutDownWidget.generated.h"

/**
 * 
 */
UCLASS()
class L20240923_API UShutDownWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* Button_yes;

	UPROPERTY(meta = (BindWidget))
	class UButton* Button_no;

	UFUNCTION()
	void OnClickedYes();

	UFUNCTION()
	void OnClickedNo();

};
