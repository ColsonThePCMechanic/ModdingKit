#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SignalDelegate.h"
#include "OnActiveResearchSubjectExpiredDelegate.h"
#include "OnResearchSubjectListChangedDelegate.h"
#include "OnActiveResearchSubjectsChangedDelegate.h"
#include "SlotReference.h"
#include "AstroDatumRef.h"
#include "ResearchReplicationData.h"
#include "AttachedResearchSubject.h"
#include "ActorResearchComponent.generated.h"

class UCurveFloat;
class APlayController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorResearchComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnWantsToResearchChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnIsResearchingChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResearchSubjectListChanged OnResearchSubjectListChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnResearchReplicationDataChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnResearchStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveResearchSubjectsChanged OnAuthorityChangedActiveResearchSubjects;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveResearchSubjectExpired OnActiveResearchSubjectExpiredAuthority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ResearchSlotNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResearchPowerRequired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumResearchPowerFraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumResearchRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* UnderPoweredResearchRateCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumResearchPowerMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumResearchRateMutliplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* OverPoweredResearchRateCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResearchSlotsUnclickableWhileActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyActiveResearchSubjectsOnInterruption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpiredResearchSubjectDestructionDelay;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ResearchData, meta=(AllowPrivateAccess=true))
    FResearchReplicationData ResearchReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ResearchSlotRefs;
    
public:
    UActorResearchComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION()
    void OnRep_ResearchData();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityStartOrInterruptResearch(APlayController* InstigatingController);
    
    UFUNCTION()
    void AuthorityChangedActiveResearchSubjects(FAstroDatumRef ResearchComponentRef, const TArray<FAttachedResearchSubject>& ActiveResearchSubjects);
    
    UFUNCTION()
    void AuthorityActiveResearchSubjectExpired(FAstroDatumRef ResearchComponentRef, FAttachedResearchSubject ExpiredAttachedResearchSubject);
    
};

