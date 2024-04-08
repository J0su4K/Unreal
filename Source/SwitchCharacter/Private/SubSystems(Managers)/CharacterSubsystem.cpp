// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems(Managers)/CharacterSubsystem.h"
#include <SubSystems(Managers)/PawnSubsystem.h>
#include <Utils/Util.h>

void UCharacterSubsystem::AddNewCharacter(TObjectPtr<ATManCharacter> _character)
{
	//LOG("Vous ajouter un character ");
	//characters.Add(_character);


	//TObjectPtr<UPawnSubsystem> _pawnManager = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();
	//if (!_pawnManager) return;
	//LOG("Vous ajouter aussi son Pawn ");
	//_pawnManager->AddPawn(_character);
}

void UCharacterSubsystem::RemoveAll()
{
	characters.Empty();
}
