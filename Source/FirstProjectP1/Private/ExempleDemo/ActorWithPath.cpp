// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/ActorWithPath.h"

// Sets default values
AActorWithPath::AActorWithPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	path = CreateDefaultSubobject<UPathMovementComponent>("Path");
	AddOwnedComponent(path);
}

// Called when the game starts or when spawned
void AActorWithPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorWithPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetPath();
}

void AActorWithPath::SetPath()
{
	path->DoPath();
}

