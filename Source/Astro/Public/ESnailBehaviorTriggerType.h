#pragma once
#include "CoreMinimal.h"
#include "ESnailBehaviorTriggerType.generated.h"

UENUM()
enum class ESnailBehaviorTriggerType : uint8 {
    Idle,
    IdleHappy,
    Fed,
    CrackedPanel,
    PlayerEmoteGesture,
    PlayerEmoteDance,
    PlayerNearby,
    Pet,
};

