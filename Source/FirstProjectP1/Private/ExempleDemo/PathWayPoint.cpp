// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/PathWayPoint.h"
#include "Util/Util.h"
// Sets default values
APathWayPoint::APathWayPoint()
{
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Root");
	RootComponent = icon;
}


void APathWayPoint::BeginPlay()
{
	Super::BeginPlay();
}


void APathWayPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DebugWayPoint();
}

void APathWayPoint::DebugWayPoint()
{
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(50), FColor::Emerald);
}

