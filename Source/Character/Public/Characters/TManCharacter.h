// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <InputMappingContext.h>


#include "TManCharacter.generated.h"

UCLASS()
class CHARACTER_API ATManCharacter : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)  TObjectPtr<UCameraComponent> camera;
	UPROPERTY(EditAnywhere)  TObjectPtr<USpringArmComponent> springArm;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputMappingContext> characterMapping = nullptr;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charMovement = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charRotation = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charJump = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charSwitch = nullptr;

public:
	// Sets default values for this character's properties
	ATManCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void InitInputSystem();
	virtual void BindAction(); 
	void Move(const FInputActionInstance& _input);
	void Rotation(const FInputActionInstance& _input);
	void Jumping();
	void SwitchCharacter();

public:	

	virtual void Tick(float DeltaTime) override;
	virtual void Register();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
