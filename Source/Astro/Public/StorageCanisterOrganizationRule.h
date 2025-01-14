#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotOrganizationRule.h"
#include "StorageCanisterOrganizationRule.generated.h"

class UItemType;

UCLASS(Blueprintable, EditInlineNew)
class UStorageCanisterOrganizationRule : public USlotOrganizationRule {
    GENERATED_BODY()
public:
    UStorageCanisterOrganizationRule();
    UFUNCTION(BlueprintCallable)
    void SetStoredItemTypeWhitelist(TArray<TSubclassOf<UItemType>> ItemTypes);
    
    UFUNCTION()
    void SetIsInputRule(bool isInput);
    
    UFUNCTION(BlueprintCallable)
    void SetDispensing(bool isDispensing);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentStoredItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    void OnSlottedItemDrainedOrFilled();
    
};

