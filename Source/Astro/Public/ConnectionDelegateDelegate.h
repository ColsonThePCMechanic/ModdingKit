#pragma once
#include "CoreMinimal.h"
#include "ConnectionDelegateDelegate.generated.h"

class ASlotConnection;
class UChildSlotComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConnectionDelegate, UChildSlotComponent*, Slot, ASlotConnection*, Connection);

