// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <InputMappingContext.h>
#include "ControllerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SWITCHCHARACTER_API UControllerComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputMappingContext> characterMapping = nullptr;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> movement = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> rotation = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> jump = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charSwitch = nullptr;

public:	
	// Sets default values for this component's properties
	UControllerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
