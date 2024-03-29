
#include "ExempleDemo/Components/MyMovementComponent.h"
#include "Util/Util.h"
UMyMovementComponent::UMyMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMyMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}



void UMyMovementComponent::Init()
{
	from = GetOwner()->GetActorLocation();
}

void UMyMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToDestination();
	DrawDestinationDebug();
}

void UMyMovementComponent::SetDestination(const FVector& _destination)
{
	destination = _destination;
	LOG_COLOR_TIME("Destination Set : " + destination.ToString(), Red, 6);
}

void UMyMovementComponent::MoveToDestination()
{
	// LA BASE DE L'ALGO
	progress += DELTATIME * speed;
	progress = FMath::Clamp(progress, 1, 0);
	const FVector& _position = FMath::Lerp(from, destination, progress);
	GetOwner()->SetActorLocation(_position);
}

void UMyMovementComponent::DrawDestinationDebug()
{
	DRAW_LINE(GetOwner()->GetActorLocation(), destination, FColor::Magenta, 3);
	DRAW_SPHERE(destination, 20, FColor::Blue, 3);
}

