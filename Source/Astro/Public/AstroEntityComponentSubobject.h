#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AstroDatumRef.h"
#include "AstroEntityComponentSubobject.generated.h"

class UAstroEntityComponentSubobjectDefinition;

UCLASS(Blueprintable)
class UAstroEntityComponentSubobject : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef OwnerComponentRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName DefinitionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroEntityComponentSubobjectDefinition* Definition;
    
    UAstroEntityComponentSubobject();
};

