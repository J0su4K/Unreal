// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPE/WorldGPE.h"
#include "HealthGPE.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API AHealthGPE : public AWorldGPE
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnConsumeHealth);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Health", meta = (UIMin = 0, ClampMin = 0)) int health = 100;

	UFUNCTION() void OnHealthBehaviour(UCharacterStatsComponent* _stats);

	void Init();


public:
	UPROPERTY(BlueprintAssignable) FOnConsumeHealth onConsumeHealth;

};
