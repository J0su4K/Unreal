// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SwitchActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SWITCHCHARACTER_API USwitchActorComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere , Category = "Pawn control unique name ") FString nameId = "Pawn";
	UPROPERTY(EditAnywhere, Category = "Pawn control unique name ") FString SwitchToId = "";

public:	
	// Sets default values for this component's properties
	USwitchActorComponent();

	void SwitchActor();

	void Register();



	void Switch();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
