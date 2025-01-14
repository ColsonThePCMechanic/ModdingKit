#include "ControlPanel.h"
#include "Net/UnrealNetwork.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "CrackableActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SpotLightComponent -FallbackName=SpotLightComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
#include "ClickableComponent.h"

class UPrimitiveComponent;


void AControlPanel::OnSecondaryButtonPressed() {
}

void AControlPanel::OnRep_ControlledActor() {
}

void AControlPanel::OnOwnerItemPickedUpOrUnslotted(bool bUnused) {
}

void AControlPanel::OnNavigationComponentClicked(UPrimitiveComponent* navigationComponent, FKey ButtonPressed) {
}

void AControlPanel::OnNavigateUpRepeat() {
}

void AControlPanel::OnNavigateUpDown(float AxisValue) {
}


void AControlPanel::OnNavigateUp() {
}

void AControlPanel::OnNavigateRightRepeat() {
}


void AControlPanel::OnNavigateRight() {
}

void AControlPanel::OnNavigateLeftRight(float AxisValue) {
}

void AControlPanel::OnNavigateLeftRepeat() {
}


void AControlPanel::OnNavigateLeft() {
}

void AControlPanel::OnNavigateDownRepeat() {
}


void AControlPanel::OnNavigateDown() {
}

void AControlPanel::OnCrackableActorComponentExaminableChanged() {
}



void AControlPanel::OnConfirm() {
}


void AControlPanel::OnCancel() {
}

bool AControlPanel::IsLocallyControlled() const {
    return false;
}

bool AControlPanel::GetCracked() const {
    return false;
}

void AControlPanel::FullyCrackedOrClosed(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked) {
}

void AControlPanel::CrackedChanged(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked) {
}

void AControlPanel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AControlPanel, ControlledActor);
}

AControlPanel::AControlPanel() {
    this->RedirectOwnerInteractions = true;
    this->SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->ControlPanelLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("ControlPanelLight"));
    this->CrackableActorComponent = CreateDefaultSubobject<UCrackableActorComponent>(TEXT("CrackableActor"));
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->ControlledActor = NULL;
    this->CameraContext = NULL;
    this->FallbackInputComponent = NULL;
    this->FirstNavigationRepeatDelay = 0.50f;
    this->NavigationRepetitionInterval = 0.15f;
    this->AnalogStickNavigationThreshold = 0.50f;
    this->bAutoOptimizeHierarchy = false;
}

