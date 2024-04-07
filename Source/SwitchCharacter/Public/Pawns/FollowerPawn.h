// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Components/FollowActorComponent.h>
#include "GamePawn.h"
#include <Camera/CameraComponent.h>
#include <InputMappingContext.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/FloatingPawnMovement.h>

#include "FollowerPawn.generated.h"

UCLASS()
class SWITCHCHARACTER_API AFollowerPawn : public AGamePawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Components") TObjectPtr<UFollowActorComponent> follow = nullptr;
	//UPROPERTY(EditAnywhere, Category = "Following") TObjectPtr<ATManCharacter> character = nullptr;

//	UPROPERTY(EditAnywhere, Category = "Following") TSubclassOf<ATManCharacter> character = nullptr;
	UPROPERTY(EditAnywhere) bool isPossess = false;
	UPROPERTY(EditAnywhere, Category = "Range", meta = (UIMin = 0, ClampMin = 0)) FVector range = FVector::Zero();

	UPROPERTY(EditAnywhere) TObjectPtr<UFloatingPawnMovement> floating;

	UPROPERTY(EditAnywhere)  TObjectPtr<UCameraComponent> camera;
	UPROPERTY(EditAnywhere)  TObjectPtr<USpringArmComponent> springArm;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputMappingContext> pawnMapping = nullptr;

	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charMovement = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charRotation = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charJump = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> charSwitch = nullptr;


public:

	AFollowerPawn();

protected:

	virtual void BeginPlay() override;

	virtual void InitInputSystem();
	virtual void BindAction();
	void Move(const FInputActionInstance& _input);
	void Rotation(const FInputActionInstance& _input);
	void Jumping();
	void SwitchCharacter();

	void Follow();
	//void Init();

public:

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};