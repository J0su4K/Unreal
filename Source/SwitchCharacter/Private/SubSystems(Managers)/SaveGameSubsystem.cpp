// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems(Managers)/SaveGameSubsystem.h"
#include <Utils/Util.h>
#include "Kismet/GameplayStatics.h"
void USaveGameSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	playerSave = NewObject<UPlayerDataSave>(this);
	LOG("Auto Save INIT");
}

void USaveGameSubsystem::SaveGame()
{
	//playerSave->SetPla
	UGameplayStatics::SaveGameToSlot(playerSave, "PlayerGameData", 0);
}

void USaveGameSubsystem::LoadGame()
{
	TObjectPtr<USaveGame> _save = UGameplayStatics::LoadGameFromSlot("PlayerGameData", 0);
	if (!_save) return;

	playerSave = Cast<UPlayerDataSave>(_save);


}
