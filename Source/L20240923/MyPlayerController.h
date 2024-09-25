// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/TimelineComponent.h"
#include "MyPlayerController.generated.h"
/**
 * 
 */
UCLASS()
class L20240923_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected :

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY()
	class UUserWidget* HUDWidget;

	void SetFullscreenMode();

};
