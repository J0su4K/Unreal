// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CharacterStatsComponent.h"

UCharacterStatsComponent::UCharacterStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

int UCharacterStatsComponent::GetLife()
{
	return life;
}

bool UCharacterStatsComponent::IsDead()
{
	return life == 0;
}

void UCharacterStatsComponent::AddLife(const int& _life)
{
	life += _life;
	life = FMath::Clamp(life, 0, 100);
	onAddLife.Broadcast(life);
}

void UCharacterStatsComponent::SetLife(const int& _life)
{
	life = _life;
	life = FMath::Clamp(life, 0, 100);
}

void UCharacterStatsComponent::RegenLife()
{
	life = 100;
}

void UCharacterStatsComponent::SetDamage(int _damage)
{
	life -= _damage;
	life = FMath::Clamp(life, 0, 100);

	if (IsDead())
	{
		onDie.Broadcast();
	}
}
