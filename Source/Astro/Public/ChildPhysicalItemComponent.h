#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CustomChildActorComponent.h"
#include "EPhysicalItemTerrainMode.h"
#include "ChildPhysicalItemComponent.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UChildPhysicalItemComponent : public UCustomChildActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> ChildMovableItemClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhysicalItemTerrainMode TerrainMode;
    
    UChildPhysicalItemComponent();
    UFUNCTION(BlueprintPure)
    APhysicalItem* GetChildPhysicalItem();
    
};

