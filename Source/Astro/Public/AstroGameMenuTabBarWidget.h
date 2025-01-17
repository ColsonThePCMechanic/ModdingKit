#pragma once
#include "CoreMinimal.h"
#include "AstroGameMenuFocusItemContainerWidget.h"
#include "AstroGameMenuTabBarAuthoringData.h"
#include "AstroGameMenuTabBarWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuTabBarWidget : public UAstroGameMenuFocusItemContainerWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroGameMenuTabBarAuthoringData AuthoringData;
    
    UAstroGameMenuTabBarWidget();
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    float GetWidthOfTabBar() const;
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
    float GetHeightOfTabBar() const;
    
};

