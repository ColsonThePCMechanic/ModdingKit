#pragma once
#include "CoreMinimal.h"
#include "CharacterSelectSignalDelegate.generated.h"

class APlayController;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterSelectSignal, APlayController*, Controller);

