// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include <Actors/TrapActor.h>

#include "TrapTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API ATrapTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TSubclassOf<ATrapActor> spawnableTrap = nullptr;
	
	// UPROPERTY(EditAnywhere , Category = "?") 

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* _origin) override;

	virtual void NotifyActorEndOverlap(AActor* _origin) override;
};
