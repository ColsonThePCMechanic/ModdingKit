#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UseStateChangeDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "ClickableDelegateNewDelegate.h"
#include "UseContextChangeDelegateDelegate.h"
#include "EUseContext.h"
#include "UseSuppressionState.h"
#include "InteractionRedirect.h"
#include "EUseType.h"
#include "ClickableComponent.generated.h"

class USceneComponent;
class UStaticMesh;
class AActor;
class APlayerController;
class UClickableComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UClickableComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *PositioningComponent;

    UPROPERTY(EditAnywhere)
    UStaticMesh *PrimaryIndicatorMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *SecondaryIndicatorMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PrimaryIndicatorScale;

    UPROPERTY(EditAnywhere)
    float PrimaryHoverHeight;

    UPROPERTY(EditAnywhere)
    float SecondaryIndicatorScale;

    UPROPERTY(EditAnywhere)
    uint8 BackpackInteraction : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 ShowPrimaryIndicator : 1;

    UPROPERTY(EditAnywhere)
    uint8 ShowPrimaryIcon : 1;

    UPROPERTY(EditAnywhere)
    uint8 CaptureDeformTool : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 EncapsulateChildren : 1;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    uint8 DisablePrimitiveClicks : 1;

    UPROPERTY(EditAnywhere)
    uint8 ReplaceChildren : 1;

    UPROPERTY(EditAnywhere)
    uint8 AllowNonOwnerClicks : 1;

    UPROPERTY(EditAnywhere)
    uint8 LocalPrimitiveClicksOnly : 1;

    UPROPERTY(EditAnywhere)
    uint8 CaptureViewActor : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta = (AllowPrivateAccess = true))
    uint8 UnencapsulateChildren : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 Unclickable : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 NoGamepadAutoselect : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 Unmovable : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bSlowVirtualCursorOnHover : 1;

    UPROPERTY(EditAnywhere)
    uint8 bExcludeNonInteractPrimitivesFromGamepadAutoFocus : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 HasUseInteractionByDefault : 1;

    UPROPERTY(EditAnywhere)
    uint8 HasAuxSlotUseByDefault : 1;

    UPROPERTY(EditAnywhere)
    uint8 HasActuatorUseByDefault : 1;

    UPROPERTY(EditAnywhere)
    uint8 HasUseWhilePlayerDriving : 1;

    UPROPERTY(EditAnywhere)
    uint8 HasInfoOnlyTooltipWhilePlayerDriving : 1;

    UPROPERTY(EditAnywhere)
    uint8 UseActionRequriesHold : 1;

    UPROPERTY(EditAnywhere)
    uint8 bUseOverridePivotOffset : 1;

    UPROPERTY(EditAnywhere)
    float SecondaryInteractionTime;

    UPROPERTY(EditAnywhere)
    FVector2D InteractionWidgetPivot;

    UPROPERTY(BlueprintAssignable)
    FClickableDelegateNew OnQueryClickable;

    UPROPERTY(BlueprintAssignable)
    FUseStateChangeDelegate OnUseStateChanged;

    UPROPERTY(BlueprintAssignable)
    FUseContextChangeDelegate OnUseContextChanged;

protected:
    UPROPERTY(EditAnywhere)
    EUseContext DefaultUseContext;

private:
    UPROPERTY(ReplicatedUsing = OnRep_UseSuppressionState)
    FUseSuppressionState UseSuppressionState;

    UPROPERTY()
    FInteractionRedirect InteractionRedirect;

public:
    UClickableComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetInteractionRedirectActor(AActor *Actor, USceneComponent *PivotComponent);

    UFUNCTION(BlueprintCallable)
    void SetActiveUseContext(EUseContext NewUseContext);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushUseSuppression_AuthorityOnly(const FName SuppressionId, EUseType useTypeFlags);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushOrPopUseSuppression_AuthorityOnly(FName SuppressionId, bool shouldSuppress, EUseType useTypeFlags);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PopUseSuppression_AuthorityOnly(const FName SuppressionId);

private:
    UFUNCTION()
    void OnRep_UseSuppressionState();

public:
    UFUNCTION(BlueprintPure)
    bool HasInteractionRedirect();

    UFUNCTION(BlueprintCallable)
    bool GetUseCapability(EUseType useType);

    UFUNCTION(BlueprintPure)
    bool GetUseAvailability(const APlayerController *Instigator, EUseType useType);

    UFUNCTION(BlueprintPure)
    USceneComponent *GetPositionComponent() const;

    UFUNCTION(BlueprintPure)
    static USceneComponent *GetActorClickableOrRoot(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static UClickableComponent *GetActorClickableOrDefault(AActor *Actor);

    UFUNCTION(BlueprintPure)
    EUseContext GetActiveUseContext() const;

    UFUNCTION(BlueprintPure)
    static UClickableComponent *ActorClickable(AActor *Actor);
};