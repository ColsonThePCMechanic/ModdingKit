#pragma once
#include "CoreMinimal.h"
#include "EUseContext.generated.h"

UENUM()
enum class EUseContext : uint8 {
    UC_Use,
    UC_Toggle,
    UC_TurnOn,
    UC_TurnOff,
    UC_ChangeColor,
    UC_Detonate,
    UC_Ignite,
    UC_Launch,
    UC_Print,
    UC_SitDown,
    UC_StandUp,
    UC_Flip,
    UC_TakeOff,
    UC_LiftOff,
    UC_Resupply,
    UC_Research,
    UC_Smelt,
    UC_Extract,
    UC_Catalyze,
    UC_Condense,
    UC_Trade,
    UC_Enter,
    UC_Exit,
    UC_Land,
    UC_Pack,
    UC_Unpack,
    UC_Equip,
    UC_Unequip,
    UC_Start,
    UC_Stop,
    UC_Pause,
    UC_Cancel,
    UC_Load,
    UC_Unload,
    UC_Transfer,
    UC_Place,
    UC_Deploy,
    UC_Plant,
    UC_AddToCatalog,
    UC_Scan,
    UC_Examine,
    UC_Gaze,
    UC_Activate,
    UC_Select,
    UC_Expand,
    UC_Collapse,
    UC_TakePhoto,
    UC_EnableDepositSlot,
    UC_EnableWithdrawalSlot,
    UC_CycleModes,
    UC_Configure,
    UC_EnableOutput,
    UC_DisableOutput,
    UC_Lock,
    UC_Unlock,
    UC_SpeedUp,
    UC_SpeedDown,
    UC_LaunchOrbit,
    UC_LaunchPlanetSelect,
    UC_Astropedia,
    UC_Harvest,
    UC_NextRecipe,
    UC_Befriend,
    UC_MAX UMETA(Hidden),
};

