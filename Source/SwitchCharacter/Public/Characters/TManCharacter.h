// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <InputMappingContext.h>
#include <Components/SwitchActorComponent.h>


#include "TManCharacter.generated.h"

UCLASS()
class SWITCHCHARACTER_API ATManCharacter : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)  TObjectPtr<UCameraComponent> camera;
	UPROPERTY(EditAnywhere)  TObjectPtr<USpringArmComponent> springArm;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputMappingContext> characterMapping = nullptr;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charMovement = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charRotation = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charJump = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charSwitch = nullptr;

	TObjectPtr<USwitchActorComponent> switchComponent = nullptr;

public:
	ATManCharacter();

protected:
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