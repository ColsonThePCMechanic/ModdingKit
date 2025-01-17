#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnResourceSlotFullDelegate.generated.h"

class UItemType;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnResourceSlotFull, TSubclassOf<UItemType>, Type);

