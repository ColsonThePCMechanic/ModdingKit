#pragma once
#include "CoreMinimal.h"
#include "EAstroTelemetryCounter.generated.h"

UENUM()
enum class EAstroTelemetryCounter : uint8 {
    KeyboardUsageTime,
    GamepadUsageTime,
    UndergroundTime,
    OvergroundTime,
    DeformRemoveTime,
    DeformAddTime,
    DeformFlattenTime,
    ResourcesSedimentAmountCollected,
    ResourcesSedimentAmountDestroyed,
    ResourcesSedimentAmountConsumedTerrainAdd,
    ResourcesSedimentAmountConsumedTerrainFlatten,
    SmallRoverOcuppiedTime,
    MediumRoverOcuppiedTime,
    LargeRoverOccupiedTime,
    AbsoluteSteeringDriveTime,
    CameraSteeringDriveTime,
    RoverManualAirControlRollTime,
    RoverManualAirControlYawTime,
    CreativeDeformRemoveTime,
    CreativeDeformAddTime,
    CreativeDeformFlattenTime,
    CreativeDeformColorPick,
    CreativeDeformColorPaint,
    AdventureToCreative,
    CreativeToAdventure,
    FreeOxygen,
    FreeVehicleFuel,
    UnlimitedBackpackPower,
    Invicible,
    InvisibleToHazards,
    RemoveDecoratorsWhilePainting,
    DisableResourceCollection,
    ShowLODAnchors,
    ShowTerrainToolLight,
    FlightSpeed,
    TimeOfDay,
    SunOrbit,
    SolorTimeMultiplier,
    COUNT,
};

