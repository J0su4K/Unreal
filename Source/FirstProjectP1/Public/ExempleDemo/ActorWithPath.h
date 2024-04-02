// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PathMovementComponent.h"
#include "ActorWithPath.generated.h"

UCLASS()
class FIRSTPROJECTP1_API AActorWithPath : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TObjectPtr<UPathMovementComponent> path = nullptr;
public:	
	// Sets default values for this actor's properties
	AActorWithPath();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetPath();

};
