#pragma once
#include "CoreMinimal.h"
#include "LockChangedEventMetadata.h"
#include "AstroDatumRef.h"
#include "LockComponentSignalDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLockComponentSignal, FAstroDatumRef, SignallingLockComponentRef, const FLockChangedEventMetadata&, EventData);
