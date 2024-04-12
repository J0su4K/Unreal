// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuWidget.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TSubclassOf<UMainMenuWidget> mainMenuwidget = nullptr;

	UPROPERTY(EditAnywhere) TObjectPtr<UMainMenuWidget> currentMainMenu = nullptr;


	FORCEINLINE TObjectPtr<UMainMenuWidget>  GetCurrentMainMenu() { return currentMainMenu; };


	void InitUI();

	virtual void BeginPlay() override;
};
