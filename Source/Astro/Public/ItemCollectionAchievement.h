#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ProgressionAchievementDefinition.h"
#include "ItemCollectionAchievement.generated.h"

class UItemList;

USTRUCT(BlueprintType)
struct FItemCollectionAchievement : public FProgressionAchievementDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> CollectionItems;
    
    ASTRO_API FItemCollectionAchievement();
};
