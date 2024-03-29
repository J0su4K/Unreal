#include "ExempleDemo/MovingActor.h"
#include "Util/Util.h"
AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CREATE(USceneComponent, "Root");
}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	Init();
	MoveInstantTo();
}

void AMovingActor::Init()
{
	start = GetActorLocation();
	targetLocation = settings.GetTargetLocation();
}

void AMovingActor::MoveOnTick()
{
	if (isInstantMovement) return;
	progress += DELTATIME;
	progress = FMath::Clamp(progress, 0, 1);
	const FVector& _newLocation = FMath::Lerp(start, targetLocation, progress);
	SetActorLocation(_newLocation);
}

FColor AMovingActor::GetDebugLerpColor(const FColor& _startColor, const FColor& _endColor, const float _progress)
{

	/*FVector _vec =*/ //FMath::Lerp(_startColor, _endColor, 0.0f);

	FVector _colorA = FVector(_startColor.R, _startColor.G, _startColor.B);

	FVector _colorB = FVector(_endColor.R, _endColor.G, _endColor.B);
	
	FVector _degrade = FMath::Lerp(_colorA, _colorB, _progress);

	return FColor(_degrade.X , _degrade.Y , _degrade.Z);
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveOnTick();
	DrawDebugMovement();
	//MoveToTarget(DeltaTime);
}


void AMovingActor::MoveInstantTo()
{
	if (!isInstantMovement)
	{
		LOG_COLOR_TIME("INTANT MOVE : OFF", Red, 5);
		return;
	}
	SetActorLocation(settings.GetTargetLocation());
}

void AMovingActor::MoveToTarget(const float _deltaTime)
{
	//if()
	FVector _newLoc = FMath::Lerp(start, targetLocation, currentTime / maxTime);
	SetActorLocation(_newLoc);
	if (currentTime >= maxTime)
	{
		currentTime = maxTime;
	}


	currentTime += _deltaTime;
	//red--;
	//green++;

	//LOG(TO_STRING(green));
	//LOG(TO_STRING(_color));
	
	//DEBUG_LINE(GetActorLocation(), Green, -1, 0, 3);
}

void AMovingActor::DrawDebugMovement()
{
	//DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100), FColor::Emerald);
	DEBUG_BOX(100, Emerald);

	DEBUG_SPHERE(50, 10, Red);


	DRAW_SPHERE(GetActorLocation() + FVector(0.0f, 0.0f, 200), 10, GetDebugLerpColor(fromDebug, toDebug,progress), 3 );

	// DEBUG_LINE(targetLocation )
	//DEBUG_LINE(settings.GetTargetLocation(), Magenta, -1, 0, 3);
	//DEBUG_LINE_COLOR(red, green,0);


}
