// Fill out your copyright notice in the Description page of Project Settings.


#include "MCheckWithinRangeService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UMCheckWithinRangeService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if(!ensure(IsValid(BlackboardComponent)))
	{
		return;
	}

	AActor* TargetActor = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetActorBBKey.SelectedKeyName));
	if(!ensure(IsValid(TargetActor)))
	{
		return;
	}

	AAIController* CurrentController = OwnerComp.GetAIOwner();
	if(!ensure(IsValid(CurrentController)))
	{
		return;
	}

	APawn* CurrentPawn = CurrentController->GetPawn();
	if(!ensure(IsValid(CurrentPawn)))
	{
		return;
	}

	bool bIsWithinRange = FVector::Distance(TargetActor->GetActorLocation(), CurrentPawn->GetActorLocation()) <= AttackRange;
	bool bHasLineOfSight = CurrentController->LineOfSightTo(TargetActor);
	
	BlackboardComponent->SetValueAsBool(WithinRangeBBKey.SelectedKeyName, bIsWithinRange && bHasLineOfSight);
}
