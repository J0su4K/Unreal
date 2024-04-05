// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <Characters/TManCharacter.h>
#include "CharacterSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTER_API UCharacterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere) TArray<TObjectPtr<ATManCharacter>> characters = {};

public:
	FORCEINLINE  TArray<TObjectPtr<ATManCharacter>> GetCharacters() const { return characters; }
public:
	void AddNewCharacter(TObjectPtr<ATManCharacter> _character);
	void RemoveAll();
};
