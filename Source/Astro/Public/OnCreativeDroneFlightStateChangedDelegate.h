#pragma once
#include "CoreMinimal.h"
#include "EDroneFlightState.h"
#include "OnCreativeDroneFlightStateChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeDroneFlightStateChanged, EDroneFlightState, flightState);

