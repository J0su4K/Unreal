// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/KitActor.h"

// Sets default values
AKitActor::AKitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKitActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//SetActorRotation(,);
}

