// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyMovementComponent.h"
#include "ExempleDemo/Path.h"
#include "CorrPathMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIRSTPROJECTP1_API UCorrPathMovementComponent : public UMyMovementComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<APath> path = nullptr;

	UPROPERTY(VisibleAnywhere) int pathIndex = 0;

	UPROPERTY()  TObjectPtr<APathWayPoint> nextPoint = nullptr;

	UPROPERTY(EditAnywhere) int  range = 100;

//public:	
//	// Sets default values for this component's properties
//	//UCorrPathMovementComponent();

protected:
	virtual void MoveToDestination() override;
	virtual void DrawDestinationDebug() override;
};
