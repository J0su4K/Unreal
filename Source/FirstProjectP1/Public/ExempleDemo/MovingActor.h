// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"


USTRUCT()
struct FTEST
{
	GENERATED_BODY()

	//UPROPERTY(EditAnywhere, Category = "CasseCouilles", meta = (EditCondition = "!isInstantMovement", UIMin = -2000, ClampMin = -2000, ClampMax = 2000, UIMax = 2000)) float x = 0;

	//UPROPERTY(EditAnywhere, Category = "CasseCouilles", meta = (EditCondition = "!isInstantMovement", UIMin = -2000, ClampMin = -2000, ClampMax = 2000, UIMax = 2000)) float y = 0;

	//UPROPERTY(EditAnywhere, Category = "CasseCouilles", meta = (EditCondition = "!isInstantMovement", UIMin = -2000, ClampMin = -2000, ClampMax = 2000, UIMax = 2000)) float z = 0;


	UPROPERTY(editanywhere, Category = "Movement||Settings") TObjectPtr<AActor>  target = nullptr;


	FORCEINLINE FVector GetTargetLocation() const { return target ? target->GetActorLocation() : FVector(0); };


	
};

UCLASS()
class FIRSTPROJECTP1_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Movement") bool isInstantMovement = false;
	//UPROPERTY(EditAnywhere, Category = "Movement|Settings", meta = (EditCondition = "!isInstantMovement" , UIMin= 0 , ClampMin = 0 , ClampMax = 25 , UIMax = 25)) float speed = 1.0f;
	//
	//UPROPERTY(EditAnywhere, Category = "Movement|Settings") FVector targetLocation;


	UPROPERTY(EditAnywhere, Category = "Movement|Settings") FTEST settings;


	UPROPERTY(editAnywhere, Category = "Temps") float currentTime = 0.0f;
	UPROPERTY(editAnywhere, Category = "Temps") float maxTime = 10.0f;


	UPROPERTY(editAnywhere, Category = "Location") FVector start = FVector(0, 0, 0);
	UPROPERTY(editAnywhere, Category = "Location") FVector targetLocation = FVector(0, 0, 0);

	UPROPERTY(editAnywhere, Category = "Color", meta = (UiMin = 0, UiMax = 128)) FColor fromDebug = FColor::Green;
	UPROPERTY(editAnywhere, Category = "Color", meta = (UiMin = 0, UiMax = 128)) FColor toDebug = FColor::Blue;


	float progress = 0.0f;
#pragma region FEUR




#pragma endregion
public:	
	// Sets default values for this actor's properties

	// Le FORCEINLINE est un accesseur 
	// En mode template ta capter 

	AMovingActor();

protected:
	void MoveInstantTo();
	void MoveToTarget(const float _deltaTime);
	void DrawDebugMovement();
	virtual void BeginPlay() override;
	void Init();

	void MoveOnTick();
	 
	FColor GetDebugLerpColor(const FColor& _startColor , const FColor& _endColor , const float _progress);
public:	
	virtual void Tick(float DeltaTime) override;

};
