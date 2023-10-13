#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MPlayerCharacter.generated.h"

UCLASS()
class PLAYERCHARACTERMODULE_API AMPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* InputMappingContext;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
