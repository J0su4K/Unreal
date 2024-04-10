// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PawnSubsystem.generated.h"

/**
 *
 */
UCLASS()
class SWITCHCHARACTER_API UPawnSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere) TArray<TObjectPtr<APawn>> pawns = {};

	UPROPERTY()  TMap<FString, TObjectPtr<APawn>> allControllablePawns = {};
	int indexPawn = 0;

public:
	FORCEINLINE  TArray<TObjectPtr<APawn>> GetPawn() const { return pawns; }
public:
	//void AddNewPawn(TObjectPtr<APawn> _pawns);

	void AddPawn(const FString& _key, TObjectPtr<APawn> _pawn);

	void SwitchTo(const FString& _key);

	void RemoveAll();

	void SwitchPawn();
};
