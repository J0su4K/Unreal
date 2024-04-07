// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GamePawn.generated.h"

UCLASS()
class SWITCHCHARACTER_API AGamePawn : public APawn
{
	GENERATED_BODY()

public:
	AGamePawn();
protected:
	virtual void BeginPlay() override;
	virtual void Register();
public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};