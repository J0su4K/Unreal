// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ExempleDemo/Components/MyMovementComponent.h"
#include "ExempleDemo/PathWayPoint.h"
#include "PathMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJECTP1_API UPathMovementComponent : public UMyMovementComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TArray<TObjectPtr<APathWayPoint>> points;


	UPROPERTY()  TObjectPtr<APathWayPoint> nextPoint = nullptr;

	int index = 0;
	// UPROPERTY();
public:	
	// Sets default values for this component's properties
	UPathMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	void DoPath();

	void ChangePoint();
};
