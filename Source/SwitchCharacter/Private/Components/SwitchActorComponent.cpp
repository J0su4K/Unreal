// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/SwitchActorComponent.h"
#include <SubSystems(Managers)/PawnSubsystem.h>
#include <Utils/Util.h>

// Sets default values for this component's properties
USwitchActorComponent::USwitchActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//void USwitchActorComponent::SwitchActor()
//{
//	TObjectPtr<UPawnSubsystem> _characterPawn = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();
//	_characterPawn->SwitchPawn();
//}

void USwitchActorComponent::Register()
{
	TObjectPtr<APawn> _pawn = Cast < APawn > (GetOwner());
	if (!_pawn)return;
	LOG("ADD");
	GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>()->AddPawn(nameId , _pawn);
}


void USwitchActorComponent::Switch()
{
	GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>()->SwitchTo(SwitchToId);
}

void USwitchActorComponent::BeginPlay()
{
	Super::BeginPlay();
	Register();
}


void USwitchActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

