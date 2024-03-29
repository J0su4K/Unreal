// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.h"
#include "RefObject.generated.h"

UCLASS()
class FIRSTPROJECTP1_API ARefObject : public AActor
{
	GENERATED_BODY()
	
//	UPROPERTY(EditAnywhere) TObjectPtr<AActor> target = nullptr; //AActor* -> Reference vers un AActor dans le level (Intancié)


		// On fait reference vers un objet deja creer
	UPROPERTY(EditAnywhere) TObjectPtr<AActor> target = nullptr;


	//SubClass Actor
	// On fait reference vers un objet à creer (Sous classe de : )


	UPROPERTY(EditAnywhere) TSubclassOf<AMovingActor> subActor = nullptr;



public:	
	// Sets default values for this actor's properties
	ARefObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
