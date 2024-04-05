// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/FollowerPawn.h"
#include <SubSystems(Managers)/CharacterSubsystem.h>
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>

// Sets default values
AFollowerPawn::AFollowerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	follow = CreateDefaultSubobject<UFollowActorComponent>("Follow");
	AddOwnedComponent(follow);


	springArm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

}

// Called when the game starts or when spawned
void AFollowerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AFollowerPawn::InitInputSystem()
{
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _inputSystem = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>();
	if (_inputSystem)
	{
		_inputSystem->AddMappingContext(characterMapping, 0);
	}
}

void AFollowerPawn::BindAction()
{
	TObjectPtr<UEnhancedInputComponent> _input = Cast<UEnhancedInputComponent>(GetWorld()->GetFirstPlayerController()->InputComponent);
	if (_input)
	{
		_input->BindAction(charMovement, ETriggerEvent::Triggered, this, &AFollowerPawn::Move);
		_input->BindAction(charRotation, ETriggerEvent::Triggered, this, &AFollowerPawn::Rotation);
		_input->BindAction(charJump, ETriggerEvent::Triggered, this, &AFollowerPawn::Jumping);
		_input->BindAction(charSwitch, ETriggerEvent::Triggered, this, &AFollowerPawn::SwitchCharacter);
	}
}

void AFollowerPawn::Move(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddMovementInput(GetActorRightVector() * _axis.X + GetActorForwardVector() * _axis.Y);
}

void AFollowerPawn::Rotation(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddControllerYawInput(_axis.X);
	AddControllerPitchInput(_axis.Y);
}

void AFollowerPawn::Jumping()
{
	//Jump();
}

void AFollowerPawn::SwitchCharacter()
{

}

// Called every frame
void AFollowerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//character->GetOwnerLocation();
	TObjectPtr<UCharacterSubsystem> _characterManager = GetWorld()->GetGameInstance()->GetSubsystem<UCharacterSubsystem>();
	TArray<TObjectPtr<ATManCharacter>> _characters = _characterManager->GetCharacters();
	follow->SetDestination(_characters[0]->GetActorLocation() + range);
}

// Called to bind functionality to input
void AFollowerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

