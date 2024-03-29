// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExempleDemo/Components/MyMovementComponent.h"
#include "BaseCar.generated.h"

UCLASS()
class FIRSTPROJECTP1_API ABaseCar : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Voiture") FString brand = "NoName";
	UPROPERTY(EditAnywhere, Category = "Voiture") FColor carColor = FColor::Black;

	UPROPERTY(EditAnywhere) TObjectPtr<UMyMovementComponent> movementComponent = nullptr;

public:	
	ABaseCar();
	virtual void DriveTo(const FVector& _to);
protected:

	virtual void BeginPlay() override;
	void DrawDebugCar();
public:	
	virtual void Tick(float DeltaTime) override;
};
