// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/MyFirstComponent.h"
#include "ActorWithComponent.generated.h"

UCLASS()
class FIRSTPROJECTP1_API AActorWithComponent : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<UStaticMeshComponent> staticMesh = nullptr;

	UPROPERTY(EditAnywhere) TObjectPtr<UMyFirstComponent> firstComponentExample = nullptr;
public:	
	// Sets default values for this actor's properties
	AActorWithComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
