// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggersOverLaps/HealTriggerBox.h"

void AHealTriggerBox::BeginPlay()
{
	currentKit = GetWorld()->SpawnActor<AKitActor>(kit, GetActorLocation(), FRotator());
}

void AHealTriggerBox::NotifyActorBeginOverlap(AActor* _origin)
{
	// Soigne le joueur 
	if (currentKit)
	{
		currentKit->Destroy();
	}
}

void AHealTriggerBox::NotifyActorEndOverlap(AActor* _origin)
{
	// Arrete de soigner le joueur
}

