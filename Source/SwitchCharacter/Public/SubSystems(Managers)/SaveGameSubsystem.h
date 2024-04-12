// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <SaveData/Player/PlayerDataSave.h>
#include "SaveGameSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API USaveGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UPROPERTY() TObjectPtr<UPlayerDataSave> playerSave = nullptr;

public:
	FORCEINLINE TObjectPtr<UPlayerDataSave> GetPlayerSave() { return playerSave; }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	void SaveGame();
	void LoadGame();
};
