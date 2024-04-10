// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "ColorSwitchMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHCHARACTER_API AColorSwitchMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<AActor> otherActor = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UMaterialInstanceDynamic> dynamicMaterial = nullptr;
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime);

	

	void InitMaterial();

	void SwitchRandomColor();

};
