// Fill out your copyright notice in the Description page of Project Settings.


#include "Garage/Garage.h"
#include "Util/Util.h"

AGarage::AGarage()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("root");

	outPoint = CreateDefaultSubobject<USceneComponent>("outPoint");
	outPoint->SetupAttachment(RootComponent);
}

void AGarage::BeginPlay()
{
	Super::BeginPlay();
	LOG_COLOR_TIME("OutPoint Location : " + outPoint->GetComponentLocation().ToString() , Green , 20);
	CreateCar();
}

void AGarage::CreateCar()
{
	if (!subCar)
	{
		LOG_COLOR_TIME("MISSING CAR MODEL " + GetActorLabel() , Red , 10);
		return;
	}
	TObjectPtr<ABaseCar> _currenCar = GetWorld()->SpawnActor<ABaseCar>(subCar, GetActorLocation(), FRotator());
//	return;
	if (_currenCar)
	{
		_currenCar->DriveTo(outPoint->GetComponentLocation());
	}
}

void AGarage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugGarage();
}

void AGarage::DrawDebugGarage()
{
	DRAW_LINE(GetActorLocation(), outPoint->GetComponentLocation(),Red ,3);

	//const FVector& _to = outPoint->GetComponentLocation();
	//DRAW_BOX(_to, 50, Cyan, 3);
	//DRAW_BOX(GetActorLocation(), 100, Yellow, 2);

}

