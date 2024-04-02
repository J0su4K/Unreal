// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/Components/CorrPathMovementComponent.h"
#include <Util/Util.h>

void UCorrPathMovementComponent::MoveToDestination()
{
	
	if (!path) return;
	//path->GetPointAt(pathIndex);

	nextPoint = path->GetPointAt(pathIndex);
	if (!nextPoint) 
		return;
	//LOG(FString::FromInt(pathIndex ));
	//return;
	SetDestination(nextPoint->GetActorLocation());

	if (path->IsAtLocation(nextPoint, GetOwner()->GetActorLocation(), range))
	{
		pathIndex++;
		return;
	}
	const FVector& _direction = FMath::Lerp(GetOwner()->GetActorLocation(), destination, GetWorld()->DeltaTimeSeconds * speed); // Bon effet de camera

	GetOwner()->SetActorLocation(_direction);
}

void UCorrPathMovementComponent::DrawDestinationDebug()
{
	Super::DrawDestinationDebug();
}


