// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Voiture/BaseCar.h"
#include "Garage.generated.h"

UCLASS()
class FIRSTPROJECTP1_API AGarage : public AActor
{
	GENERATED_BODY()

	// On fait reference vers un objet à creer (Sous classe de : )
	UPROPERTY(EditAnywhere) TSubclassOf<ABaseCar> subCar = nullptr;

	UPROPERTY(EditAnywhere) TObjectPtr<USceneComponent> outPoint = nullptr;
public:	
	AGarage();

protected:
	virtual void BeginPlay() override;
	void CreateCar();
public:	
	virtual void Tick(float DeltaTime) override;
	void DrawDebugGarage();

};
