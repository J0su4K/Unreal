// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProgressWidget.h"
#include "HoldingWidget.h"
#include "CharacterStatHUD.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API ACharacterStatHUD : public AHUD
{
	GENERATED_BODY()



	// UPROPERTY(EditAnywhere) TSubclassOf<UUserWidget> player = nullptr;

	UPROPERTY(EditAnywhere) TSubclassOf<UProgressWidget> progressWidget = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UProgressWidget> currentProgress = nullptr;


	UPROPERTY(EditAnywhere) TSubclassOf<UHoldingWidget> holdingWidget = nullptr;
	UPROPERTY(Editanywhere) TObjectPtr<UHoldingWidget> currentHolding = nullptr;


	FORCEINLINE TObjectPtr<UProgressWidget>  GetCurrentWidget() { return currentProgress; };


	void InitUI();

	virtual void BeginPlay() override;
};
