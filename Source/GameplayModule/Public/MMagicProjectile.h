#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MMagicProjectile.generated.h"

UCLASS()
class GAMEPLAYMODULE_API AMMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AMMagicProjectile();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
	class USphereComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "VFX")
	class UParticleSystemComponent* ParticleSystemComponent;

public:	
	virtual void Tick(float DeltaTime) override;

};
