
#include "Pawns/FollowerPawn.h"
#include <SubSystems(Managers)/CharacterSubsystem.h>
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include <Utils/Util.h>

AFollowerPawn::AFollowerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	follow = CreateDefaultSubobject<UFollowActorComponent>("Follow");
	AddOwnedComponent(follow);

	springArm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	floating = CreateDefaultSubobject<UFloatingPawnMovement>("Floating");
	AddOwnedComponent(floating);
}

void AFollowerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AFollowerPawn::InitInputSystem()
{
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _inputSystem = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>();
	if (_inputSystem)
	{
		_inputSystem->AddMappingContext(pawnMapping, 0);
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
		_input->BindAction(charSwitch, ETriggerEvent::Completed, this, &AFollowerPawn::SwitchCharacter);
	}
}

void AFollowerPawn::Move(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddMovementInput(GetActorRightVector() * _axis.X + GetActorForwardVector() * _axis.Y);
	LOG("SESE");
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

void AFollowerPawn::Follow()
{
	// if (isPossess) return;
	TObjectPtr<UCharacterSubsystem> _characterManager = GetWorld()->GetGameInstance()->GetSubsystem<UCharacterSubsystem>();
	TArray<TObjectPtr<ATManCharacter>> _characters = _characterManager->GetCharacters();
	follow->SetDestination(_characters[0]->GetActorLocation() + range);
}

void AFollowerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Follow();
}

void AFollowerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InitInputSystem();
	BindAction();
}


