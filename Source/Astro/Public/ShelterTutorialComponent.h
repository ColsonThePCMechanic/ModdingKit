#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
#include "ShelterTutorialComponent.generated.h"

class ASlotConnection;
class APhysicalItem;
class AResourceInfo;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UShelterTutorialComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableTutorialCompleteEvent);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResourceInfo> GrabSlotIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResourceInfo> AttachSlotIndicator;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableTutorialCompleteEvent OnCableTutorialComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CableTutorialIsComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AResourceInfo*> ShelterCableIndicators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AResourceInfo*> PlatformCableIndicators;
    
public:
    UShelterTutorialComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopCableTutorial();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupCableTutorial(TArray<FSlotReference> shelterCableSlots, APhysicalItem* Platform);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCableTutorialKey(FName tutorialKey);
    
protected:
    UFUNCTION()
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION()
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION()
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable);
    
};

