// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPE/WorldGPE.h"
#include "TrapGPE.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API ATrapGPE : public AWorldGPE
{
	GENERATED_BODY()
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Trap Damage ", meta = (UIMin = 0, ClampMin = 0)) int damages = 10;

	UFUNCTION() void OnTrapBehaviour(UCharacterStatsComponent* _stats); 

	void Init();
};
