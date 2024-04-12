


#include "GPE/WorldGPE.h"
#include "Components/CharacterStatsComponent.h"
#include <Utils/Util.h>

AWorldGPE::AWorldGPE()
{
	PrimaryActorTick.bCanEverTick = true;

	gpeMesh = CreateDefaultSubobject<UStaticMeshComponent>("GPE");
	RootComponent = gpeMesh;

	gpeMesh->SetGenerateOverlapEvents(true);
}

void AWorldGPE::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWorldGPE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWorldGPE::NotifyActorBeginOverlap(AActor* _origin)
{
	Super::NotifyActorBeginOverlap(_origin);

	TObjectPtr<UCharacterStatsComponent> _stats = _origin->GetComponentByClass<UCharacterStatsComponent>();
	if (!_stats) return;

	onStatsOverLap.Broadcast(_stats);
	LOG("OK");
}

void AWorldGPE::NotifyActorEndOverlap(AActor* _origin)
{

}

