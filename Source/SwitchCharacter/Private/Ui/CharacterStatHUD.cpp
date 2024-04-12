// Fill out your copyright notice in the Description page of Project Settings.


#include "Ui/CharacterStatHUD.h"


void ACharacterStatHUD::BeginPlay()
{
	Super::BeginPlay();
	InitUI();


	
}

void ACharacterStatHUD::InitUI()
{
	currentProgress = CreateWidget<UProgressWidget>(GetWorld(), progressWidget);
	currentHolding = CreateWidget<UHoldingWidget>(GetWorld() /* changer le getworld */ , holdingWidget);
	if (currentProgress)
	{
		currentProgress->AddToViewport();
		currentHolding->AddToViewport();
	}

}