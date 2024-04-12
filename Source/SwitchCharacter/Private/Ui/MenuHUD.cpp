// Fill out your copyright notice in the Description page of Project Settings.


#include "Ui/MenuHUD.h"


void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	InitUI();
}

void AMenuHUD::InitUI()
{
	currentMainMenu  = CreateWidget<UMainMenuWidget>(GetWorld(), mainMenuwidget);
	if (currentMainMenu)
	{
		currentMainMenu->AddToViewport();
	}
}