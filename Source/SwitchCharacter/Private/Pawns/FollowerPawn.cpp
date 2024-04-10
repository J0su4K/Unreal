
#include "Pawns/FollowerPawn.h"
#include <SubSystems(Managers)/CharacterSubsystem.h>
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include <Utils/Util.h>

AFollowerPawn::AFollowerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	
	meshRoot = CreateDefaultSubobject<UStaticMeshComponent>("Root");

	RootComponent = meshRoot;

	//follow = CreateDefaultSubobject<UFollowActorComponent>("Follow");
	//AddOwnedComponent(follow);

	springArm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	floating = CreateDefaultSubobject<UFloatingPawnMovement>("Floating");
	AddOwnedComponent(floating);



	switcher = CreateDefaultSubobject<USwitchActorComponent>("Switcher");
	AddOwnedComponent(switcher);

	bUseControllerRotationYaw = true;
	//springArm_>bUs
}

void AFollowerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AFollowerPawn::InitInputSystem()
{
	// GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->ClearAllMapping

	//TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _inputSystem = GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	//if (_inputSystem)
	//{
	//_inputSystem->ClearAllMappings();
	//_inputSystem->AddMappingContext(pawnMapping, 0);
	//}
	GetWorld()->GetFirstPlayerController()->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()->AddMappingContext(pawnMapping, 0);
}

void AFollowerPawn::BindAction(class UInputComponent* PlayerInputComponent)
{
	TObjectPtr<UEnhancedInputComponent> _input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (_input)
	{
		_input->BindAction(movementAction, ETriggerEvent::Triggered, this, &AFollowerPawn::Move);
		_input->BindAction(rotationAction, ETriggerEvent::Triggered, this, &AFollowerPawn::Rotation);
		_input->BindAction(switchAction, ETriggerEvent::Started, switcher.Get(), &USwitchActorComponent::Switch);
	}
}

void AFollowerPawn::Move(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddMovementInput(GetActorRightVector() * _axis.X + GetActorForwardVector() * _axis.Y);
	isPossess = true;
	//LOG("SESE");
}

void AFollowerPawn::Rotation(const FInputActionInstance& _input)
{
	const FVector2D _axis = _input.GetValue().Get<FVector2D>();
	AddControllerYawInput(_axis.X);
	AddControllerPitchInput(_axis.Y);
	isPossess = true;
}

void AFollowerPawn::SwitchCharacter()
{

}

void AFollowerPawn::Follow()
{
	//if (isPossess) return;
	//TObjectPtr<UCharacterSubsystem> _characterManager = GetWorld()->GetGameInstance()->GetSubsystem<UCharacterSubsystem>();
	//TArray<TObjectPtr<ATManCharacter>> _characters = _characterManager->GetCharacters();
	//follow->SetDestination(_characters[0]->GetActorLocation() + range);
}

void AFollowerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Follow();
}

void AFollowerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InitInputSystem();
	BindAction(PlayerInputComponent);
}


