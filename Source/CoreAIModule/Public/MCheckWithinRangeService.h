#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "MCheckWithinRangeService.generated.h"

UCLASS()
class COREAIMODULE_API UMCheckWithinRangeService : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Keys")
	FBlackboardKeySelector WithinRangeBBKey;

	UPROPERTY(EditAnywhere, Category = "Keys")
	FBlackboardKeySelector TargetActorBBKey;

	UPROPERTY(EditAnywhere, Category = "Range")
	float AttackRange = 400.0f;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
