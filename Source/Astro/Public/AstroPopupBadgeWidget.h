#pragma once
#include "CoreMinimal.h"
#include "AstroUICardWidget.h"
#include "AstroPopupBadgeWidgetDisplayData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "AstroPopupBadgeWidget.generated.h"

class UBorder;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroPopupBadgeWidget : public UAstroUICardWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PresentationAnimationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UBorder* PopupBadgeContainerBorder;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroPopupBadgeWidgetDisplayData DisplayData;
    
public:
    UAstroPopupBadgeWidget();
    UFUNCTION(BlueprintCallable)
    void UpdateDisplayData(const FAstroPopupBadgeWidgetDisplayData& NewDisplayData);
    
    UFUNCTION(BlueprintImplementableEvent)
    FVector2D GetPivotForUserWidget();
    
    UFUNCTION(BlueprintImplementableEvent)
    FVector2D GetDrawSizeForUserWidget();
    
};

