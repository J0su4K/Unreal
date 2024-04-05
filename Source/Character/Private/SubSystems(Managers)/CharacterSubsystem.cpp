// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems(Managers)/CharacterSubsystem.h"

void UCharacterSubsystem::AddNewCharacter(TObjectPtr<ATManCharacter> _character)
{
	characters.Add(_character);
}

void UCharacterSubsystem::RemoveAll()
{
	characters.Empty();
}
