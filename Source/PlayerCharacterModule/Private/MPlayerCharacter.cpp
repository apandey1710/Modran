#include "MPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "MPlayerController.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMPlayerCharacter::AMPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);
	// ACharacter::GetMovementComponent()

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	
}

void AMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AMPlayerController* PlayerController = Cast<AMPlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
	
}

void AMPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if(ensure(IsValid(EnhancedInputComponent)))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMPlayerCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMPlayerCharacter::Look);
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
}

void AMPlayerCharacter::Move(const FInputActionValue& Value)
{
	FVector2d Movement = Value.Get<FVector2d>();
	
	if(ensure(IsValid(Controller)))
	{
		const FRotator MovementRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

		const FVector ForwardDirection = FRotationMatrix(MovementRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(MovementRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, Movement.Y);
		AddControllerYawInput(Movement.X);
		AddMovementInput(RightDirection, Movement.X);
	}
}

void AMPlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2d LookVector = Value.Get<FVector2d>();

	if(ensure(IsValid(Controller)))
	{
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}
}
