// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <InputMappingContext.h>
#include "Components/SwitchActorComponent.h"
#include <Components/SwitchActorComponent.h>
#include <Components/CharacterStatsComponent.h>


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
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> switchAction = nullptr;
	UPROPERTY(EditAnywhere, Category = "Character Input") TObjectPtr<UInputAction> switchLevelAction = nullptr;

	FName levelName = "";

	TObjectPtr<UEnhancedInputComponent>  inputSwitch;

	UPROPERTY(EditAnywhere) TObjectPtr<USwitchActorComponent> switcher = nullptr;

	UPROPERTY(EditAnywhere, BluePrintReadWrite ,Category = "Character Stats" , meta = (AllowPrivateAccess)) TObjectPtr<UCharacterStatsComponent> stats = nullptr;


	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character Stats", meta = (AllowPrivateAccess)) int respawnTime = 5;
	

public:
	ATManCharacter();
	UFUNCTION(BluePrintPure) UCharacterStatsComponent* GetStats() { return stats;  };

	FORCEINLINE void SetLevelDestination(const FName& _newDestination) { levelName = _newDestination; };
protected:

	virtual void BeginPlay() override;
	virtual void InitInputSystem();
	virtual void BindAction();
	void Move(const FInputActionInstance& _input);
	void Rotation(const FInputActionInstance& _input);
	void Jumping();
	void SwitchCharacter();
	void UpdateTimer();
public:
	virtual void Tick(float DeltaTime) override;
	virtual void Register();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Init();
	void RespawnPlayer();
	void InitSwitchLevelInput();
	void DeleteSwitchLevelInput();
	void SwitchLevel();


	UFUNCTION() void OnDiePlayer();
	UFUNCTION() void OnStartRespawnPlayer();
	UFUNCTION() void SaveStats();
	UFUNCTION() void Reload();
	//UFUNCTION() void LostLife();
};