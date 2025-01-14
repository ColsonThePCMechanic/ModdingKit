#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroGameMenuEntryWidgetDisplayData.h"
#include "AstroGameMenuPopoutWidgetContentsBase.generated.h"

class UAstroGameMenuFocusItemWidget;
class UAstroGameMenuPopoutWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuPopoutWidgetContentsBase : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuFocusItemWidget* OwningFocusItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PopoutParentTitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroGameMenuEntryWidgetDisplayData PopoutParentTitleTextWidgetDisplayData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialFocusCoordinates;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroGameMenuPopoutWidget* ParentPopoutWidget;
    
public:
    UAstroGameMenuPopoutWidgetContentsBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleWrapperFocusIndexChanged(int32 NewFocusIndex);
    
    UFUNCTION(BlueprintNativeEvent)
    void HandleNavigationBackRequest();
    
};

