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
	onAddLife.Broadcast(life);
	onStatUpdate.Broadcast();
	life = FMath::Clamp(life, 0, 100);
}

void UCharacterStatsComponent::SetLife(const int& _life)
{
	life = _life;
	life = FMath::Clamp(life, 0, 100);
	onStatUpdate.Broadcast();
	onAddLife.Broadcast(life);
}

void UCharacterStatsComponent::RegenLife()
{
	life = 100;
	onAddLife.Broadcast(life);
	onStatUpdate.Broadcast();
}

void UCharacterStatsComponent::SetDamage(int _damage)
{
	life -= _damage;
	life = FMath::Clamp(life, 0, 100);
	onDamage.Broadcast(life);
	onStatUpdate.Broadcast();
	if (IsDead())
	{
		onDie.Broadcast();
		return;
	}
}
