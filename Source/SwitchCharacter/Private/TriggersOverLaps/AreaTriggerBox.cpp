// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggersOverLaps/AreaTriggerBox.h"
#include <SubSystems(Managers)/PawnSubsystem.h>
#include <Utils/Util.h>


void AAreaTriggerBox::NotifyActorBeginOverlap(AActor* _origin)
{
	//TObjectPtr<UPawnSubsystem> pawnManager = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();
	Super::NotifyActorBeginOverlap(_origin);
	if (CreateFollowerPawn())
	{
		PossessDrone();
	}
	else
	{
		LOG("???");
		DestroyCurrentDrone();
		SwitchToMainCharacter();
	}
}

void AAreaTriggerBox::NotifyActorEndOverlap(AActor* _origin)
{
	Super::NotifyActorEndOverlap(_origin);
	LOG("Remove");
	//GetWorld()->DestroyActor(currentPawn);
}

void AAreaTriggerBox::PossesIt()
{
	GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>()->SwitchTo(possessId);
}

bool AAreaTriggerBox::CreateFollowerPawn()
{
	if (currentPawn)
		return false;

	FActorSpawnParameters _param;
	_param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	currentPawn = GetWorld()->SpawnActor<AFollowerPawn>(spawnableSpawn, FVector(0, 0, 200), FRotator( 0,180,0) , _param);
	return true;
}

void AAreaTriggerBox::PossessDrone()
{
	if (!currentPawn)
		return;
	GetWorld()->GetFirstPlayerController()->Possess(currentPawn);
}

void AAreaTriggerBox::DestroyCurrentDrone()
{
	currentPawn->Destroy();
	currentPawn = nullptr;
}

void AAreaTriggerBox::SwitchToMainCharacter()
{
	GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>()->SwitchTo("Joueur");
	LOG("HIT");
}
