#pragma once
#include "CoreMinimal.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "PersistentLocalPlayerData.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UPersistentLocalPlayerData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnDirtied;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasCompletedTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasSkippedTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasSeenIntroCutscene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsMultiplayerDisabled;
    
    UPROPERTY(EditAnywhere, SaveGame)
    uint8 LastUpdateCutsceneVersionSeen;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TArray<uint32> EarnedItemDrivePhysicalRewardHashes;
    
public:
    UPersistentLocalPlayerData();
    UFUNCTION(BlueprintCallable)
    void NotifySkippedTutorial();
    
    UFUNCTION(BlueprintCallable)
    void NotifySeenIntroCutscene(bool wasUpdateCinematic);
    
    UFUNCTION(BlueprintCallable)
    void NotifyCompletedTutorial();
    
};

