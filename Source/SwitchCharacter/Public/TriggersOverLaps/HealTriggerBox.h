// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include <Actors/KitActor.h>
#include "HealTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API AHealTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TSubclassOf<AKitActor> kit = nullptr;
	UPROPERTY() TObjectPtr<AKitActor> currentKit = nullptr;

	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* _origin) override;
	virtual void NotifyActorEndOverlap(AActor* _origin) override;
};
