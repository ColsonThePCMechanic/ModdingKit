#include "ItemSlot.h"
#include "ClickableComponent.h"

class UChildSlotComponent;
class APhysicalItem;
class ASlotConnection;



void AItemSlot::OnConnectionDestroyed_Implementation(UChildSlotComponent* Other, bool IsSource) {
}

void AItemSlot::OnConnectionBuilt_Implementation(ASlotConnection* Connection, bool IsSource) {
}


bool AItemSlot::AcceptsItem_Implementation(APhysicalItem* Item) {
    return false;
}

AItemSlot::AItemSlot() {
    this->slotType = ESlotType::Inert;
    this->BaseClassType = NULL;
    this->Subslot = NULL;
    this->ConnectionClass = NULL;
    this->SingleConnection = true;
    this->ItemBlocksConnection = true;
    this->ConnectionBlocksItem = false;
    this->ConnectionTense = false;
    this->PowerIncomingOnly = false;
    this->StreamingPowerConnectionsMergePowerNodes = false;
    this->CanAcceptUnslottableItems = false;
    this->IsTrailerHitch = false;
    this->SlotTier = 1;
    this->SlotTierCount = 1;
    this->CanHoldItem = true;
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("SlotClickableComponent"));
    this->CanAcceptItems = true;
}

