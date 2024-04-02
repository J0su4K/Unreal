// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "PathWayPoint.h"
#include "Path.generated.h"

UCLASS()
class FIRSTPROJECTP1_API APath : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TObjectPtr<UBillboardComponent> icon  = nullptr;

	UPROPERTY(EditAnywhere, Category = "Path|WayPoint") TArray<TObjectPtr<APathWayPoint>> points = {} ;

	UPROPERTY(EditAnywhere, Category = "Path|Settings") FString pathUniqueName = "Name ";

//	UPROPERTY(EditAnywhere, Category = "Path|Settings") FColor pathColor;

public:	
	APath();
	TObjectPtr< APathWayPoint> GetPointAt(const int _index);
	bool IsAtLocation(const int&  _index , const FVector& _from, const float& _range);
	bool IsAtLocation(const TObjectPtr<APathWayPoint> _point , const FVector& _from,  const float& _range);

protected:

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void DebugPath();
};
