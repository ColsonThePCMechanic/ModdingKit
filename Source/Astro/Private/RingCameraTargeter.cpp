#include "RingCameraTargeter.h"

class APlayController;
class USceneComponent;
class ASlotConnection;
class AActor;
class URingCameraTargeter;

void URingCameraTargeter::SnapToTargetLocation(const FVector& TargetLocation) {
}

void URingCameraTargeter::SnapToTarget(APlayController* Controller) {
}

void URingCameraTargeter::SetTarget(USceneComponent* TargetComponent, USceneComponent* RingCenter, FSlotReference TargetingSlot) {
}

void URingCameraTargeter::OnSlotDisconnected(FSlotReference ConnectedSlot, ASlotConnection* Connection) {
}

void URingCameraTargeter::OnSlotConnected(FSlotReference ConnectedSlot, ASlotConnection* Connection) {
}

URingCameraTargeter* URingCameraTargeter::ActorRingCameraTargeter(AActor* Actor) {
    return NULL;
}

URingCameraTargeter::URingCameraTargeter() {
    this->AvoidRadians = 1.00f;
    this->Target = NULL;
    this->Center = NULL;
    this->CenterDistance = 250.00f;
    this->LerpSpeed = 4.00f;
    this->PlayerCameraTargetLerp = 0.50f;
}

