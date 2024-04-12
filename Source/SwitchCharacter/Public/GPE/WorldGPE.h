// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldGPE.generated.h"

UCLASS()
class SWITCHCHARACTER_API AWorldGPE : public AActor
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatsOverLap, UCharacterStatsComponent*, stats);
	UPROPERTY(EditAnywhere) TObjectPtr <UStaticMeshComponent> gpeMesh = nullptr;
protected:

	FOnStatsOverLap onStatsOverLap;
public:	
	AWorldGPE();

	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;



private:
	virtual void NotifyActorBeginOverlap(AActor* _origin) override;

	virtual void NotifyActorEndOverlap(AActor* _origin) override;
};
