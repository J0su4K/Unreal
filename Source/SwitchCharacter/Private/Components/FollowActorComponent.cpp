#include "Components/FollowActorComponent.h"
#include "Utils/Util.h"

UFollowActorComponent::UFollowActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFollowActorComponent::BeginPlay()
{
	Super::BeginPlay();
	//Init();
}

void UFollowActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FollowTarget();
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

void UFollowActorComponent::FollowTarget()
{
	TObjectPtr<APawn> _pawnOwner = Cast<APawn>(GetOwner());
	TObjectPtr<APawn> _targetPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!_pawnOwner || _pawnOwner->IsControlled() || !_targetPawn)
	{
		return;

	}
	if (IsAtRange(_targetPawn)) return;
	const FVector& _targetLocation = _targetPawn->GetActorLocation();
	const FVector& _finalLocation = FMath::Lerp(_pawnOwner->GetActorLocation(), _targetLocation, GetWorld()->DeltaTimeSeconds);
	_pawnOwner->SetActorLocation(_finalLocation);
}

bool UFollowActorComponent::IsAtRange(const TObjectPtr<AActor> _actor) const
{
	return _actor->GetDistanceTo(GetOwner()) < range;
}




void UFollowActorComponent::Init()
{
	from = GetOwner()->GetActorLocation();
}


