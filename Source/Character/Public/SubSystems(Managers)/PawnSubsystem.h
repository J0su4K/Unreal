// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PawnSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTER_API UPawnSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere) TArray<TObjectPtr<APawn>> pawns = {};
	int indexPawn = 0;

public:
	FORCEINLINE  TArray<TObjectPtr<APawn>> GetPawn() const { return pawns; }
public:
	void AddNewPawn(TObjectPtr<APawn> _pawns);
	void RemoveAll();

	void SwitchPawn();
};
