// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PossessTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API APossessTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "PawnControl ") FString SwitchToId = "";

	virtual void NotifyActorBeginOverlap(AActor* _origin) override;

	virtual void NotifyActorEndOverlap(AActor* _origin) override;


	
};
