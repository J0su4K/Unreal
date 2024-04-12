// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include "Kismet/GameplayStatics.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */

// Voici Comment creer un enum Unreal
UENUM()
enum EEnumExample
{
	FIRST,
	MIDDLE,
	LAST,

};
UCLASS()
class SWITCHCHARACTER_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	// Recuperer un bouton
	UPROPERTY(EditAnywhere , meta = (BindWidget)) TObjectPtr<UButton> playButton = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) TObjectPtr<UButton> quitButton = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidgetOptional)) TObjectPtr<UTextBlock> text = nullptr;
	// On créer le lien grâce a BindWidget
	// On peut anticiper un boutton grâce à BindWidgetOptional 


	// Voici comment afficher un enum
	UPROPERTY(EditAnywhere) TEnumAsByte<EEnumExample> myEnum = FIRST;
	

	void InitBiding();

	virtual void NativeConstruct() override;


	UFUNCTION() void  OnPlayButton();

	UFUNCTION() void  OnQuitButton();


	void LoadLevel();
};
