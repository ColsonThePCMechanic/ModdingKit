#pragma once
#include "CoreMinimal.h"
#include "RewardPossibility.h"
#include "RewardSelectionParameters.generated.h"

USTRUCT(BlueprintType)
struct FRewardSelectionParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRewardPossibility> Possibilities;
    
    UPROPERTY(EditAnywhere)
    uint32 SubsetCount;
    
    ASTRO_API FRewardSelectionParameters();
};

