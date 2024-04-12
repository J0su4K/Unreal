// Fill out your copyright notice in the Description page of Project Settings.


#include "Ui/ProgressWidget.h"
#include <Utils/Util.h>
#include <Characters/TManCharacter.h>

void UProgressWidget::InitBinding()
{
	TObjectPtr <ATManCharacter> _player = GetWorld()->GetFirstPlayerController()->GetPawn<ATManCharacter>();
	_player->GetStats()->onAddLife.AddDynamic(this, &UProgressWidget::OnLifeUpdate);
	_player->GetStats()->onDamage.AddDynamic(this, &UProgressWidget::OnDamageUpdate);
	// _player->GetStats()->onAddLife.AddDynamic(this, &UProgressWidget::OnUpdateLifeColor);
	onLifeBarUpdate.AddDynamic(this, &UProgressWidget::OnUpdateLifeColor);

}

void UProgressWidget::NativeConstruct()
{
	Super::NativeConstruct();
	InitBinding();
}

void UProgressWidget::OnLifeUpdate(const int& _life)
{
	const float _f = _life / 100.0f;
	healthBar->SetPercent(_f);

	onLifeBarUpdate.Broadcast(healthBar->Percent);
}

void UProgressWidget::OnDamageUpdate(const int& _life)
{
	const float _f = _life / 100.0f;
	healthBar->SetPercent(_f);

	// onLifeBarUpdate.Broadcast(healthBar->Percent);
}

void UProgressWidget::OnUpdateLifeColor(float _percent)
{
	healthBar->SetFillColorAndOpacity(FLinearColor::LerpUsingHSV(FLinearColor::Red, FLinearColor::Green, _percent));
}
