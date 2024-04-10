// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggersOverLaps/TrapTriggerBox.h"

void ATrapTriggerBox::Tick(float DeltaTime)
{

}

void ATrapTriggerBox::BeginPlay()
{
	TObjectPtr<ATrapActor> _trap = GetWorld()->SpawnActor<ATrapActor>(spawnableTrap , GetActorLocation() , FRotator() );
}

void ATrapTriggerBox::NotifyActorBeginOverlap(AActor* _origin)
{
	// Inflige des degat

	_origin = GetWorld()->GetFirstPlayerController();

	
}

void ATrapTriggerBox::NotifyActorEndOverlap(AActor* _origin)
{
	// Arrete d'infliger des degats 
}
