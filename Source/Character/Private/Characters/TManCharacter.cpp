// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TManCharacter.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "SubSystems(Managers)/CharacterSubsystem.h"
#include <SubSystems(Managers)/PawnSubsystem.h>
#include <Utils/Util.h>
// Sets default values
ATManCharacter::ATManCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	springArm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
}

// Called when the game starts or when spawned
void ATManCharacter::BeginPlay()
{
	Super::BeginPlay();
	Register();
}

void ATManCharacter::InitInputSystem()
{
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _inputSystem = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>();
	if (_inputSystem)
	{
		_inputSystem->AddMappingContext(characterMapping, 0);
	}
}

void ATManCharacter::BindAction()
{
	TObjectPtr<UEnhancedInputComponent> _input = Cast<UEnhancedInputComponent>(GetWorld()->GetFirstPlayerController()->InputComponent);
	if (_input)
	{
		_input->BindAction(charMovement, ETriggerEvent::Triggered, this, &ATManCharacter::Move);
		_input->BindAction(charRotation, ETriggerEvent::Triggered, this, &ATManCharacter::Rotation);
		_input->BindAction(charJump, ETriggerEvent::Triggered, this, &ATManCharacter::Jumping);
		_input->BindAction(charSwitch, ETriggerEvent::Triggered, this, &ATManCharacter::SwitchCharacter);
	}
}

void ATManCharacter::Move(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddMovementInput(GetActorRightVector() * _axis.X + GetActorForwardVector() * _axis.Y);
}

void ATManCharacter::Rotation(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddControllerYawInput(_axis.X);
	AddControllerPitchInput(_axis.Y);
}

void ATManCharacter::Jumping()
{
	Jump();

	LOG("CA MARCHE ");

}

void ATManCharacter::SwitchCharacter()
{
	LOG("CA MARCHE ");
	TObjectPtr<UPawnSubsystem> _characterPawn = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();

	_characterPawn->SwitchPawn();
}


// Called every frame
void ATManCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATManCharacter::Register()
{
	TObjectPtr<UCharacterSubsystem> _characterManager = GetWorld()->GetGameInstance()->GetSubsystem<UCharacterSubsystem>();

	if (!_characterManager) return;

	_characterManager->AddNewCharacter(this);
}

// Called to bind functionality to input
void ATManCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InitInputSystem();
	BindAction();
}

