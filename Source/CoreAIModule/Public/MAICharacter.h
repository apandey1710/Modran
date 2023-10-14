#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MAICharacter.generated.h"

UCLASS()
class COREAIMODULE_API AMAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AMAICharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
