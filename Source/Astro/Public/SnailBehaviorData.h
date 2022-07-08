#pragma once
#include "CoreMinimal.h"
#include "SnailBehaviorData.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FSnailBehaviorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    TArray<UAnimMontage*> Anims;
    
    ASTRO_API FSnailBehaviorData();
};
