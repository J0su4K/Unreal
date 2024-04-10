// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include <Pawns/FollowerPawn.h>
#include "AreaTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API AAreaTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<AFollowerPawn> spawnableSpawn = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<AFollowerPawn> currentPawn = nullptr;
	UPROPERTY(EditAnywhere) FString possessId;


	virtual void NotifyActorBeginOverlap(AActor* _origin) override;
	virtual void NotifyActorEndOverlap(AActor* _origin) override;


	void PossesIt();

	bool CreateFollowerPawn();
	void PossessDrone();

	void DestroyCurrentDrone();

	void SwitchToMainCharacter();
};
