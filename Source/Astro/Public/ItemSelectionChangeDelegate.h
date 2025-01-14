#pragma once
#include "CoreMinimal.h"
#include "ItemSelectionChangeDelegate.generated.h"

class APhysicalItem;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemSelectionChange, APhysicalItem*, Item);

