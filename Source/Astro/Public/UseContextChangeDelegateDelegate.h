#pragma once
#include "CoreMinimal.h"
#include "EUseContext.h"
#include "UseContextChangeDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUseContextChangeDelegate, EUseContext, UseContext);

