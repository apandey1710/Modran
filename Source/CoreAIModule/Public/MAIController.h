// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MAIController.generated.h"

/**
 * 
 */
UCLASS()
class COREAIMODULE_API AMAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Behavior")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditDefaultsOnly, Category = "Behavior")
	FName TargetActorBBKey;
	
	virtual void BeginPlay() override;
};
