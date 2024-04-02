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
	GetWorldTimerManager().SetTimer(createCarTimer, this ,&AGarage::OnTimerUp , maxTimeValue , true); // On ne peut pas changer une donner sur un timer en cours , il faut d'abord l'arreter puis le redemarrrer !
}

//void AGarage::CreateCar()
//{
//	if (!subCar)
//	{
//		LOG_COLOR_TIME("MISSING CAR MODEL " + GetActorLabel() , Red , 10);
//		return;
//	}
//	TObjectPtr<ABaseCar> _currenCar = GetWorld()->SpawnActor<ABaseCar>(subCar, GetActorLocation(), FRotator());
//	if (cars.Num() >= 5)
//	{
//		reachLimit = true;
//		return ;
//	}
//	if (_currenCar)
//	{
//		_currenCar->DriveTo(outPoint->GetComponentLocation());
//	}
//	cars.Add(_currenCar);
//	LOG("CAR ADDED " + FString::FromInt(cars.Num()));
//}

TObjectPtr<ABaseCar> AGarage::CreateCar()
{
	if (!subCar)
	{
		LOG_COLOR_TIME("MISSING CAR MODEL " + GetActorLabel(), Red, 10);
		return nullptr;
	}
	TObjectPtr<ABaseCar> _currenCar = GetWorld()->SpawnActor<ABaseCar>(subCar, GetActorLocation(), FRotator());

	// ABaseCar::StaticClass() Permet de nous retourner la classe 
	if (_currenCar)
	{
		_currenCar->DriveTo(outPoint->GetComponentLocation());
	}
		return _currenCar;
}

void AGarage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugGarage();
}

//void AGarage::UpdateTimer()
//{
//	timer += DELTATIME;
//	if (timer > 1)
//	{
//		timer = 0.0f;
//		if (reachLimit) return;
//		CreateCar();
//	}
//}

void AGarage::DrawDebugGarage()
{
	DRAW_LINE(GetActorLocation(), outPoint->GetComponentLocation(),Red ,3);
}

//void AGarage::UpdateTimerC(float& _timer, const float _max)
//{
//	_timer += DELTATIME;
//	if (_timer > _max)
//	{
//		OnTimerUp();
//		_timer = 0;
//	}
//}

void AGarage::OnTimerUp()
{
	if (CanProduceCar())
	{
		cars.Add(CreateCar()); 
	}
}
