// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SwitchActorComponent.h"
#include <SubSystems(Managers)/PawnSubsystem.h>

// Sets default values for this component's properties
USwitchActorComponent::USwitchActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USwitchActorComponent::SwitchActor()
{
	TObjectPtr<UPawnSubsystem> _characterPawn = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();
	_characterPawn->SwitchPawn();
}


// Called when the game starts
void USwitchActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USwitchActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

