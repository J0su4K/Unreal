// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/SpawnPawn.h"

// Sets default values
ASpawnPawn::ASpawnPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpawnPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

