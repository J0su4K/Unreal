#include "Components/FollowActorComponent.h"
#include "Utils/Util.h"

UFollowActorComponent::UFollowActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFollowActorComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UFollowActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToDestination();
}

void UFollowActorComponent::SetDestination(const FVector& _destination)
{
	to = _destination;
}

void UFollowActorComponent::MoveToDestination()
{
	progress += DELTATIME * speed;
	progress = FMath::Clamp(progress, 0, 1);
	const FVector& _position = FMath::Lerp(from, to, progress);
	GetOwner()->SetActorLocation(_position);
}

void UFollowActorComponent::Init()
{
	from = GetOwner()->GetActorLocation();
}


