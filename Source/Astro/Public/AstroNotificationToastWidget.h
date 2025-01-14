#pragma once
#include "CoreMinimal.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroNotificationToastDisplayData.h"
#include "SignalDelegate.h"
#include "AstroNotificationToastWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UAstroNotificationToastWidget : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationToastDisplayData DisplayData;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnMaxLifetimeReached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLifetime;
    
public:
    UAstroNotificationToastWidget();
    UFUNCTION(BlueprintImplementableEvent)
    void PresentToast();
    
private:
    UFUNCTION(BlueprintCallable)
    void MarkNotificationForDestruction();
    
};

