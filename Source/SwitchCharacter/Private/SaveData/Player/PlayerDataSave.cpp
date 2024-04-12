// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveData/Player/PlayerDataSave.h"

void UPlayerDataSave::SavePlayerStats(TObjectPtr<UCharacterStatsComponent> _stats)
{
	playerLife = _stats->GetLife();
}

void UPlayerDataSave::SetPlayerStat(TObjectPtr<UCharacterStatsComponent> _stats)
{

	_stats->SetLife(playerLife);
}
