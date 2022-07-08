#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "RingCameraTargeter.generated.h"

class AActor;
class USceneComponent;
class APlayController;
class ASlotConnection;
class URingCameraTargeter;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API URingCameraTargeter : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float AvoidRadians;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *Target;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *Center;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CenterDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LerpSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PlayerCameraTargetLerp;

    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta = (AllowPrivateAccess = true))
    TArray<USceneComponent *> AvoidTargets;

private:
    UPROPERTY()
    FSlotReference Slot;

public:
    URingCameraTargeter();
    UFUNCTION(BlueprintCallable)
    void SnapToTargetLocation(const FVector &TargetLocation);

    UFUNCTION(BlueprintCallable)
    void SnapToTarget(APlayController *Controller);

    UFUNCTION(BlueprintCallable)
    void SetTarget(USceneComponent *TargetComponent, USceneComponent *RingCenter, FSlotReference TargetingSlot);

    UFUNCTION()
    void OnSlotDisconnected(FSlotReference ConnectedSlot, ASlotConnection *Connection);

    UFUNCTION()
    void OnSlotConnected(FSlotReference ConnectedSlot, ASlotConnection *Connection);

    UFUNCTION(BlueprintPure)
    static URingCameraTargeter *ActorRingCameraTargeter(AActor *Actor);
};