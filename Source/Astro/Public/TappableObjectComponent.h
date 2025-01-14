#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "TappableObjectComponent.generated.h"

class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTappableObjectComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ResourceItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResourceProductionRate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTappingEfficiencyChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> TapperSlots;
    
public:
    UTappableObjectComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UnregisterTapperSlot(FSlotReference tapperSlot);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void RegisterTapperSlot(FSlotReference tapperSlot);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    float GetCurrentTappingEfficiency();
    
};

