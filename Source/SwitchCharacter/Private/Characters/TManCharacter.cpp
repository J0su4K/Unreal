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


	switcher = CreateDefaultSubobject<USwitchActorComponent>("Switcher");
	AddOwnedComponent(switcher);


	stats = CreateDefaultSubobject<UCharacterStatsComponent>("Stats");

	AddOwnedComponent(stats);
}

//UCharacterStatsComponent* ATManCharacter::GetStats()
//{
//	return stats;
//}


// Called when the game starts or when spawned
void ATManCharacter::BeginPlay()
{
	Super::BeginPlay();
	Register();
	Init();
}

//TObjectPtr<UCharacterStatsComponent> ATManCharacter::GetStats()
//{
//	return stats;
//}

void ATManCharacter::InitInputSystem()
{
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _inputSystem = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem< UEnhancedInputLocalPlayerSubsystem>();
	if (_inputSystem)
	{
		_inputSystem->ClearAllMappings();
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
		//_input->BindAction(charSwitch, ETriggerEvent::Triggered , switchComponent, &USwitchActorComponent::SwitchActor);
		_input->BindAction(switchAction, ETriggerEvent::Started, switcher.Get(), &USwitchActorComponent::Switch);
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
}

void ATManCharacter::SwitchCharacter()
{
	//LOG("CA MARCHE ");
	//TObjectPtr<UPawnSubsystem> _characterPawn = GetWorld()->GetGameInstance()->GetSubsystem<UPawnSubsystem>();

	//_characterPawn->SwitchPawn();

//	switchComponent->SwitchActor();
}

void ATManCharacter::UpdateTimer()
{
	//timer  DELTATIME;
}


// Called every frame
void ATManCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//LOG_COLOR_TIME("OK" , Red , 1.0);
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

void ATManCharacter::Init()
{
	if (stats)
	{
		stats->onDie.AddDynamic(this, &ATManCharacter::OnDiePlayer);
	}
}

void ATManCharacter::OnDiePlayer()
{
	GetWorld()->GetFirstPlayerController()->DisableInput(Cast<APlayerController>(GetController()));
}


