#include "RewardState.h"
#include "Templates/SubclassOf.h"

class UItemType;

bool URewardState::IsUnlocked(TSubclassOf<UItemType> ItemType) const {
    return false;
}

URewardState::URewardState() {
}

