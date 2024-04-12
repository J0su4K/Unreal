// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DoorSwitchActor.h"

// Sets default values
ADoorSwitchActor::ADoorSwitchActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;

	mesh->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ADoorSwitchActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorSwitchActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

