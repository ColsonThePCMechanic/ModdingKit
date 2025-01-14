#pragma once
#include "CoreMinimal.h"
#include "AstroStatics.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "EPlanetIdentifier.h"
#include "AtmosphericResource.h"
#include "PlanetStatics.generated.h"

class ASolarBody;
class USceneComponent;
class UObject;
class AAstroPlanet;
class AActor;
class ASun;
class AGateStation;

UCLASS(Blueprintable)
class ASTRO_API UPlanetStatics : public UAstroStatics
{
    GENERATED_BODY()
public:
    UPlanetStatics();
    UFUNCTION(BlueprintPure)
    static FVector ToPlanet(AAstroPlanet *Planet, AActor *Actor);

    UFUNCTION(BlueprintCallable)
    static FVector TargetVelocity(FVector Velocity, AActor *Actor, float Time);

    UFUNCTION(BlueprintCallable)
    static void TargetFacingUp(FVector Up, AActor *Actor, float TorqueStrength);

    UFUNCTION(BlueprintCallable)
    static void TargetBody(ASolarBody *Body, AActor *Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector SunDirectionRelativeToSolarBody(UObject *WorldContextObject, const ASolarBody *centerBody, const FVector &WorldPosition);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector SunDirection(UObject *WorldContextObject, const FVector &WorldPosition);

    UFUNCTION(BlueprintCallable)
    static void SoftLanding(AAstroPlanet *Planet, AActor *Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer);

    UFUNCTION(BlueprintPure)
    static FVector PlanetUpComponent(USceneComponent *Component);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static FVector PlanetUp(const UObject *WorldContextObject, const FVector &WorldPosition);

    UFUNCTION(BlueprintPure)
    static bool PlanetTrace(AActor *Actor, FHitResult &OutHit);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static bool IsTerrainReadyAtLocation(UObject *WorldContextObject, const FVector &Location);

    UFUNCTION(BlueprintPure)
    static FVector GravityUp(const AActor *Actor);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static ASun *GetSun(UObject *WorldContextObject);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static ASolarBody *GetSolarBodyByLocation(const UObject *WorldContextObject, FVector Location, bool bDoBoundsCheck, bool bVisitableByPlayerOnly);

    UFUNCTION(BlueprintPure)
    static ASolarBody *GetSolarBody(AActor *Actor, bool bBoundsCheck);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static TArray<AAstroPlanet *> GetPlanets(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static EPlanetIdentifier GetPlanetIdentifier(AActor *Actor);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static AAstroPlanet *GetPlanetByLocation(const UObject *WorldContextObject, FVector Position, bool boundsCheck, bool locationIsSolar);

    UFUNCTION(BlueprintPure)
    static AAstroPlanet *GetPlanet(AActor *Actor, bool bBoundsCheck);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintPure)
    static AGateStation *GetGateStation(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static AAstroPlanet *GetClosestPlanet(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static FVector GetBodyGravityAtLocation(ASolarBody *Body, FVector Location);

    UFUNCTION(BlueprintPure)
    static FVector GetBodyGravity(ASolarBody *Body, AActor *Actor);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"))
    static void GeneratePlanetGravitySources(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FVector FromPlanet(AAstroPlanet *Planet, AActor *Actor);

    UFUNCTION(BlueprintPure)
    static bool EscapedBodyByLocation(ASolarBody *Body, const FVector &Location, float Scale, float Distance, bool locationIsSolar);

    UFUNCTION(BlueprintPure)
    static bool EscapedBody(ASolarBody *Body, AActor *Actor, float Scale, float Distance);

    UFUNCTION(BlueprintPure)
    static bool AreAtmosphericResourcesEqual(const FAtmosphericResource &resourceA, const FAtmosphericResource &resourceB);
};
