// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/Path.h"
#include "Util/Util.h"
// Sets default values
APath::APath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Root");
	RootComponent = icon;
}

TObjectPtr<APathWayPoint> APath::GetPointAt(const int _index)
{
	if (points.IsEmpty())
		return nullptr;

	if (_index < 0)
		return points[0];
	else if (_index > points.Num() - 1) 
		return points.Last();
	return points[_index];
}

// Called when the game starts or when spawned
void APath::BeginPlay()
{
	Super::BeginPlay();
}


bool APath::IsAtLocation(const int& _index, const FVector& _from, const float& _range) 
{
	return IsAtLocation(GetPointAt(_index), _from, _range);
}


bool APath::IsAtLocation(const TObjectPtr<APathWayPoint> _point, const FVector& _from, const float& _range) 
{
	return _point ? FVector::Distance(_point->GetActorLocation(), _from) < _range : false;
}



// Called every frame
void APath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DebugPath();
}

void APath::DebugPath()
{
	for (size_t _i = 0; _i < points.Num()-1; _i++)
	{
		DRAW_LINE(points[_i]->GetActorLocation(), points[_i + 1]->GetActorLocation(), Red ,3);
	}
}

