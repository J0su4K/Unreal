// Fill out your copyright notice in the Description page of Project Settings.


#include "GPE/HealthGPE.h"
#include <Utils/Util.h>

void AHealthGPE::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


void AHealthGPE::OnHealthBehaviour(UCharacterStatsComponent* _stats)
{
		if (_stats)
	{
		_stats->AddLife(100);
		LOG(FString::FromInt(_stats->GetLife()));

		onConsumeHealth.Broadcast();
		//Destroy();
		SetLifeSpan(0.2);
	}
}

void AHealthGPE::Init()
{
	onStatsOverLap.AddDynamic(this, &AHealthGPE::OnHealthBehaviour);
}
