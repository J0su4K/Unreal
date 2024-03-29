// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/RefObject.h"
#include "Util/Util.h"
// Sets default values
ARefObject::ARefObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CREATE(USceneComponent, "Object");
}

// Called when the game starts or when spawned
void ARefObject::BeginPlay()
{
	Super::BeginPlay();
	target = GetWorld()->SpawnActor<AMovingActor>(subActor);
}

// Called every frame
void ARefObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

