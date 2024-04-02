// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/Components/PathMovementComponent.h"

UPathMovementComponent::UPathMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPathMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UPathMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPathMovementComponent::DoPath()
{
	for (int _i = 0; _i < points.Num(); _i++)
	{
		//GetOwner()->SetActorLocation(points[_i].Get()->GetActorLocation());
		SetDestination(points[_i].Get()->GetActorLocation());
	}

}

void UPathMovementComponent::ChangePoint()
{
	// points.
}

