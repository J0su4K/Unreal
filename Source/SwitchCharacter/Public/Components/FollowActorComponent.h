// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SWITCHCHARACTER_API UFollowActorComponent : public UActorComponent
{
	GENERATED_BODY()

	FVector from, to;
	UPROPERTY(EditAnywhere, Category = "Stat") float speed = 0.5f;
	UPROPERTY(EditAnywhere, Category = "Stat") int range = 300.0f;
	UPROPERTY(VisibleAnywhere) float progress = 0.0f;

public:	
	// Sets default values for this component's properties
	UFollowActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void SetDestination(const FVector& _destination);
	virtual void MoveToDestination();

	void FollowTarget();
	virtual bool IsAtRange(const TObjectPtr<AActor> _actor) const;
	void Init();
};