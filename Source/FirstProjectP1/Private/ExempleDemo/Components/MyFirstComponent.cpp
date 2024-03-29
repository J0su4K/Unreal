// Fill out your copyright notice in the Description page of Project Settings.


#include "ExempleDemo/Components/MyFirstComponent.h"
#include "Util/Util.h"

// Sets default values for this component's properties
UMyFirstComponent::UMyFirstComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMyFirstComponent::BeginPlay()
{
	Super::BeginPlay();
	//LOG_COLOR_TIME("New Componenet MyFirst " + GetOwner()->GetActorLocation().ToString(), Red, 20.0f);
}


// Called every frame
void UMyFirstComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

