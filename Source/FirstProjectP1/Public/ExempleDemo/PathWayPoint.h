// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "PathWayPoint.generated.h"

UCLASS()
class FIRSTPROJECTP1_API APathWayPoint : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TObjectPtr<UBillboardComponent> icon;
public:	
	// Sets default values for this actor's properties
	APathWayPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void DebugWayPoint();
};
