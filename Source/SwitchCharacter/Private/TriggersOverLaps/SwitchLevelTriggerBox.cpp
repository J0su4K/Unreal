// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggersOverLaps/SwitchLevelTriggerBox.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Characters/TManCharacter.h>
#include <Utils/Util.h>


void ASwitchLevelTriggerBox::BeginPlay()
{
//	Super::BeginPlay();
	GetWorld()->SpawnActor<ADoorSwitchActor>(door, GetActorLocation(), FRotator());



}
void ASwitchLevelTriggerBox::NotifyActorBeginOverlap(AActor* _origin)
{
	//UGameplayStatics::
	TObjectPtr <ATManCharacter> _player = GetWorld()->GetFirstPlayerController()->GetPawn<ATManCharacter>();

	if (!_player)
	return;
	_player->SetLevelDestination(nextLevelName);
	_player->InitSwitchLevelInput();
	//_player->SwitchLevel();
	//FString _levelName = FString<FName>FName(nextLevelName);

//	FString _levelName = FName::AppendString(nextLevelName);



	LOG("cette porte vous emmene vers " );
}


void ASwitchLevelTriggerBox::NotifyActorEndOverlap(AActor* _origin)
{
	TObjectPtr <ATManCharacter> _player = GetWorld()->GetFirstPlayerController()->GetPawn<ATManCharacter>();

	if (!_player)
		return;
	_player->DeleteSwitchLevelInput();

}