#include "VehicleBase.h"
#include "Net/UnrealNetwork.h"

class AAstroPlayerController;
class ASeatBase;



void AVehicleBase::PerformVehicleAux2Action(AAstroPlayerController* OriginatingController, EInputEvent eventType) {
}

void AVehicleBase::PerformVehicleAux1Action(AAstroPlayerController* OriginatingController, EInputEvent eventType) {
}

void AVehicleBase::OnRep_VehicleBaseReplicationData() {
}

ASeatBase* AVehicleBase::GetDrivingControllerSeat() {
    return NULL;
}

AAstroPlayerController* AVehicleBase::GetDrivingController() {
    return NULL;
}

void AVehicleBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AVehicleBase, VehicleBaseReplicationData);
}

AVehicleBase::AVehicleBase() {
    this->storage = NULL;
}

