#pragma once
#include "CoreMinimal.h"
#include "EGateObjectType.h"
#include "GateObjectReference.generated.h"

class ASolarBody;

USTRUCT(BlueprintType)
struct FGateObjectReference {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EGateObjectType GateObjectType;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ChamberIndex;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TWeakObjectPtr<ASolarBody> GateObjectSolarBody;
    
public:
    ASTRO_API FGateObjectReference();
};

