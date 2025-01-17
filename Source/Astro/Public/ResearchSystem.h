#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ResearchSubjectComponent.h"
#include "AstroEntitySystem.h"
#include "AstroDatumRef.h"
#include "ResearchSystem.generated.h"

class UObject;
class APlayerController;
class UItemType;
class APhysicalItem;
class UItemComponent;
class AAstroGameState;

UCLASS(Blueprintable)
class ASTRO_API UResearchSystem : public UAstroEntitySystem
{
    GENERATED_BODY()
public:
    UResearchSystem();
    UFUNCTION(BlueprintCallable)
    static void StartOrInterruptResearch(FAstroDatumRef ResearchEntityRef, FAstroDatumRef InstigatorEntityRef, bool &bOutSuccess);

    UFUNCTION()
    void OnResearchSubjectSet(APhysicalItem *Item);

    UFUNCTION()
    void OnResearchSubjectReleased(APhysicalItem *Item);

    UFUNCTION()
    void OnResearchSubjectItemTypeChanged(UItemComponent *researchSubjectItemComponent, TSubclassOf<UItemType> NewItemType);

    UFUNCTION()
    void OnResearchSubjectDestroyedInSlot(APhysicalItem *Item);

    UFUNCTION(BlueprintPure)
    static bool IsItemTypeUnlockedForGame(const AAstroGameState *GameState, TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static bool IsItemTypeUnlocked(const APlayerController *PlayerController, TSubclassOf<UItemType> ItemType);

    UFUNCTION(BlueprintPure)
    static float GetResearchTimeProgressRatio(const FResearchSubjectComponent &ResearchSubject);

    UFUNCTION(BlueprintPure)
    static void GetResearchSubjectTotals(const FResearchSubjectComponent &ResearchSubject, float &OutTotalPointsFromSubject, float &OutSubjectTotalResearchTime);

    UFUNCTION(BlueprintPure)
    static float GetResearchPointProgressRatio(const FResearchSubjectComponent &ResearchSubject);

    UFUNCTION(BlueprintPure)
    static float GetCurrentResearchPointsPerMinute(const APlayerController *PlayerController);

    UFUNCTION(BlueprintPure)
    static float GetCurrentResearchPointBalance(const APlayerController *PlayerController);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintAuthorityOnly, BlueprintCallable)
    static void AuthorityGrantResearchPoints(const UObject *WorldContextObject, int32 PointsToGrant);
};
