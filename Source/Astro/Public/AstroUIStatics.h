#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateColor -FallbackName=SlateColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateBrush -FallbackName=SlateBrush
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=ESlateBrushDrawType -FallbackName=ESlateBrushDrawType
#include "EAstroUIAudioEventKey.h"
#include "AstroPopupBadgeAuthoringData.h"
#include "AstroUIStatics.generated.h"

class UImage;
class UBorder;
class UWidget;
class UAstroUIStylingDatabase;
class UAstroPopupBadgeDatabase;
class UWidgetAnimation;
class AActor;
class UItemType;

UCLASS(Blueprintable)
class UAstroUIStatics : public UObject {
    GENERATED_BODY()
public:
    UAstroUIStatics();
    UFUNCTION(BlueprintPure)
    static FSlateBrush SlateBrushWithNewSlateColor(FSlateBrush SlateBrush, FSlateColor SlateColor);
    
    UFUNCTION(BlueprintPure)
    static FSlateBrush SlateBrushWithNewColor(FSlateBrush SlateBrush, FLinearColor LinearColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushSlateColor(UImage* Image, FSlateColor BrushColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushSize(UImage* Image, FVector2D NewSize);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushImage(UImage* Image, UObject* ImageResource);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushColor(UImage* Image, FLinearColor BrushColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetBorderBrushSlateColor(UBorder* Border, FSlateColor Color);
    
    UFUNCTION(BlueprintCallable)
    static void SetBorderBrushImage(UBorder* Border, UObject* ImageResource);
    
    UFUNCTION(BlueprintCallable)
    static void SetBorderBrushDrawAs(UBorder* Border, TEnumAsByte<ESlateBrushDrawType::Type> DrawAsType);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllUserFocus(UWidget* WidgetToFocus);
    
    UFUNCTION(BlueprintPure)
    static UAstroUIStylingDatabase* GetAstroUIStylingDatabase();
    
    UFUNCTION(BlueprintPure)
    static FString GetAstroUIAudioEvent(EAstroUIAudioEventKey AudioEventKey);
    
    UFUNCTION(BlueprintPure)
    static UAstroPopupBadgeDatabase* GetAstroPopupBadgeDatabase();
    
    UFUNCTION(BlueprintCosmetic, BlueprintPure)
    static float GetAnimationDuration(const UWidgetAnimation* InAnimation);
    
    UFUNCTION(BlueprintCallable)
    static void DisplayPopupBadgeForItemPing(AActor* OwningActor, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    static void DisplayPopupBadge(AActor* OwningActor, const FAstroPopupBadgeAuthoringData& AuthoringData);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllUserFocus();
    
};

