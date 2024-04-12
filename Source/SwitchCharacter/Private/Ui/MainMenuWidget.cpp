// Fill out your copyright notice in the Description page of Project Settings.


#include "Ui/MainMenuWidget.h"
#include <Utils/Util.h>
#include "Kismet/KismetSystemLibrary.h"
void UMainMenuWidget::InitBiding()
{
	playButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPlayButton);
	quitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitButton);
}

void UMainMenuWidget::NativeConstruct()
{
	//Super::NativeConstruct();

	Super::NativeConstruct();
	InitBiding();
}

void UMainMenuWidget::OnPlayButton()
{
	LOG("Lancement de la Partie ! ");
	LoadLevel();
}

void UMainMenuWidget::OnQuitButton()
{
	LOG("Au Revoir !");
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);

}

void UMainMenuWidget::LoadLevel()
{
	UGameplayStatics::OpenLevel(this, "LVL_Trap_Kit");

	// UGameplayStatics::
}
