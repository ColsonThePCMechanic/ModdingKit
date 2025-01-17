#pragma once
#include "CoreMinimal.h"
#include "RestartPlayerSignalDelegate.generated.h"

class APlayerController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRestartPlayerSignal, APlayerController*, Player);

