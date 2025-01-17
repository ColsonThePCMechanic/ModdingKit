#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "EClickSlotBehavior.h"
#include "SlotClickResult.generated.h"

USTRUCT(BlueprintType)
struct FSlotClickResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference SlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EClickSlotBehavior Behavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubslotIndex;
    
    ASTRO_API FSlotClickResult();
};

