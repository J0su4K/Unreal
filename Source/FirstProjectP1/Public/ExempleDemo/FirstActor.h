// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FirstActor.generated.h"

UCLASS()
class FIRSTPROJECTP1_API AFirstActor : public AActor
{
	GENERATED_BODY()
	
	//UPROPERTY() AActor* target = nullptr;

	UPROPERTY(EditAnywhere, Category = "Stats|Speed" , meta=(UIMin=0 , UIMax=5 , ClamMin=0 , ClampMax=5)) float speed = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Stats|Strenght") float strenght = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Test") FVector test = FVector(0,100,0);
	UPROPERTY(EditAnywhere, Category = "Test") FVector targetLocation = FVector::ZeroVector;

	UPROPERTY(Editanywhere) float currentTime = 0.0f;

	UPROPERTY(Editanywhere) float maxTime  = 6.0f;

	UPROPERTY(Editanywhere) bool useTP = true;
	
	UPROPERTY(Editanywhere) FVector start = FVector::ZeroVector;
public:	
	// Sets default values for this actor's properties
	AFirstActor(); //RunType et editor

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; // RunType

public:	
	// Called every frame
	virtual void Tick(const float _deltaTime) override; // RunType

	void Teleportation();



	void Lerp(const float _deltaTime);
	void MoveActor();
};
