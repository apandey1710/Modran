#include "MAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


void AMAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	UBlackboardComponent* BlackboardComponent = GetBlackboardComponent();
	
	APawn* PlayerCharacter = UGameplayStatics::GetPlayerPawn(this, 0);
	if(ensure(IsValid(PlayerCharacter)) && ensure(IsValid(BlackboardComponent)))
	{
		BlackboardComponent->SetValueAsObject(TargetActorBBKey, PlayerCharacter);
	}
}
