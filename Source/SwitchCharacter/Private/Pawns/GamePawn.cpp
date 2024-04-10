// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/GamePawn.h"
#include <SubSystems(Managers)/PawnSubsystem.h>

// Sets default values
AGamePawn::AGamePawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGamePawn::BeginPlay()
{
	Super::BeginPlay();
	Register();
}

void AGamePawn::Register()
{
	TObjectPtr<UPawnSubsystem> _characterManager = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();

	if (!_characterManager) return;

	//_characterManager->AddPawn(this);
}

// Called every frame
void AGamePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
