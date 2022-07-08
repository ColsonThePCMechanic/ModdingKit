#pragma once
#include "CoreMinimal.h"
#include "ResearchSubjectComponent.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "ResearchSubjectComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UResearchSubjectComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UResearchSubjectComponentContainer();
    UFUNCTION(BlueprintPure)
    static FResearchSubjectComponent GetResearchSubjectComponent(FAstroDatumRef ResearchSubjectComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FResearchSubjectComponent FindResearchSubjectComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};