#include "MAICharacter.h"
#include "Components/CapsuleComponent.h"

AMAICharacter::AMAICharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
}

void AMAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
