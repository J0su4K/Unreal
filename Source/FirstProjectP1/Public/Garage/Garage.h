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

	UPROPERTY(EditAnywhere , Category = "Spawn settings|Timer" , meta = (UIMin = 1.0f  , ClampMin = 1.0f)) float maxTimeValue = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Spawn settings", meta = (UIMin = 1.0f, ClampMin = 1.0f)) float maxCar  = 10;

	UPROPERTY(VisibleAnywhere , Category = "Spawn") TArray<TObjectPtr<ABaseCar>> cars = {};

	FTimerHandle  createCarTimer; // Pour creer un timer on utilise "FTimerHandle" 

	float timer = 0.0f;
	bool reachLimit = false;


public:	
	AGarage();
	FORCEINLINE bool CanProduceCar() const { return cars.Num() < maxCar;}
protected:
	virtual void BeginPlay() override;
	//void CreateCar();
	TObjectPtr<ABaseCar> CreateCar();
public:	
	virtual void Tick(float DeltaTime) override;
	void UpdateTimer();
	void DrawDebugGarage();
	void UpdateTimerC(float& _timer, const float _max);
	void OnTimerUp(); // Methode de correction 
};
