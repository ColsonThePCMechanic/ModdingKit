#pragma once
#include "CoreMinimal.h"
#include "EPlayerCategory.h"
#include "AstroClientProperties.generated.h"

USTRUCT(BlueprintType)
struct FAstroClientProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EPlayerCategory PlayerCategory;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FString PlayerName;
    
    ASTRO_API FAstroClientProperties();
};
