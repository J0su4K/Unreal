// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Kismet/GameplayStatics.h"
#include <Actors/DoorSwitchActor.h>
#include "SwitchLevelTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API ASwitchLevelTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

	//UPROPERTY(EditAnywhere) Level
	UPROPERTY(EditAnywhere) FName nextLevelName;
	UPROPERTY(Editanywhere) TSubclassOf<ADoorSwitchActor> door = nullptr;
	
public:


private:

	virtual void BeginPlay() override;


	virtual void NotifyActorBeginOverlap(AActor* _origin) override;

	virtual void NotifyActorEndOverlap(AActor* _origin) override;


public:
	void InitTemporaryInput();

	void DeleteTemporaryInput();
	//virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

};
