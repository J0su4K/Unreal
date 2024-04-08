// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggersOverLaps/PossessTriggerBox.h"
#include <Utils/Util.h>
#include "Pawns/FollowerPawn.h"
#include <SubSystems(Managers)/PawnSubsystem.h>

void APossessTriggerBox::NotifyActorBeginOverlap(AActor* _origin)
{

	Super::NotifyActorBeginOverlap(_origin);
	TObjectPtr<UPawnSubsystem> _pawn = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();

	_pawn->SwitchTo(SwitchToId);
	//TObjectPtr<AFollowerPawn> _pawn = Cast< AFollowerPawn>(_origin);
	//if (!_pawn)return;
	LOG(_origin->GetActorNameOrLabel() + "Enter in : " + GetActorNameOrLabel());
}

void APossessTriggerBox::NotifyActorEndOverlap(AActor* _origin)
{
	TObjectPtr<AFollowerPawn> _pawn = Cast< AFollowerPawn>(_origin);
	if (!_pawn)return;
	LOG(_origin->GetActorNameOrLabel() +  "Exit in : " + _origin->GetActorNameOrLabel());
}
