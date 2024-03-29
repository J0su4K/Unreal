// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include <xkeycheck.h>
#include "MyMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJECTP1_API UMyMovementComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere , Category = "Stat") float speed = 0.0f;
	UPROPERTY(EditAnywhere) float progress = 0.0f;
	FVector from, destination;


public:	
	UMyMovementComponent();
	virtual void SetDestination(const FVector& _destination);

protected:
	virtual void BeginPlay() override;
public:	
	void Init();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveToDestination();
	void DrawDestinationDebug();
};
