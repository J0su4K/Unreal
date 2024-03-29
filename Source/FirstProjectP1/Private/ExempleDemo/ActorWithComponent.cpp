// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/ActorWithComponent.h"

// Sets default values
AActorWithComponent::AActorWithComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	staticMesh->SetupAttachment(RootComponent);


	firstComponentExample = CreateDefaultSubobject<UMyFirstComponent>("first");
	AddOwnedComponent(firstComponentExample); // Pour setUP un componenet attacher a une classe creer .
}

// Called when the game starts or when spawned
void AActorWithComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AActorWithComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//CONSIGNE