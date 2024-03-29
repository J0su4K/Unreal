// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/FirstActor.h"

#include "Util/Util.h"

// Sets default values
AFirstActor::AFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CREATE(USceneComponent, "Root");

}

// Called when the game starts or when spawned
void AFirstActor::BeginPlay()
{
	Super::BeginPlay();
	//UKismetSystemLibrary::PrintString(this, "Pepito" , true , true , FLinearColor::Blue , 10.0f);
	UKismetSystemLibrary::PrintString(this, TO_STRING(speed), true, true, FLinearColor::Blue, 10.0f);
	//MoveActor();
	LOG("Pepito");

	LOG_COLOR("Pepitooo", Red);

	LOG_COLOR_TIME("Bienvenue a Shrek City ", Yellow, 8);

	if (useTP)
	{
		MoveActor();
	}
	start = GetActorLocation();
}

// Called every frame
void AFirstActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (!useTP) return;
	Lerp(_deltaTime);
}

void AFirstActor::Teleportation()
{
	SetActorLocation(test);
	currentTime++;
}



void AFirstActor::Lerp(const float _deltaTime)
{
	
	const FVector _newLoc = FMath::Lerp(start, targetLocation, currentTime / maxTime);
	SetActorLocation(_newLoc);
	if (currentTime >= maxTime)
	{
		currentTime = maxTime;
	}
	currentTime += _deltaTime;
}

void AFirstActor::MoveActor()
{
	//UE::ToolTarget::ApplyIncrementalMeshEditChange
	
	//ApplyWorldOffset(test,true);
	//SetReplicatedMovement(,)
	// Le troisième param est dans le temps .

}

