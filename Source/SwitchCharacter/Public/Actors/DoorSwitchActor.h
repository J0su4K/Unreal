// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorSwitchActor.generated.h"

UCLASS()
class SWITCHCHARACTER_API ADoorSwitchActor : public AActor
{
	GENERATED_BODY()
	UPROPERTY(Editanywhere) TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:	
	// Sets default values for this actor's properties
	ADoorSwitchActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
