// Fill out your copyright notice in the Description page of Project Settings.


#include "GPE/TrapGPE.h"
#include <Utils/Util.h>
#include <Components/ProgressBar.h>
void ATrapGPE::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


void ATrapGPE::OnTrapBehaviour(UCharacterStatsComponent* _stats)
{

	if (_stats)
	{
		_stats->SetDamage(damages);
		//LOG( FString::FromInt (_stats->GetDamage() ) ) ;
		LOG(FString::FromInt(_stats->GetLife()));

	}
}

void ATrapGPE::Init()
{
	onStatsOverLap.AddDynamic(this, &ATrapGPE::OnTrapBehaviour);
}
