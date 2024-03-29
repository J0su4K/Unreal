// Fill out your copyright notice in the Description page of Project Settings.


#include "Voiture/BaseCar.h"
#include "Util/Util.h"

// Sets default values
ABaseCar::ABaseCar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CREATE(USceneComponent, "RootFCar"); // CreateDefaultSubObject<>

	movementComponent = CreateDefaultSubobject<UMyMovementComponent>("MovementComponent");
	AddOwnedComponent(movementComponent);
}

void ABaseCar::DriveTo(const FVector& _to)
{
	if (!movementComponent)
	{
		LOG_COLOR_TIME("RESTE CONCENTRER FREROT", Red, 5);
		return;
	}
	movementComponent->SetDestination(_to);
}

// Called when the game starts or when spawned
void ABaseCar::BeginPlay()
{
	Super::BeginPlay();
	LOG("New car : " + brand);
}

void ABaseCar::DrawDebugCar()
{
	DRAW_SPHERE(GetActorLocation(), 10, carColor, 2);
}



// Called every frame
void ABaseCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugCar();
}

