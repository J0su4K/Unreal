// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include <Components/CharacterStatsComponent.h>
#include "PlayerDataSave.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API UPlayerDataSave : public USaveGame
{
	GENERATED_BODY()
	
	UPROPERTY() int playerLife = 0;
public:
	void SavePlayerStats(TObjectPtr<UCharacterStatsComponent> _stats);
	void SetPlayerStat(TObjectPtr<UCharacterStatsComponent> _stats);
};
